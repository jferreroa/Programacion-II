#ifndef SQUARE_H
#define SQUARE_H
#include <cmath>
#include "figure.h"
class Square: public Figure{
private:
    float sideLength;
public:
    Square(float sideLength);

    float getArea() const;

    float getPerimeter() const;

    void print() const;

    void drawFigure() const;

    float getDiagonal() const;

    float getHeight() const;
};

#endif // SQUARE_H
