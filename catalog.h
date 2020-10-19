#ifndef AEDAPROJECT1_CATALOG_H
#define AEDAPROJECT1_CATALOG_H
#include "book.h"
#include <vector>
#include <iostream>
using namespace std;

class Catalog{
public:
    vector<Book> books;
    Catalog(); //done
    Catalog(vector<Book> books); //done
    void addBook(Book book); //done
    Book getBook(int code); //done
    void lendBook(int code, int nif);
    void receiveBook(int code, int nif);
    void registerComments(int code);
    void registerRating(int code); //done
    int searchBook(int code); //done
    bool searchBook(string name); //done
    void showBook(int code); //done
    void showBooks(); //done
    void updateCodes(); //done
};

#endif //AEDAPROJECT1_CATALOG_H
