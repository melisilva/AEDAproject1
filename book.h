#ifndef AEDAPROJECT1_BOOK_H
#define AEDAPROJECT1_BOOK_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Book {
    int code, units, opinions = 0, edition, owner;
    float realRating, value, sumRating = 0;
    string title, author, category, writ_ops;
    bool state;

public:
    Book(); //nice
    Book(int code, string title, string author, string category,int edition, int owner); //nice
    void addUnits(); //nice (usable when returning a book)
    void addWritops(string writ_ops); //nice
    void calculateValue(); //nice
    void calculateRating(float rate); //nice
    void deleteUnit(); //nice
    int getCode(); //nice
    int getOwner(); //nice
    int getEdition(); //nice
    float getRating(); //nice
    string getTitle(); //nice
    string getWritops(); //nice
    bool getState(); //nice
    string getAuthor(); //nice
    string getCategory(); //nice
    float getValue(); //nice
    int getUnits(); //nice
    void setOwner(int owner); //nice
    void setCode(int code); //nice
    void setUnits(int units); //nice
    void setOpinions(int opinions); //nice
    void setSumR(float sumRating); //nice
    void setRating(float realRating); //nice
    void setValue(float value); //nice
    void setTitle(string title); //nice
    void setAuthor(string author); //nice
    void setCat(string category); //nice
    void setState(); //nice
    void setEdition(int edition); //nice
    void showBook(); //nice
    string getData(); //nice
    bool operator==(Book b1);
};


#endif //AEDAPROJECT1_BOOK_H
