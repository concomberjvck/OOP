#include "TVector.h"
#include <stdlib.h>

const int INC = 1.5;

TVector::TVector(int VecCap){
    array = (Triangle*)malloc(sizeof(Triangle) * VecCap);
    size = 0;
    capacity = VecCap;
}

Triangle *TVector::ResizeVector(Triangle *array){
    return (Triangle*)realloc(array, sizeof(Triangle) * INC * capacity);
}

void TVector::Push(Triangle &temp){
    if(size == capacity) {
        array = ResizeVector(array);
    }
    array[size] = temp;
    size++;
    capacity *= INC;
}

 Triangle& TVector::Get(int index){
    return array[index];
}

void TVector::Delete(){
    array[--size].~Triangle();
}

void TVector::Delete(int index){
    int i;
    int j;
    Triangle *temp = (Triangle*)malloc(sizeof(Triangle) * (size - 1));
    for(j = 0, i = 0; i < size; ++i){
        if(i != index){
            temp[j] = array[i];
            j++;
        }
    }
    free(array);
    array = temp;
    --size;
}

TVector::~TVector(){
    free(array);
    array = NULL;
    capacity = size = 0;
}

int TVector::GetSize() const{
    return this->size;
}
/*Triangle TVector::GetI(int i) const{
    return this->array[i];
}*/

std::ostream& operator<<(std::ostream& os, const TVector& vector){
    for(int i = 0; i < vector.size; ++i){
        os << vector.array[i];
    }
    return os;
}

