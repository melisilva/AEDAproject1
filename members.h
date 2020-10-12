#ifndef PROJETO_MEMBERS_H
#define PROJETO_MEMBERS_H
#include "book.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Member{
    vector<Book> books, lendRequests, lendings;
    string name;
    int nif;
    float balance;

    public:
        Member(string name, int nif, vector<Book> books);
        void showData(ofstream file) const;
        void updateData(ofstream file, string name, string account);
        void showLendRequests() const;
        void makeRequest() const;
        void renovateRequest() const;
        int getNIF() const;
        int getAccount() const;
        string getName() const;
        vector<Book> getBooks() const;
        vector<Book> lendRequests() const;
};

#endif //PROJETO_MEMBERS_H
