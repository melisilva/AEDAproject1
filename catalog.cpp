#include "catalog.h"

void Catalog::addBook(Book book,int edition){
    book.calculateValue(edition);
    books.push_back(book);
}

void Catalog::removeBook(string title, int balance){
    unsigned todel=-1;
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==title){
            balance+=books[i].getValue();
            if(books[i].getUnits()!=1){
                books[i].deleteUnit(true);
            }
            else{ //note: going with the idea that if it's the last unit, we should just remove all book info from catalog (still not sure if that's the best course of action but we can change it afterwards)
                todel=i;
            }
        }
    }
    if(todel!=-1) {
        books.erase(books.begin() + todel);
    }
}

void Catalog::showRating(int code){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            cout<<"Book rating: "<<books[i].getRating()<<endl;
        }
    }
}

void Catalog::registerRating(int code){
    int rate;
    cout<<"Rank this book from 1 to 5: "<<endl;
    cin>>rate;
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
           books[i].calculateRating(rate);
        }
    }
}

void Catalog::showBooks(){
    for(unsigned int i=0;i<books.size();i++){
       books[i].showBook();
    }
}

bool Catalog::searchBook(int code){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            return true;
        }
    }
    return false;
}

bool Catalog::searchBook(string name){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==name){
            return true;
        }
    }
    return false;
}

int Catalog::convertnametocode(string name){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==name){
            return books[i].getCode();
        }
    }
}

void Catalog::showBook(int code){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            books[i].showBook();
        }
    }
}