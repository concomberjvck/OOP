#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(0,0) { }

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
    std::cout << "Прямоугольник создан: " << side_a << "," << side_b << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
    is >> side_a;
    is >> side_b;
}

Rectangle::Rectangle(const Rectangle& orig) {
    std::cout << "Копия прямоугольника была создана" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
}

Rectangle *Rectangle::Get(){
    return this;
}

Rectangle& Rectangle::operator=(const Rectangle& right){
    if(this == &right)
    return *this;

    side_a = right.side_a;
    side_b = right.side_b;
    return *this;
}

void Rectangle::Print() {
    std::cout << "Это прямоугольник" << std::endl;
    std::cout << "a=" << side_a << ", b=" << side_b << ", c=" << side_a << ", d=" << side_b << std::endl;
}

Rectangle::~Rectangle() {
    std::cout << "Прямоугольник удалён" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj){
    os << "a=" << obj.side_a << "b=" << obj.side_b << ", c=" << obj.side_a << ", d=" << obj.side_b << std::endl;
    return os;
}