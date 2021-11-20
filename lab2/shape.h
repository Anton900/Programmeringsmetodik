#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class shape
{
public:
    shape();
    shape(std::string color);
    virtual std::string get_color();
    virtual double get_area() = 0;

protected:
    std::string color;
};

#endif