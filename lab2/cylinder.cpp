#include "cylinder.h"

cylinder::cylinder(std::string color, double radius, double height) : circle(color, radius), height(height) {}

double cylinder::get_area()
{
    return (2 * 3 * get_radius() * get_radius()) + height * (2 * 3 * get_radius());
}