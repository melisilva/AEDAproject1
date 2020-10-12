#include "Book.h"
using namespace std;

Book::Book(int code, string title, string author){
    this->code = code;
    this->title = title;
    this->author = author;
}

int Book::getCode() {
    return code;
}

float Book::getRating() {
    return rating;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

bool Book::getState() {
    return state;
}

void Book::calculateValue(int edition){
    int count=0;
    if(edition ==1) {
        value=25;
        count++;
    }
    if(edition%10==0){
        value=25;
        count++;
    }
    if(count==0){
        value=20-edition*0.65;
    }
}

float Book::getValue(){
    return value;
}