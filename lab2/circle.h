#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "shape.h"

class circle : public shape
{
public:
    circle(std::string color, double radius);
    double get_area() override;
    double get_radius();

protected:
    double radius;

private:
};

#endif