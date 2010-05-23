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

note_t sine1[] = {{C4,6},{0,0}};
track_t sineTracks[] = {{255,sine1}};
song_t sine = {1, 700000, sineTracks};

note_t maryBass1[] = {
    {C3,2},
    {0,2},
    {G3,2},
    {0,2},
    {C3,2},
    {0,2},
    {G3,2},
    {0,2},
    {D3,2},
    {0,2},
    {G3,2},
    {0,2},
    {C3,2},
    {0,2},
    {G3,2},
    {0,2},
    {C3,2},
    {0,2},
    {G3,2},
    {0,2},
    {C3,2},
    {0,2},
    {G3,2},
    {0,2},
    {D3,2},
    {0,2},
    {G3,2},
    {0,2},
    {C3,2},
    {G3,2},
    {G3,2},
    {0,2},
    {0,0}
};

note_t maryBass2[] = {
    {0,4},
    {E3,2},
    {0,6},
    {E3,2},
    {0,6},
    {F3,2},
    {0,6},
    {E3,2},
    {0,6},
    {E3,2},
    {0,6},
    {E3,2},
    {0,6},
    {F3,2},
    {0,4},
    {E3,4},
    {0,2},
    {0,0}
};

note_t marySolo[] = {
    {E4,3},
    {D4,1},
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
    {E4,3},
    {D4,1},
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

track_t maryHadALittleLambTracks[] = {
    {200,marySolo}, {25,maryBass1}, {25,maryBass2}
};

song_t maryHadALittleLamb = {3, 700000, maryHadALittleLambTracks};

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

track_t theResistanceIntroTracks = {255, theResistanceIntroSolo};
song_t theResistanceIntro = {1, 700000, theResistanceIntroTracks};

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

track_t happyBirthdayTracks = {255, happyBirthdaySolo};
song_t happyBirthday = {1, 700000, happyBirthdayTracks};

song_t songs[] = {maryHadALittleLamb, theResistanceIntro, happyBirthday, sine, sine, sine, sine, sine, sine};
