/*
* timers.cc       : Timer Management Class
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

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "timers.hh"

class EventQueue {

/*
*  Methods
*
*  Eq_Add        inserts an event into the queue
*  Eq_AddAfter   creates a new event and inserts it
*  Eq_Pop        extracts the first event and returns it
*  Eq_NextTimer  returns the time of expiration for the next event
*  Eq_TopInPast  returns true if the head of the timer queue is in the past
*  Eq_Remove     remove an event from the queue
*/

public:
	EventQueue(){
	        head_ = NULL;
	};
	~EventQueue(){
	  /* Empty destructor */
	};

	void Eq_Add(event *n);
	void Eq_AddAfter(int type, void *payload, int delay_msec);
	event * Eq_Pop();
	event * Eq_FindEvent(int type);
	event * Eq_FindNextEvent(int type, event *e);
	void Eq_NextTimer(struct timeval *tv);
	int Eq_TopInPast();
	void Eq_Print();
	int Eq_Remove(event *e);

/*
*  Event methods
*
*  Event_SetDelay   sets the expiration time to a delay after present time
*  RandDelay        computes a randomized delay, measured in milliseconds.
*                   note that most OS timers have granularities on order of
*                   5-15 ms.
*/

private:

	void Event_SetDelay(event *e, int delay_msec);
	static bool rng_seeded_;
	int RandDelay(int base_ms, int pm_range_ms);

	event *head_;
};

bool EventQueue::rng_seeded_ = false;


/*
* This class is used to define a timer in the event queue. The timeout provided
* should be in milliseconds. cb specifies the function that will be
* called. 
*/
class TimerEntry {
public:
	handle         hdl_;
	int            timeout_;
	TimerCallback  *cb_;

	TimerEntry(handle hdl, int timeout,TimerCallback *cb) : 
		hdl_(hdl), timeout_(timeout), cb_(cb) {};
	~TimerEntry() { };
};


/*
*  Timeval utility routines
*/

/*  returns -1, 0, 1  for < == > */
int Timeval_Cmp(struct timeval *x, struct timeval *y)
{
	if (x->tv_sec > y->tv_sec) return 1;
	if (x->tv_sec < y->tv_sec) return -1;
	if (x->tv_usec > y->tv_usec) return 1;
	if (x->tv_usec < y->tv_usec) return -1;
	return 0;
}

/* Returns a pointer to a static structure.  returns {0,0} if x<y.*/
struct timeval *Timeval_Sub(struct timeval *x, struct timeval *y)
{
	static struct timeval tv;

	if (Timeval_Cmp(x,y) < 0) 
		tv.tv_sec = tv.tv_usec = 0;
	else{
		tv = *x;
		// borrow..
		if (tv.tv_usec < y->tv_usec){
			tv.tv_usec += 1000000;
			tv.tv_sec--;
		}
		// sub
		tv.tv_usec -= y->tv_usec;
		tv.tv_sec -= y->tv_sec;
	}
	return &tv;
}

/*  adds usecs delay to tv, handling wrap around */
void Timeval_Addusecs(struct timeval *tv, int usecs)
{
	tv->tv_usec += usecs;
	if (tv->tv_usec > 1000000) {
		tv->tv_sec += tv->tv_usec / 1000000;
		tv->tv_usec = tv->tv_usec % 1000000;
	}
}

/*  adds usecs delay to tv, handling wrap around */
void Timeval_Addmsecs(struct timeval *tv, int msecs)
{
	/*
	 * First, extract the seconds component.
	 * Do this to handle long durations, where msecs*1000 > MAXINT
	 */
	if (msecs >= 1000) {
		int secs = msecs / 1000;
		msecs %= 1000;
		tv->tv_sec += secs;
	};
	// let addusecs do with wrapping the usecs field
	assert(msecs < 1000);
	Timeval_Addusecs(tv, msecs * 1000);
}


/*
 *  Event utility routines. These are used internally by Timers class
 *
 *
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

/*  compares times of two events, returns -1, 0, 1 for < == > */
int Event_Cmp(event *x, event *y)
{
	return Timeval_Cmp(&(x->tv_),&(y->tv_));
}

/*
*  EventQueue Methods
*/

void EventQueue::Eq_Add(event *n)
{
	event *ptr = head_;
	event *last = ptr;
	while (ptr && (Event_Cmp(n,ptr) > 0)){
		last = ptr; 
		ptr = ptr->next_;
	}
	if (last == ptr){
		n->next_ = head_;
		head_ = n;
	}
	else{
		n->next_ = ptr;
		last->next_ = n;
	}
}

event * EventQueue::Eq_Pop()
{
	event *e = head_;
	if (e){
		head_ = head_->next_;
		e->next_ = NULL;
	}
	return e;
}

event * EventQueue::Eq_FindEvent(int type)
{
	return Eq_FindNextEvent(type, head_);
}

