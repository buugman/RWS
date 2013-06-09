/********************************************************************************
 * MarkMSGProtocol.h                                                            *
 * Copyright (C) 2011-09-12 Andreev Slava                                       *
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




#ifndef MARKMSGPROTOCOL_H
#define MARKMSGPROTOCOL_H

#include <iostream>
#include <cstring>
#include <MarkIO.h>
#include <MarkCalcData.h>
#include <MarkClInfo.h>

using namespace std;

class MarkMSGProtocol_t : public MarkIO_t 
{
public:
	MarkMSGProtocol_t();
	virtual ~MarkMSGProtocol_t();
	int MarkSend(void* Data, char flag, const unsigned int fd);
	int MarkRecive(void* Data, char flag, const unsigned int fd);
	int MarkSendData(string source, unsigned int fd);
	int MarkReciveData(string destination, unsigned int fd);
private:
	int Send(const MarkClInfo_t* MClientInfo, const unsigned int fd);
	int Send(const MarkCalcData_t* MData, const unsigned int fd);
	int Send(const unsigned int MsgNum, const unsigned int fd);
	int Recive(const unsigned int MsgNum, const unsigned int fd);
	int Recive(const MarkClInfo_t* MClientInfo, const unsigned int fd);
	int Recive(const MarkCalcData_t* MData, const unsigned int fd);
};

 
#endif 
