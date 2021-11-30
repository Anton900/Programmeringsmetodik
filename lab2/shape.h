#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class shape
{
public:
    shape() = delete;
    shape(std::string color);
    virtual std::string get_color();
    virtual double get_area() = 0;
    int get_counter();

protected:
    std::string color;
    static int counter;
};

#endif