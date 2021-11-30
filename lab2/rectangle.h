#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
public:
    rectangle(std::string color, double height, double width);
    double get_area() override;

    void set_width(double width);
    double get_width();

    void set_height(double heigth);
    double get_height();

protected:
    double height;
    double width;
};

#endif