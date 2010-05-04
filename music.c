/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

static const uint8_t quarterSine[] = {
    0,4,8,12,16,20,23,27,31,35,39,43,47,50,54,58,61,65,68,71,75,78,81,84,87,90,
    93,96,98,101,103,105,108,110,112,114,,115,117,119,120,121,122,123,124,125,
    26,126,127,127,127
}

struct note {
    uint16_t timePeriod; // The period of the note to play in microseconds, generally use the defines from music.h
    uint8_t length; // The length of the note in number of quavers.
}

note maryHadALittleLamb[] = {
    {E4,2},
    {D4,2},
    {C4,2},
    {D4,2},
    {E4,2},
    {E4,2},
    {E4,4},
    {D4,2},
    {D4,2},
    {D4,4},
    {E4,2},
    {G4,2},
    {G4,4},
    {E4,2},
    {D4,2},
    {C4,2},
    {D4,2},
    {E4,2},
    {E4,2},
    {E4,2},
    {E4,2},
    {D4,2},
    {D4,2},
    {E4,2},
    {D4,2},
    {C4,8}
}
