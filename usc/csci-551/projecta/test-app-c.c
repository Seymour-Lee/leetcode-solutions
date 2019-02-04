/*
* test-app-c.c   : sample timer app in C
* author         : Alefiya Hussain and John Heidemann
*
* Copyright (C) 2000-2004 by the Unversity of Southern California
* $Id$
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License,
* version 2, as published by the Free Software Foundation.
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
*/

#include "timers-c.h"



/* 
 * This application demonstrates using the timer package
 * by getting two timers going.
 */

/*
* In this example, the return value from expire is used 
* to indicate what should be done with the timer
*  = 0   Add timer again to queue
*  > 0   Set new_timeout as timeout value for timer 
*  < 0   Discard timer 
*/  
struct TestTimer1_context {
	int count;
};

int TestTimer1_expire(void *context)
{
	/* demonstrate passing a structure with arbitrary context in it */
	struct TestTimer1_context *tt1_ctx = (struct TestTimer1_context *)context;
	struct timeval tv;
	int count = tt1_ctx->count++;

	getTime(&tv);
	fprintf(stderr, "Timer 1 has expired %d times! Time %d.%06d\n",
		count, (int)tv.tv_sec, (int)tv.tv_usec);
	fflush(NULL);
	return TIMER_CALLBACK_RESCHEDULE_SAME;
}

int TestTimer2_expire(void *p)
{
	struct timeval tv;

	getTime(&tv);
	fprintf(stderr, "Timer 2 has expired! Time %d.%06d\n",
		(int)tv.tv_sec, (int)tv.tv_usec);
	fflush(NULL);
	return TIMER_CALLBACK_RESCHEDULE_SAME;
}

struct TestTimer3_context {
	int victim;
};


int TestTimer3_expire(void *p)
{
	struct TestTimer3_context *context = (struct TestTimer3_context *)p;

	fprintf(stderr, "TestTimer3_expire: removing other timer handle %d\n", context->victim);
	Timers_RemoveTimer(context->victim);
	return TIMER_CALLBACK_RESCHEDULE_SAME;
}

void TestApp_start()
{
	struct timeval tmv;
	int status;

	/*
	 * Change while condition to reflect what is required for Project 1
	 * ex: Routing table stabalization. 
	 */
	while (1) {
		Timers_NextTimerTime(&tmv);
		if (tmv.tv_sec == 0 && tmv.tv_usec == 0) {
			/* No Timer have been defined. */
		        Timers_ExecuteNextTimer();
			continue;
		}
		if (tmv.tv_sec == MAXVALUE && tmv.tv_usec == 0){
			/* There are no timers in the event queue */
		        break;
		}

		/*
		 * The select call here will wait for tv seconds
		 * before expiring You need to modifiy it to listen to
		 * multiple sockets and add code for packet
		 * processing. Refer to the select man pages or "Unix
		 * Network Programming" by R. Stevens Pg 156.
		 */
		status = select(0, NULL, NULL, NULL, &tmv);
		
		if (status < 0){
			/* This should not happen */
			fprintf(stderr, "Select returned %d\n", status);
		} else {
			if (status == 0) {
				/* Timer expired, Hence process it  */
			        Timers_ExecuteNextTimer();
				/* Execute all timers that have expired.*/
				Timers_NextTimerTime(&tmv);
				while(tmv.tv_sec == 0 && tmv.tv_usec == 0) {
					/* Timer at the head of the queue has expired  */
				        Timers_ExecuteNextTimer();
					Timers_NextTimerTime(&tmv);
					
				}
			}
			if (status > 0){
				/*
				 * The socket has received data.
				 * Perform packet processing.
				 */
		    
			}
		}
	}
}

void
TestApp_init() /* initialization */
{
	static struct TestTimer1_context tt1_ctx;
	static struct TestTimer3_context tt3_ctx;
	struct timeval tv;
	int tt2_handle;

	getTime(&tv);

	fprintf(stderr,"Start Time = %d.%06d\n",
		(int)tv.tv_sec, (int)tv.tv_usec);

	/* Create callback classes and set up pointers */
	tt1_ctx.count = 0;
	(void) Timers_AddTimer(3000, TestTimer1_expire, (void*)&tt1_ctx);

	tt2_handle = Timers_AddTimer(10000, TestTimer2_expire, NULL);

	tt3_ctx.victim = tt2_handle;
	(void) Timers_AddTimer(20100, TestTimer3_expire, (void*)&tt3_ctx);
}

int main()
{
	/*
	 * Initialize the Timer test application  by
	 * adding timers initially. 
	 *     -Add a timer for each packet sent.
	 *     -Set the timeout value appropriately 
	 */
	TestApp_init();
	TestApp_start();

	return 0;
}
