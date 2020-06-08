#include "square.h"



Square::Square(float sideLength): Figure{"Square"}
{
    this->sideLength = sideLength;
}

float Square::getArea() const{
    return sideLength*sideLength;
}

float Square::getPerimeter() const{
    return  4*sideLength;
}

void Square::print() const
{
    std::cout << getType() << " " << "Area: " << getArea() << " Perimeter: " << getPerimeter() <<
                 " Height: " << getHeight() << " Diagonal: "<< getDiagonal() << std::endl;
}

void Square::drawFigure() const
{
    int num = sideLength*sideLength;
    for (int i = 1; i < num + 1; i++){
        std::cout << "* ";
        if ((i%int(sideLength)) == 0){
            std::cout << " \n";
        }
    }
}


float Square::getDiagonal() const{
    float diag = 0;
    double lado1 = pow(sideLength,2);
    double lados = lado1*2;
    diag = sqrt(lados);
    return  diag;
}

float Square::getHeight() const{
    return sideLength;
}
