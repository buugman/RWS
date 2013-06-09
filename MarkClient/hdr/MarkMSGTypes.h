/********************************************************************************
 * MarkMSGTypes.h                                                                     *
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

#ifndef MARKMSGTYPES_H
#define MARKMSGTYPES_H

#include <MarkClInfo.h>
#include <MarkCalcData.h>
#include <MarkMSGProtocol.h>

using namespace std;

class MarkMSGTypes_t : public MarkMSGProtocol_t
{
public:
	MarkMSGTypes_t();
	virtual ~MarkMSGTypes_t();
	void MSet_Masocket(unsigned int value);
	unsigned int MGet_Masocket();
	enum  MarkClientMsg_t { GETMETASK, GETNEWPART, CLDONE, CLFAILURE, SHUTDOWN };
	MarkClInfo_t* MClientInformation;
	MarkCalcData_t* MSolvedData;
private:
	unsigned int Masocket;
	
};
#endif 












