#ifndef AEDAPROJECT1_NONMEM_H
#define AEDAPROJECT1_NONMEM_H
#include "Member.h"
#include "Club.h"

class nonMem : public Club{
    vector<pair<int, string>> lendRequest;
    string name;
    int nif, account;
    float balance;

public:
    void showData(ofstream file) const;
    void updateData(ofstream file, string name, string account);
    bool showLendRequests() const;
    bool makeRequest(int code=0,string name="");
    int getNIF() const;
    int getAccount() const;
    string getName() const;
};


#endif //AEDAPROJECT1_NONMEM_H
