/*
 * Authors:
 *      Wim Looman
 *      Henry Jenkins
 * Copyright:
 *      Copyright (c) 2010 Wim Looman, Henry Jenkins
 * License:
 *      GNU General Public License (see LICENSE in root folder)
 */

#ifndef sound_h
#define sound_h
// Include Standard files
#include "Board.h"
//TODO: add defines for DAC io

/* Initilizes the DAC and it's output
 */
void soundInit( void );

void sendData( char data );

#endif //sound_h
