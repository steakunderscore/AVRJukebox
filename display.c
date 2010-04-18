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
const uint8_t states[] = { 0x03, 0x60, 0x6D, 0x79, 0x66,
                           0xB6, 0xB6, 0xE0, 0xFC, 0xE4 };

void displayInit() {
    AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, DISPLAY_MASK ) ;
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK) ;
}

void scrollDisplay( void ) {
    if (currentSegment >= 3) { //This could be changed to ==3
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK) ;
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, display_mask[0] );
        currentSegment = 0;
    }
    else {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, display_mask[currentSegment++]);
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, display_mask[currentSegment]);
    }

    /* First set all the segments to off, then turn on the ones we want on*/
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_SEGMENT_MASK);
    if ((display[currentSegment] & (1<<7)) == (1<<7)) { //Deal with seg a
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTA);
    }
    if ((display[currentSegment] & (1<<6)) == (1<<6)) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTB);
    }
    if ((display[currentSegment] & (1<<5)) == (1<<5)) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTC);
    }
    if ((display[currentSegment] & (1<<4)) == (1<<4)) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTD);
    }
    if ((display[currentSegment] & (1<<3)) == (1<<3)) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTE);
    }
    if ((display[currentSegment] & (1<<2)) == (1<<2)) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTF);
    }
    if ((display[currentSegment] & (1<<1)) == (1<<1)) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTG);
    }
    if ((display[currentSegment] & (1<<0)) == (1<<0)) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, DSEGMENTDP);
    }



}

void setDisplay(int displayNum, int value) {
    if (value > 9) {
        /* If the value if out of range, turn the display off */
        display[displayNum] = 0x00;
    }
    else {
        display[displayNum] = states[value-1];
    }
}
