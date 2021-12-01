#ifndef EMAIL_H
#define EMAIL_H

#include <string>

class email
{
private:
    std::string who;
    std::string date;
    std::string subject;

public:
    email(std::string who = "", std::string date = "", std::string subject = "") : who(who), date(date), subject(subject) {}

    friend std::ostream &operator<<(std::ostream &out, email e);
    friend struct compWhoDateSubject;
    friend struct compDateWhoSubject;
    friend struct compSubjectWhoDate;
};

std::ostream &operator<<(std::ostream &out, email e)
{
    return out << e.who << ", " << e.date << ", " << e.subject;
}

struct compWhoDateSubject
{
    bool operator()(email lhs, email rhs)
    {
        if (lhs.who == rhs.who)
        {
            if (lhs.date == rhs.date)
            {
                return lhs.subject < rhs.subject;
            }
            return lhs.date < rhs.date;
        }
        return lhs.who < rhs.who;
    }
};

struct compDateWhoSubject
{
    bool operator()(email lhs, email rhs)
    {
        if (lhs.date == rhs.date)
        {
            if (lhs.who == rhs.who)
            {
                return lhs.subject < rhs.subject;
            }
            return lhs.who < rhs.who;
        }
        return lhs.date < rhs.date;
    }
};

struct compSubjectWhoDate
{
    bool operator()(email lhs, email rhs)
    {
        if (lhs.subject == rhs.subject)
        {
            if (lhs.who == rhs.who)
            {
                return lhs.date < rhs.date;
            }
            return lhs.who < rhs.who;
        }
        return lhs.subject < rhs.subject;
    }
};

#endif