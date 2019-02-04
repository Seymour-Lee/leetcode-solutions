/*
* timers.hh       : Timer Management Include File
* authors         : John Heidemann, Fabio Silva and Alefiya Hussain
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

#ifndef _TIMERS_H_
#define _TIMERS_H_

#include <string.h>

#include "tools.hh"

#define MAXVALUE    0x7ffffff // no timer present 

typedef long handle;

/* timeval routines */
/*  returns -1, 0, 1  for < == > */
int Timeval_Cmp(struct timeval *x, struct timeval *y);
/* Returns a pointer to a static structure.  returns {0,0} if x<y.*/
struct timeval *Timeval_Sub(struct timeval *x, struct timeval *y);
/*  adds usecs delay to tv */
void Timeval_Addusecs(struct timeval *tv, int usecs);

#ifndef RAND_MAX
#define RAND_MAX 2147483647
#endif // RAND_MAX


/*
 * To make a new timer,
 * subclass TimerCallback and override
 * the Expire() method.
 *
 * If you need to pass parameters to your timer,
 * pass them in the constructor of your subclass.
 *
 * If you allocate data in your callback,
 * free it in the destructor.
 *
 *
 * When the timer fires, Expire() will be called.
 * You can do anything you want there.
 * When you're done, return a value that indicates what happens
 * to the timer:
 *
 * return == TimerCallback::RESCHEDULE_SAME
 *		re-add timer again to queue with same timeout as last time
 *        > 0   re-add timer to queue with new timeout given by return value
 *        == TimerCallback::DISCARD   discard timer (do not re-add it to the queue)
 */
class TimerCallback {
public:
	TimerCallback() {};
  	virtual ~TimerCallback() {};
       	virtual int Expire() = 0;

	enum TimerCallbackReturn { DISCARD = -1, RESCHEDULE_SAME = 0 };
};


/*
 * event queues are used INTERNALY to timer.cc
 * to keep track of multiple timers.
 *
 * These are NOT for external use...
 * the right way is to subclass TimerCallback.
 * See examples in test-app.{cc,hh}.
 */

/*
*  An event specifies an expiration time, a type, and a payload.
*  An eventQueue is a list of events, kept in sorted order by 
*  expiration time.  
*/

class event {
public:
	struct timeval tv_;
	int type_;
	void *payload_;
	event *next_;
};

class EventQueue;

/* Creates the Timer Management class. Creates the eventqueue
* The eventqueue is used by the Timer class only. 
* Use the NextTimerTime and ExecuteNextTimer functions to access
* the event queue
*/

class Timers {
public:
	Timers();
	~Timers() {};

	// Timer API functions:
	
        /* add a timer to the queue, returning the handle
	 * that can be used to cancel it with RemoveTimer
	 * timeout value deifne in ms. 
	 * When the timer fires, Expire() will be called.
	 * You can do anything you want there.
	 * When you're done, return a value that indicates what happens
	 * to the timer, see TimerCallback for details.
	 */
  	handle AddTimer(int tv,TimerCallback *cb);
	
        // remove a timer that's scheduled, returns if it was there.
	bool RemoveTimer(handle hdl);
	
	// returns the timer value at head of the queue
	void NextTimerTime(struct timeval *tv);
  
	// Executes the timer on the head of the queue
	void ExecuteNextTimer();

protected:
	int next_handle_;  // counter of handle ids
	EventQueue *eq_;  // internal list of timers
};


#endif // _TIMERS_H_

