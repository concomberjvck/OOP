prog : main.o Triangle.o Rectangle.o Foursquare.o TVector.o
	g++ main.o Triangle.o Rectangle.o Foursquare.o TVector.o -o prog -std=c++11
main.o : main.cpp TVector.h Foursquare.h Rectangle.h Triangle.h Figure.h
	g++ -std=c++11 -c main.cpp
Triangle.o : Triangle.cpp Triangle.h Figure.h
	g++ -std=c++11 -c Triangle.cpp
Rectangle.o : Rectangle.cpp Rectangle.h Figure.h
	g++ -std=c++11 -c Rectangle.cpp
Foursquare.o : Foursquare.cpp Foursquare.h Figure.h
	g++ -std=c++11 -c Foursquare.cpp
TVector.o : TVector.cpp TVector.h Foursquare.h Rectangle.h Triangle.h Figure.h
	g++ -std=c++11 -c TVector.cpp
clear :
	rm *.o prog