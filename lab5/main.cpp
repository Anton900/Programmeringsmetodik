#include <iostream>
#include <vector>
#include <algorithm>
#include "person.h"

int main()
{
    person arr[] = {{"dwayne", 40}, {"kevin", 35}, {"anna", 29}};
    std::vector<person> vec(arr, arr + 3);

    std::for_each(vec.begin(), vec.end(), myPrint());
}