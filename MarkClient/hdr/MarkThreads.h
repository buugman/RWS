/********************************************************************************
 * MarkThreads.h                                                                     *
 * Copyright (C) 2011-09-17 Andreev Slava                                       *
 *                                                                              *
 * Contact information:                                                         *
 *   Email  - buugman@gmail.com                                                 *      
 *   ICQ    - 460912209                                                         *
 *   Skype  - timebanditx                                                       * 
 *   WWW    - http://bungman.cyberblogger.ru/                                   *
 *                                                                              *
 * This program is free software: you can redistribute it and/or modify         *
 * it under the terms of the GNU General Public License as published by         *
 * the Free Software Foundation, either version 3 of the License, or            *
 * (at your option) any later version.                                          *
 *                                                                              *
 * This program is distributed in the hope that it will be useful,              *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of               *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                *
 * GNU General Public License for more details.                                 *
 *                                                                              *
 * You should have received a copy of the GNU General Public License            *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.        *
 *                                                                              *
 ********************************************************************************/

#ifndef MARKTHREADS_H
#define MARKTHREADS_H

#include <iostream>
#include <pthread.h>
#include <MarkMSGTypes.h>

class MarkThreads_t {
public:
	MarkThreads_t ();
	virtual ~MarkThreads_t ();
	int MarkThreadCreate(MarkMSGTypes_t* MTypes);
private:
	MarkThreads_t(const MarkThreads_t& copy);
	static	void *MThreadFunction(MarkMSGTypes_t* MTypes);
	pthread_t Thread;
	pthread_attr_t ThreadAtr;
};





#endif













































