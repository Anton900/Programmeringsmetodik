// RAII, Merge och Merge-sort, Programmeringsmetodik
// Anton Wallin
// main.cpp, redigerad senast: 2021-11-24
// Utför de 3 punkterna i instruktionerna i labb anvisningen.
// 1. Skapar en buffer med size 10 med värden från 1 till 10
// 2. Skapar två int_buffer med slumpvalda tal och utför insert och merge funktioner.
// 3. genomför tids jämförelse mellan selection sort, standard sort och merge sort

#include <iostream>
#include <time.h>
#include <chrono>
#include <random>
#include <algorithm>

#include "int_buffer.h"
#include "int_sorted.h"

void selection_sort(int *begin, int *end)
{
    for (int *it = begin; it != end - 1; it++)
    {
        int *lowest = it;

        for (int *jt = it + 1; jt != end; jt++)
        {
            if (*jt < *lowest)
                lowest = jt;
        }

        std::swap(*it, *lowest);
    }
    // for(; begin != end; begin++)
    // {
    // 	auto min = std::min_element(begin, end);
    // 	std::swap(*begin, *min);
    // }
}

int_sorted sort(const int *begin, const int *end)
{
    if (begin == end)
    {
        return int_sorted(nullptr, 0);
    }
    if (begin == end - 1)
    {
        return int_sorted(begin, 1);
    }
    using std::ptrdiff_t;
    ptrdiff_t half = (end - begin) / 2; // pointer diff type
    const int *mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

void f(int_buffer buffer)
{
    int value = 1;
    for (int *i = buffer.begin(); i != buffer.end(); i++)
    {
        *i = value++;
    }
    for (const int *i = buffer.begin(); i != buffer.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    // Also possible to use the for-range syntax
    // for(auto e: buffer) {
    //     std::cout << e << " ";
    // }
    // std::cout << "\n";
}

void generate_random_values(int_buffer &buffer)
{
    for (int *i = buffer.begin(); i != buffer.end(); i++)
    {
        *i = rand() % 1000;
    }
}

bool is_sorted(int_sorted &sorted)
{
    const int *value = sorted.begin();
    int prev = *value;
    value++;
    while (value != sorted.end())
    {
        int next = *value;
        if (prev > next)
            return false;
        prev = *value;
        value++;
    }
    return true;
}

void print_buffer(int_sorted &sorted)
{
    const int *buffer_ptr = sorted.begin();
    while (buffer_ptr != sorted.end())
    {
        std::cout << *buffer_ptr << " ";
        buffer_ptr++;
    }
    std::cout << "\n";
}

double calculate_average(double total, int samples)
{
    double average = total / samples;
    return average;
}

void calculate_sorts()
{
    using namespace std::chrono;
    int size = 40000;
    int samples = 5;
    double totalTime = 0;

    int_buffer buffer(size);

    std::cout << "\n-------------------- SELECTION SORT --------------------\n";
    std::cout << "\nElements: " << size << " Samples: " << samples << "\n";

    for (int i = 0; i < samples; i++)
    {
        generate_random_values(buffer);
        auto start = high_resolution_clock::now();
        selection_sort(buffer.begin(), buffer.end());
        auto stop = high_resolution_clock::now();
        auto duration = std::chrono::duration<double>(stop - start);
        double time = duration.count();
        std::cout << "Time: " << time << "\n";
        totalTime += time;
    }
    std::cout << "Total time: " << totalTime << "\n";
    double average = calculate_average(totalTime, samples);
    std::cout << "Time Selection Sort (average): " << average << " seconds\n";
    totalTime = 0;

    std::cout << "\n-------------------- STANDARD SORT --------------------\n";
    std::cout << "\nElements: " << size << " Samples: " << samples << "\n";

    for (int i = 0; i < samples; i++)
    {
        generate_random_values(buffer);
        auto start = high_resolution_clock::now();
        std::sort(buffer.begin(), buffer.end());
        auto stop = high_resolution_clock::now();
        auto duration = std::chrono::duration<double>(stop - start);
        double time = duration.count();
        std::cout << "Time: " << time << "\n";
        totalTime += time;
    }
    std::cout << "Total time: " << totalTime << "\n";
    average = calculate_average(totalTime, samples);
    std::cout << "Standard Sort (average): " << average << " seconds\n";
    totalTime = 0;

    std::cout << "\n-------------------- MERGE SORT --------------------\n";
    std::cout << "\nElements: " << size << " Samples: " << samples << "\n";

    for (int i = 0; i < samples; i++)
    {
        generate_random_values(buffer);
        auto start = high_resolution_clock::now();
        int_sorted merge(buffer.begin(), buffer.size());
        auto stop = high_resolution_clock::now();
        auto duration = std::chrono::duration<double>(stop - start);
        double time = duration.count();
        std::cout << "Time: " << time << "\n";
        totalTime += time;
    }
    std::cout << "Total time: " << totalTime << "\n";
    average = calculate_average(totalTime, samples);
    std::cout << "Merge Sort (average): " << average << " seconds\n";
}

int main()
{

    srand(time(0));
//
//    // 1
      f(int_buffer(10));
//
//    // 2
      int_buffer buffer(5);

    generate_random_values(buffer);
    int_sorted sort_buffer1(buffer.begin(), buffer.size());

    generate_random_values(buffer);
    int_sorted sort_buffer2(buffer.begin(), buffer.size());

    std::cout << "\nsort_buffer1: ";
    print_buffer(sort_buffer1);
    std::cout << "sort_buffer2: ";
    print_buffer(sort_buffer2);

    std::cout << "\nBefore Insertion: ";
    print_buffer(sort_buffer1);
    std::cout << "After insertion: ";
    for(int i = 0; i < 5; i++){
        int random_value = rand() % 100;
        sort_buffer1.insert(random_value);
    }
//    sort_buffer1.insert(10);
//    sort_buffer1.insert(70);
//    sort_buffer1.insert(5);
    print_buffer(sort_buffer1);
    std::cout << "\n";

    sort_buffer1 = sort_buffer1.merge(sort_buffer2);
    std::cout << "Buffer1 After Merge: ";
    print_buffer(sort_buffer1);
    std::cout << "\n";

    auto buffer_sort = is_sorted(sort_buffer1);
    if (buffer_sort)
        std::cout << "The buffer is sorted\n";
    else
        std::cout << "The buffer is NOT sorted\n";

    // 3
    calculate_sorts();
}