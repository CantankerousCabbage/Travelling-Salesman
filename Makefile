.default: all

all: ts

clean: ts

clean:
	rm -rf ppd *.o

ts: main.o Algorithm.o BruteForce.o FastOne.o FastTwo.o AGraphGen.o
	g++ -Wall -Werror -std=c++20 -g -O -o $@ $^	

%.o: %.cpp
	g++ -Wall -Werror -std=c++20 -g -O -c $^
