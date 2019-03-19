/*
* tools.hh      : Other utility functions
* authors       : Fabio Silva
*
* Copyright (C) 2000-2001 by the Unversity of Southern California
* $Id$
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
*
* A complete copy of the LGPL is at http://www.gnu.org/copyleft/lesser.txt
*/

/*
* tools.hh contains OS abstractions to make it easy to use
* in different environments (i.e. in simulations,
* where time is virtualized, and in embeddedd apps where
* error logging happens in some non-trivial way).
*/
#ifndef _TOOLS_H_
#define _TOOLS_H_
#include <sys/time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

	void setSeed();
	void getTime(struct timeval * tv);
	int getRand();

#ifdef __cplusplus
};
#endif

#endif				/* !_TOOLS_H_ */
