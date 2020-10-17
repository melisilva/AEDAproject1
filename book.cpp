#include "Book.h"
using namespace std;

Book::Book(){
    code = -1;
    title = "";
    author = "";
    category = "";
    edition = -1;
}

Book::Book(int code, string title, string author,string category,int edition){
    this->code = code;
    this->title = title;
    this->author = author;
    this->category=category;
    this->edition=edition;
}

void Book::setState() {
    if (units == 0){
        state = false;
    } else {
        state = true;
    }
}

void Book::setCode(int code){
    this->code = code;
}

void Book::setUnits(int units){
    this->units = units;
}

void Book::setOpinions(int opinions){
    this->opinions = opinions;
}

void Book::setSumR(float sumRating){
    this->sumRating = sumRating;
}

void Book::setRating(float realRating){
    this->realRating = realRating;
}

void Book::setValue(float value){
    this->value = value;
}

void Book::setTitle(string title){
    this->title = title;
}

void Book::setAuthor(string author){
    this->author = author;
}

void Book::setCat(string category){
    this->category = category;
}

void Book::setEdition(int edition){
    this->edition = edition;
}

void Book::setWritops(string writ_ops){
    this->writ_ops=writ_ops;
}

int Book::getCode() {
    return code;
}

string Book::getWritops(){
    return writ_ops;
}

float Book::getRating() {
    return realRating;
}

string Book::getTitle() {
    return title;
}

int Book::getEdition(){
    return edition;
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

void Book::calculateValue(){
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

void Book::calculateRating(float rate){
    opinions+=1;
    sumRating+=rate;
    realRating=sumRating/opinions;
}

void Book::showBook(){
    cout << "   - " << title << ", de " << author << " (" << realRating << "/5)" << endl;
}

string Book::getData(){
    stringstream temp;

    temp << getCode() << endl << getTitle() << endl << getAuthor() << endl << edition << getCategory() << endl << getValue() << endl << getRating() << endl << getUnits() << endl << opinions << endl << sumRating << endl << getState();

    return temp.str();
}

void Book::addUnits(){
    units+=1;
}
