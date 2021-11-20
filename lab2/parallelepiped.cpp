#include "parallelepiped.h"

parallelepiped::parallelepiped(std::string color, double height, double width, double length) : rectangle(color, height, width), length(length) {}

double parallelepiped::get_area()
{
    return (2 * length * getWidth()) * (2 * length * getHeight()) * (2 * getWidth() * getHeight()); // surface area
    // return (2 * length * getHeight()) * (2 * getWidth() * getHeight()); // lateral surface area
}