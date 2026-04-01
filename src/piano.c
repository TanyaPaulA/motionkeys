#include "piano.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

PianoKey keys[NUM_KEYS];

void initKeys(int fw, int fh) {
    int kw = fw / NUM_KEYS;
    char* names[] = {"C4","D4","E4","F4","G4","A4","B4","C5"};
    int   freqs[] = {261, 294, 330, 349, 392, 440, 494, 523};
    int i;
    for (i = 0; i < NUM_KEYS; i++) {
        strcpy(keys[i].note_name, names[i]);
        keys[i].frequency = freqs[i];
        keys[i].x1 = i * kw;
        keys[i].x2 = (i + 1) * kw;
        keys[i].y1 = fh / 4;
        keys[i].y2 = fh * 3 / 4;
    }
}

int detectKey(int fx, int fy) {
    int i;
    for (i = 0; i < NUM_KEYS; i++) {
        if (fx >= keys[i].x1 && fx <= keys[i].x2 &&
            fy >= keys[i].y1 && fy <= keys[i].y2)
            return i;
    }
    return -1;
}

void playNote(int idx) {
    if (idx < 0) return;
#ifdef _WIN32
    Beep(keys[idx].frequency, 200);
#else
    char cmd[64];
    sprintf(cmd, "beep -f %d -l 200", keys[idx].frequency);
    system(cmd);
#endif
}

void resizeZones(float factor) {
    int i;
    for (i = 0; i < NUM_KEYS; i++) {
        int center = (keys[i].y1 + keys[i].y2) / 2;
        int half   = (int)((keys[i].y2 - keys[i].y1) * factor / 2);
        keys[i].y1 = center - half;
        keys[i].y2 = center + half;
    }
}
