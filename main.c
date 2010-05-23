/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

// Include Standard files
#include "Board.h"
#include "display.h"
#include "input.h"
#include "sound.h"
#include "music.h"
#include "music_lib.c"
#include "led.h"

/* Software entry point
 */
int main(void)
{
    uint8_t result;
    uint8_t playingSong = 0xFF;
    displayInit();
    keypadInit();
    soundInit();
    musicInit();
    ledInit();

    setRedLed(ON);

    for(;;) {
        if ((result = getCleanInput()) < 0x0C) {
            switch (result) {
                case 0xA: { // Stop
                    stopMusic();
                    resetMusic();
                    setStop();
                }
                case 0x0: { // Pause
                    stopMusic();
                    setPause(playingSong);
                }
                case 0xB: { // Play
                    startMusic();
                    setPlay(playingSong);
                }
                default: {
                    setPlay(result);
                    setMusic(songs[result-1], 7000000);
                    playingSong = result;
                }
            }
        }
        scrollDisplay();
        playMusic();
    }
}
