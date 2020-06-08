#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle: public Figure {
private:
    float radius;
public:
    Circle(float radius);

    float getArea() const;

    float getPerimeter() const;

    void print() const;

    void drawFigure() const;
};

#endif // CIRCLE_H
