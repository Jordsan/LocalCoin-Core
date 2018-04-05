CC=g++
CFLAGS= -g -Wall -Wextra -std=c++11

csrc = $(wildcard *.cpp) \
       $(wildcard src/*.cpp) \
       $(wildcard include/*.hpp)

obj = $(csrc:.c=.o) 



localcoin: $(obj)
	$(CC) $^ $(CFLAGS) 