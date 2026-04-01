#include "detector.h"
#include <opencv2/imgproc/imgproc_c.h>
#include <math.h>

Fingertip detectFingertip(IplImage* frame) {
    Fingertip result = {0, 0, 0};
    IplImage* hsv  = cvCreateImage(cvGetSize(frame), 8, 3);
    IplImage* mask = cvCreateImage(cvGetSize(frame), 8, 1);
    cvCvtColor(frame, hsv, CV_BGR2HSV);
    CvScalar lower = cvScalar(0,  48,  80,  0);
    CvScalar upper = cvScalar(20, 255, 255, 0);
    cvInRangeS(hsv, lower, upper, mask);
    IplConvKernel* kernel = cvCreateStructuringElementEx(
        5, 5, 2, 2, CV_SHAPE_ELLIPSE, 0);
    cvErode (mask, mask, kernel, 1);
    cvDilate(mask, mask, kernel, 2);
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contours = NULL;
    cvFindContours(mask, storage, &contours,
                   sizeof(CvContour), CV_RETR_EXTERNAL,
                   CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
    CvSeq* largest = NULL;
    double max_area = 0;
    for (CvSeq* c = contours; c != NULL; c = c->h_next) {
        double area = fabs(cvContourArea(c, CV_WHOLE_SEQ, 0));
        if (area > max_area) {
            max_area = area;
            largest = c;
        }
    }
    if (largest && max_area > 1000) {
        int top_y = 99999;
        int top_x = 0;
        for (int i = 0; i < largest->total; i++) {
            CvPoint* pt = (CvPoint*)cvGetSeqElem(largest, i);
            if (pt->y < top_y) {
                top_y = pt->y;
                top_x = pt->x;
            }
        }
        result.x     = top_x;
        result.y     = top_y;
        result.found = 1;
    }

    cvReleaseImage(&hsv);
    cvReleaseImage(&mask);
    cvReleaseMemStorage(&storage);
    return result;
}
