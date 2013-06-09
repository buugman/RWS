# Compiler
CC =gcc

# Project directories
SRC=./src
HDR=./hdr
OBJ=./obj
LIB=../CloudComputing/lib
BIN=./bin

# Build flags
CFLAGS = -c -g -fPIC  -Wall
LFLAGS = -shared -g -ldl -o 
BFLAGS = -g -fPIC  -Wall

#Build commands
CP = cp
MV = mv
CD = cd
MAKE = make

#Main target

all: compile build


compile: $(SRC)/ironman.c
	$(CC) $(CFLAGS) -I$(HDR) $(SRC)/ironman.c -o $(OBJ)/ironman.o 

build: 
	$(CC) $(BFLAGS) -o $(BIN)/iron $(OBJ)/ironman.o -L$(LIB) -lMLL -lpthread -lcrypto
#################################################################################


#################################################################################

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	


