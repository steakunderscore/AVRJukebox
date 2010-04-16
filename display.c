#include "display.h"

const int display_mask[4]= {DSTATE0, DSTATE1, DSTATE2, DSTATE3};
unsigned int currentSegment;
static int display[] = {10, 10, 10, 10};

void displayInit() {
    currentSegment = 0;
    AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, DISPLAY_MASK ) ;
    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK) ;
}

void scrollDisplay( void ) {
    if (currentSegment >= 3) {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK) ;
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, display_mask[0] );
        currentSegment = 0;
    } else {
        AT91F_PIO_SetOutput( AT91C_BASE_PIOA, display_mask[currentSegment++]);
        AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, display_mask[currentSegment]);
    }
}

void setDisplay(int displayNum, int value) {
    //TODO
}
