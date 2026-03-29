#include "recorder.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void startRecording(Session* s) {
    s->count     = 0;
    s->recording = 1;
    printf("Recording started...\n");
}

void recordNote(Session* s, const char* note, int freq) {
    if (!s->recording || s->count >= MAX_NOTES) return;
    strcpy(s->events[s->count].note, note);
    s->events[s->count].freq      = freq;
    s->events[s->count].timestamp = time(NULL);
    s->count++;
}

void stopRecording(Session* s) {
    s->recording = 0;
    printf("Recording stopped. %d notes captured.\n", s->count);
}

void playbackSession(Session* s) {
    int i;
    printf("Playing back %d notes...\n", s->count);
    for (i = 0; i < s->count; i++) {
        printf("Playing: %s\n", s->events[i].note);
#ifdef _WIN32
        Beep(s->events[i].freq, 300);
        Sleep(100);
#else
        char cmd[64];
        sprintf(cmd, "beep -f %d -l 300", s->events[i].freq);
        system(cmd);
#endif
    }
}

void exportMelody(Session* s, const char* filename) {
    int i;
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("Cannot open file\n");
        return;
    }
    fprintf(f, "MotionKeys Melody Export\n");
    fprintf(f, "========================\n");
    for (i = 0; i < s->count; i++)
        fprintf(f, "%s ", s->events[i].note);
    fprintf(f, "\n");
    fclose(f);
    printf("Melody saved to %s\n", filename);
}

float calculateBPM(Session* s) {
    if (s->count < 2) return 0;
    double total_time = difftime(
        s->events[s->count - 1].timestamp,
        s->events[0].timestamp);
    if (total_time == 0) return 0;
    return (s->count / total_time) * 60.0;
}
