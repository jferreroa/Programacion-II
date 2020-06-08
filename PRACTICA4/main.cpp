#include <iostream>
#include "figure.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include <vector>


int main(){
    std::vector <Figure*> vec;
    Figure* a = new Circle(3);      vec.push_back(a);
    Figure* b = new Square(4);      vec.push_back(b);
    Figure* c = new Triangle(5);    vec.push_back(c);

    for(auto elem: vec){
        elem->print();
        elem->drawFigure();
    }
    return 0;
}
