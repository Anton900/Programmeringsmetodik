#include "rectangle.h"

rectangle::rectangle(std::string color, double height, double width) : shape(color), height(height), width(width) {}

double rectangle::get_area()
{
    return height * width;
}

std::string rectangle::get_shape_type()
{
    return "rectangle";
}

void rectangle::setWidth(double width)
{
    this->width = width;
};

double rectangle::getWidth()
{
    return width;
};

void rectangle::setHeight(double heigth)
{
    this->height = height;
};

double rectangle::getHeight()
{
    return height;
};