#include "circle.h"

circle::circle(std::string color, double radius) : shape(color), radius(radius) {}

double circle::get_area()
{
    return PI * radius * radius;
}

double circle::get_radius()
{
    return radius;
}

std::string circle::get_shape_type()
{
    return "circle";
}