#ifndef AEDAPROJECT1_CATALOG_H
#define AEDAPROJECT1_CATALOG_H
#include "Member.h"
#include "nonMem.h"
#include "Book.h"

class Catalog {
    vector<Book> books, lendings;
    vector <pair<Book, Member>> lendRequests, delays;

public:
    void addBook(Book book,int edition);
    void removeBook(string title, int balance);
    void showBooks(); //shows every book that exists
    void showBookWaitlist(int code);
    void showRating(int code);
    void lendBook(int code, int balance);
    void receiveBook(int code, int balance);
    void registerRating(int code);
    void registerLendRequest(string title, int nif);
    bool searchBook(int code);
    bool searchBook(string name);
    int convertnametocode(string name);
    void showBook(int code);

};


#endif //AEDAPROJECT1_CATALOG_H
