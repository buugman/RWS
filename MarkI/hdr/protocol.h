/********************************************************************************
 * protocol.h                                                                     *
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

#ifndef PROTOCOL_H
#define PROTOCOL_H 

#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <sys/param.h>
#include <sys/types.h>

#define QLEN								32
#define SVPORT          "7777"      /**Порт на котором работает сервер*/

#define UDP_SERV  0                
#define TCP_SERV  1
#define NOSOCK   -1
#define TCP				"tcp"
#define UDP				"udp"

using namespace std;

class Protocol
{
	private:
		struct ServiceInfo{
			char *sv_name;
			char sv_useTCP;
			int sv_sock;
			};
	public:
		ServiceInfo MSInfo;

	public:
		Protocol();
		~Protocol();
		int errexit(const char *format,...);
		int PassiveUDP(const char* service);
		int PassiveTCP(const char* service);
		int ConnectTCP(const char* host, const char* service);
		int ConnectUDP(const char* host, const char* service);
		int GetTCP(struct ServiceInfo *psv);
	private:
		int PassiveSocket(const char* service, const char* transport, int qlen);
		int ConnectSocket(const char* host, const char* service, const char* transport);

		struct servent *pse;
		struct protoent *ppe;
		struct sockaddr_in sin, fsin;
		struct hostent *phe;
		int s, type, errno;
		unsigned int alen, asocket;
		unsigned short portbase;
};

#endif 
