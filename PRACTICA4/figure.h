#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>

class Figure{
private:
    std::string type;

public:
    Figure(const std::string &type);

    virtual float getArea() const = 0;

    virtual float getPerimeter() const = 0;

    virtual void print() const = 0;

    virtual void drawFigure() const = 0;

    std::string getType() const;

    void setType(const std::string &tipo);

};

#endif // FIGURE_H
