#ifndef PARALLElEPIPED_H
#define PARALLELEPIPED_H

#include "rectangle.h"

class parallelepiped : public rectangle
{
public:
    parallelepiped(std::string color, double height, double width, double length);
    double get_area() override;
    std::string get_shape_type() override;

protected:
    double length;
};

#endif