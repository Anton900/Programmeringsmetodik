#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "cylinder.h"
#include "parallelepiped.h"
#include "rounded_rectangle.h"

void get_data(shape **shapes)
{
    int size = 5;
    double totalArea = 0;
    // std::cout << "Shapes Memory Address (Function): " << &shapes << "\n";

    for (int i = 0; i < size; i++)
    {
        std::cout << "Shape " << i << " is color: " << shapes[i]->get_color() << "\n";
        double area = shapes[i]->get_area();
        totalArea += area;
    }
    std::cout << "Total Area: " << totalArea << "\n";
}
int main()
{

    shape *rectangle_ = new rectangle("blue", 20, 10);
    shape *circle_ = new circle("green", 10);
    shape *cylinder_ = new cylinder("orange", 10, 10);
    shape *rounded_rectangle_ = new rounded_rectangle("yellow", 10, 10, 20);
    shape *parallelepiped_ = new parallelepiped("purple", 10, 10, 20);

    shape *shapes[5] = {rectangle_, circle_, cylinder_, rounded_rectangle_, parallelepiped_};

    // std::cout << "Shapes Memory Address (Main): " << &shapes << "\n";

    get_data(shapes);
}