#ifndef PROJETO_CATALOG_H
#define PROJETO_CATALOG_H
#include "members.h"
#include "nonMem.h"
#include "book.h"

class Catalog{
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
    void registerLendRequest(string title, int account);

};

#endif //PROJETO_CATALOG_H
