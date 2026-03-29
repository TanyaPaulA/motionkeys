#ifndef PIANO_H
#define PIANO_H

#include <string.h>

#define NUM_KEYS 8

typedef struct {
    char note_name[4];
    int  frequency;
    int  x1, x2;
    int  y1, y2;
} PianoKey;

extern PianoKey keys[NUM_KEYS];

void initKeys(int frame_width, int frame_height);
int  detectKey(int fx, int fy);
void playNote(int key_index);
void resizeZones(float factor);

#endif