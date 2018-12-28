#include <iostream>
#include <cmath>
#include "Foursquare.h"

Foursquare::Foursquare() : Foursquare(0) { }

Foursquare::Foursquare(size_t i) : side_a(i) {
    std::cout << "Foursquare created:" << side_a << std::endl;
}

Foursquare::Foursquare(std::istream &is) {
    is >> side_a;
}

Foursquare::Foursquare(const Foursquare& orig) {
    std::cout << "Copy of Foursquare was created" << std::endl;
    side_a = orig.side_a;
}

double Foursquare::Square() {
    return side_a * side_a;
}

void Foursquare::Print() {
    std::cout << "a=" << side_a << std::endl;
}

Foursquare::~Foursquare() {
    std::cout << "Foursquare was deleted" << std::endl;
}