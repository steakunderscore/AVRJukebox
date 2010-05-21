/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#include "Board.h"

#define ON      -1
#define OFF     0

/*----------------*/
/* LED Definition */
/*----------------*/
#define REDLED     (1<<13)  // PA13
#define GREENLED   (1<<14)  // PA14

#define LED_MASK  (REDLED | GREENLED)

//*--------------------------------------------------------------------------------------
//* Function Name       : ledInit
//* Object              : Initilise the LED IO ports.
//* Input Parameters    : none
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void ledInit( void );

//*--------------------------------------------------------------------------------------
//* Function Name       : setRedLed
//* Object              : set the red led on or off.
//* Input Parameters    : Either ON or OFF. All other values return with no effect
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void setRedLed( uint8_t status);

//*--------------------------------------------------------------------------------------
//* Function Name       : setGreenLed
//* Object              : set the green led on or off.
//* Input Parameters    : Either ON or OFF. All other values return with no effect
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void setGreenLed( uint8_t status);
