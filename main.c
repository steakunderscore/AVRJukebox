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
    uint8_t j = 0;
    int8_t ledState = OFF;
    uint8_t result;

    displayInit();
    keypadInit();
    soundInit();
    musicInit();
    ledInit();

    setRedLed(ON);
    setMusic(sine, 7000000);

    for(;;) {
        if ((result = getCleanInput()) < 0xFF) {
            setDisplay(j++,result);
            ledState = (ledState == OFF ? ON: OFF);

            setGreenLed(ledState);
            j = j > 3 ? 0 : j;
            
            switch (result) {
                case 0xA: { // Stop
                    stopMusic();
                    resetMusic();
                }
                case 0x0: { // Pause
                    stopMusic();
                }
                case 0xB: { // Play
                    startMusic();
                }
                default: {
                    setMusic(songs[result], 7000000);
                }
            }
        }
        scrollDisplay();
        playMusic();
    }
    setRedLed(OFF);
}
