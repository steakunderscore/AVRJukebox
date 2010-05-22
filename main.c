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
    displayInit();
    keypadInit();
    soundInit();
    musicInit();
    ledInit();
    setMusic(theResistanceIntro, 7000000);


    for(;;) {
        scrollDisplay();
        playMusic();
    }
}
