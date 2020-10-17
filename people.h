#ifndef AEDAPROJECT1_MEMBER_H
#define AEDAPROJECT1_MEMBER_H
#include "book.h"
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
    Member(); //done
    Member(string &name, int &nif, vector<Book*> &books); //done
    int findBook(string title)const; //done
    virtual bool registerRequest(int code, string date); //done
    bool showLendRequests() const; //done
    void showData() const; //done
    string getData(); //done
    void showLendings() const; //done
    void showBooks() const; //done
    void updateData(string &name, int balance);
    void renovateLending();
    int getNIF() const; //done
    string getName() const; //done
    vector<Book*> getBooks() const; //done
    float getBalance() const; //done
};

class nonMem : public Member {
private:
    vector<pair<int, string>> lendRequest;
public:
    nonMem(string &name, int &nif);
    bool registerRequest(int code, string date);
    bool showLendRequests()const;
};



#endif //AEDAPROJECT1_MEMBER_H
