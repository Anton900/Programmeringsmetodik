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

    std::cout << "\n-------------------- STD::SORT --------------------\n";
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
    std::cout << "std::sort (average): " << average << " seconds\n";
    totalTime = 0;

    std::cout << "\n-------------------- MERGE SORT --------------------\n";
    std::cout << "\nElements: " << size << " Samples: " << samples << "\n";

    for (int i = 0; i < samples; i++)
    {
        generate_random_values(buffer);
        auto start = high_resolution_clock::now();
        int_sorted merge = sort(buffer.begin(), buffer.end());
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

    // 1
    f(int_buffer(10));

    // 2
    int size = 5;
    int randArray[size];
    for (int i = 0; i < size; i++)
    {
        randArray[i] = rand() % 100;
    }

    int randArray2[size];
    for (int i = 0; i < size; i++)
    {
        randArray2[i] = rand() % 100;
    }

    int_sorted buffer1(randArray, size);
    int_sorted buffer2(randArray2, size);

    std::cout << "\nbuffer1: ";
    print_buffer(buffer1);
    std::cout << "buffer2: ";
    print_buffer(buffer2);

    std::cout << "\nBefore Insertion: ";
    print_buffer(buffer1);
    std::cout << "After insertion: ";
    buffer1.insert(10);
    buffer1.insert(70);
    buffer1.insert(5);
    print_buffer(buffer1);
    std::cout << "\n";

    buffer1 = buffer1.merge(buffer2);
    std::cout << "Buffer1 After Merge: ";
    print_buffer(buffer1);
    std::cout << "\n";

    auto buffer_sort = is_sorted(buffer1);
    if (buffer_sort)
        std::cout << "The buffer is sorted\n";
    else
        std::cout << "The buffer is NOT sorted\n";

    // 3
    calculate_sorts();
}