#ifndef AEDAPROJECT1_BOOK_H
#define AEDAPROJECT1_BOOK_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Book {
    int code, units, opinions=0,sumRating = 0;
    int edition;
    float realRating, value;
    string title, author, category, writ_ops;
    bool state;

public:
    Book();
    Book(int code, string title, string author, string category,int edition);
    void calculateValue();
    void calculateRating(int rate);
    int getCode();
    int getEdition();
    float getRating();
    string getTitle();
    bool getState();
    string getAuthor();
    string getCategory();
    float getValue();
    int getUnits();
    void deleteUnit(bool gonebook);
    void showBook();
    string getData();
    void addUnits();
};


#endif //AEDAPROJECT1_BOOK_H
