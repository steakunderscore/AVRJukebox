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

#define BUTTON_BOUNCE_DELAY 500

int keypadButtons[4][4] = {{ 0xA , 0x0 , 0xB , 0xC },
                           { 0x7 , 0x8 , 0x9 , 0xD },
                           { 0x4 , 0x5 , 0x6 , 0xE },
                           { 0x1 , 0x2 , 0x3 , 0xF }};

static int K_ROWS_ARRAY[4] = {K_ROW_0, K_ROW_1, K_ROW_2, K_ROW_3};
static int K_COLUMNS_ARRAY[4] = {K_COLUMN_0, K_COLUMN_1, K_COLUMN_2, K_COLUMN_3};
static uint8_t lastReturn;
static uint8_t buttonPress;
static uint16_t buttonPressCount;

void keypadInit() {
    AT91F_PIO_CfgOutput(AT91C_BASE_PIOA, K_COLUMNS);
    AT91F_PIO_CfgInput(AT91C_BASE_PIOA, K_ROWS);

    lastReturn = NULL_BUTTON;
    buttonPressCount = 0;
}

uint8_t getInput( void ) {
    uint8_t i, j;
    int input;

    // Check for any keys pressed. Then quit if none
    AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, K_COLUMNS);
    if (((input = AT91F_PIO_GetInput(AT91C_BASE_PIOA)) & K_ROWS) == K_ROWS) {
        return NULL_BUTTON;
    }
    // Set the outputs back high
    AT91F_PIO_SetOutput(AT91C_BASE_PIOA, K_COLUMNS);
    // Find pressed key
    for (i = 0; i <= 3; i++) {
        AT91F_PIO_SetOutput(AT91C_BASE_PIOA, K_COLUMNS);
        AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, K_COLUMNS_ARRAY[i]);
        input = AT91F_PIO_GetInput(AT91C_BASE_PIOA);
        for (j = 0; j <= 3; j++) {
            if ((input & K_ROWS_ARRAY[j]) == 0) {
                return keypadButtons[j][i];
            }
        }
    }
    return NULL_BUTTON;
}

uint8_t getCleanInput( void ) {
    uint8_t returnVal;

    //First get a result that ignores the button bounce
    if (buttonPressCount > BUTTON_BOUNCE_DELAY ) {
        if (buttonPress == (returnVal = getInput())) {
            // Then return the button only if it's not the same as the last one
            if (returnVal != lastReturn) {
                lastReturn = returnVal;
                return returnVal;
            }
        }
        else {
            buttonPress = returnVal;
        }
        buttonPressCount = 0;
    }
    else {
        buttonPressCount++;
    }
    return NULL_BUTTON;


}

