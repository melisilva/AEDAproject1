#ifndef AEDAPROJECT1_CLUB_H
#define AEDAPROJECT1_CLUB_H
#include "Book.h"
#include "Catalog.h"
#include "Member.h"
#include "nonMem.h"
using namespace std;

class Club :public Book{
protected:
    Catalog catalog;
private:
    vector<Member> members;
public:
    void addMember(); //pede o nome e NIF e depois os livros;
    void removeMember(int nif);
    void chargeDelay(int nif, int balance,Book book,int delayp);
    void chargeFee(int nif, int balance,Book book);
    void showMembers();
    void showLendings();
    void showDelays();
    void showLendRequests();
};


#endif //AEDAPROJECT1_CLUB_H