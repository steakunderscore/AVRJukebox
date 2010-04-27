/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#include "sound.h"

void soundInit( void ) {
    AT91F_SPI_Enable(AT91C_BASE_SPI)
    //TODO: initilize the output for the DAC
}

void sendData( int data ) {
    int control = 0x9;
    AT91F_SPI_CfgCs(AT91C_BASE_SPI, 0, 1)
    AT91F_SPI_SendFrame(AT91C_BASE_SPI
}
