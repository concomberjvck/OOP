#include <cmath>
#include <cstring>
#include <iostream>
#include "Rectangle.h"

#define PI 3.14159265

Octagon::Octagon() : Octagon(0)
{
}

Octagon::Octagon(int32_t s): side(s)
{
    //std::cout << "Octagon created: " << side << std::endl;
}

Octagon::Octagon(std::istream& is)
{
    std::cout << "Введите сторону: ";
    is >> side;
    if(side < 0) {
        std::cerr << "Ошибка: стороны должны быть больше 0." << std::endl;
    }
}

Octagon::Octagon(const Octagon& orig)
{
    side = orig.side;
}

double Octagon::Square()
{
    return (double)(5 * side * side / (4 * (double)tan(36 * (PI / 180))));
}

void Octagon::Print()
{
    std::cout << "Сторона а = " << side << " Сторона b =" << side - 1 << ", Тип: прямоугольник" << std::endl;
}

Octagon::~Octagon()
{
}

std::ostream& operator <<(std::ostream &os, const Octagon &obj)
{
    os << "(" << obj.side << ")," << "Тип прямоугольник" << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Octagon &obj)
{
    std::cout << "Введите сторону: ";
    is >> obj.side;
    return is;
}

bool Octagon::operator ==(const Octagon &obj) const
{
    return side == obj.side;
}


Octagon& Octagon::operator =(const Octagon &obj)
{
    if (&obj == this) {
        return *this;
    }

    side = obj.side;

    return *this;
}