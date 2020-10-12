#include "Catalog.h"

void Catalog::addBook(string title, int edition,int code, string author){
    Book b1(code,title,author);
    b1.calculateValue(edition);
    books.push_back(b1);
}

void Catalog::removeBook(string title, int account){
    unsigned todel=-1;
    for(unsigned i=0;i<books.size();i++){
        if(books[i].getTitle()==title){
            account+=books[i].getValue();
            if(books[i].getUnits()!=1){
                books[i].deleteUnit(true);
            }
            else{ //note: going with the idea that if it's the last unit, we should just remove all book info from catalog (still not sure that's best course of action but we can change it afterwards)
                todel=i;
            }
        }
    }
    if(todel!=-1) {
        books.erase(books.begin() + todel);
    }
}
