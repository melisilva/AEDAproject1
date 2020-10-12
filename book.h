#ifndef PROJETO_BOOK_H
#define PROJETO_BOOK_H

Class Book{
    int code, units;
    float rating, value;
    string title;
    bool state;

public:
    int getCode();
    float getRating();
    string getTitle();
    bool getState();
};

#endif //PROJETO_BOOK_H
