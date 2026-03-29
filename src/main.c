#include <stdio.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include "piano.h"
#include "detector.h"
#include "recorder.h"

int main() {
    CvCapture* cap = cvCreateCameraCapture(0);
    if (!cap) {
        printf("Cannot open camera\n");
        return 1;
    }

    cvNamedWindow("MotionKeys", CV_WINDOW_AUTOSIZE);
    IplImage* frame = cvQueryFrame(cap);
    int fw = frame->width;
    int fh = frame->height;

    initKeys(fw, fh);

    Session session;
    session.count     = 0;
    session.recording = 0;

    int last_key = -1;

    printf("MotionKeys Ready!\n");
    printf("R=Record  T=Stop Recording  P=Playback\n");
    printf("S=Save Melody  Q=Quit\n");

    while (1) {
        frame = cvQueryFrame(cap);
        if (!frame) break;

        int i;
        for (i = 0; i < NUM_KEYS; i++) {
            cvRectangle(frame,
                cvPoint(keys[i].x1, keys[i].y1),
                cvPoint(keys[i].x2, keys[i].y2),
                CV_RGB(0, 150, 200), 2, 8, 0);
        }

        Fingertip tip = detectFingertip(frame);

        if (tip.found) {
            cvCircle(frame,
                cvPoint(tip.x, tip.y),
                10, CV_RGB(255, 200, 0), -1, 8, 0);

            int key_idx = detectKey(tip.x, tip.y);

            if (key_idx >= 0 && key_idx != last_key) {
                cvRectangle(frame,
                    cvPoint(keys[key_idx].x1, keys[key_idx].y1),
                    cvPoint(keys[key_idx].x2, keys[key_idx].y2),
                    CV_RGB(0, 255, 100), -1, 8, 0);

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

        cvShowImage("MotionKeys", frame);

        int key = cvWaitKey(10);
        if      (key == (int)'q') break;
        else if (key == (int)'r') startRecording(&session);
        else if (key == (int)'t') stopRecording(&session);
        else if (key == (int)'p') playbackSession(&session);
        else if (key == (int)'s') exportMelody(&session, "melody.txt");
    }

    cvReleaseCapture(&cap);
    cvDestroyAllWindows();
    return 0;
}