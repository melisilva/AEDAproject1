//
// Created by Melissa Silva on 12/10/2020.
//

#ifndef AEDAPROJECT1_NONMEM_H
#define AEDAPROJECT1_NONMEM_H
#include "Member.h"

class nonMem : public Member{
    vector<Book> lendRequests, lendings;
    string name;
    int nif, account;

public:
    void showData(ofstream file) const;
    void updateData(ofstream file, string name, string account);
    void showLendRequests() const;
    void makeRequest() const;
    int getNIF() const;
    int getAccount() const;
    string getName() const;
};


#endif //AEDAPROJECT1_NONMEM_H
