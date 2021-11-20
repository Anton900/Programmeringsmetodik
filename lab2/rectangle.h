#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
public:
    rectangle();
    double get_area() override;

private:
    double height;
    double width;
};

#endif