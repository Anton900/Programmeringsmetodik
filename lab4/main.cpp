#include <iostream>
#include "email.h"
#include "mailbox.h"

void show(std::vector<email> &emailVec)
{
    for (auto e : emailVec)
    {
        std::cout << "Email: " << e << "\n";
    }
    std::cout << "\n";
}

void show(email &email)
{
    std::cout << "Email: " << email << "\n";
}

int main()
{
    email email1("Dwayne Johnson", "2020-05-11", "A topic");
    email email2("Kevin Hart", "2019-05-25", "B topic");
    email email3("Dwayne Johnson", "2021-09-15", "C topic");
    email email4("Kevin Hart", "2021-03-16", "C topic");
    email email5("Jennifer Aniston", "2020-05-11", "A topic");

    mailbox mailbox;
    mailbox.write(email1);
    mailbox.write(email2);
    mailbox.write(email3);
    mailbox.write(email4);
    mailbox.write(email5);

    std::cout << "----- Sort Who -----\n";
    mailbox.sortWho();
    auto emails = mailbox.read();
    show(emails);
    std::cout << "----- Sort Date -----\n";
    mailbox.sortDate();
    emails = mailbox.read();
    show(emails);
    std::cout << "----- Sort Subject -----\n";
    mailbox.sortSubject();
    emails = mailbox.read();
    show(emails);
}