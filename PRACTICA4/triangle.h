#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include <cmath>

class Triangle: public Figure{   //equilateral triangle
private:
    float sideLength;
public:
    Triangle(float sideLength);

    float getHeight() const;

    float getArea() const;

    float getPerimeter() const;

    void print() const;

    void drawFigure() const;

};

#endif // TRIANGLE_H
