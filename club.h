#ifndef AEDAPROJECT1_CLUB_H
#define AEDAPROJECT1_CLUB_H
#include "catalog.h"
#include <fstream>
#include "people.h"
#include <vector>

class Club {
private:
    vector<Member> members;
    vector<tuple<int, string, int>> lendings, delays, lendRequests;
    Catalog catalog;
public:
    void addMember(); //pede o nome e NIF e depois os livros;
    void removeMember(int nif);
    bool makeRequest();
    int findMember(int nif);
    void chargeDelay(int nif, int balance, Book book,int delayPrice);
    void chargeFee(int nif, int balance,Book book);
    void showMembers();
    void showLendings();
    void showDelays();
    void showLendRequests();
    void saveData();
};


#endif //AEDAPROJECT1_CLUB_H
