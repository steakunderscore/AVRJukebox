/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

// Note defines as number of microseconds per period.
#define C4 3822
#define D4 3405
#define E4 3034
#define G4 2551

typedef struct note {
    // The period of the note to play in microseconds, generally use the defines
    // from music.h for this.
    uint16_t timePeriod;
    // The length of the note in number of quavers.
    uint8_t length;
} note_t;

/* Sets the music to be played to the given music with a given quaverlength. */
void setMusic( note_t *music_p, uint16_t quaverLength );

/* Gets the amplitude for the note at a time measured in microseconds. */
uint8_t getAmplitude( uint32_t time );