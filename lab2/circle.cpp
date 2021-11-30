#include "circle.h"

circle::circle(std::string color, double radius) : shape(color), radius(radius) {}

double circle::get_area()
{
    return M_PI * radius * radius;
}

double circle::get_radius()
{
    return radius;
}