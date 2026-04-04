#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "piano.h"
#include "detector.h"
#include "recorder.h"

using namespace cv;

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        printf("Cannot open camera\n");
        return 1;
    }

    namedWindow("MotionKeys", WINDOW_AUTOSIZE);

    int fw = (int)cap.get(CAP_PROP_FRAME_WIDTH);
    int fh = (int)cap.get(CAP_PROP_FRAME_HEIGHT);

    initKeys(fw, fh);

    Session session;
    session.count     = 0;
    session.recording = 0;

    int last_key = -1;

    printf("MotionKeys Ready!\n");
    printf("R=Record  T=Stop  P=Playback  S=Save  Q=Quit\n");

    Mat frame;
    while (1) {
        cap >> frame;
        if (frame.empty()) break;

        int i;
        for (i = 0; i < NUM_KEYS; i++) {
            rectangle(frame,
                Point(keys[i].x1, keys[i].y1),
                Point(keys[i].x2, keys[i].y2),
                Scalar(200, 150, 0), 2);
        }

        // Convert Mat to IplImage for detector
        IplImage iplFrame = cvIplImage(frame);
        Fingertip tip = detectFingertip(&iplFrame);

        if (tip.found) {
            circle(frame,
                Point(tip.x, tip.y),
                10, Scalar(0, 200, 255), -1);

            int key_idx = detectKey(tip.x, tip.y);

            if (key_idx >= 0 && key_idx != last_key) {
                rectangle(frame,
                    Point(keys[key_idx].x1, keys[key_idx].y1),
                    Point(keys[key_idx].x2, keys[key_idx].y2),
                    Scalar(100, 255, 0), -1);

                playNote(key_idx);

                if (session.recording)
                    recordNote(&session,
                        keys[key_idx].note_name,
                        keys[key_idx].frequency);

                last_key = key_idx;
            }
        } else {
            last_key = -1;
        }

        imshow("MotionKeys", frame);

        int key = waitKey(10);
        if      (key == (int)'q') break;
        else if (key == (int)'r') startRecording(&session);
        else if (key == (int)'t') stopRecording(&session);
        else if (key == (int)'p') playbackSession(&session);
        else if (key == (int)'s') exportMelody(&session, "melody.txt");
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
