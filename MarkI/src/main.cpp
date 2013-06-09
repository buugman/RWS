/********************************************************************************
 * main.cpp                                                                     *
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

#include <iostream>
#include <memory>
#include <protocol.h>
#include <MarkIO.h>
#include <MarkThreads.h>
#include <MarkClInfo.h>
#include <MarkMSGTypes.h>
#include <MarkCalcData.h>
#include <MarkMSGProtocol.h>
#include <MarkServer.h>


using namespace std;

typedef auto_ptr<MarkThreads_t> MarkThreadPtr;

int main(int argc, char *argv[])
{

MarkServer_t Serv;
Serv.MarkStartServer();
return 0;
}

