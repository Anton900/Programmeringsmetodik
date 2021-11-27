// RAII, Merge och Merge-sort, Programmeringsmetodik
// Anton Wallin
// int_sorted.cpp, redigerad senast: 2021-11-24
// Ser till att buffern alltid är sorterad med merge sort

#include "int_sorted.h"

int_sorted::int_sorted(const int *source, size_t size) : buffer(0)
{
    if (size > 1)
        buffer = sort(source, (source + size)).buffer;
    else
        buffer = int_buffer(source, size);
}

size_t int_sorted::size() const
{
    return buffer.size();
}

void int_sorted::insert(int value)
{
    int_sorted tmp(&value, 1);
    buffer = merge(tmp).buffer;
}

const int *int_sorted::begin() const
{
    return buffer.begin();
}
const int *int_sorted::end() const
{
    return buffer.end();
}

int_sorted int_sorted::sort(const int *begin, const int *end)
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

int_sorted int_sorted::merge(const int_sorted &merge_with) const
{
    int_buffer merge_buffer = merge_with.buffer;
    int_buffer result_buffer(size() + merge_with.size());

    const int *first_buffer_ptr = begin();
    const int *second_buffer_ptr = merge_buffer.begin();
    int *result_ptr = result_buffer.begin();

    while (first_buffer_ptr != end() && second_buffer_ptr != merge_buffer.end())
    {
        if (*first_buffer_ptr < *second_buffer_ptr)
        {
            *result_ptr = *first_buffer_ptr;
            result_ptr++;
            first_buffer_ptr++;
        }
        else
        {
            *result_ptr = *second_buffer_ptr;
            result_ptr++;
            second_buffer_ptr++;
        }
    }
    while (first_buffer_ptr != end())
    {
        *result_ptr = *first_buffer_ptr;
        result_ptr++;
        first_buffer_ptr++;
    }
    while (second_buffer_ptr != merge_buffer.end())
    {
        *result_ptr = *second_buffer_ptr;
        result_ptr++;
        second_buffer_ptr++;
    }

    int_sorted result(nullptr, 0);
    result.buffer = result_buffer;

    return result;
}