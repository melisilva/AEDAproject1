#ifndef AEDAPROJECT1_CLUB_H
#define AEDAPROJECT1_CLUB_H
#include "Book.h"
#include "Catalog.h"
#include "Member.h"
#include "nonMem.h"
using namespace std;

class Club {
    Catalog catalog;
    vector<Member> members;

public:

    void addMember(); //pede o nome e NIF e depois os livros;
    void removeMember();
    void chargeDelay(int nif, int account);
    void chargeFee(int nif, int account);
    void showMembers();
    void showLendings();
    void showDelays();
    void showLendRequests();
};


#endif //AEDAPROJECT1_CLUB_H
