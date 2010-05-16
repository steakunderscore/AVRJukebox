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
#include "sound.h"

static uint32_t NUM_TICKS = (CALLBACK_TIME * (MCK / 1000000) + 8) >> 4;
static uint8_t playingMusic = 0;
static note_t *music;
static uint16_t quaverTime, currentNote, currentQuaver, currentTime;

// An array of the values of a sine wave between 0 and pi/2-pi/128 with 
// intervals of pi/128 and an ampltitude of 128.
static const uint8_t quarterSine[64] = {
    0,3,6,9,12,15,18,21,24,28,31,34,37,40,43,46,48,51,54,57,60,63,65,68,71,73,
    76,78,81,83,85,88,90,92,94,96,98,100,102,104,106,108,109,111,112,114,115,
    117,118,119,120,121,122,123,124,124,125,126,126,127,127,127,127,127
};

uint8_t getNotesAmplitude( note_t *note, uint32_t time ) {
    uint16_t period;
    
    period = note->timePeriod;
    
    if (time > period) {
        time = time % note->timePeriod;
    }
    
    if (time < (period >> 2)) { // First quater-wave.
        return 128 + quarterSine[(time << 6) / period];
    }
    else if (time < (period >> 1)) { // Second quater-wave.
        time = time % (period >> 2);
        return 128 + quarterSine[63 - (time << 6) / period];
    }
    else if (time < ((period >> 2) + (period >> 1))) { // Third quater-wave.
        time = time % (period >> 2);
        return 128 - quarterSine[(time << 6) / period];
    }
    else { // Final quater-wave.
        time = time % (period >> 2);
        return 128 - quarterSine[63 - (time << 6) / period];
    }
}

void stopMusic( void ) {
    playingMusic = FALSE;
}

void playMusic( void ) {
    uint32_t status;
    if (!playingMusic) {
        return;
    }
    status = AT91F_PITGetStatus(AT91C_BASE_PITC);
    currentTime += ((status & AT91C_PITC_PICNT >> 20) * NUM_TICKS + (status & AT91C_PITC_CPIV)) * CALLBACK_TIME / NUM_TICKS;
    if (currentTime > quaverTime) {
        currentQuaver++;
        currentTime -= quaverTime;
    }
    if (currentQuaver >= music[currentNote].length) {
        currentNote++;
        currentQuaver = 0;
    }
    if (music[currentNote].timePeriod == 0) {
        stopMusic();
        return;
    }
    sendData(getNotesAmplitude(&music[currentNote], currentTime + quaverTime * currentQuaver));
}

void resetMusic( void ) {
    currentNote = 0;
    currentQuaver = 0;
    currentTime = 0;
}

void musicInit( void ) {
    AT91F_PITSetPIV(AT91C_BASE_PITC, NUM_TICKS);
}

void startMusic( void ) {
    playingMusic = TRUE;
}

void setMusic( note_t *music_p, uint16_t quaver ) {
    stopMusic();
    music = music_p;
    quaverTime = quaver;
    resetMusic();
    startMusic();
}
