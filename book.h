#ifndef AEDAPROJECT1_BOOK_H
#define AEDAPROJECT1_BOOK_H

#include <string>
using namespace std;

class Book {
    int code, units, opinions=0,sumrating=0;
    float realrating, value;
    string title, author;
    bool state;

public:
    Book(int code, string title, string author);
    void calculateValue(int edition);
    void calculateRating(int rate);
    int getCode();
    float getRating();
    string getTitle();
    bool getState();
    string getAuthor();
    float getValue();
    int getUnits();
    void deleteUnit(bool gonebook);
    void showBook();
};


#endif //AEDAPROJECT1_BOOK_H
