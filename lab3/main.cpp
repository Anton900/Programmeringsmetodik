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

    std::cout << "----- SELL QUEUE -----\n";
    for (auto e : sell_queue)
    {
        std::cout << e;
    }
    std::cout << "\n";

    std::cout << "----- BUY QUEUE -----\n";
    for (auto e : buy_queue)
    {
        std::cout << e;
    }
    std::cout << "\n";
}