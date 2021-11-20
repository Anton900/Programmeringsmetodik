#include "circle.h"
#include <iostream>
// #define PI 3.14159265358979323846

circle::circle(std::string color, double radius) : shape(color), radius(radius) {}

double circle::get_area()
{
    return PI * radius * radius;
}

double circle::get_radius()
{
    return radius;
}