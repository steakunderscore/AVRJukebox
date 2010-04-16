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
#define get(x) (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & x)

#include "input.h"

static int K_ROWS_ARRAY[4] = {K_ROW_0, K_ROW_1, K_ROW_2, K_ROW_3};
static int K_COLUMNS_ARRAY[4] = {K_COLUMN_0, K_COLUMN_1, K_COLUMN_2, K_COLUMN_3};
int k_results[4][4];

void keypadInit() {
       AT91F_PIO_CfgOutput(AT91C_BASE_PIOA, K_ROWS);
       AT91F_PIO_CfgInput(AT91C_BASE_PIOA, K_COLUMNS);
}

int** getInputs() {
    int i,j;
    
    for (i = 0; i <= 3; i++) {
        clear(K_ROWS);
        set(K_ROWS_ARRAY[i]);
        for (j = 0; j <= 3; j++) {
            k_results[i][j] = get(K_COLUMNS_ARRAY[j]);
        }
    }
    
    return k_results;
}
