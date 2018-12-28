#include <iostream>
#include "Foursquare.h"

Foursquare::Foursquare() : Foursquare(0) { }

Foursquare::Foursquare(size_t i) : side_a(i) {
    std::cout << "Квадрат создан:" << side_a << std::endl;
}

Foursquare::Foursquare(std::istream &is) {
    is >> side_a;
}

Foursquare::Foursquare(const Foursquare& orig) {
    std::cout << "Копия квадрата создана" << std::endl;
    side_a = orig.side_a;
}

Foursquare& Foursquare::operator=(const Foursquare& right){
    if(this == &right)
    return *this;

    side_a = right.side_a;
    return *this;
}

void Foursquare::Print() {
    std::cout << "Это квадрат" << std::endl;
    std::cout << "a=" << side_a << std::endl;
}

Foursquare::~Foursquare() {
    std::cout << "Квадрат удалён" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Foursquare& obj){
    os << "a=" << obj.side_a << std::endl;
    return os;
}