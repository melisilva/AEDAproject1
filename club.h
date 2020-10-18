#ifndef AEDAPROJECT1_CLUB_H
#define AEDAPROJECT1_CLUB_H
#include "catalog.h"
#include <fstream>
#include "people.h"
#include "date.h"
#include <vector>

class Club {
private:
    vector<Member> members;
    vector<nonMem> nonmembers;
    vector<tuple<int, Date, int>> lendings, delays, lendRequests;
    Catalog catalog;
public:
    Club(); //done
    void run();
    void beginningInfo();
    void addMember(); //done
    void removeMember(int nif); //done
    void addBook();
    void removeBook();
    bool makeRequest(); //done
    bool makeLending();
    bool returnLending();
    int findMember(int nif); //done
    void chargeDelay(int nif, int balance, Book book,int delayp); //done
    void chargeFee(int nif, int balance,Book book); //done
    int calculateDelay();
    void showMembers(); //done
    void showBookWaitlist(int code);
    void checkDelays();
    void retrieveData();
    bool isMember(int nif); //done
    void showLendings(); //done
    void showDelays(); //done
    void showLendRequests(); //done
    void saveData(); //done
};


#endif //AEDAPROJECT1_CLUB_H
