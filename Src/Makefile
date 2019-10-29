
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Transition.o State.o Alphabet.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o DFA2dot ${OBJS}

clean:
	rm -rf *.o *.txt DFA2dot
