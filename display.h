
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

#define DISPLAY_SEGMENT_MASK  (DSEGMENTA | DSEGMENTB | DSEGMENTC | DSEGMENTD | \
                               DSEGMENTE | DSEGMENTF | DSEGMENTG | DSEGMENTDP )


//*--------------------------------------------------------------------------------------
//* Function Name       : scrollDisplay
//* Object              : set the current display segment to the next segment
//* Input Parameters    : none. But does use global currentSegment.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
static void scrollDisplay( void );
