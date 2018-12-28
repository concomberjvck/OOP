#include <iostream>
#include <memory>
#include <cstdlib>

#include "Figure.h"
#include "Vector.h"
#include "TAllocationBlock.h"

using std::cin;
using std::cout;
using std::endl;

void menu();

int main() {
    int key;
    int index;
    int a = 0;
    int b = 0;
    int c = 0;

    std::shared_ptr<Figure> tri;
    // TMyVector <Figure> vector(5);
    TMyVector<Figure> *vector = new TMyVector <Figure> (10);
    Triangle *t = nullptr;
    Rectangle *r = nullptr;
    Foursquare *f = nullptr;
    do {
        menu();
        cin >> key;
        switch(key) {
            case 1:
                cout << "Введите стороны треугольника:" << endl;
                cin >> a >> b >> c;
                t = new Triangle(a, b, c);
                // tri = std::shared_ptr<Figure>(new Triangle(a, b ,c)); // Без доп указателя
                tri = std::shared_ptr<Figure>(t);
                vector->Push(tri);
                break;
            case 2:
                cout << "Введите стороны прямоугольника:" << endl;
                cin >> a >> b;
                r = new Rectangle(a, b);
                tri = std::shared_ptr<Figure>(r);
                // tri = std::shared_ptr<Figure>(new Rectangle(a, b)); // Без доп указателя
                vector->Push(tri);
                break;
            case 3:
                cout << "Введите сторону квадрата:" << endl;
                cin >> a;
                f = new Foursquare(a);
                tri = std::shared_ptr<Figure>(f);
                // tri = std::shared_ptr<Figure>(new Foursquare(a)); // Без доп указателя
                vector->Push(tri);
                break;
            case 4:
                cout << "Введите индекс фигуры" << endl;
                cin >> index;
                if(index >= vector->GetSize()) {
                    cout << "Фигура не найдена" << endl;
                } else {
                        vector->Get(index);
                }
                break;
            case 5:
                if(vector->GetSize() > 0) {
                    vector->Delete();
                } else {
                    cout << "Фигура не найдена" << endl;
                }
                break;
            case 6:
                vector->~TMyVector();
                key = 0;
                break;
            case 7:
                cout << *vector;
                break;
            case 8:
                vector->MySort(0, vector->GetSize() - 1);
                for(auto i : *vector) {
                    (*i).Print();
                }
                break;
            case 9:
                vector->Quicksort_parallel(0, vector->GetSize() - 1);
                for(auto i : *vector) {
                    (*i).Print();
                }
                break;
            case 0:
                break;
            default:
                cout << "Неизвестная команда" << endl;
                break;
        }
    } while(key);
    delete vector;
    return 0;
}

void menu() {
    cout << "Введите" << endl;
    cout << "1) Чтобы добавить треугольник." << endl;
    cout << "2) Чтобы добавить прямоугольник." << endl;
    cout << "3) Чтобы добавить квадрат." << endl;
    cout << "4) Чтобы получить фигуру." << endl;
    cout << "5) Чтобы удалить фигуру." << endl;
    cout << "6) Чтобы удалить все фигуры." << endl;
    cout << "7) Чтобы напечать массив." << endl;
    cout << "8) Напечатать массив при помощи итератора и быстрой сортировки" << endl;
    cout << "9) Напечатать массив при помощи итератора и параллельной сортировки" << endl;
    cout << "0) Выход" << endl;

}