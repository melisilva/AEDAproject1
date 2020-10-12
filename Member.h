#ifndef AEDAPROJECT1_MEMBER_H
#define AEDAPROJECT1_MEMBER_H
#include "Book.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>


class Member {
    vector<Book*> books, lendRequests, lendings;
    string name;
    int nif;
    float balance;

public:
    Member(string name, int nif, vector<Book*> books);
    void showData(ofstream file) const;
    void updateData(ofstream file, string name, string account);
    bool showLendRequests() const;
    bool makeRequest(int code, string name);
    void renovateRequest() const;
    int findBook(string title) const;
    int getNIF() const;
    float getBalance() const;
    string getName() const;
    vector<Book*> getBooks() const;
};


#endif //AEDAPROJECT1_MEMBER_H
