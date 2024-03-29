/*
 *
 *+  Copyright (c) 2009 Ian Halpern
 *@  http://impulse.ian-halpern.com
 *
 *   This file is part of Impulse.
 *
 *   Impulse is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Impulse is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Impulse.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef IMPULSE_H
#define IMPULSE_H

#ifdef __cplusplus
extern "C" {
#endif

#define IM_NOFFT 0
#define IM_FFT 1

double *im_getSnapshot( int fft );

void im_start( void );

void im_setup( int source );

void im_stop( void );

#ifdef __cplusplus
}

#endif

#endif
