#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class shape
{
public:
    shape();

    std::string get_color() const;
    std::string get_area() const;

private:
    std::string color;
};

#endif