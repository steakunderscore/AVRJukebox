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

// Maximum number of tracks that can be played at once.
#define MAX_TRACKS 4

// Note defines as number of microseconds per period.
// Note, these are actually 3 octaves above there
// listed values.
#define C3 955
#define D3 851
#define E3 758
#define F3 716
#define G3 638
#define C4 478
#define D4 426
#define E4 379
#define G4 319

typedef struct note {
    // The period of the note to play in microseconds, generally use the defines
    // from music.h for this.
    uint16_t timePeriod;
    // The length of the note in number of quavers.
    uint8_t length;
} note_t;

/* Sets the music to be played to the given music with a given quaverlength. */
void setMusic( note_t **music_p, uint8_t numOfTracks, uint32_t quaverLength );

void musicInit( void );

void playMusic( void );

#endif /* music_h */
