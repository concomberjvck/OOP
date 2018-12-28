#ifndef TVECTOR_H
#define TVECTOR_H

#include "Triangle.h"

class TVector{
public:
    TVector(int VecCap);
    void Push(Triangle &temp);
    Triangle& Get(int index);
    void Delete();
    void Delete(int index);
    friend std::ostream& operator<<(std::ostream& os, const TVector& vector);
    ~TVector();
    int GetSize() const;
    //Triangle GetI(int i) const;

private:
    Triangle *ResizeVector(Triangle *array);
    int size;
    int capacity;
    Triangle *array;
};
#endif