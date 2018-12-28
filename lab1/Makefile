all: program

program: main.o Triangle.o Foursquare.o Rectangle.o
    g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -o program main.o Triangle.o Foursquare.o Rectangle.o

main.o: main.cpp
        g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -c main.cpp

Triangle.o: Triangle.cpp Triangle.h
        g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -c Triangle.cpp

Foursquare.o: Foursquare.cpp Foursquare.h
        g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -c Foursquare.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
        g++ -std=c++11 -pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -c Rectangle.cpp

clean:
		rm -rf *.o program