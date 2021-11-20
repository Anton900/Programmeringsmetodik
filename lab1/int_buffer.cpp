#include "int_buffer.h"

// initialisering istället för tilldelning.
// eftersom om initialisering går fel så kommer objektet ej konstrukteras
int_buffer::int_buffer(size_t size)
    : buffer(new int[size]), buffer_end(buffer + size)
{
    // std::cout << "Default CTOR\n";
}

int_buffer::int_buffer(const int *source, size_t n)
    : int_buffer(n)
{
    // std::cout << "Copy CTOR\n";
    std::copy(source, source + n, buffer);
}

int_buffer::int_buffer(const int_buffer &rhs) : int_buffer(rhs.buffer, rhs.size())
{
    // std::cout << "what CTOR\n";
}

// ta över rhs och att rhs tar över mitt giltiga tillstånd (nullptr)
int_buffer::int_buffer(int_buffer &&rhs) : buffer(nullptr), buffer_end(nullptr)
{
    // std::cout << "Move CTOR\n";
    swap(rhs);
}

void int_buffer::swap(int_buffer &rhs)
{
    // std::cout << "swap\n";
    std::swap(this->buffer, rhs.buffer);
    std::swap(this->buffer_end, rhs.buffer_end);
}

size_t int_buffer::size() const
{
    // std::cout << "size return\n";
    return buffer_end - buffer;
}

int_buffer::~int_buffer()
{
    // std::cout << "DTOR\n";
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
    // std::cout << "in begin const\n";
    return buffer;
}
const int *int_buffer::end() const
{
    // std::cout << "in end const\n";
    return buffer_end;
}

void int_buffer::clear()
{
    buffer = nullptr;
}

// jag = annan
// copy assign
// idiom copy-swap
int_buffer &int_buffer::operator=(const int_buffer &rhs)
{
    // std::cout << "Copy assign operator\n";
    int_buffer copy = rhs;
    swap(copy);
    return *this;
}

// jag = temporär annan
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
    // std::cout << "[] operator\n";
    return buffer[index];
}

const int &int_buffer::operator[](size_t index) const
{
    // std::cout << "const [] operator\n";
    return buffer[index];
}