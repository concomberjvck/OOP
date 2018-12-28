#ifndef TVECTOR_H
#define TVECTOR_H

#include "Figure.h"
#include "Triangle.h"
#include "Foursquare.h"
#include "Rectangle.h"
#include <memory>

class TVector{
public:
    TVector(int VecCap);
    void Push(std::shared_ptr<Figure> &temp);
    void Get(int index);
    void Delete();
    // void Delete(int index);
    friend std::ostream& operator<<(std::ostream& os, const TVector& vector);
    ~TVector();
    int GetSize();
    void DeleteAll();

private:
    void ResizeVector(std::shared_ptr<Figure> *&array);
    int size;
    int capacity;
    std::shared_ptr<Figure> *array;
};

#endif