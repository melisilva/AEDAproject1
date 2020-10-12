#ifndef PROJETO_BOOK_H
#define PROJETO_BOOK_H
#include <string>
using namespace std;

Class Book{
    int code, units;
    float rating, value;
    string title, author;
    bool state;

public:
    Book(int code, string title, string author);
    int getCode();
    float getRating();
    string getTitle();
    bool getState();
};

#endif //PROJETO_BOOK_H
