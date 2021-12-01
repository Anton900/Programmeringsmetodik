#ifndef PERSON_H
#define PERSON_H

#include <string>

class person
{
private:
    std::string name;
    double age;

public:
    person(std::string name = "", double age = 0) : name(name), age(age) {}

    bool operator==(const person lhs)
    {
        if (this->name == lhs.name)
            return true;
        return false;
    }

    friend class myPrint;
};

class myPrint
{
public:
    void operator()(const person &p)
    {
        std::cout << "{ " << p.name << ", " << p.age << " }\n";
    }
};

#endif