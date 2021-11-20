#include "circle.h"
#define PI 3.14159265358979323846

double circle::get_area()
{
    area = PI * radius * radius;
    return area;
}