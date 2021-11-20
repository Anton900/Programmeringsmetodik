#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
public:
    rectangle(std::string color, double height, double width);
    double get_area() override;

    void setWidth(double width);
    double getWidth();

    void setHeight(double heigth);
    double getHeight();

protected:
    double height;
    double width;
};

#endif