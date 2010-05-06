/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#include "music.h"

// An array of the values of a sine wave between 0 and pi/2-pi/128 with 
// intervals of pi/128 and an ampltitude of 128.
static const uint8_t quarterSine[64] = {
    0,3,6,9,12,15,18,21,24,28,31,34,37,40,43,46,48,51,54,57,60,63,65,68,71,73,
    76,78,81,83,85,88,90,92,94,96,98,100,102,104,106,108,109,111,112,114,115,
    117,118,119,120,121,122,123,124,124,125,126,126,127,127,127,127,127
}

uint8_t getNotesAmplitude( note_t *note, uint32_t time ) {
    uint16_t period;
    
    period = note->timePeriod;
    
    if (time > period) {
        time = time % note->timePeriod;
    }
    
    if (time < (period >> 2)) { // First quater-wave.
        return 128 + quaterSine[(time << 6) / period];
    }
    else if (time < (period >> 1)) { // Second quater-wave.
        time = time % (period >> 2);
        return 128 + quaterSine[63 - (time << 6) / period];
    }
    else if (time < ((period >> 2) + (period >> 1))) { // Third quater-wave.
        time = time % (period >> 2);
        return 128 - quaterSine[(time << 6) / period];
    }
    else { // Final quater-wave.
        time = time % (period >> 2);
        return 128 - quaterSine[63 - (time << 6) / period];
    }
}

static note_t *musicPointer;
static uint16_t quaverTime, currentNote, currentQuaver, currentTime;

void setMusic( note_t *music_p, uint16_t quaver ) {
    stopMusc();
    music = music_p;
    quaverTime = quaver;
    resetMusic();
    startMusic();
}

void resetMusic() {
    currentNote = 0;
    currentQuaver = 1;
    currentTime = 0;
}

void callback() {
    currentTime += CALLBACK_TIME;
    if (currentTime > quaverTime) {
        currentQuaver++;
        currentTime -= quaverTime;
    }
    if (currentQuaver > music[currentNote].length) {
        currentNote++;
        currentQuaver = 1;
    }
    if (music[currentNote].timePeriod == 0) {
        stopMusic();
        return;
    }
    sendData(getNotesAmplitude(&music[currentNote], currentTime + quaverTime * (currentQuaver - 1))
}
