#ifndef PROJETO_NONMEM_H
#define PROJETO_NONMEM_H
#include "members.h"


class nonMem : public members{
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
    vector<Book> lendRequests() const;
};


#endif //PROJETO_NONMEM_H
