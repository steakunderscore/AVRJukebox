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

note_t sine[] = {{C4,6},{0,0}};

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

note_t *maryHadALittleLamb[] = {
    marySolo, maryBass1, maryBass2
};
