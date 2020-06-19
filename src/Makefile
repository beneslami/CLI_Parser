CC=gcc
CFLAGS= -g -Wall
INCLUDES=-I .
CLILIB=libcli.a
TARGET:exe ${CLILIB}

OBJ=serialize.o

exe:testapp.o ${CLILIB}
	@echo "Building final executable"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} testapp.o -o exe -L . -lcli

serialize.o:serialize.c
	@echo "Building serialize.o"
	@ ${CC} ${CFLAGS} -c ${INCLUDES} serialize.c -o serialize.o
