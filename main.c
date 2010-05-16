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

/* Software entry point
 */
int main(void)
{
    displayInit();
    keypadInit();
    soundInit();
    musicInit();

    for(;;) {
        scrollDisplay();
        playMusic();
    }
}
