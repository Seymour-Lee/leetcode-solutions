
/*
* test-app.hh    : Test App Include File
* author         : Fabio Silva and Chalermek Intanagonwiwat
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

#ifndef _TEST_APP_H_
#define _TEST_APP_H_

#include "timers.hh"

class TestApp;

/* In TestTimer1 and TestTimer2, we are using a varible count_ to demonstrate 
 * the how to associate variable in the event queue. 
 * count_ can be replace by any other type of varible/structure 
 * ex: a LSA structure 
 */
class TestTimer1: public TimerCallback {
public:
        TestTimer1(TestApp *app, int count) : app_(app), count_(count) {};
        ~TestTimer1() {};
	TestApp *app_;
        int count_;
	int Expire();
};

class TestTimer2: public TimerCallback {
public:
	TestTimer2(int p):p_(p) {};
        ~TestTimer2() {};
        int p_;
	int Expire();
};

class TestTimer3 : public TimerCallback {
public:
	TestTimer3(Timers *mgr, handle h):mgr_(mgr), h_(h) {};
        ~TestTimer3() {};
	Timers *mgr_;
        handle h_;
	int Expire();
};

class TestApp{
public:
	TestApp();
	void start();

protected:
	Timers *timersManager_;
};

#endif /* _TEST_APP_H_ */






