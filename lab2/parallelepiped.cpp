#include "parallelepiped.h"

parallelepiped::parallelepiped(std::string color, double height, double width, double length) : rectangle(color, height, width), length(length) {}

double parallelepiped::get_area()
{
    return (2 * length * get_width()) + (2 * length * get_height()) + (2 * rectangle::get_area()); // surface area
}