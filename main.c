//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name: 		main.c
//* Object: 		main application written in C
//* Creation: 		JPP   16/Jun/2004
//* Modifications:	Steve Weddell for ENEL353/COSC361, March, 2008
//*                 Minor mods, Feb 22, 2010
//* Purpose:		Produces a "Knight-Rider" effect on a bank of 8-LEDs
//*----------------------------------------------------------------------------

// Include Standard files
#include "Board.h"
#include "display.h"
#include "input.h"
#include "sound.h"

/* Global variables */
#define SPEED 		(MCKKHz/20)
unsigned int LedSpeed = SPEED *50 ;
const int display_mask[4]= {DSTATE0, DSTATE1, DSTATE2, DSTATE3};
unsigned int currentSegment = 0;

//Function Prototypes
static void change_speed ( void );
static void wait ( void );
static void scrollDisplay ( void );


//*--------------------------------------------------------------------------------------
//* Function Name       : change_speed
//* Object              : Adjust "LedSpeed" value depending on SW1 and SW3 are pressed or not
//* Input Parameters    : none
//* Output Parameters   : Update of LedSpeed value.
//*--------------------------------------------------------------------------------------
static void change_speed ( void )
{//* Begin
    if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW1) == 0 )
    {
        if ( LedSpeed > SPEED ) LedSpeed -=SPEED ;
    }
    if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW3) == 0 )
    {
        if ( LedSpeed < MCK ) LedSpeed +=SPEED ;
    }
}//* End

//*--------------------------------------------------------------------------------------
//* Function Name       : wait
//* Object              : Software waiting loop
//* Input Parameters    : none. Waiting time is defined by the global variable LedSpeed.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
static void wait ( void )
{//* Begin
    volatile unsigned int waiting_time ;
    change_speed () ;
    for(waiting_time = 0; waiting_time < LedSpeed; waiting_time++) ;
}//* End


//*--------------------------------------------------------------------------------------
//* Function Name       : Main
//* Object              : Software entry point
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
int main(void)
{//* Begin
       AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, DISPLAY_MASK ) ;
       AT91F_PIO_SetOutput( AT91C_BASE_PIOA, DISPLAY_MASK) ;

       for(;;) {
           scrollDisplay();
       }
}//* End of main

