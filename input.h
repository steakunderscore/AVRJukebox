// Author::    Wim Looman  (mailto:ghostunderscore@gmail.com)
// Copyright:: Copyright (c) 2010 Wim Looman
// License::   GNU General Public License (see LICENSE in root folder)

// Include Standard files
#include "Board.h"


/*------------------------*
 * Keypad Pin Definitions *
 *------------------------*/
#define K_ROW_0     (1<<7)   // PA7
#define K_ROW_1     (1<<8)   // PA8
#define K_ROW_2     (1<<9)   // PA9
#define K_ROW_3     (1<<10)  // PA10
#define K_COLUMN_0  (1<<11)  // PA11
#define K_COLUMN_1  (1<<12)  // PA12
#define K_COLUMN_2  (1<<13)  // PA13
#define K_COLUMN_3  (1<<14)  // PA14

#define K_ROWS      (K_ROW_0 | K_ROW_1 | K_ROW_2 | K_ROW_3)
#define K_COLUMNS   (K_COLUMN_0 | K_COLUMN_1 | K_COLUMN_2 | K_COLUMN_3)
#define KEYPAD_MASK (K_ROWS | K_COLUMNS)

//*--------------------------------------------------------------------------------------
//* Function Name       : init
//* Object              : Initialize the 
//* Input Parameters    : none. Waiting time is defined by the global variable LedSpeed.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void keypadInit( void );

//*--------------------------------------------------------------------------------------
//* Function Name       : wait
//* Object              : Software waiting loop
//* Input Parameters    : none. Waiting time is defined by the global variable LedSpeed.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
int** getInputs( void );
