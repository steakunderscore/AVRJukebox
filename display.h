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
#include <stdint.h>

/*--------------------*/
/* Display Definition */
/*--------------------*/
#define DSTATE0    (1<<20)  // PA20
#define DSTATE1    (1<<21)  // PA21
#define DSTATE2    (1<<22)  // PA23
#define DSTATE3    (1<<23)  // PA24

#define DISPLAY_MASK  (DSTATE0 | DSTATE1 | DSTATE2 | DSTATE3)

#define DSEGMENTA  (1<<24)  // PA24
#define DSEGMENTB  (1<<25)  // PA25
#define DSEGMENTC  (1<<26)  // PA26
#define DSEGMENTD  (1<<27)  // PA27
#define DSEGMENTE  (1<<28)  // PA28
#define DSEGMENTF  (1<<29)  // PA29
#define DSEGMENTG  (1<<30)  // PA30
#define DSEGMENTDP (1<<31)  // PA31

#define NO_SEGMENTS 8
#define DISPLAY_SEGMENT_MASK  (DSEGMENTA | DSEGMENTB | DSEGMENTC | DSEGMENTD | \
                               DSEGMENTE | DSEGMENTF | DSEGMENTG | DSEGMENTDP )

//*--------------------------------------------------------------------------------------
//* Function Name       : dispalyInit
//* Object              : Initilise the dispaly IO ports.
//* Input Parameters    : none
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void displayInit( void );

//*--------------------------------------------------------------------------------------
//* Function Name       : scrollDisplay
//* Object              : set the current display segment to the next segment
//* Input Parameters    : none. But does use global currentSegment.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void scrollDisplay( void );


//*--------------------------------------------------------------------------------------
//* Function Name       : setDisplay
//* Object              : set the givenDisplay to display the value that is passed in
//* Input Parameters    : displayNum, the value from 0 to 3.
//                      : value, the value to be displayed.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
void setDisplay(int displayNum, int value);

//Display an error message
void setError(int errorNum);
