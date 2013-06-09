/********************************************************************************
 * MarkServer.cpp                                                                     *
 * Copyright (C) 2011-09-21 Andreev Slava                                       *
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
 
#include <MarkServer.h>
#include <protocol.h>
#include <memory>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <string.h>
#include <MarkThreads.h>
#include <MarkMSGTypes.h>


using namespace std;

 MarkServer_t::MarkServer_t()
 {
 }
 
 MarkServer_t::~MarkServer_t()
 {
 }
 
 void MarkServer_t::MarkStartServer(void)
 {
		int fd, nfds;
		fd_set afds, rfds;
		Protocol MProto;
		MarkThreads_t MThread;
		MarkMSGTypes_t* MSGTypes = new MarkMSGTypes_t();
		nfds = 0;

		FD_ZERO(&afds);
		MProto.MSInfo.sv_name = (char*)SVPORT;
		MProto.MSInfo.sv_useTCP = TCP_SERV;
		MProto.MSInfo.sv_sock = MProto.PassiveTCP(MProto.MSInfo.sv_name);
		
		nfds = MAX(MProto.MSInfo.sv_sock+1,nfds);

		FD_SET(MProto.MSInfo.sv_sock,&afds);
		cout<<"Getting passive socket for server port - "<<MProto.MSInfo.sv_name<<endl;
	  
while(1)
{
	memcpy(&rfds, &afds, sizeof(rfds));
	if (select(nfds, &rfds, (fd_set *) 0, (fd_set *) 0, (struct timeval *) 0) < 0)
	{
		if(errno == EINTR)
			continue;
		MProto.errexit("select error: %s\n", strerror(errno));
	}

	for(fd = 0; fd<nfds;++fd)
	{
		if(FD_ISSET(fd, &rfds))
		{
			MSGTypes->MSet_Masocket(MProto.GetTCP(&(MProto.MSInfo)));/*Запуск потока*/
		
			MThread.MarkThreadCreate(MSGTypes);

		}
	}
}
}
 






















