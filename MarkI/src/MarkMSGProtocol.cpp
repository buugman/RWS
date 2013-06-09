/********************************************************************************
 * MarkMSGProtocol.cpp                                                                     *
 * Copyright (C) 2011-09-25 Andreev Slava                                       *
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
 
	#include <MarkMSGProtocol.h>
	#include <typeinfo>
	#include <iostream>
	#include <stdint.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/sendfile.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/socket.h>
	#include <sys/types.h>

using namespace std;

 MarkMSGProtocol_t::MarkMSGProtocol_t()
 {
     
 }
 
 MarkMSGProtocol_t::~MarkMSGProtocol_t()
 {
     
 }
 
 int MarkMSGProtocol_t::MarkSend(void* Data, char flag, const unsigned int fd)
 {
		switch(flag)
		{
			case 'i':
				MarkMSGProtocol_t::Send((const MarkClInfo_t*)Data, fd);
				break;
			case 'd':
				MarkMSGProtocol_t::Send((const MarkCalcData_t*)Data, fd);
				break;
			case 'm':
				MarkMSGProtocol_t::Send((const uintptr_t)Data, fd);
				break;
		}
		
	return 0;     
 }
 
 int MarkMSGProtocol_t::MarkRecive(void* Data, char flag, const unsigned int fd)
 {
		switch(flag)
		{ 
			case 'i':
				MarkMSGProtocol_t::Recive((const MarkClInfo_t*)Data, fd);
				break;
			case 'd':
				MarkMSGProtocol_t::Recive((const MarkCalcData_t*)Data, fd);
				break;
			case 'm':
				MarkMSGProtocol_t::Recive((const uintptr_t)Data, fd);
				break;
		}
		
	return 0;
 }
 
 int MarkMSGProtocol_t::Send(const MarkClInfo_t* MClientInfo, const unsigned int fd)
 {
		MarkMSGProtocol_t::MarkWriteBuf(fd,(void*)MClientInfo, sizeof(MarkClInfo_t));
     return 0;
 }
 
 int MarkMSGProtocol_t::Recive(const MarkClInfo_t* MClientInfo, const unsigned int fd)
 {
	MarkMSGProtocol_t::MarkReadBuf(fd,(void*)MClientInfo, sizeof(MarkClInfo_t));
    return 0;
 }
 
int MarkMSGProtocol_t::Send(const MarkCalcData_t* MData, const unsigned int fd)
{
	MarkMSGProtocol_t::MarkWriteBuf(fd,(void*)MData, sizeof(MarkCalcData_t));
	return 0;
}

int MarkMSGProtocol_t::Recive(const MarkCalcData_t* MData, const unsigned int fd)
{
	MarkMSGProtocol_t::MarkReadBuf(fd,(void*)MData, sizeof(MarkCalcData_t));
	return 0;
}

int MarkMSGProtocol_t::Send(const unsigned int MsgNum, const unsigned int fd)
{
	MarkMSGProtocol_t::MarkWriteBuf(fd, (void*)MsgNum, sizeof(unsigned int));
	return 0;
}

int MarkMSGProtocol_t::Recive(const unsigned int MsgNum, const unsigned int fd)
{
	MarkMSGProtocol_t::MarkReadBuf(fd,(void*)MsgNum, sizeof(unsigned int));
	return 0;
}

int MarkMSGProtocol_t::MarkSendData(string source, unsigned int fd)
{
    struct stat fst;
    off_t nsend, ns, filesize;

    unsigned int flfd = MarkOpenfd(source.c_str(), O_RDONLY, S_IRWXU | S_IRWXG);

    if (fstat(flfd, &fst) < 0)
        errexit("fstat TASKNAME: %s\n", strerror(errno));

    nsend = 0;
    filesize = fst.st_size;
    while (nsend < filesize) {

        if ((ns = sendfile(fd, flfd, NULL, filesize)) <= 0) {
            MarkClosefd(flfd);
            errexit("send error: %s\n", strerror(errno));
        } else {
            nsend += ns;
        }
    }
    close(flfd);
  
	return 0;
}

int MarkMSGProtocol_t::MarkReciveData(string destination, unsigned int fd)
{
    size_t nread;
    size_t nwrite;
    size_t nr;
    char pbuf[BUFSIZE + 1];

    nread = sizeof (pbuf);

    unsigned int flfd = MarkOpenfd(destination.c_str(), O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
    printf("Start new recive - %d\n", fd);

    while ((nr = recv(fd, pbuf, nread, 0)) > 0) {
        if (nr < nread) {
            nread = nr;
        }

        nwrite = MarkWriteBuf(flfd, pbuf, nread);
        if (nwrite != nread)
            errexit("nwrite != nread %s\n", strerror(errno));

    }
    MarkClosefd(flfd);


	return 0;
}




















