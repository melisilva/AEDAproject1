#ifndef AEDAPROJECT1_BOOK_H
#define AEDAPROJECT1_BOOK_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Book {
    int code, units, opinions = 0, sumRating = 0, edition;
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
    void setCode(int code);
    void setUnits(int units);
    void setOpinions(int opinions);
    void setSumR(int sumRating);
    void setRating(float realRating);
    void setValue(float value);
    void setTitle(string title);
    void setAuthor(string author);
    void setCat(string category);
    void setState();
    void setEdition(int edition);
    void deleteUnit(bool gonebook);
    void showBook();
    string getData();
    void addUnits();
};


#endif //AEDAPROJECT1_BOOK_H
