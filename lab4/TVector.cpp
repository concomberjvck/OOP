#include "TVector.h"
#include <stdlib.h>
#include "Figure.h"

const int INC = 1.5;

template <class T> TTVector<T>::TTVector(int VecCap){
    array = new std::shared_ptr<T> [VecCap];
    size = 0;
    capacity = VecCap;
}

template <class T> void TTVector<T>::ResizeVector(std::shared_ptr<T> *&array){
    capacity *= INC;
    std::shared_ptr<T> *tmp = new std::shared_ptr<T> [capacity];
    for(int i = 0; i < size; ++i){
        tmp[i] = array[i];
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    array = tmp;
    tmp = nullptr;
}

template <class T> void TTVector<T>::Push(std::shared_ptr<T> &temp){
    if(size == capacity) {
    ResizeVector(array);
    }
    array[size] = temp;
    ++size;
}

 template <class T> void TTVector<T>::Get(int index){
    array[index]->Print();
}

template <class T> void TTVector<T>::Delete(){
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

template <class T> void TTVector<T>::DeleteAll(){
    for(int i = 0; i < GetSize(); i++){
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    capacity = size = 0;
}

template <class T> TTVector<T>::~TTVector(){
    DeleteAll();
}

template <class T> int TTVector<T>::GetSize(){
    return size;
}



template <class T> std::ostream& operator<<(std::ostream& os, const TTVector<T>& vector){
    for(int i = 0; i < vector.size; ++i){
        vector.array[i]->Print();
    }
    return os;
}

template class TTVector<Figure>;
template std::ostream& operator<<(std::ostream& os, const TTVector<Figure>& vector);