// RAII, Merge och Merge-sort, Programmeringsmetodik
// Anton Wallin
// int_buffer.cpp, redigerad senast: 2021-11-24
// Skapar en buffer för att hålla flyttal med RAII idiomet för att undvika minnesläckage.

#include "int_buffer.h"

int_buffer::int_buffer(size_t size)
        : buffer(new int[size]), buffer_end(buffer + size)
{
    // std::cout << "Parameterized CTOR\n";
}

int_buffer::int_buffer(const int *source, size_t n)
        : int_buffer(n)
{
    std::copy(source, source + n, buffer);
}

int_buffer::int_buffer(const int_buffer &rhs) : int_buffer(rhs.buffer, rhs.size())
{
    // std::cout << "Copy CTOR\n";
}

int_buffer::int_buffer(int_buffer &&rhs) : buffer(nullptr), buffer_end(nullptr)
{
    // std::cout << "Move CTOR\n";
    swap(rhs);
}

void int_buffer::swap(int_buffer &rhs)
{
    std::swap(this->buffer, rhs.buffer);
    std::swap(this->buffer_end, rhs.buffer_end);
}

size_t int_buffer::size() const
{
    return buffer_end - buffer;
}

int_buffer::~int_buffer()
{
    delete[] buffer;
}

int *int_buffer::begin()
{
    // std::cout << "in begin\n";
    return buffer;
}
int *int_buffer::end()
{
    // std::cout << "in end\n";
    return buffer_end;
}
const int *int_buffer::begin() const
{
    return buffer;
}
const int *int_buffer::end() const
{
    return buffer_end;
}

// copy assign
int_buffer &int_buffer::operator=(const int_buffer &rhs)
{
    // std::cout << "Copy assign operator\n";
    int_buffer copy = rhs;
    swap(copy);
    return *this;
}

// move assign
int_buffer &int_buffer::operator=(int_buffer &&rhs)
{
    // std::cout << "Move assign operator\n";
    swap(rhs);
    return *this;
}

// kompilatorn får välja mellan copy eller move
// int_buffer &int_buffer::operator=(int_buffer rhs)
// {
//     swap(rhs);
//     return *this;
// }

int &int_buffer::operator[](size_t index)
{
    return buffer[index];
}

const int &int_buffer::operator[](size_t index) const
{
    return buffer[index];
}