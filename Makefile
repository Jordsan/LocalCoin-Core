CC=g++
CFLAGS= -g -Wall -Wextra -std=c++11 -Wno-sign-compare

csrc = $(wildcard *.cpp) \
       $(wildcard src/*.cpp) \
       $(wildcard include/*.hpp) \
       $(wildcard lib/*.hpp) \
       $(wildcard lib/*.cpp)

obj = $(csrc:.c=.o) 



localcoin: $(obj)
	$(CC) $^ $(CFLAGS) 