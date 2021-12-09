#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
private:
    std::string name;
    double age;

public:
    Person(std::string name = "", double age = 0) : name(name), age(age) {}
    Person(const Person &p) : name(p.name), age(p.age) {}

    bool operator==(const Person lhs)
    {
        if (this->name == lhs.name)
        {
            return true;
        }
        return false;
    }

    double getAge()
    {
        return age;
    }

    std::string getName()
    {
        return name;
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &p)
    {
        return out << "[\"" << p.name << "\", \"" << p.age << "\"]";
    }

    friend class MyPrint;
    friend class PersonAgeCompare;
    friend class MyBinOp;
    friend class MyUnOp;
    friend Person operator+(Person &p1, Person &p2);
};

class MyPrint
{
public:
    void operator()(const Person &p)
    {
        std::cout << "{ " << p.name << ", " << p.age << " }\n";
    }
};

class PersonAgeCompare
{
public:
    bool operator()(Person &p1, Person &p2)
    {
        return p1.age < p2.age;
    }
};

class MyBinOp
{
private:
    int size;

public:
    MyBinOp(int size = 0) : size(size) {}
    double operator()(double d, Person &p2)
    {
        return d + p2.age / size;
    }
};

class MyFunc
{
public:
    double mean;

    MyFunc(double mean = 0) : mean(mean) {}

    double operator()(double d)
    {
        return d - mean;
    }
};

class MyUnOp
{
public:
    double operator()(Person &p)
    {
        return p.getAge();
    }
};

#endif