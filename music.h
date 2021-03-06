/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#ifndef music_h
#define music_h
#include "Board.h"
#include <stdint.h>

// Number of microseconds between callbacks.
#define CALLBACK_TIME 100

// Note defines as number of microseconds per period.
// Note, these are actually 3 octaves above there
// listed values.

#define C3 1911
#define D3 1703
#define D3S 1607
#define E3 1517
#define F3 1432
#define F3S 1351
#define G3 1276
#define A3 1136
#define B3B 1073
#define B3 1012
#define C4 955
#define D4 851
#define D4S 804
#define E4 758
#define F4 716
#define F4S 676
#define G4 638
#define G4S 602
#define A4 568
#define B4B 536
#define B4 506
#define C5 478
#define D5 426
#define E5 379
#define F5 358
#define G5 319
#define A5 284
#define B5 253
#define C6 239
#define D6 213
#define E6 190
#define F6 179

typedef struct note {
    // The period of the note to play in microseconds, generally use the defines
    // from music.h for this.
    uint16_t timePeriod;
    // The length of the note in number of quavers.
    uint8_t length;
} note_t;

typedef struct song {
    uint32_t speed;
    note_t *notes;
} song_t;

void stopMusic( void );
void resetMusic( void );
void startMusic( void );

/* Sets the music to be played to the given music with a given quaverlength. */
void setMusic( note_t *music_p, uint32_t quaverLength );

void musicInit( void );

void playMusic( void );

#endif /* music_h */
