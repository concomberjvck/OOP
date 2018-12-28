#include <iostream>
#include <cmath>
#include <algorithm>
#include "Triangle.h"

Triangle::Triangle() : Triangle(0, 0, 0)
{
}

Triangle::Triangle(int32_t a, int32_t b, int32_t c): side_a(a), side_b(b), side_c(c)
{

    //std::cout << "Triangle created: " << small_base << ", " << big_base << ", " << l_side << ", " << r_side << std::endl;
}

Triangle::Triangle(std::istream &is)
{
    std::cout << "Введите сторону а: ";
    is >> side_a;
    std::cout << "Введите сторону b: ";
    is >> side_b;
    std::cout << "Введите сторону с: ";
    is >> side_c;
    if(side_a < 0 || side_b < 0 || side_c < 0) {
        std::cerr << "Ошибка: стороны должны быть больше 0." << std::endl;
    }
}

Triangle::Triangle(const Triangle &orig)
{
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_c = orig.side_c;
}

double Triangle::Square() {
    double p = double(side_a + side_b + side_c) / 2.0;
    return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));
}

void Triangle::Print()
{
    std::cout << "Сторона а = " << side_a << ", Сторона b = " << side_b << ", Сторона с = " <<  side_c << ", Тип: треугольник" << std::endl;
}

Triangle::~Triangle()
{
}

std::ostream& operator <<(std::ostream &os, const Triangle &obj)
{
    os << "(" << obj.side_a << " " << obj.side_b << " " << obj.side_c  << ")," << "Тип: треугольник" << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Triangle &obj)
{
    std::cout << "Введите сторону а: ";
    is >> obj.side_a;
    std::cout << "Введите сторону b: ";
    is >> obj.side_b;
    std::cout << "ВВедите сторону с: ";
    is >> obj.side_c;
    return is;
}

bool Triangle::operator ==(const Triangle &obj) const
{
    return side_a == obj.side_a && side_b == obj.side_b && side_c == obj.side_c;
}


Triangle& Triangle::operator =(const Triangle &obj)
{
    if (&obj == this) {
        return *this;
    }

    side_a = obj.side_a;
    side_b = obj.side_b;
    side_c = obj.side_c;
   

    return *this;
}


