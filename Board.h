/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : Board.h
* Object              : AT91SAM7S Evaluation Board Features Definition File.
*
* Creation            : JPP   16/Jun/2004
* Modifications	      : Steve Weddell  March, 2008
*                       SW1 now correctly defined as PA15 
* V 1.0 21/Feb/05 JPP : Define __ramfunc
* V 1.1 21/Feb/05 JPP : add Lib definition
* V 1.2 22/Feb/05 JPP : Add DBGU inline definition
*----------------------------------------------------------------------------
*/
#ifndef Board_h
#define Board_h

#include "AT91SAM7S64.h"
#define __inline static inline
#include "lib_AT91SAM7S64.h"

#define __ramfunc

#define true	-1
#define false	0

/*-------------------------------*/
/* SAM7Board Memories Definition */
/*-------------------------------*/
// The AT91SAM7S256 embeds a 64 Kbyte SRAM bank, and 256 KByte Flash

#define  INT_SARM           0x00200000
#define  INT_SARM_REMAP	    0x00000000

#define  INT_FLASH          0x00000000
#define  INT_FLASH_REMAP    0x01000000

#define  FLASH_PAGE_NB	    512
#define  FLASH_PAGE_LOCK    32
#define  FLASH_PAGE_SIZE    128

/*-------------------*/
/* Switch Definition */
/*-------------------*/
#define SW1        (1<<15)	// PA15  Set-up the input (switch) mask
#define SW2        (1<<17)	// PA17 
#define SW3        (1<<19)	// PA19 

#define SW_MASK (SW1 | SW2 | SW3)

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

#define DISPLAY_SEGMENT_MASK  (DSTATE0 | DSTATE1 | DSTATE2 | DSTATE3)

/*--------------*/
/* Master Clock */
/*--------------*/

#define EXT_OC          18432000   // Exetrnal ocilator MAINCK
#define MCK             47923200   // MCK (PLLRC div by 2)
#define MCKKHz          (MCK/1000) //

#endif /* Board_h */

