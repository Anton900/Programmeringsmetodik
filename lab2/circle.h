#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#define PI 3.14159265358979323846

class circle : public shape
{
public:
    circle(std::string color, double radius);
    double get_area() override;
    double get_radius();
    std::string get_shape_type() override;

protected:
    double radius;

private:
};

#endif