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
    void removeBook(string title, int balance,int edition); //done
    Book getBook(int code, string name); //done
    void showBooks(); //done
    void showRating(int code); //done
    void lendBook(int code, int nif);
    void receiveBook(int code, int nif);
    void registerRating(int code); //done
    int searchBook(int code); //done
    int searchBook(string name); //done
    int convertNameToCode(string name); //done
    void showBook(int code); //done

};

#endif //AEDAPROJECT1_CATALOG_H
