#include "TVector.h"
#include <stdlib.h>

const int INC = 1.5;

TVector::TVector(int VecCap){
    array = new std::shared_ptr<Figure> [VecCap];
    size = 0;
    capacity = VecCap;
}

void TVector::ResizeVector(std::shared_ptr<Figure> *&array){
    capacity *= INC;
    std::shared_ptr<Figure> *tmp = new std::shared_ptr<Figure> [capacity];
    for(int i = 0; i < size; ++i){
        tmp[i] = array[i];
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    array = tmp;
    tmp = nullptr;
}

void TVector::Push(std::shared_ptr<Figure> &temp){
    if(size == capacity) {
    ResizeVector(array);
    }
    array[size] = temp;
    ++size;
}

 void TVector::Get(int index){
    array[index]->Print();
}

void TVector::Delete(){
    //array[size]->~Figure();
    array[size] = nullptr;
    size--;
}

/*void TVector::Delete(int index){
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
}*/

void TVector::DeleteAll(){
    for(int i = 0; i < GetSize(); i++){
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    capacity = size = 0;
}

TVector::~TVector(){
    DeleteAll();
}

int TVector::GetSize(){
    return size;
}



std::ostream& operator<<(std::ostream& os, const TVector& vector){
    for(int i = 0; i < vector.size; ++i){
        os << *vector.array[i];
    }
    return os;
}