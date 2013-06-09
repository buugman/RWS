/********************************************************************************
 * MarkCalcData.h                                                                     *
 * Copyright (C) 2011-09-15 Andreev Slava                                       *
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

#ifndef MARKCALCDATA_H
#define MARKCALCDATA_H

#include <iostream>
#include <string.h>
#include <unistd.h>

#define TASKPATH									"task/"

using namespace std;

class MarkCalcData_t {

public:
	MarkCalcData_t ();
	virtual ~MarkCalcData_t ();
	void  MarkCalculate(string execname); 
};

#endif 
