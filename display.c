/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#include "display.h"


const int display_mask[]= {DSTATE0, DSTATE1, DSTATE2, DSTATE3};
const int seg_mask[]= {DSEGMENTA, DSEGMENTB, DSEGMENTC, DSEGMENTD,
                       DSEGMENTE, DSEGMENTF, DSEGMENTG, DSEGMENTDP };
static uint8_t currentSegment = 0;
static uint8_t display[] = {0, 0, 0, 0};
const uint8_t states[] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0,
                           0xFE, 0xE6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E,
                           0x0A }; // Hex chars plus a 'r' for errors

static uint16_t displayCount = 0;

void displayInit() {
    //Setup the display diget selecting outputs
    AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, DISPLAY_MASK );
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK);
    //Setup the segment outputs
    AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, DISPLAY_SEGMENT_MASK );
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_SEGMENT_MASK );

}

void scrollDisplay( void ) {
    int i;
    if (displayCount < 200) {
        displayCount++;
        return;
    }
    else {
        displayCount = 0;
    }

    // Clear the display segments
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_SEGMENT_MASK);

    // Scroll the display diget
    if (currentSegment >= 3) {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK) ;
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, display_mask[0] );
        currentSegment = 0;
    }
    else {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, display_mask[currentSegment++]);
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, display_mask[currentSegment]);
    }

    for (i = NO_SEGMENTS; i > 0; i--) {
        if ((display[currentSegment] & (1<<(i-1)))) { //Deal with seg
            AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, seg_mask[NO_SEGMENTS - i] );
        }
    }
}

void setDisplay(int displayNum, int value) {
    if (value > 15) {
        /* If the value if out of range, turn the display off */
        display[displayNum] = 0x00;
    }
    else {
        display[displayNum] = states[value];
    }
}

void clearDisplay( void ) {
    uint8_t i;
    for (i = 0; i < NO_SEGMENTS ; i++) {
        display[i] = 0x00;
    }
}

void setPlay( uint8_t songNum ) {
    display[0] = 0xCE; // Set the 'P'
    display[1] = 0x1C; // Set the 'L'
    display[2] = 0x00;
    setDisplay(3,songNum);
}

void setStop( void ) {
    display[0] = 0xB6; // Set the 'S'
    display[1] = 0xE2; // Set the 'T'
    display[2] = 0xFC; // Set the 'O'
    display[3] = 0x9E; // Set the 'P'
}

void setPause( uint8_t songNum ) {
    display[0] = 0xCE; // Set the 'P'
    display[1] = 0xFF; // Set the 'A'
    display[2] = 0x00;
    setDisplay(3,songNum);
}

void setError(int errorNum) {
    display[0] = states[0xE]; // Display 'Err'
    display[1] = states[0x10];
    display[2] = states[0x10];
    if (errorNum <= 0xF) {
        display[3] = states[errorNum];
    }
    else {
        display[3] = 0x00; // Unknowen error
    }
}
