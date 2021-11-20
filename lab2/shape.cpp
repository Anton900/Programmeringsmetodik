#include "shape.h"
#include <iostream>

shape::shape(std::string color) : color(color) {}

std::string shape::get_color()
{
    return color;
}