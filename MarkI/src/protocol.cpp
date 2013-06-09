/********************************************************************************
 * protocol.cpp                                                                     *
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

#include <protocol.h>
#include <memory.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include <sys/socket.h>


#define QLEN										32

using namespace std;

Protocol::Protocol():pse(NULL),ppe(NULL),phe(NULL),s(0),type(0),alen(0),asocket(0),portbase(0)
{
	memset(&sin,0,sizeof(sin));
	memset(&fsin,0,sizeof(fsin));
	errno = 0;
}

Protocol::~Protocol()
{

}

int Protocol::errexit(const char* format,...)
{
	va_list args;
  va_start(args, format);
  vfprintf(stderr,format,args);
  va_end(args);
  exit(1);

}
int Protocol::PassiveSocket(const char* service, const char* transport, int qlen)
{
	sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  
  if((pse = getservbyname(service, transport)))
     sin.sin_port = htons(ntohs((unsigned short)pse->s_port)+portbase);
  else if((sin.sin_port=htons((unsigned short)atoi(service))) == 0)
     errexit("can't get \"%s\" service entry\n",service);

  if((ppe = getprotobyname(transport)) == 0)
     errexit("can't get \"%s\" protocol entry\n", transport);

  if(strcmp(transport, "udp") == 0)
     type = SOCK_DGRAM;
  else
		type = SOCK_STREAM;

  s = socket(PF_INET, type, ppe->p_proto);
  
  if(s < 0)
    errexit("can't create socket: %s\n", strerror(errno));

  if(bind(s, (struct sockaddr *) &sin, sizeof(sin)) < 0)
    errexit("can't bind to %s port: %s\n", service, strerror(errno));

  if(type == SOCK_STREAM && listen(s,qlen) < 0)
    errexit("can't listen on %s port %s\n", service, strerror(errno));

  return s;
}

int Protocol::ConnectSocket(const char* host, const char* service, const char* transport)
{
	sin.sin_family = AF_INET;

  if((pse = getservbyname(service, transport)))
      sin.sin_port = pse->s_port;
  else if((sin.sin_port=htons((unsigned short)atoi(service))) == 0)
  	   errexit("can't get \"%s\" service entry\n", service);
  	
  if((phe = gethostbyname(host)))
      memcpy(&sin.sin_addr, phe->h_addr, phe->h_length);
  else if((sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE)
	   errexit("can't get \"%s\" host entry\n", host);
	

  if((ppe = getprotobyname(transport)) == 0)
      errexit("can't get \"%s\" protocol entry\n", transport);
  
  if(strcmp(transport,"udp") == 0)
      type = SOCK_DGRAM;
  else
      type = SOCK_STREAM;

  s = socket(PF_INET, type, ppe->p_proto);
 
  if(s<0)
  {

    errexit("can't create socket: %s\n",strerror(errno));
  }

  if(connect(s,(struct sockaddr*)&sin, sizeof(sin)) < 0)
  {
    errexit("can't connect to %s.%s: %s\n", host, service, strerror(errno)); 
  }
return s;
}

int Protocol::ConnectTCP(const char* host, const char* service)
{
	return Protocol::ConnectSocket(host, service, TCP);
}
int Protocol::ConnectUDP(const char* host, const char* service)
{
	return Protocol::ConnectSocket(host, service, UDP);
}

int Protocol::PassiveTCP(const char* service)
{
	return Protocol::PassiveSocket(service, TCP, 0);
}

int Protocol::PassiveUDP(const char* service)
{
	return Protocol::PassiveSocket(service, UDP, 0);
}


int Protocol::GetTCP(struct ServiceInfo *psv)
{

	alen = sizeof(fsin);
	asocket = accept(psv->sv_sock,(struct sockaddr*)&fsin, &alen);
	if(asocket < 0)
		errexit("accept: %s\n", strerror(errno));
	cout<<"Accept socket"<<endl;
return asocket;
}




















