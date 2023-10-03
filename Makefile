.default: all

all: ts

clean: ts

clean_ts:
	rm -rf ppd *.o

ts: main.o VectorGen.o BruteForce.o FastOne.o FastTwo.o
	g++ -Wall -Werror -std=c++20 -g -O -o $@ $^	

%.o: %.cpp
	g++ -Wall -Werror -std=c++20 -g -O -c $^
