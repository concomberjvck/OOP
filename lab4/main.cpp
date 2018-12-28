#include <iostream>
#include <cstdlib>
#include "Figure.h"
#include "TVector.h"
#include <memory>

void navigate();

int main()
{
    int key;
    int index;
    int a = 0;
    int b = 0;
    int c = 0;
    std::shared_ptr<Figure> tri;
    TTVector<Figure> vector(20);
    do{
        navigate();
        std::cin >> key;
        switch(key){
            case 1:
                std::cout << "Введите стороны треугольника" << std::endl;
                std::cin >> a >> b >> c ;
                tri = std::shared_ptr<Figure>(new Triangle(a, b, c));
                vector.Push(tri);
                break;
            case 2:
                std::cout << "Введите cтороны квадрата" << std::endl;
                std::cin >> a ;
                tri = std::shared_ptr<Figure>(new Foursquare(a));
                vector.Push(tri);
                break;
            case 3:
                std::cout << "Введите cтороны прямоугольника" << std::endl;
                std::cin >> a >> b ;
                tri = std::shared_ptr<Figure>(new Rectangle(a, b));
                vector.Push(tri);
                break;
            case 4:
                std::cout << "Введите индекс фигуры" << std::endl;
                std::cin >> index ;
                if(index >= vector.GetSize()){
                    std::cout << "Такой фигуры не существует" << std::endl;
                } else {
                    vector.Get(index);
                }
                break;
            case 5:
                if(vector.GetSize() > 0){
                    vector.Delete();
                } else {
                    std::cout << "Такой фигуры не существует" << std::endl;
                }
                break;
            case 6:
                vector.~TTVector();
                key = 0;
                break;
            case 7:
                std::cout << vector << std::endl;
                break;
            case 0:
                break;
            default:
                std::cout << "Неизвестная команда" << std::endl;
                break;
        }
    } while(key);
    //std::cout << vector.GetSize() << std::endl;
    return 0;
}

void navigate() {
    std::cout << "Введите" << std::endl;
    std::cout << "1) Чтобы добавить треугольник." << std::endl;
    std::cout << "2) Чтобы добавить квадрат." << std::endl;
    std::cout << "3) Чтобы добавить прямоугольник." << std::endl;
    std::cout << "4) Чтобы получить фигуру." << std::endl;
    std::cout << "5) Чтобы удалить фигуру." << std::endl;
    std::cout << "6) Чтобы удалить все фигуры." << std::endl;
    std::cout << "7) Чтобы напечать массив." << std::endl;
    std::cout << "0) Выход" << std::endl;
}