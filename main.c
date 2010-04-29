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
    int i = 0;
    int j = 0;
    displayInit();
    keypadInit();
    soundInit();

    for(;;) {
        i++;
        if (i > 100066) {
            i = 0;
            setError(j++); 
            /*setDisplay(0,j++);
            setDisplay(1,j++);
            setDisplay(2,j++);
            setDisplay(3,j++);*/
            if ( j > 0xF) {
                j = 0;
            }
        }

        //int** inputs = getInputs();
        //processInputs(inputs);
        //...sound stuff
        scrollDisplay();
    }
}
