#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class shape
{
public:
    shape(std::string color, double area);

    virtual std::string get_color();
    virtual double get_area();

protected:
    std::string color;
    double area;
};

#endif