/********************************************************************************
 * MarkIO.cpp                                                                     *
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
 
 #include <MarkIO.h>

using namespace std;

 MarkIO_t::MarkIO_t ():Mreadbytes(0),Mwritebytes(0), MarkIOBuffer(0),Mffd(0),Minfd(0),Moutfd(0)
 {
    memset(buffer,0,sizeof(BUFSIZE+1)); 
 }
 void MarkIO_t::errexit(const char* format,...)
{
	va_list args;
  va_start(args, format);
  vfprintf(stderr,format,args);
  va_end(args);
  exit(1);
}

 int MarkIO_t::MarkOpenfd(const char *filename, int flag, int access)
 {
	 Mffd = open(filename, flag, access);
	 if(Mffd == -1)
			errexit("can't open file: %s\n", strerror(errno));
		return Mffd;    
 }
 
 int MarkIO_t::MarkClosefd(unsigned int ffd)
 {
	 if(close(ffd) == -1)
		 errexit("can't close file: %s\n",strerror(errno));
     return 0;
}
 
 size_t MarkIO_t::MarkReadBuf(unsigned int rfd, void *buf, size_t bytes)
 {
	 Mreadbytes = read(rfd, buf, bytes);
	 if(Mreadbytes < 0)
		 errexit("can't read bytes: %s\n",strerror(errno));
   return Mreadbytes;
 }
 
 size_t MarkIO_t::MarkWriteBuf(unsigned int wfd, void *buf, size_t bytes)
 {
		 Mwritebytes = write(wfd,buf,bytes);
		 if(Mwritebytes < 0)
				errexit("can't write bytes: %s\n",strerror(errno));
     return Mwritebytes;
 }
 
 int MarkIO_t::MarkCopyfile(const char *filename, const char *destination)
 {
	MarkIOBuffer = BUFSIZE;
  
  Minfd = MarkOpenfd(filename, O_RDWR, S_IRWXU | S_IRWXG);
  Moutfd = MarkOpenfd(destination, O_WRONLY | O_CREAT,S_IRWXG | S_IRWXG);

  if(Minfd < 0 || Moutfd < 0)
    errexit("can't open file descriptors: %s\n",strerror(errno));

  while((Mreadbytes = MarkReadBuf(Minfd, buffer, MarkIOBuffer)) > 0)
  {
    if(Mreadbytes<MarkIOBuffer)
      MarkIOBuffer = Mreadbytes;
    
    Mwritebytes = MarkWriteBuf(Moutfd, buffer, MarkIOBuffer);
    
    if(Mwritebytes != Mreadbytes)
      errexit("wrbytes != rdbytes: %s\n",strerror(errno));  
  }

  MarkClosefd(Minfd);
  MarkClosefd(Moutfd);


			return 0; 
 }
 
 MarkIO_t::~MarkIO_t ()
 {
     
 }
  
