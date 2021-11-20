#include "rounded_rectangle.h"
#define PI 3.14159265358979323846

rounded_rectangle::rounded_rectangle(std::string color, double height, double width, double corner_radius) : rectangle(color, height, width), corner_radius(corner_radius) {}

double rounded_rectangle::get_area()
{
    return (getHeight() * getWidth()) - (corner_radius * corner_radius) * (4 - PI);
}