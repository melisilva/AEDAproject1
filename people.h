#ifndef AEDAPROJECT1_MEMBER_H
#define AEDAPROJECT1_MEMBER_H
#include "book.h"
#include "date.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;


class Member {
protected:
    vector<pair<int, Date>> lendRequest, lendings;
    vector<Book> books;
    string name;
    int nif;
    float balance;

public:
    Member(); //done
    Member(string &name, int &nif, vector<Book> &books, float &balance); //done
    void deleteRequest(int code);
    void addBalance(int quantity);
    virtual int findBook(int code) const; //done
    virtual string getData(); //done
    int getNIF() const; //done
    string getName() const; //done
    virtual vector<Book> getBooks() const; //done
    float getBalance() const; //done
    void minusBalance(int quantity);
    bool registerRequest(int code, Date date); //done
    bool registerLending(int code, Date date); //done
    void renovateLending(int code, Date date);
    virtual void removeBook(int index);
    void setName(string name);
    void setNif(int nif);
    bool showLendRequests() const; //done
    void showData() const; //done
    void showLendings() const; //done
    virtual void showBooks() const; //done
    void updateData(string &name, float quantity);
    void finishLending(int code, Date date);
    void finishRequest(int code);
    virtual void addBook(Book &book);
};

class nonMem : public Member {
public:
    nonMem(string &name, int &nif, float &balance); //done
    string getData();
};



#endif //AEDAPROJECT1_MEMBER_H
