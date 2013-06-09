/********************************************************************************
 * MarkIO.h                                                                     *
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

#ifndef MARKIO_H
#define MARKIO_H

#include <iostream>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define		BUFSIZE								16384

class MarkIO_t {
public:
	MarkIO_t ();
	void errexit(const char* format, ...);
	int MarkOpenfd(const char *filename, int flag, int access);
	int MarkClosefd(unsigned int ffd);
	size_t MarkReadBuf(unsigned int rfd, void *buf, size_t bytes);
	size_t MarkWriteBuf(unsigned int wfd, void *buf, size_t bytes);
	int MarkCopyfile(const char *filename, const char *destination);
	virtual ~MarkIO_t ();

private:
	size_t Mreadbytes, Mwritebytes, MarkIOBuffer;
	int Mffd, Minfd, Moutfd;
	char buffer[BUFSIZE+1];
	
};

#endif 
