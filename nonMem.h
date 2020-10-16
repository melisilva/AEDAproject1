#ifndef AEDAPROJECT1_NONMEM_H
#define AEDAPROJECT1_NONMEM_H
#include "Member.h"
#include "Club.h"

class Member;

class nonMem : public Member {
    vector<pair<int, string>> lendRequests;
    string name;
    int nif;
    float balance;

public:
    nonMem(string &name, int &nif);
    void showData(ofstream file) const;
    void updateData(ofstream file, string name, string account);
    bool showLendRequests() const;
    bool makeRequest(int code=0,string name="");
    int getNIF() const;
    string getName() const;
    float getBalance()const;
};


#endif //AEDAPROJECT1_NONMEM_H