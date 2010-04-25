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

int keypadButtons[4][4] = {{ 1 ,  2 ,  3 , 'F'},
                           { 4 ,  5 ,  6 , 'E'},
                           { 7 ,  8 ,  9 , 'D'},
                           {'A',  0 , 'B', 'C'}};

static int K_ROWS_ARRAY[4] = {K_ROW_0, K_ROW_1, K_ROW_2, K_ROW_3};
static int K_COLUMNS_ARRAY[4] = {K_COLUMN_0, K_COLUMN_1, K_COLUMN_2, K_COLUMN_3};

void keypadInit() {
       AT91F_PIO_CfgOutput(AT91C_BASE_PIOA, K_ROWS);
       AT91F_PIO_CfgInput(AT91C_BASE_PIOA, K_COLUMNS);
}

//    int *results = calloc(4*4, sizeof(*results))
void getInputs(int results[][]) {
    int i,j;
    int input;
    
    for (i = 0; i <= 3; i++) {
        AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, K_ROWS)
        AT91F_PIO_SetOutput(AT91C_BASE_PIOA, K_ROWS_ARRAY[i])
        input = AT91F_PIO_GetInput(AT91C_BASE_PIOA)
        for (j = 0; j <= 3; j++) {
            results[i][j] = input & K_COLUMNS_ARRAY[j];
        }
    }
}
