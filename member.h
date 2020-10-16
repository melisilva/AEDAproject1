#ifndef AEDAPROJECT1_MEMBER_H
#define AEDAPROJECT1_MEMBER_H
#include "book.h"
#include "club.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;


class Member {
protected:    
    vector<pair<int, string>> lendRequest, lendings;
    vector<Book*> books;
    string name;
    int nif;
    float balance;

public:
    Member();
    Member(string &name, int &nif, vector<Book*> &books);
    int findBook(string title)const;
    bool registerRequest(int code, string name);
    bool showLendRequests() const;
    void showData() const;
    void saveData();
    void retrieveData(ofstream file) const;
    void showLendings() const;
    void showBooks() const;
    void updateData(string &name, int balance);
    void renovateLending();
    int getNIF() const;
    string getName() const;
    vector<Book*> getBooks() const;
    float getBalance() const;
};

class nonMem : public Member {

public:
    nonMem(string &name, int &nif);
};



#endif //AEDAPROJECT1_MEMBER_H
