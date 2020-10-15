#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(int code, string title, string author,string category){
    this->code = code;
    this->title = title;
    this->author = author;
    this->category=category;
}

int Book::getCode() {
    return code;
}

float Book::getRating() {
    return realrating;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getCategory() {
    return category;
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

int Book::getUnits(){
    return units;
}

void Book::deleteUnit(bool gonebook){
    if(gonebook==true){
        units-=1;
    }
}

void Book::calculateRating(int rate){
    opinions+=1;
    sumrating+=rate;
    realrating=sumrating/opinions;
}

void Book::showBook(){
    cout<<"Title: "<<title<<"/n"<<"Author: "<<author<<"/n"<<"Category: "<<category<<"/n"<<"Code: "<<code<<"/n"<<"Rating: "<<realrating<<"/n"<<"State: "<<state<<"/n";
}

