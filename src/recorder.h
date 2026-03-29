#ifndef RECORDER_H
#define RECORDER_H

#include <time.h>

#define MAX_NOTES 512

typedef struct {
    char   note[4];
    int    freq;
    time_t timestamp;
} NoteEvent;

typedef struct {
    NoteEvent events[MAX_NOTES];
    int       count;
    int       recording;
} Session;

void  startRecording(Session* s);
void  recordNote(Session* s, const char* note, int freq);
void  stopRecording(Session* s);
void  playbackSession(Session* s);
void  exportMelody(Session* s, const char* filename);
float calculateBPM(Session* s);

#endif