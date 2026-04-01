#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/core/core_c.h>

typedef struct {
    int x;
    int y;
    int found;
} Fingertip;

Fingertip detectFingertip(IplImage* frame);

#endif