#ifndef MAILBOX_H
#define MAILBOX_H

#include "email.h"
#include <vector>
#include <algorithm>

class mailbox
{
private:
    std::vector<email> emails;

public:
    mailbox() {}

    std::vector<email> read()
    {
        return emails;
    }

    void write(email e)
    {
        emails.push_back(e);
    }

    void sortWho()
    {
        std::sort(emails.begin(), emails.end(), compWhoDateSubject());
    }

    void sortDate()
    {
        std::sort(emails.begin(), emails.end(), compDateWhoSubject());
    }

    void sortSubject()
    {
        std::sort(emails.begin(), emails.end(), compSubjectWhoDate());
    }
};

#endif