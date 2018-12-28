#include <cstdlib>
#include "Triangle.h"
#include "Foursquare.h"
#include "Rectangle.h"

void navigate();

int main(int argc, char const *argv[]) {
    int key = 6;
    Figure *ptr;

    while(key != 0) {

        navigate();
        std::cin >> key;
        switch(key) {
            case 1 :
                std::cout << "Print side of Triangle" << std::endl;
                ptr = new Triangle(std::cin);
                std::cout << "Triangle:" << std::endl;

                break;
            case 2 :
                std::cout << "Print side of Foursquare" << std::endl;
                ptr = new Foursquare(std::cin);
                std::cout << "Foursquare:" << std::endl;

                break;
            case 3 :
                std::cout << "Print side of Rectangle" << std::endl;
                ptr = new Rectangle(std::cin);
                std::cout << "Rectangle:" << std::endl;

                break;

            default :
                if(key != 0) std::cout << "Wrong number!" << std::endl;
        }
        if(key != 0) {
                ptr->Print();
                std::cout << "Square:" << ptr->Square() << std::endl;
        }
    }

    delete ptr;
    return 0;
}

void navigate() {
    printf("Exit - 0\n");
    printf("Create Triangle - 1\n");
    printf("Create Foursquare - 2\n");
    printf("Create Rectangle - 3\n");
}