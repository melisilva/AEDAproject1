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
    Club(); //done
    void addMember(); //done
    void removeMember(int nif); //done
    bool makeRequest(); //done
    int findMember(int nif); //done
    void chargeDelay(int nif, int balance, Book book,int delayPrice); //done
    void chargeFee(int nif, int balance,Book book); //done
    void showMembers(); //done
    void showBookWaitlist(int code);
    void retrieveData();
    bool isMember(int nif); //done
    void showLendings(); //done
    void showDelays(); //done
    void showLendRequests(); //done
    void saveData(); //done
};


#endif //AEDAPROJECT1_CLUB_H
