# Phantasy Queeny - Sega Genesis RPG
# Makefile for SGDK

GDK = $(GDK)
SRC = src/main.c

RES = res/resources.res

.PHONY: all clean

all: 
	$(MAKE) -f $(GDK)/makefile.gen

clean:
	$(MAKE) -f $(GDK)/makefile.gen clean

RESOURCES += res/resources.res
