#include "Book.h"
using namespace std;

Book::Book(){
    code = -1;
    title = "";
    author = "";
    category = "";
    edition = -1;
    units = 1;
    oguni=1;
    opinions = 0;
    sumRating = 0;
    realRating = 0;
    writ_ops = "";
    setState();
    multi=true;

}

Book::Book(int code, string title, string author,string category,int edition, int owner){
    this->code = code;
    this->title = title;
    this->author = author;
    this->category=category;
    this->edition=edition;
    this->owner = owner;
    this->units = 1;
    this->oguni=1;
    this->opinions = 0;
    this->sumRating = 0;
    this->realRating = 0;
    this->writ_ops = "";
    calculateValue();
    setState();
    this->multi=true;
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

void Book::setMulti(){
    if(oguni>units){
        multi=false;
    }
    else{
        multi=true;
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

int Book::getCode() const {
    return code;
}

string Book::getWritops() const{
    return writ_ops;
}

float Book::getRating() const {
    return realRating;
}

string Book::getTitle() const {
    return title;
}

int Book::getEdition() const{
    return edition;
}

string Book::getAuthor() const{
    return author;
}

string Book::getCategory() const{
    return category;
}

bool Book::getState() const{
    return state;
}

bool Book::getMulti()const{
    return multi;
}

float Book::getValue() const{
    return value;
}

int Book::getUnits() const{
    return units;
}

int Book::getOguni()const{
    return oguni;
}

int Book::getOwner() const{
    return owner;
}

void Book::deleteUnit(){
    units-=1;
    setState();
    setMulti();
}

void Book::deleteOgunit(){
    oguni-=1;
}

void Book::calculateRating(float rate){
    opinions+=1;
    sumRating+=rate;
    realRating=sumRating/opinions;
}

void Book::showBook() const{
    cout << "   - " << title << " (" << code << "), de " << author << ", "<< edition << " edicao" <<" (" << realRating << "/5), do membro " << owner <<", "<<units<<" unidades"<<endl << "Comentários do Livro: " << endl << writ_ops;
}

string Book::getData() const{
    stringstream temp;

    temp << code << endl << title << endl << author << endl << edition << endl << owner << endl << category << endl << value << endl << realRating << endl << units << endl << oguni << endl << opinions << endl << sumRating << endl << state << endl << multi; 

    string tmp = temp.str();
    return temp.str();
}



void Book::addUnits(){
    units+=1;
    oguni+=1;
    setState();
    setMulti();
}

bool Book::operator==(Book b1){
    if(title==b1.getTitle() && author==b1.getAuthor() && category==b1.getCategory() && edition==b1.getEdition() && owner==b1.owner){
        return true;
    }
    else{
        return false;
    }
}

void Book::setOgunit(int oguni){
    this->oguni = oguni;
}