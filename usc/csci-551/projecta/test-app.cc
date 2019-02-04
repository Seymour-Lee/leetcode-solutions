/*
* test-app.cc    : Test Application
* author         : Fabio Silva, Chalermek Intanagonwiwat and Alefiya Hussain
*
* Copyright (C) 2000-2001 by the Unversity of Southern California
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

#include "test-app.hh"

/* 
 * This application demonstrates using the timer package
 * by getting two timers going.
 */

/*
* The return value from expire is used 
* to indicate what should be done with the timer
*  = 0   Add timer again to queue
*  > 0   Set new_timeout as timeout value for timer 
*  < 0   Discard timer 
*/  
int TestTimer1::Expire()
{
	struct timeval tv;
	getTime(&tv);
	fprintf(stderr, "Timer 1 has expired %d times! Time %d.%06d\n",
		count_, (int)tv.tv_sec,(int)tv.tv_usec);
	count_++;
	fflush(NULL);
	return TimerCallback::RESCHEDULE_SAME;
}


int TestTimer2::Expire()
{
	struct timeval tv;

	getTime(&tv);
	fprintf(stderr, "Timer %d has expired! Time %d.%06d\n",
		p_, (int)tv.tv_sec, (int)tv.tv_usec);
	fflush(NULL);
	return TimerCallback::RESCHEDULE_SAME;
}

int TestTimer3::Expire()
{
	fprintf(stderr, "TestTimer3::Expire: removing other timer handle %d\n", (int)h_);
	mgr_->RemoveTimer(h_);
	return TimerCallback::RESCHEDULE_SAME;
}

void TestApp::start()
{
	struct timeval tmv;
	int status;

	// Change while condition to reflect what is required for Project 1
	// ex: Routing table stabalization. 
	while (1) {
		timersManager_->NextTimerTime(&tmv);
		if (tmv.tv_sec == 0 && tmv.tv_usec == 0) {
		        // The timer at the head on the queue has expired 
		        timersManager_->ExecuteNextTimer();
			continue;
		}
		if (tmv.tv_sec == MAXVALUE && tmv.tv_usec == 0){
		        // There are no timers in the event queue 
		        break;
		}
		  
		/* The select call here will wait for tv seconds before expiring 
		 * You need to  modifiy it to listen to multiple sockets and add code for 
		 * packet processing. Refer to the select man pages or "Unix Network 
		 * Programming" by R. Stevens Pg 156.
		 */
		status = select(0, NULL, NULL, NULL, &tmv);
		
		if (status < 0){
			// This should not happen
			fprintf(stderr, "Select returned %d\n", status);
		}else{
			if (status == 0){
				// Timer expired, Hence process it 
			        timersManager_->ExecuteNextTimer();
				// Execute all timers that have expired.
				timersManager_->NextTimerTime(&tmv);
				while(tmv.tv_sec == 0 && tmv.tv_usec == 0){
				       // Timer at the head of the queue has expired 
				        timersManager_->ExecuteNextTimer();
					timersManager_->NextTimerTime(&tmv);
					
				}
			}
			if (status > 0){
				// The socket has received data.
				// Perform packet processing.
		    
			}
		}
	}
	return;
}

TestApp::TestApp()
{
	TimerCallback *tcb;
	struct timeval tv;

	getTime(&tv);

	fprintf(stderr,"Start time %d.%06d\n",
		(int)tv.tv_sec, (int)tv.tv_usec);
	// Create the timer event management class
	timersManager_ = new Timers;

	// Create callback classes and set up pointers
	// Add timers to the event queue and specify the timer in ms.
	tcb = new TestTimer1(this, 1);
	timersManager_->AddTimer(3000, tcb);

	tcb = new TestTimer2(2);
	handle t2 = timersManager_->AddTimer(10000, tcb);

	tcb = new TestTimer3(timersManager_, t2);
	timersManager_->AddTimer(20100, tcb);

	// a really long one: 60 minutes
	tcb = new TestTimer2(3);
	timersManager_->AddTimer(3600*1000, tcb);

}

int main()
{
	TestApp *app;

	/* Initialize the Timer test application  by
	 * adding timers initially. 
	 *     -Add a timer for each packet sent.
	 *     -Set the timeout value appropriately 
	 */
	app = new TestApp;
	// Start the timers 
	app->start();

	return 0;
}
