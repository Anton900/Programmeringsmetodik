#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "person.h"

class PrintDoubleValue
{
public:
    void operator()(const double &value)
    {
        std::cout << value << " ";
    }
};

int main()
{
    Person arr[] = {{"dwayne", 40}, {"kevin", 35}, {"anna", 29}, {"kevin", 30}, {"jack", 60}, {"sara", 45}, {"adam", 14}};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    std::vector<Person> vec1(arr, arr + size);
    MyPrint myPrint;

    // 1
    std::cout << "\n----- 1 -----\n";
    std::cout << "Using the for_each algorithm to print the objects in the vector.\n";
    std::for_each(vec1.begin(), vec1.end(), myPrint);

    // 2
    std::cout << "\n----- 2 -----\n";
    std::cout << "Searching for the first Person that is over 30 years with the find_if algorithm.\n";
    double age = 30;
    Person personCompare("", 30);
    auto find = std::find_if(vec1.begin(), vec1.end(), [&personCompare](Person p)
                             {
                                 PersonAgeCompare comp;
                                 return comp(personCompare, p);
                             });
    myPrint(*find);

    // 3
    std::cout << "\n----- 3 -----\n";
    std::cout << "Searching for persons that share the same name and are adjacent to each other with the adjacent_find algorithm.\n";
    auto pair = std::adjacent_find(vec1.begin(), vec1.end());
    if (pair == vec1.end())
    {
        std::cout << "No persons were found\n";
    }
    else
    {
        std::cout << "Found person: ";
        myPrint(*pair);
    }

    // 4
    std::cout << "\n----- 4 -----\n";
    std::cout << "Comparing the array and vector containers to see if they're equal with the equal algorithm.\n";
    if (std::equal(vec1.begin(), vec1.end(), arr))
    {
        std::cout << "The containers are equal\n";
    }
    else
    {
        std::cout << "The containers are NOT equal.\n";
    }

    // 5
    std::cout << "\n----- 5 -----\n";
    std::cout << "Searching for a subsequence in vector 1 with the search algorithm.\n";
    int start = 1, end = 3;
    auto subsequence = std::search(vec1.begin(), vec1.end(), arr + start, arr + end);
    if (subsequence == vec1.begin())
    {
        std::cout << "No subsequence found\n";
    }
    else
    {
        for (int i = 0; i < end; i++)
        {
            myPrint(*subsequence);
            subsequence++;
        }
    }

    std::cout << "\n----- 6 -----\n";
    std::cout << "Calculate the mean of the persons ages using std::accumulate and MyBinOp.\n";
    auto mean = std::accumulate(vec1.begin(), vec1.end(), 0.0, MyBinOp(vec1.size()));
    std::cout << "mean: " << mean << "\n";

    // 7
    std::cout << "\n----- 7 -----\n";
    std::cout << "Fill in double vector 'vec2' with the age values from vec1 using std::transform.\n";
    std::vector<double> vec2(7);
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), MyUnOp());
    std::for_each(vec2.begin(), vec2.end(), PrintDoubleValue());
    std::cout << "\n";

    // 8
    std::cout << "\n----- 8 -----\n";
    std::cout << "Replacing all values in 'vec2' with new ones using the MyFunc function operator, using the mean calculated from 5.\n";
    MyFunc myFunc(mean);
    std::transform(vec2.begin(), vec2.end(), vec2.begin(), myFunc);
    std::for_each(vec2.begin(), vec2.end(), PrintDoubleValue());
    std::cout << "\n";

    // 9
    std::cout << "\n----- 9 -----\n";
    std::cout << "Sorting vec2 with std::sort.\n";
    std::sort(vec2.begin(), vec2.end());
    std::for_each(vec2.begin(), vec2.end(), PrintDoubleValue());
    std::cout << "\n";
}