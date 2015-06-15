CC=g++ -std=c++11
CFLAGS= -c -Wall
all: go

go: main.o  
	$(CC) main.o -o ss -lsfml-graphics -lsfml-window -lsfml-system 

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp


clean:
	rm -rf *o ss 

