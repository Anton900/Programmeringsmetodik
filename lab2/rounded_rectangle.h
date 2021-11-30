#ifndef ROUNDED_RECTANGLE_H
#define ROUNDED_RECTANGLE_H

#include "rectangle.h"

class rounded_rectangle : public rectangle
{
public:
    rounded_rectangle(std::string color, double height, double width, double corner_radius);
    double get_area() override;

protected:
    double corner_radius;
};

#endif