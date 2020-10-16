#ifndef AEDAPROJECT1_MEMBER_H
#define AEDAPROJECT1_MEMBER_H
#include "book.h"
#include "Club.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;


class Member :public Club {
    vector<pair<Book*, string>> lendings, lendRequests;
    vector<pair<int, string>> lendRequest;
    vector<Book*> books;
    string name;
    int nif;
    float balance;

public:
    Member(string &name, int &nif, vector<Book*> &books);
    int findBook(string title)const;
    bool makeRequest(int code = 0, string name = "");
    bool showLendRequests() const;
    void showData() const;
    void saveData() const;
    void retrieveData(ofstream file) const;
    void showLendings() const;
    void showBooks() const;
    void updateData(string &name, int balance);
    void renovateLending() const;
    int getNIF() const;
    string getName() const;
    vector<Book*> getBooks() const;
    float getBalance() const;
};


#endif //AEDAPROJECT1_MEMBER_H
