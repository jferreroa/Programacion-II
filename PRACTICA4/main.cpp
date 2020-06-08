#include <iostream>
#include "figure.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include <vector>


int main(){
    std::vector <Figure*> vec;
    //Figure* a = new Circle(3);      vec.push_back(a);
    //Figure* b = new Square(4);      vec.push_back(b);
    //Figure* c = new Triangle(5);    vec.push_back(c);
    /*for(auto elem: vec){
        elem->print();
        elem->drawFigure();
    }*/



    int option;
    while (true) {
        std::cout << "Do you want to add a figure to the vector? \n";
        std::cout << "1.Yes\n2.No\n";
        std::cin>> option;
        if(option == 1){
            int a;
            std::cout << "What figure do you want to add?\n";
            std::cout << "1.Circle\n2.Triangle\n3.Square\n";
            std::cin >> a;

            Figure *fig;

            switch (a) {
            case 1:
                float rad;
                std::cout << "Enter the radius size: ";
                std::cin>>rad;
                fig = new Circle(rad);
                vec.push_back(fig);
                break;
            case 2:
                float len;
                std::cout << "Enter the side size : ";
                std::cin>>len;
                fig = new Triangle(len);
                vec.push_back(fig);
                break;
            case 3:
                float len2;
                std::cout << "Enter the side size : ";
                std::cin>>len2;
                fig = new Square(len2);
                vec.push_back(fig);
                break;
            }

        }else {
            int b;
            std::cout << "Do you want to exit or print the vector?\n";
            std::cout << "1.Exit\n2.Print Vector\n";
            std::cin>> b;
            switch (b) {
            case 1: return 0;
            case 2:
                for(auto elem: vec){
                    elem->print();
                    elem->drawFigure();
                }
                break;
            }

        }
    }



    return 0;
}
