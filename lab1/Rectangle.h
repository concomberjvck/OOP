#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Rectangle : public Figure {
    public:
    Rectangle();
    Rectangle(std::istream &is);
    Rectangle(size_t i, size_t j);
    Rectangle(const Rectangle& orig);
    double Square();
    void Print();
    virtual ~Rectangle();
    private:
    size_t side_a; size_t side_b;
};

#endif