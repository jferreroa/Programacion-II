#include "triangle.h"


Triangle::Triangle(float sideLength): Figure{"Triangle"}
{
    this->sideLength = sideLength;
}

float Triangle::getHeight() const{
    return (sqrt(3)*sideLength/2);
}

float Triangle::getArea() const{
    float h = getHeight();
    return (sideLength * h / 2);
}

float Triangle::getPerimeter() const{
    return 3*sideLength;
}

void Triangle::print() const
{
    std::cout << getType() << " " << "Area: " << getArea() << " Perimeter: " << getPerimeter() <<
                 " Height: " << getHeight() << std::endl;
}

void Triangle::drawFigure() const{
    int o = 1;
    for(int a = 1;a <= sideLength; a++){
        for(int b= sideLength-1;b >= a; b--){
            std::cout << " ";
        }
        for(int c = 0; c < o; c++){
            std::cout << "*";
        }
        std::cout << std::endl;
        o=o+2;
    }
}
