/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */
#define clear(x) AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, x)
#define set(x) AT91F_PIO_SetOutput(AT91C_BASE_PIOA, x)
#define get AT91F_PIO_GetInput(AT91C_BASE_PIOA)

#include "input.h"

int keypadButtons[4][4] = {{ 0x1 , 0x2 , 0x3 , 0xF },
                           { 0x4 , 0x5 , 0x6 , 0xE },
                           { 0x7 , 0x8 , 0x9 , 0xD },
                           { 0xA , 0x0 , 0xB , 0xC }};

static int K_ROWS_ARRAY[4] = {K_ROW_0, K_ROW_1, K_ROW_2, K_ROW_3};
static int K_COLUMNS_ARRAY[4] = {K_COLUMN_0, K_COLUMN_1, K_COLUMN_2, K_COLUMN_3};

void keypadInit() {
       AT91F_PIO_CfgOutput(AT91C_BASE_PIOA, K_ROWS);
       AT91F_PIO_CfgInput(AT91C_BASE_PIOA, K_COLUMNS);
}

uint8_t getInput(uint8_t *result) {
    uint8_t i, j;
    int input;
    
    // Check for any key press.
    clear(K_ROWS);
    if ((get & K_COLUMNS) == K_COLUMNS) {
        set(K_ROWS);
        return 0;
    }
    set(K_ROWS);
    
    // Wait for de-bounce
    /* TODO: Start 20 ms timer */
    while (/* TODO: Timer not finished */ 1) {
        // Wait
    }
    
    // Check for any key press again.
    clear(K_ROWS);
    if ((get & K_COLUMNS) == K_COLUMNS) {
        return 0;
        set(K_ROWS);
    }
    set(K_ROWS);
    
    // Find pressed key
    for (i = 0; i <= 3; i++) {
        set(K_ROWS);
        clear(K_ROWS_ARRAY[i]);
        input = get;
        for (j = 0; j <= 3; j++) {
            if ((input & K_COLUMNS_ARRAY[j]) == 0) {
              *result =  keypadButtons[i][j];
              return 1;
            }
        }
    }
    
    return 0;
}
