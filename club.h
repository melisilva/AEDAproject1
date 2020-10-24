#ifndef AEDAPROJECT1_CLUB_H
#define AEDAPROJECT1_CLUB_H
#include "catalog.h"
#include "date.h"
#include <fstream>
#include "people.h"
#include <vector>
#include <stdio.h>

class Club {
private:
    vector<Member> members;
    vector<nonMem> nonmembers;
    vector<tuple<int, Date, int>> lendings, delays, lendRequests;
    Catalog catalog;
    Date today;
public:
    Club(); //done
    void run();
    void beginningInfo(); //done
    void help(); //done
    void showBooks(); //done
    void updatePerson(); //done
    void addMember(); //done
    void removeMember(int nif); //done
    void addBook(int nif); //done
    void registerLoss(); //done
    void removeBook(tuple<int, Date, int> lostBook); //done
    bool makeRequest(); //done
    bool makeLending(); //done
    bool returnLending(); //done
    void chargeFirstDelay(int nif, Book book); //done
    void chargeFee(int nif,Book book); //done, precisa ser usada
    int calculateDelay(Date date); //done
    void showMembers(); //done
    void showNonMembers(); //done
    void checkDelays(); //done
    void retrieveData(); //done, tem de checar delays
    int isMember(int nif); //done
    int isnonMem(int nif); //done
    void showLendings(); //done
    void showDelays(); //done
    void showLendRequests(); //done
    void saveData(); //done
};


#endif //AEDAPROJECT1_CLUB_H
