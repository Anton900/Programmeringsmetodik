#include "cylinder.h"

cylinder::cylinder(std::string color, double radius, double height) : circle(color, radius), height(height) {}

double cylinder::get_area()
{
    return (2 * circle::get_area() + height * (2 * M_PI * get_radius()));
}