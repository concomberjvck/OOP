#ifndef TVECTOR_H
#define TVECTOR_H

#include "Figure.h"
#include "Triangle.h"
#include "Foursquare.h"
#include "Rectangle.h"
#include <memory>

template <class T> class TTVector {
public:
    TTVector(int VecCap);
    void Push(std::shared_ptr<T> &temp);
    void Get(int index);
    void Delete();
    // void Delete(int index);
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TTVector<A>& vector);
    ~TTVector();
    int GetSize();
    void DeleteAll();

private:
    void ResizeVector(std::shared_ptr<T> *&array);
    int size;
    int capacity;
    std::shared_ptr<T> *array;
};

#endif