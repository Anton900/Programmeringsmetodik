#include "rectangle.h"

rectangle::rectangle(std::string color, double height, double width) : shape(color), height(height), width(width) {}

double rectangle::get_area()
{
    return height * width;
}

void rectangle::set_width(double width)
{
    this->width = width;
};

double rectangle::get_width()
{
    return width;
};

void rectangle::set_height(double heigth)
{
    this->height = height;
};

double rectangle::get_height()
{
    return height;
};