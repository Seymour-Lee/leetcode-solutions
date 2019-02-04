/*
* timers-c.h      : Timer Management Include File
* authors         : John Heidemann
*
* Copyright (C) 2000-2004 by the Unversity of Southern California
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


#ifndef _TIMERS_C_H_
#define _TIMERS_C_H_

#include <sys/time.h>
#include <stdio.h>
#include "tools.hh"

#define MAXVALUE  0x7ffffff /* no timer present */ 

#ifdef __cplusplus
extern "C" {
#endif

/*
 * To make a new timer,
 * pass a function pointer (cb) and optional context (p)
 * to Timers_AddTimer.
 *
 * When the timer expires cb will be called with the timer 
 * handle and context as arguments.
 *
 * If you need to pass parameters to your timer,
 * pass them through the context.
 * (Note that C++ is MUCH cleaner about this...
 * you can do it type-safely via subclassing.)
 *
 * The return value of your callback indicates what should happen
 * to the timer:
 *
 * return == TimerCallback::RESCHEDULE_SAME
 *		re-add timer again to queue with same timeout as last time
 *        > 0   re-add timer to queue with new timeout given by return value
 *        == TimerCallback::DISCARD   discard timer (do not re-add it to the queue)
 */

enum TimerCallbackReturn_t { TIMER_CALLBACK_DISCARD = -1, TIMER_CALLBACK_RESCHEDULE_SAME = 0 };

typedef int (*TimerCallback_t)(void *p);

int Timers_AddTimer(int timeout, TimerCallback_t cb, void *p);
int Timers_RemoveTimer(int handle);

/*
 * Your main app needs an event loop where it calls
 * Timers_NextTimerTime to figure out when the next timer is,
 * and then calls Timers_ExecuteNextTimer when it
 * wants to run one.
 * See test-app-c.c for an example.
 */
void Timers_NextTimerTime(struct timeval *tv);
void Timers_ExecuteNextTimer();

#ifdef __cplusplus
};
#endif

#endif // _TIMERS_C_H_


