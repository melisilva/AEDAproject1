#ifndef AEDAPROJECT1_CATALOG_H
#define AEDAPROJECT1_CATALOG_H
#include "member.h"
#include "nonMem.h"
#include "book.h"
#include <vector>
using namespace std;

class Catalog{
protected:    
    vector<Book> books;
public:
    Catalog();
    Catalog(vector<Book> books);
    void addBook(Book book, int edition);
    void removeBook(string title, int balance);
    Book getBook(int code, string name);
    void showBooks(); //shows every book that exists
    void showBookWaitlist(int code);
    void showRating(int code);
    void lendBook(int code, int balance);
    void receiveBook(int code, int balance);
    void registerRating(int code);
    void registerLendRequest(string title, int nif);
    int searchBook(int code);
    int searchBook(string name);
    int convertNameToCode(string name);
    void showBook(int code);

};


#endif //AEDAPROJECT1_CATALOG_H
