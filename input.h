/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#ifndef input_h
#define input_h
// Include Standard files
#include "Board.h"


// Keypad Pin Definitions
#define K_ROW_0    (1<<1) // PA1
#define K_ROW_1    (1<<2) // PA2
#define K_ROW_2    (1<<3) // PA3
#define K_ROW_3    (1<<4) // PA4
#define K_COLUMN_0 (1<<5) // PA5
#define K_COLUMN_1 (1<<6) // PA6
#define K_COLUMN_2 (1<<7) // PA7
#define K_COLUMN_3 (1<<8) // PA8

#define K_ROWS      (K_ROW_0 | K_ROW_1 | K_ROW_2 | K_ROW_3)
#define K_COLUMNS   (K_COLUMN_0 | K_COLUMN_1 | K_COLUMN_2 | K_COLUMN_3)
#define KEYPAD_MASK (K_ROWS | K_COLUMNS)

/* Initializes the keypad ready for use.
 */
void keypadInit( void );

/* Gets the currently pressed keypad buttons.
 * 
 * Returns:
 *  A 4x4 array of 1's on the pressed buttons and 0's on the unpressed buttons.
 */
void getInputs( int results[][] );
#endif //input_h
