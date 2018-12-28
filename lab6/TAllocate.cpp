#include "TAllocate.h"
#include "iostream"

TAllocate::TAllocate(size_t size, size_t count):_size(size),_count(count){
    _used_blocks = (char*)malloc(_size*_count);
    _free_blocks = (void**)malloc(sizeof(void*) * _count);

    for(size_t i = 0; i < _count; i++) _free_blocks[i] = _used_blocks+i*_size;
    _free_count = count;
    std::cout << "Allocator: Память инициализирована" << std::endl;
}

void *TAllocate::allocate() {
    void *result = nullptr;

    if(_free_count > 0) { 
        result = _free_blocks[_free_count-1];
        _free_count--;
        std::cout << "Allocator: Выделено " << (_count-_free_count) <<
        " из " << _count << std::endl;
    } else {
        std::cout << "Allocator: Нет памяти" << std::endl;
    }
    return result;
}

void TAllocate::deallocate(void *pointer) {
    std::cout << "Allocator: Возвращение памяти "<< std::endl;
    _free_blocks[_free_count] = pointer;
    _free_count ++;
}

bool TAllocate::free_blocks() {
    return _free_count>0;
}

TAllocate::~TAllocate() {
    if(_free_count<_count) {
        std::cout << "Allocator: Утечка памяти" << std::endl;
    } else {
        std::cout << "Allocator: Память освобождена" << std::endl;
    }
    delete _free_blocks;
    delete _used_blocks;
}
