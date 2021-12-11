#include "p_queue.h"
#include "order.h"
#include <random>
#include <time.h>

int main()
{

    srand(time(0));

    p_queue<order, less_price> sell_queue;
    p_queue<order, less_price> buy_queue;

    int max = 30;
    int min = 15;

    for (int i = 0; i < 7; i++)
    {
        sell_queue.push(order("Erik Pendel", rand() % (max - min + 1) + min));
        sell_queue.push(order("Jarl Wallenburg", rand() % (max - min + 1) + min));
        sell_queue.push(order("Joakim von Anka", rand() % (max - min + 1) + min));
        buy_queue.push(order("Erik Pendel", rand() % (max - min + 1) + min));
        buy_queue.push(order("Jarl Wallenburg", rand() % (max - min + 1) + min));
        buy_queue.push(order("Joakim von Anka", rand() % (max - min + 1) + min));
    }

    auto sell = sell_queue.pop();

    while (!sell_queue.empty() && !buy_queue.empty())
    {
        auto buy = buy_queue.pop();
        if (buy.price > sell.price && buy.name != sell.name)
        {
            std::cout << buy.name << " just purchased for the price of " << buy.price << " from " << sell.name << "\n";
            sell = sell_queue.pop();
        }
    }
}