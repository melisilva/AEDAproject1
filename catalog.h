//
// Created by Melissa Silva on 12/10/2020.
//

#ifndef AEDAPROJECT1_CATALOG_H
#define AEDAPROJECT1_CATALOG_H
#include "Member.h"
#include "nonMem.h"
#include "Book.h"
using namespace std;

class Catalog {
    vector<Book> books, lendings;
    vector <pair<Book, Member>> lendRequests, delays;

public:
    void addBook(string title, int edition);
    void removeBook(string title, int account);
    void showBooks(int account);
    void showBookWaitlist(int code);
    void showRating(int code);
    void lendBook(int code, int account);
    void receiveBook(int code, int account);
    void registerRating(int code);
    void registerLendRequest(string title, int nif);

};


#endif //AEDAPROJECT1_CATALOG_H
