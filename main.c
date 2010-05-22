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
    uint8_t result = 0;

    displayInit();
    keypadInit();
    soundInit();
    musicInit();
    ledInit();

    setRedLed(ON);
    setMusic(sine, 500000);

    for(;;) {
        if ((result = getInput()) != 0xFF) {
            setError(result);
            setGreenLed(ON);
        }
        j = j > 3 ? 0 : j;
        scrollDisplay();
        playMusic();
    }
    setRedLed(OFF);
}
