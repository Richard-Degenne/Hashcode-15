CC=g++
CFLAGS=-c --std=c++11 -Wall
LDFLAGS=
SRCS=Row.cpp Server.cpp Slot.cpp Datacenter.cpp
OBJS=$(SRCS:.cpp=.o)

all: main.out
	./main.out dc.in

main.out: main.cpp $(OBJS)
	$(CC) $(LDFLAGS) main.cpp $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *.o main
