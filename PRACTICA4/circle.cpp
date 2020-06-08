#include "circle.h"
#include <cmath>

Circle::Circle(float radius):Figure{"Circle"}
{
    this->radius = radius;
}

float Circle::getArea() const{
    return (3.14*radius*radius);
}

float Circle::getPerimeter() const{
    return (2*3.14*radius);
}

void Circle::print() const
{
    std::cout << getType() << " " << "Area: " << getArea() << " Perimeter: " << getPerimeter() << std::endl;
}

void Circle::drawFigure() const{
    float dist;
      // for horizontal movement
      for (int i = 0; i <= 2 * radius; i++) {
        // for vertical movement
        for (int j = 0; j <= 2 * radius; j++) {
          dist = sqrt((i - radius) * (i - radius) +(j - radius) * (j - radius));
          // dist should be in the range (radius - 0.5)
          // and (radius + 0.5) to print stars(*)
          if (dist > radius - 0.5 && dist < radius + 0.5) std::cout << "*";
          else std::cout << " ";
        }
       std::cout << std::endl;
      }
}
