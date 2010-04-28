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

const int display_mask[4]= {DSTATE0, DSTATE1, DSTATE2, DSTATE3};
static uint8_t currentSegment = 0;
static uint8_t display[] = {0, 0, 0, 0};
const uint8_t states[] = { 0x00, 0x60, 0xDA, 0xF2, 0x66,
                           0xB6, 0xBE, 0xE0, 0xFE, 0xE6 };

void displayInit() {
    //Setup the display diget selecting outputs
    AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, DISPLAY_MASK );
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK);
    //Setup the segment outputs
    AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, DISPLAY_SEGMENT_MASK );
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_SEGMENT_MASK );

}

void scrollDisplay( void ) {
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

    if ((display[currentSegment] & (1<<7))) { //Deal with seg a
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTA);
    }
    if ((display[currentSegment] & (1<<6))) { // etc..
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTB);
    }
    if ((display[currentSegment] & (1<<5))) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTC);
    }
    if ((display[currentSegment] & (1<<4))) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTD);
    }
    if ((display[currentSegment] & (1<<3))) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTE);
    }
    if ((display[currentSegment] & (1<<2))) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTF);
    }
    if ((display[currentSegment] & (1<<1))) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTG);
    }
    if ((display[currentSegment] & (1<<0))) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTDP);
    }
}

void setDisplay(int displayNum, int value) {
    if (value > 9) {
        /* If the value if out of range, turn the display off */
        display[displayNum] = states[0];
    }
    else {
        display[displayNum] = states[value];
    }
}
