#ifndef AEDAPROJECT1_BOOK_H
#define AEDAPROJECT1_BOOK_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Book {
    int code, units, opinions = 0, sumRating = 0;
    float realRating, value;
    string title, author, category;
    bool state;

public:
    Book();
    Book(int code, string title, string author, string category);
    void calculateValue(int edition);
    void calculateRating(int rate);
    int getCode();
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
};


#endif //AEDAPROJECT1_BOOK_H
