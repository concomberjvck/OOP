#include <iostream>
#include "Triangle.h"
#include "TVector.h"

void navigate();

int main()
{
    int key;
    int index;
    int a = 0;
    int b = 0;
    int c = 0;
    Triangle tmp;

    TVector vector(5);
    do{
        navigate();
        std::cin >> key;
        switch(key){
            case 1:
                std::cout << "Введите стороны треугольника" << std::endl;
                std::cin >> a >> b >> c ;
                tmp.SetSides(a, b, c);
                vector.Push(tmp);
                break;
            case 2:
                std::cout << "Введите индекс треугольника" << std::endl;
                std::cin >> index;
                if(index >= vector.GetSize()){
                    std::cout << "Треугольник не найден" << std::endl;
                } else {
                    std::cout << vector.Get(index) << std::endl;
                    std::cout << vector.Get(index).Square() << std::endl;
                }
                break;
            case 3:
                std::cout << "Введите индекс" << std::endl;
                std::cin >> index;
                vector.Delete(index);
                break;
            case 4:
                vector.~TVector();
                key = 0;
                break;
            case 5:
                std::cout << vector << std::endl;
                break;
            case 0:
                break;
            default:
                std::cout << "Неизвестная команда" << std::endl;
                break;
        }
    } while(key);
    return 0;
}

void navigate() {
    std::cout << "Введите" << std::endl;
    std::cout << "1) Чтобы добавить треугольник." << std::endl;
    std::cout << "2) Чтобы получить длины сторон и площадь треугольника" << std::endl;
    std::cout << "3) Чтобы удалить треугольник" << std::endl;
    std::cout << "4) Чтобы удалить все треугольники" << std::endl;
    std::cout << "5) Чтобы напечатать все треугольники" << std::endl;
    std::cout << "0) Выход" << std::endl;
}