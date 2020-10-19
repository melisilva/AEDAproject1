#include "Book.h"
using namespace std;

Book::Book(){
    code = -1;
    title = "";
    author = "";
    category = "";
    edition = -1;
    units = 1;
    opinions = 0;
    sumRating = 0;
    realRating = 0;
    writ_ops = "";
    setState();
}

Book::Book(int code, string title, string author,string category,int edition, int owner){
    this->code = code;
    this->title = title;
    this->author = author;
    this->category=category;
    this->edition=edition;
    this->owner = owner;
    this->units = 1;
    this->opinions = 0;
    this->sumRating = 0;
    this->realRating = 0;
    this->writ_ops = "";
    calculateValue();
    setState();
}

void Book::calculateValue(){
    int count=0;
    if(edition == 1) {
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

void Book::setOwner(int owner) {
    this->owner = owner;
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

void Book::addWritops(string writ_ops){
    stringstream temp;
    temp << writ_ops << endl;
    writ_ops += temp.str();

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

float Book::getValue(){
    return value;
}

int Book::getUnits(){
    return units;
}

int Book::getOwner(){
    return owner;
}

void Book::deleteUnit(bool gonebook){
    if (gonebook==true) {
        units-=1;
    }
    setState();
}

void Book::calculateRating(float rate){
    opinions+=1;
    sumRating+=rate;
    realRating=sumRating/opinions;
}

void Book::showBook(){
    cout << "   - " << title << "(" << code << "), de " << author << ", "<< edition << " edicao" <<" (" << realRating << "/5), do membro " << owner << endl << "Comentários do Livro: " << endl << writ_ops;
}

string Book::getData(){
    stringstream temp;

    temp << code << endl << title << endl << author << endl << edition << endl << owner << endl << category << endl << value << endl << realRating << endl << units << endl << opinions << endl << sumRating << endl << state;

    string tmp = temp.str();
    return temp.str();
}

void Book::addUnits(){
    units+=1;
    setState();
}
