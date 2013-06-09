#Compiler
CXX =g++

# Project directories
HDR=./hdr
CLPRO=../MarkClient
SRC=./src
OBJ=./obj
LIB=./lib
BIN=./bin
# Build flags
CFLAGS = -c -g -fPIC  -Wall -pedantic
LFLAGS = -shared -g -ldl -o 
BFLAGS = -g -fPIC  -Wall
#Build commands
CP = cp
MV = mv
CD = cd
MAKE = make

#Main target

all: libcompile compile build

########################LIBRARY###############################

libcompile:
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/protocol.cpp -o $(OBJ)/protocol.o
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/MarkCalcData.cpp -o $(OBJ)/MarkCalcData.o
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/MarkMSGTypes.cpp -o $(OBJ)/MarkMSGTypes.o
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/MarkClInfo.cpp -o $(OBJ)/MarkClInfo.o
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/MarkMSGProtocol.cpp -o $(OBJ)/MarkMSGProtocol.o
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/MarkIO.cpp -o $(OBJ)/MarkIO.o
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/MarkThreads.cpp -o $(OBJ)/MarkThreads.o

	$(CXX) $(LFLAGS) $(LIB)/libMark.so $(OBJ)/*.o
	$(CP) $(HDR)/* $(CLPRO)/hdr
	$(CP) $(LIB)/* $(CLPRO)/lib

########################BUILD#################################

compile: $(SRC)/MarkServer.cpp $(SRC)/main.cpp
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/MarkServer.cpp -o $(OBJ)/MarkServer.o
	$(CXX) $(CFLAGS) -I$(HDR) $(SRC)/main.cpp -o $(OBJ)/main.o
build:
	$(CXX) $(BFLAGS) -o $(BIN)/run $(OBJ)/MarkServer.o $(OBJ)/main.o -L$(LIB) -lpthread -lMark -lcrypto 
clean:
	rm -rf $(OBJ)/*.o
	rm -rf $(BIN)/run
	rm -rf $(LIB)/libMark.so
