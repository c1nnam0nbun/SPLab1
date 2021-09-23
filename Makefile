CC = g++
CFLAGS = -c -Wall
all: clear lab1

lab1: main.o taxi.o
	$(CC) main.o taxi.o -o lab1

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

taxi.o: taxi.cpp
	$(CC) $(CFLAGS) taxi.cpp

clean: 
	rm -rf *.o lab1
