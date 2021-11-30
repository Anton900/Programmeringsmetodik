#include "rounded_rectangle.h"
#include "circle.h"
#include <math.h>

rounded_rectangle::rounded_rectangle(std::string color, double height, double width, double corner_radius) : rectangle(color, height, width), corner_radius(corner_radius) {}

double rounded_rectangle::get_area()
{
    rectangle corner_to_remove("blue", corner_radius, corner_radius);
    circle circle_to_add("blue", corner_radius);
    return (rectangle::get_area() + circle_to_add.get_area() - (4 * corner_to_remove.get_area()));
}