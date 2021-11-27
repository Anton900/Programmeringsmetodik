// RAII, Merge och Merge-sort, Programmeringsmetodik
// Anton Wallin
// int_sorted.h, redigerad senast: 2021-11-24

#ifndef INT_SORTED_H
#define INT_SORTED_H
#include <iostream>
#include "int_buffer.h"

class int_sorted
{
public:
    int_sorted(const int *source, size_t size);
    size_t size() const;
    void insert(int value);
    const int *begin() const;
    const int *end() const;
    int_sorted sort(const int *begin, const int *end);
    int_sorted merge(const int_sorted &merge_with) const;
    int *find() const;

private:
    int_buffer buffer;
};

#endif