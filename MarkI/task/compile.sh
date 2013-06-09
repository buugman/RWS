#!/bin/sh

gcc -c -g -fPIC -Wall -pedantic Task.c -o Task.o
gcc -shared -g -ldl Task.o -o libTask.so
