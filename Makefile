CC = gcc
CFLAGS = -I.
DEPS = main.c 
CDEPS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

default: main.o build/
	$(CC) -o build/demo main.o $(CDEPS)
	cp -r res build/

build/:
	mkdir build

main.o: main.c
	$(CC) main.c -c -o main.o
