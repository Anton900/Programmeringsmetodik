#include <iostream>
#include <vector>
#include <memory>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "cylinder.h"
#include "parallelepiped.h"
#include "rounded_rectangle.h"

void get_data(shape **shapes, int size)
{

    int counter = shapes[0]->get_counter();
    double total_area = 0;

    // std::cout << "arr_size: " << size << "\n";
    // std::cout << "counter: " << counter << "\n";

    // bound check
    if (size > counter)
    {
        std::cout << "Error! Array larger then elements created.\n";
        return;
    }

    auto rec = dynamic_cast<rectangle *>(shapes[0]);
    auto cir = dynamic_cast<circle *>(shapes[1]);
    auto cyl = dynamic_cast<cylinder *>(shapes[2]);
    auto rr = dynamic_cast<rounded_rectangle *>(shapes[3]);
    auto pp = dynamic_cast<parallelepiped *>(shapes[4]);

    if (rec != nullptr)
        std::cout << typeid(rec).name() << " has area " << rec->get_area() << " and color " << rec->get_color() << "\n";
    if (cir != nullptr)
        std::cout << typeid(cir).name() << " has area " << cir->get_area() << " and color " << cir->get_color() << "\n";
    if (cyl != nullptr)
        std::cout << typeid(cyl).name() << " has area " << cyl->get_area() << " and color " << cyl->get_color() << "\n";
    if (rr != nullptr)
        std::cout << typeid(rr).name() << " has area " << rr->get_area() << " and color " << rr->get_color() << "\n";
    if (pp != nullptr)
        std::cout << typeid(pp).name() << " has area " << pp->get_area() << " and color " << pp->get_color() << "\n";

    for (int i = 0; i < size; i++)
    {
        double area = shapes[i]->get_area();
        total_area += area;
    }
    std::cout << "Total Area: " << total_area << "\n";
}

int main()
{
    shape *shapes[5];
    shapes[0] = new rectangle("blue", 20, 10);
    shapes[1] = new circle("green", 10);
    shapes[2] = new cylinder("orange", 10, 10);
    shapes[3] = new rounded_rectangle("yellow", 20, 10, 2);
    shapes[4] = new parallelepiped("purple", 2, 5, 9);

    int arr_size = sizeof(shapes) / sizeof(*shapes);

    get_data(shapes, arr_size);
}