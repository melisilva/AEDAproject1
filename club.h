#ifndef PROJETO_CLUB_H
#define PROJETO_CLUB_H
#include "book.h"
#include "catalog.h"
#include "members.h"
#inlcude "nonMem.h"
using namespace std;

class Club{
    Catalog catalog;
    vector<Members> members;

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



#endif //PROJETO_CLUB_H
