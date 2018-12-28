#ifndef TALLOCATE_H
#define TALLOCATE_H
#include <cstdlib>

class TAllocate{
    public:

    TAllocate(size_t size, size_t count);// конструктор блока

    void *allocate(); // аллоцирование под запрос

    void deallocate(void *pointer); //возврат памяти

    bool free_blocks(); // проверка на свободные блоки

    virtual ~TAllocate(); //деструктор блока

    private:

    size_t _size; //размер выделенного
    size_t _count; // текущий размер

    char *_used_blocks; //используемые блоки
    void **_free_blocks;// свободные блоки

    size_t _free_count; //количество свободных
};


#endif 