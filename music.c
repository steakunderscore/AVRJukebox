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
#include "led.h"

// Number of ticks per microsecond
static const uint32_t NUM_TICKS = (MCK / 1000000);

static uint8_t playingMusic = FALSE;
static note_t *music;
static uint32_t quaverTicks, currentNote, currentQuaver, currentTicks;

// An array of the values of a sine wave between 0 and pi/2-pi/128 with 
// intervals of pi/128 and an ampltitude of 128.
static const uint8_t sine[256] = {
    128,131,134,137,140,143,146,149,152,155,158,161,164,167,170,173,176,179,182,
    185,187,190,193,195,198,201,203,206,208,210,213,215,217,219,222,224,226,228,
    230,231,233,235,236,238,240,241,242,244,245,246,247,248,249,250,251,251,252,
    253,253,254,254,254,254,254,255,254,254,254,254,254,253,253,252,251,251,250,
    249,248,247,246,245,244,242,241,240,238,236,235,233,231,230,228,226,224,222,
    219,217,215,213,210,208,206,203,201,198,195,193,190,187,185,182,179,176,173,
    170,167,164,161,158,155,152,149,146,143,140,137,134,131,128,124,121,118,115,
    112,109,106,103,100, 97, 94, 91, 88, 85, 82, 79, 76, 73, 70, 68, 65, 62, 60,
     57, 54, 52, 49, 47, 45, 42, 40, 38, 36, 33, 31, 29, 27, 25, 24, 22, 20, 19,
     17, 15, 14, 13, 11, 10,  9,  8,  7,  6,  5,  4,  4,  3,  2,  2,  1,  1,  1,
      1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  3,  4,  4,  5,  6,  7,  8,  9, 10,
     11, 13, 14, 15, 17, 19, 20, 22, 24, 25, 27, 29, 31, 33, 36, 38, 40, 42, 45,
     47, 49, 52, 54, 57, 60, 62, 65, 68, 70, 73, 76, 79, 82, 85, 88, 91, 94, 97,
    100,103,106,109,112,115,118,121,124
};

uint8_t getNotesAmplitude( note_t *note, uint32_t tick ) {
    uint32_t time;
    uint16_t period;
    
    time = tick / NUM_TICKS;
    
    period = note->timePeriod;
    
    if (time > period) {
        time = time % period;
    }
    
    return sine[(time << 8) / period];
}

void stopMusic( void ) {
    setGreenLed(OFF);
    playingMusic = FALSE;
}

void resetMusic( void ) {
    currentNote = 0;
    currentQuaver = 0;
    currentTicks = 0;
}

void playMusic( void ) {
    uint32_t status;
    uint8_t value = 0;
    static uint8_t oldValue = 0;

    if (!playingMusic) {
        return;
    }
    status = AT91F_PITGetPIVR(AT91C_BASE_PITC);
    currentTicks += (status & AT91C_PITC_PICNT >> 20) * NUM_TICKS + (status & AT91C_PITC_CPIV);
    if (currentTicks > quaverTicks) {
        currentQuaver++;
        currentTicks -= quaverTicks;
    }
    if (currentQuaver >= music[currentNote].length) {
        currentNote++;
        currentQuaver = 0;
    }
    if (music[currentNote].timePeriod == 0) {
        stopMusic();
        sendData(128);
        return;
    }
    value = getNotesAmplitude(&music[currentNote], currentTicks + quaverTicks * currentQuaver);
    if (value != oldValue) {
        sendData(value);
        oldValue = value;
    }
}

void musicInit( void ) {
    AT91F_PITInit(AT91C_BASE_PITC, CALLBACK_TIME, MCK/1000000);
    AT91F_PITSetPIV(AT91C_BASE_PITC, NUM_TICKS);
}

void startMusic( void ) {
    volatile uint32_t status = AT91F_PITGetPIVR(AT91C_BASE_PITC);
    playingMusic = TRUE;
    setGreenLed(status ? ON : OFF);
    setGreenLed(ON);
}

void setMusic( note_t *music_p, uint32_t quaver ) {
    stopMusic();
    music = music_p;
    quaverTicks = quaver;
    resetMusic();
    startMusic();
}

