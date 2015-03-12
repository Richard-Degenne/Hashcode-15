CC=g++
CFLAGS=--std=c++11 -Wall
LDFLAGS=
SRCS=
OBJS=$(SRCS:.cpp=.o)

all: main.out
	./main.out

main.out: main.cpp $(OBJS)
	$(CC) $(LDFLAGS) main.cpp $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *.o main
