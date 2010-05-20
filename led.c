/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#include "led.h"

void ledInit( void ) {
    AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, LED_MASK );
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED_MASK );
}

void setRedLed( uint8_t status) {
    if (status == ON) {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, REDLED);
    }
    else if (status == OFF) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, REDLED);
    }
}

void setGreenLed( uint8_t status) {
    if (status == ON) {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, GREEENLED);
    }
    else if (status == OFF) {
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, GREENLED);
    }
}

