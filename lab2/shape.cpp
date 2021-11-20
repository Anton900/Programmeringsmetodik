#include "shape.h"
#include <iostream>

int shape::counter = 0;

shape::shape(std::string color) : color(color)
{
    counter++;
}

std::string shape::get_color()
{
    return color;
}

int shape::get_counter()
{
    return counter;
}