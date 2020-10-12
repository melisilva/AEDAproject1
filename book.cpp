#include "Book.h"
using namespace std;

Book::Book(int code, string title, string author){
    this->code = code;
    this->title = title;
    this->author = author;
}

int Book::getCode(){
    return code;
}

float Book::getRating(){
    return rating;
}

string Book::getTitle(){
    return title;
}
bool Book::getState(){
    return state;
}