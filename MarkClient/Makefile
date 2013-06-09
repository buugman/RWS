#/********************************************************************************
# * Makefile                                                                     *
# * Copyright (C) 2011-10-08 Andreev Slava                                       *
# *                                                                              *
# * Contact information:                                                         *
# *   Email  - buugman@gmail.com                                                 *      
# *   ICQ    - 460912209                                                         *
# *   Skype  - timebanditx                                                       * 
# *   WWW    - http://bungman.cyberblogger.ru/                                   *
# *                                                                              *
# * This program is free software: you can redistribute it and/or modify         *
# * it under the terms of the GNU General Public License as published by         *
# * the Free Software Foundation, either version 3 of the License, or            *
# * (at your option) any later version.                                          *
# *                                                                              *
# * This program is distributed in the hope that it will be useful,              *
# * but WITHOUT ANY WARRANTY; without even the implied warranty of               *
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                *
# * GNU General Public License for more details.                                 *
# *                                                                              *
# * You should have received a copy of the GNU General Public License            *
# * along with this program.  If not, see <http://www.gnu.org/licenses/>.        *
# *                                                                              *
# ********************************************************************************/


#Compiler
CC =g++

# Project directories
HDR=./hdr
SRC=./src
OBJ=./obj
LIB=./lib
BIN=./bin
LIBPROJECT = ../MarkI

# Build flags
CFLAGS = -c -g -fPIC  -Wall -pedantic
LFLAGS = -shared -g -ldl -o 
BFLAGS = -g -fPIC  -Wall -pedantic

#Build commands
CP = cp
MV = mv
CD = cd
MAKE = make

#Main target

all: makelib compile build

makelib:
	$(MAKE) -eC $(LIBPROJECT)	

compile: $(SRC)/MarkClient.cpp $(SRC)/main.cpp
	$(CC)	$(CFLAGS) -I$(HDR) $(SRC)/MarkClient.cpp -o $(OBJ)/MarkClient.o
	$(CC) $(CFLAGS) -I$(HDR) $(SRC)/main.cpp -o $(OBJ)/main.o 
build:
	$(CC) $(BFLAGS) -o $(BIN)/run $(OBJ)/MarkClient.o $(OBJ)/main.o -L$(LIB) -lMark -lpthread -lcrypto

clean:
	rm -rf $(BIN)/*
	rm -rf $(LIB)/*
	rm -rf $(OBJ)/*



