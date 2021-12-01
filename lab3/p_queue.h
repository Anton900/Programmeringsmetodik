#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
template <typename T, typename Compare = std::less<T>>
class p_queue
{
private:
    std::vector<T> buffer;
    Compare comp;

public:
    p_queue() { buffer.reserve(10); }
    p_queue(std::initializer_list<T> source) : buffer(source.size())
    {
        std::copy(source.begin(), source.end(), buffer.begin());
        std::sort(buffer.begin(), buffer.end(), comp);
    }
    T pop()
    {
        auto ele = buffer.front();
        buffer.erase(buffer.begin());
        return ele;
    }
    void push(T e)
    {
        if (buffer.size() == buffer.capacity())
        {
            buffer.reserve(resize());
        }

        buffer.push_back(e);
        std::sort(buffer.begin(), buffer.end(), comp);
    }
    int size()
    {
        return buffer.size();
    }
    bool empty()
    {
        return buffer.empty();
    }
    size_t resize()
    {
        return 1.6 * buffer.capacity();
    }

    auto begin() const
    {
        return buffer.begin();
    }

    auto end() const
    {
        return buffer.end();
    }
};

#endif