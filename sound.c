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

#define SPI_PERIPH (AT91C_PA13_MOSI | AT91C_PA14_SPCK | AT91C_PA11_NPCS0 | AT91C_PA12_MISO)
#define SPI_MODE ((AT91C_SPI_MSTR | AT91C_SPI_PS_FIXED) & ~(AT91C_SPI_PCSDEC | AT91C_SPI_LLB))
#define CS_REG ((AT91C_SPI_NCPHA | AT91C_SPI_BITS_16 | (0x0A << 8)) & ~(AT91C_SPI_CSAAT | AT91C_SPI_CPOL))
void soundInit( void ) {
    AT91F_PIO_CfgPeriph(AT91C_BASE_PIOA, SPI_PERIPH, 0x0);  //Sets the output lines required for the SPI.
    AT91F_SPI_CfgPMC(); // Enables the SPI periphial clock.
    AT91F_SPI_CfgMode (AT91C_BASE_SPI, SPI_MODE); //Sets the SPI's mode.
    AT91F_SPI_CfgCs(AT91C_BASE_SPI, 0, CS_REG); // Sets the clients settings.
    AT91F_SPI_Enable(AT91C_BASE_SPI); // Enables the SPI.
}

void sendData( uint8_t data ) {
    while (! AT91F_PDC_IsTxEmpty((AT91PS_PDC) &(AT91C_BASE_SPI->SPI_RPR))) {
        // Wait
    }
    
    data = 0x09 << 8 + data
    pSPI->SPI_TDR = data;
}
