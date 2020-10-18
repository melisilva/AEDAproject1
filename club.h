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
    void beginningInfo();
    void addMember(); //done
    void removeMember(int nif); //done
    void addBook(); //done
    void removeBook(string title,string owner,int edition); 
    bool makeRequest(); //done
    bool makeLending();
    bool returnLending();
    int findMember(int nif); //done
    void chargeDelay(int nif, Book book,int delayp); //done
    void chargeFee(int nif,Book book); //done
    int calculateDelay(); //done
    void showMembers(); //done
    void showBookWaitlist(int code);
    void checkDelays();
    void retrieveData(); //done
    int isMember(int nif); //done
    int isnonMem(int nif); 
    void showLendings(); //done
    void showDelays(); //done
    void showLendRequests(); //done
    void saveData(); //done
};


#endif //AEDAPROJECT1_CLUB_H
