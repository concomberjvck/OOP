#ifndef TITER_H
#define TITER_H

#include <memory>
#include <iostream>
#include "TVector.h"

template <class T> class TIter{ // класс итератор 
    public:

    TIter(std::shared_ptr<T> *n){ // конструктор итератора
        ptr = n;
    }

    std::shared_ptr<T> operator * (){
        return *ptr;
    }

    std::shared_ptr<T> operator -> (){
        return ptr->GetValue();
    }

    void operator ++ (){
        ++ptr;
    }

    TIter operator ++ (int){
        TIter iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (TIter const& i){
        return ptr == i.ptr;
    }

    bool operator != (TIter const& i){
        return !(*this == i);
    }

    private:
    std::shared_ptr<T> *ptr;
};

#endif