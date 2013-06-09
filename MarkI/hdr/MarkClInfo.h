/********************************************************************************
 * MarkClInfo.h                                                                     *
 * Copyright (C) 2011-09-14 Andreev Slava                                       *
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

#ifndef MARKCLINFO_H
#define MARKCLINFO_H

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class MarkClInfo_t {
public:
	MarkClInfo_t();
	virtual ~MarkClInfo_t();
	
	unsigned int Get_MCoreNumber() const;
	unsigned long int Get_MFreeMemory() const;
	unsigned long int Get_MTotalMemory() const;
	unsigned long int Get_MCPUFrequency() const;
	unsigned int Get_MUpTime() const;
	string Get_MGuid() const;
	void MInitClientInfo();

private:
	unsigned int MarkGetCoreNumber();
	unsigned long int MarkGetFreeMemory();
	unsigned long int MarkGetCPUFrequency();
	unsigned long int MarkGetTotalMemory();
	unsigned int MarkGetUpTime();
	string MarkGetGuid();

private:
	string MGuid;
	unsigned int MCoreNumber;
	unsigned long int MFreeMemory;
	unsigned long int MCPUFrequency;
	unsigned long int MTotalMemory;
	unsigned int MUpTime;

};

#endif 
