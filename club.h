#ifndef AEDAPROJECT1_CLUB_H
#define AEDAPROJECT1_CLUB_H
#include "Book.h"
#include "Catalog.h"
#include "Member.h"
#include "nonMem.h"

class Club {
protected:
    Catalog catalog;
private:
    std::vector<Member*> members;
public:
    Club(Catalog catalog, std::vector<Member*> members);
    void addMember(); //pede o nome e NIF e depois os livros;
    void removeMember(int nif);
    void chargeDelay(int nif, int balance, Book book,int delayPrice);
    void chargeFee(int nif, int balance,Book book);
    void showMembers();
    void showLendings();
    void showDelays();
    void showLendRequests();
};


#endif //AEDAPROJECT1_CLUB_H