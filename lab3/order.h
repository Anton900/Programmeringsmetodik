#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

struct order
{
    order(std::string name = "", double price = 0) : name(name), price(price) {}
    std::string name;
    double price;

    // friend bool operator<(const order &s1, const order &s2);
};

// bool operator<(const order &s1, const order &s2)
// {
//     return s1.price < s2.price;
// }

std::ostream &operator<<(std::ostream &out, order o)
{
    return out << "{" << o.name << ", " << o.price << "}\n";
}

struct less_price
{
    bool operator()(order s1, order s2)
    {
        return s1.price < s2.price;
    }
};

#endif