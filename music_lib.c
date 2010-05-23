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
    {D4S,3},
    {E4,18},
    {0,3},
    {F4S,3},
    {G4,18},
    {0,3},
    {D4S,3},
    {E4,9},
    {F4S,3},
    {G4,9},
    {C5,3},
    {B4,9},
    {E4,3},
    {G4,9},
    {B4,9},
    {B4B,24},
    {B4,4},
    {A4,4},
    {G4,4},
    {E4,4},
    {D4,4},
    {B4,40},
    {0,3},
    {0,0}
};

song_t pinkPanther = {9000000, pinkPantherSolo};

note_t threeBlindMiceSolo[] = {
    {E4,6},
    {D4,6},
    {C4,12},
    {E4,6},
    {D4,6},
    {C4,12},
    {G4,6},
    {F4,4},
    {F4,2},
    {E4,12},
    {G4,6},
    {F4,4},
    {F4,2},
    {E4,10},
    {G4,2},
    {C5,4},
    {C5,2},
    {B4,2},
    {A4,2},
    {C5,4},
    {G4,2},
    {G4,2},
    {G4,2},
    {C5,2},
    {C5,2},
    {C5,2},
    {B4,2},
    {A4,2},
    {B4,2},
    {C5,4},
    {G4,2},
    {G4,4},
    {G4,1},
    {G4,1},
    {C5,4},
    {C5,2},
    {B4,2},
    {A4,2},
    {C5,2},
    {G4,2},
    {G4,2},
    {G4,4},
    {F4,2},
    {E4,2},
    {D4,6},
    {C4,10},
    {0,0}
};

song_t threeBlindMice = {5000000, threeBlindMiceSolo};

song_t *songs[] = {&maryHadALittleLamb, &theResistanceIntro, &happyBirthday, &pinkPanther, &threeBlindMice, &sine, &sineC3, &sineF3, &sineD4, NULL, NULL, &sineG4, &sineB4, &sineF5, &sineD6};
