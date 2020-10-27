#ifndef AEDAPROJECT1_BOOK_H
#define AEDAPROJECT1_BOOK_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Book {
    int code, units, opinions = 0, edition, owner,oguni;
    float realRating, value, sumRating = 0;
    string title, author, category, writ_ops;
    bool state,multi;

public:
    Book(); //nice
    Book(int code, string title, string author, string category,int edition, int owner,int units,int oguni); //nice
    void addUnits(); //nice (usable when returning a book)
    void addWritops(string writ_ops); //nice
    void calculateValue(); //nice
    void calculateRating(float rate); //nice
    void deleteUnit(); //nice
    int getCode() const; //nice
    int getOwner() const; //nice
    int getEdition() const; //nice
    float getRating() const; //nice
    string getTitle() const; //nice
    string getWritops() const; //nice
    bool getState() const; //nice
    bool getMulti() const;
    string getAuthor() const; //nice
    string getCategory() const; //nice
    float getValue() const; //nice
    int getUnits() const; //nice
    int getOguni() const;
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
    void setOgunit(int oguni);
    void showBook() const; //nice
    string getData() const; //nice
    bool operator==(Book b1);
    void deleteOgunit();
    void setMulti();
};



#endif //AEDAPROJECT1_BOOK_H