event * EventQueue::Eq_FindNextEvent(int type, event *e)
{
	while (e){

		if (e->type_ == type)
			return e;

		e = e->next_;
	}

	return e;
}

void EventQueue::Eq_AddAfter(int type, void *payload, int delay_msec)
{

        event *e = new event;
	e->type_ = type;
	e->payload_ = payload;
	Event_SetDelay(e,delay_msec);
	Eq_Add(e);
}

void EventQueue::Event_SetDelay(event *e, int delay_msec)
{
	getTime(&(e->tv_));
	Timeval_Addmsecs(&(e->tv_), delay_msec);
}

/* returns pointer to the next timer value  */
void EventQueue::Eq_NextTimer(struct timeval *tvp)
{
	if (head_){
		struct timeval now;
    
		getTime(&now);
		*tvp = *Timeval_Sub(&(head_->tv_), &now);
	}
	else {
		// nothing, so pick a time far in the future
		tvp->tv_sec = MAXVALUE;
		tvp->tv_usec = 0;
	};
}


int EventQueue::Eq_TopInPast()
{
	if (head_){
		struct timeval now;
		getTime(&now);
		return (Timeval_Cmp(&(head_->tv_),&now) <= 0);
	}
	return 0;
}

void EventQueue::Eq_Print()
{
	event *e = head_;
	for (; (e); e = e->next_){
		printf("time=%ld:%06ld type=%d\n",e->tv_.tv_sec,e->tv_.tv_usec,e->type_);
	}
}

int EventQueue::Eq_Remove(event *e)
{
	event *ce, *pe;

	if (e){
		if (head_ == e){
			head_ = e->next_;
			return 0;
		}

		pe = head_;
		ce = head_->next_;

		while (ce){
			if (ce == e){
				pe->next_ = e->next_;
				return 0;
			}
			else{
				pe = ce;
				ce = ce->next_;
			}
		}
	}

	return -1;
}

/* computes a randomized delay, measured in milliseconds.
* note that most OS timers have granularities on order of 5-15 ms.
*/
int EventQueue::RandDelay(int base_ms, int pm_range_ms)
{
	if (!rng_seeded_)
		setSeed();
	return (int) (base_ms + ((((float) getRand()) /
				   ((float) RAND_MAX)) - 0.5) * pm_range_ms);
}

/* Creates the Timer Management class. Creates the eventqueue
* The eventqueue is used by the Timer class only. 
* Use the nextTimer and ExecuteNextTimer functions to access
* the event queue
*/
Timers::Timers()
{
	// Initialize basic stuff
	next_handle_ = 1;

	// Initialize event queue
	eq_ = new EventQueue;
}

/*
* This function adds a timer to the event queue. The timeout provided
* should be in milliseconds. cb specifies the function that will be
* called. 
*/
handle Timers::AddTimer(int timeout, TimerCallback *cb)
{
	TimerEntry *entry;

	entry = new TimerEntry(next_handle_, timeout, cb);
	next_handle_++;
	eq_->Eq_AddAfter(1, entry, timeout);

	return entry->hdl_;
}

/*
* Applications can use this function to remove from the eventqueue
* a previously scheduled timer (the handle should be the one returned
* by the AddTimer function)
*/
bool Timers::RemoveTimer(handle hdl)
{
	event *e;
	TimerEntry *entry;
	bool found = false;

	// Find the timer in the queue
	e = eq_->Eq_FindEvent(1);
	while (e){
		entry = (TimerEntry *) e->payload_;
		if (entry->hdl_ == hdl){
			found = true;
			break;
		}

		e = eq_->Eq_FindNextEvent(1, e->next_);
	}

	// If timer found, remove it from the queue
	if (e){
		if (eq_->Eq_Remove(e) != 0){
			fprintf(stderr, "Error: Can't remove event from queue !\n");
			exit(1);
		}

		// Call the application provided delete function

		delete entry;
		free(e);
	}

	return found;
}

// Returns the expiration value for the first timer on the queue
void Timers::NextTimerTime(struct timeval * tvp)
{
	eq_->Eq_NextTimer(tvp);
}

// Executes the first timer callback in the queue 
void Timers::ExecuteNextTimer()
{
  
	event *e = eq_->Eq_Pop();
	TimerEntry *entry = (TimerEntry *) e->payload_;
	// run it
	int new_timeout = entry->cb_->Expire();
  
	if (new_timeout == TimerCallback::DISCARD) {
		delete entry;
	} else if (new_timeout == TimerCallback::RESCHEDULE_SAME || new_timeout > 0) {
		if (new_timeout > 0){
			// Change the timer's timeout
			entry->timeout_ = new_timeout;
		}
		eq_->Eq_AddAfter(1, (TimerEntry *) entry, entry->timeout_);
	} else {
		fprintf(stderr, "error: unknown return value from timer callback.\n");
		exit(1);
	};
	free(e);
}










