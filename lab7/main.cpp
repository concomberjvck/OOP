#include <iostream>
#include <memory>
#include <cstdlib>

#include "Figure.h"
#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;

void menu();

int main() {
    int key;
    int a = 0;
    int b = 0;
    int c = 0;

    std::shared_ptr<Figure> tri;
    TMyVector<TMyVector <Figure> > *vector = new TMyVector <TMyVector <Figure> > (1);

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
                tri = std::shared_ptr<Figure>(t);
                vector->SubPush(tri);
                break;
            case 2:
                cout << "Введите стороны прямоугольника" << endl;
                cin >> a >> b;
                r = new Rectangle(a, b);
                tri = std::shared_ptr<Figure>(r);
                vector->SubPush(tri);
                break;
            case 3:
                cout << "Введите стороны квадрата" << endl;
                cin >> a;
                f = new Foursquare(a);
                tri = std::shared_ptr<Figure>(f);
                vector->SubPush(tri);
                break;
            case 4:
                if(vector->GetSize() > 0) {
                    int gg;
                    cout << "Удалить по площади (1) или по типу (2)?" << endl;
                    cin >> gg;
                    if(gg == 1) {
                        cout << "Введите площадь: " << endl;
                        int s;
                        cin >> s;
                        vector->SDelete(s);
                    } else if(gg == 2) {
                        cout << "Введите тип фигуры: треугольник (1), прямоугольник (2), квадрат (3)." << endl;
                        int type;
                        cin >> type;
                        vector->TDelete(type);
                    } else {
                        cout << "Попробуйте ещё раз" << endl;
                    }
                } else {
                    cout << "Фигура не найдена" << endl;
                }
                break;
            case 5:
                vector->~TMyVector();
                key = 0;
                break;
            case 6:
                cout << *vector;
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
    std::cout << "Введите" << std::endl;
    std::cout << "1) Чтобы добавить треугольник." << std::endl;
    std::cout << "2) Чтобы добавить прямоугольник." << std::endl;
    std::cout << "3) Чтобы добавить квадрат." << std::endl;
 //   std::cout << "4) Чтобы получить фигуру." << std::endl;
    std::cout << "4) Чтобы удалить фигуру." << std::endl;
    std::cout << "5) Чтобы удалить все фигуры." << std::endl;
    std::cout << "6) Чтобы напечать массив." << std::endl;
   // std::cout << "8) Цикл 'for' с итератором" << std::endl;
    std::cout << "0) Выход" << std::endl;
}