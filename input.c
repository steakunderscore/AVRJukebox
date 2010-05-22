/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */
#include "input.h"

int keypadButtons[4][4] = {{ 0xA , 0x0 , 0xB , 0xC },
                           { 0x7 , 0x8 , 0x9 , 0xD },
                           { 0x4 , 0x5 , 0x6 , 0xE },
                           { 0x1 , 0x2 , 0x3 , 0xF }};

static int K_ROWS_ARRAY[4] = {K_ROW_0, K_ROW_1, K_ROW_2, K_ROW_3};
static int K_COLUMNS_ARRAY[4] = {K_COLUMN_0, K_COLUMN_1, K_COLUMN_2, K_COLUMN_3};
static uint8_t lastReturn;
static uint8_t buttonPress;

void keypadInit() {
    AT91F_PIO_CfgOutput(AT91C_BASE_PIOA, K_COLUMNS);
    AT91F_PIO_CfgInput(AT91C_BASE_PIOA, K_ROWS);


    AT91F_RTTSetTimeBase(AT91C_BASE_RTTC, 1);
    AT91F_RTTSetAlarmValue(AT91C_BASE_RTTC,5000);
    lastReturn = NULL_BUTTON;
}

uint8_t getInput( void ) {
    uint8_t i, j, returnVal = NULL_BUTTON;
    int input;
    
    // Check for any keys pressed. Then quit if none
    AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, K_COLUMNS);
    if (((input = AT91F_PIO_GetInput(AT91C_BASE_PIOA)) & K_ROWS) == K_ROWS) {
        buttonPress = FALSE;
        lastReturn = NULL_BUTTON;
        return NULL_BUTTON;
    }
    if (buttonPress == FALSE) {
        buttonPress = TRUE;
        AT91F_RTTRestart(AT91C_BASE_RTTC);
        return NULL_BUTTON;
    }
    // If allarm hasn't accoured, return to stop button bounce
    if (!(AT91F_RTTGetAlarmValue(AT91C_BASE_RTTC) | AT91C_RTTC_ALMS)) {
        return NULL_BUTTON;
    }

    AT91F_PIO_SetOutput(AT91C_BASE_PIOA, K_COLUMNS);
    
    // Find pressed key
    for (i = 0; i <= 3; i++) {
        AT91F_PIO_SetOutput(AT91C_BASE_PIOA, K_COLUMNS);
        AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, K_COLUMNS_ARRAY[i]);
        input = AT91F_PIO_GetInput(AT91C_BASE_PIOA);
        for (j = 0; j <= 3; j++) {
            if ((input & K_ROWS_ARRAY[j]) == 0) {
              returnVal = keypadButtons[j][i];
            }
        }
    }
    if (returnVal != lastReturn) {
        lastReturn = returnVal;
        return returnVal;
    }
    else {
        return NULL_BUTTON;
    }
}
