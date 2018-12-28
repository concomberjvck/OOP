#ifndef FOURSQUARE_H
#define FOURSQUARE_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Foursquare : public Figure{
    public:
    Foursquare();
    Foursquare(std::istream &is);
    Foursquare(size_t i);
    Foursquare(const Foursquare& orig);
    double Square() override;
    void Print() override;
    virtual ~Foursquare();
    private:
    size_t side_a;
};

#endif