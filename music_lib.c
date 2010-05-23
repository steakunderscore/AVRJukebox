/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#include "music.h"
#include <stdlib.h>

note_t sineSolo[] = {{D5,6},{0,0}};
song_t sine = {7000000, sineSolo};

note_t sineSoloC3[] = {{C3,6},{0,0}};
song_t sineC3 = {7000000, sineSoloC3};

note_t sineSoloF3[] = {{F3,6},{0,0}};
song_t sineF3 = {7000000, sineSoloF3};

note_t sineSoloD4[] = {{D4,6},{0,0}};
song_t sineD4 = {7000000, sineSoloD4};

note_t sineSoloG4[] = {{G4,6},{0,0}};
song_t sineG4 = {7000000, sineSoloG4};

note_t sineSoloB4[] = {{B4,6},{0,0}};
song_t sineB4 = {7000000, sineSoloB4};

note_t sineSoloF5[] = {{F5,6},{0,0}};
song_t sineF5 = {7000000, sineSoloF5};

note_t sineSoloD6[] = {{D6,6},{0,0}};
song_t sineD6 = {7000000, sineSoloD6};

note_t maryHadALittleLambSolo[] = {
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
    {C4,8},
    {0,0}
};

song_t maryHadALittleLamb = {8500000, maryHadALittleLambSolo};

note_t theResistanceIntroSolo[] = {
    {E4,2},
    {B4,2},
    {C5,2},
    {D5,4},
    {C5,4},
    {B4,4},
    {C5,2},
    {B4,12},
    {E4,2},
    {A4,2},
    {B4,2},
    {C5,4},
    {B4,4},
    {A4,4},
    {B4,2},
    {D5,12},
    {E4,2},
    {D5,2},
    {E5,2},
    {F5,4},
    {E5,4},
    {D5,4},
    {E5,2},
    {C5,10},
    {E5,2},
    {D5,2},
    {C5,2},
    {B4,4},
    {D5,2},
    {C4,2},
    {B4,2},
    {A4,6},
    {A4,1},
    {G4S,10},
    {E4,2},
    {B4,2},
    {C5,2},
    {D5,4},
    {C5,4},
    {B4,4},
    {C5,2},
    {A4,12},
    {E4,2},
    {A4,2},
    {B4,2},
    {C5,4},
    {B4,4},
    {A4,4},
    {B4,2},
    {D5,12},
    {G4,2},
    {D5,2},
    {E5,2},
    {F5,4},
    {E5,4},
    {D5,4},
    {E5,2},
    {C5,10},
    {E5,2},
    {D5,2},
    {C5,2},
    {B4,4},
    {D5,2},
    {C5,2},
    {B4,2},
    {A4,6},
    {B4,1},
    {A4,1},
    {G4S,10},
    {0,0}
};

song_t theResistanceIntro = {8000000, theResistanceIntroSolo};

note_t happyBirthdaySolo[] = {
    {D4,1},
    {D4,1},
    {E4,2},
    {D4,2},
    {G4,2},
    {F4S,4},
    {D4,1},
    {D4,1},
    {E4,2},
    {D4,2},
    {A4,2},
    {G4,4},
    {D4,1},
    {D4,1},
    {D5,2},
    {B4,2},
    {G4,2},
    {F4S,2},
    {E4,2},
    {C5,1},
    {C5,1},
    {B4,2},
    {G4,2},
    {A4,2},
    {G4,6},
    {0,0}
};

song_t happyBirthday = {10000000, happyBirthdaySolo};

note_t pinkPantherSolo[] = {
    {D3S,3},
    {E3,18},
    {0,3},
    {F3S,3},
    {G3,18},
    {0,3},
    {D3S,3},
    {E3,9},
    {F3S,3},
    {G3,9},
    {C4,3},
    {B3,9},
    {E3,3},
    {G3,9},
    {B3,9},
    {B3B,24},
    {B3,4},
    {A3,4},
    {G3,4},
    {E3,4},
    {D3,4},
    {B3,40},
    {0,3},
    {0,0}
};

song_t pinkPanther = {3000000, pinkPantherSolo};

song_t *songs[] = {&maryHadALittleLamb, &theResistanceIntro, &happyBirthday, &pinkPanther, &sine, &sine, &sineC3, &sineF3, &sineD4, NULL, NULL, &sineG4, &sineB4, &sineF5, &sineD6};
