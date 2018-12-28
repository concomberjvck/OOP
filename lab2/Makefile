all: prog

prog: main.o TVector.o Triangle.o
	g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -o prog main.o TVector.o Triangle.o

main.o: main.cpp
	g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -c main.cpp

Triangle.o: Triangle.cpp Triangle.h
	g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -c Triangle.cpp

TVector.o: TVector.cpp TVector.h
	g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -c TVector.cpp

clean:
		rm -rf *.o prog