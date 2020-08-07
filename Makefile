IDIR=include/
ODIR=src/

CC=gcc
CFLAGS=-I. -Wall -pthread -std=c99

_DEPS=camera.h command_io.h commands.h delay.h device_core.h devices.h hsserver.h inspection.h logs.h sensor.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=camera.c command_io.c devices.c hsserver.c inspection.c logs.c sensor.c
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hsserver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
