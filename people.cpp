#include <fstream>
#include "people.h"
using namespace std;

Member::Member(){
    name = "";
    nif = -1;
    balance = 50;
}

Member::Member(string &name, int &nif, vector<Book> &books, float &balance) {
    this->name = name;
    this->nif = nif;
    this->books = books;
    this->balance = balance;
}

nonMem::nonMem(string &name, int &nif, float &balance) : Member() {
    this->name = name;
    this->nif = nif;
    this->balance = balance;
}

void Member::setName(string name){
    this->name = name;
}

void Member::setNif(int nif){
    this->nif = nif;
}

int Member::getNIF() const {
    return nif;
}

float Member::getBalance() const {
    return balance;
}

void Member::addBalance(float quantity){
    balance+=quantity;
}

void Member::minusBalance(float quantity){
    balance-=quantity;
}

string Member::getName() const {
    return name;
}

vector<Book> Member::getBooks() const {
    return books;
}

int Member::findBook(int code) const{
    for (int i = 0; i < books.size(); i++){
        if (code == books[i].getCode()){
            return i;
        }
        continue;
    }
    return -1;
}

void Member::removeBook(int index) {
    if(books[index].getUnits()>1){
        books[index].deleteUnit();
    }
    else{
        books.erase(books.begin()+index);
    }
}

bool Member::registerRequest(int code, Date date){
    lendRequest.push_back(make_pair(code, date));
    return true;
}

void Member::addBook(Book &book){
    if(books.size()!=0){
        vector<Book>::iterator it=find(books.begin(),books.end(),book);
        if(it==books.end()){
            books.push_back(book);
        }
        else{
            it->addUnits();
        }
    }else{
        books.push_back(book);
    }
}

bool Member::showLendRequests() const {
    if (lendRequest.size() == 0){
        return false;
    }

    for (int i = 0; i < lendRequest.size(); i++){
        cout << "Empréstimo do " << lendRequest[i].first << " a " << (lendRequest[i].second).getDateStr() << endl;
    }

    return true;
}

void Member::showData() const {
    stringstream temp;

    temp << "Nome: " << name << endl << "NIF: " << nif << endl;


    showBooks();

    showLendRequests();

    showLendings();
}

void Member::showBooks() const {
    cout << "Livros de " << getName() << ": " << endl;
    for (int i = 0; i < books.size(); i++){
        books[i].showBook(0);
    }
}

void Member::showLendings() const {
    cout << "Empréstimos em Vigor: " << endl;
    for (int i = 0; i < lendings.size(); i++){
        cout << "   " << i << " - " << lendings[i].first << " a " << lendings[i].second.getDateStr() << endl;
    }
}

bool Member::registerLending(int code, Date date) {
    lendings.push_back(make_pair(code, date));
    return true;
}

string Member::getData() {

    stringstream temp;

    temp << name << endl << nif << endl << to_string(balance) << endl;
    for (int i = 0; i < books.size(); i++){
        if (i < books.size() - 1 ) {
            temp << books[i].getCode() << "," << endl;
        } else if (i == books.size() - 1){
            temp << books[i].getCode() << ";";
        }
    }
    return temp.str();
}

void Member::renovateLending(int code, Date date) {
    for (int i = 0; i < lendings.size(); i++){
        if ((lendings[i].first == code)){
            lendings[i].second=date;
            break;
        }
    }
}

void Member::updateData(string &name, float quantity){
    this->name = name;
    addBalance(quantity);
}

void Member::finishLending(int code, Date date){
    for (int i = 0; i < lendings.size(); i++){
        if ((lendings[i].first == code) && (lendings[i].second == date)){
            lendings.erase(lendings.begin()+i);
            break;
        }
    }
}

void Member::finishRequest(int code){
    for (int i = 0; i < lendRequest.size(); i++){
        if (lendRequest[i].first == code){
            lendRequest.erase(lendRequest.begin()+i);
            break;
        }
    }
}

void Member::deleteRequest(int code){
    int temp;
    for (int i = 0; i < lendRequest.size(); i++){
        if (lendRequest[i].first == code){
            temp = i;
            break;
        }
    }
    lendRequest.erase(lendRequest.begin()+temp);
}

string nonMem::getData() {

    stringstream temp;

    temp << name << endl << nif << endl << to_string(balance);
    return temp.str();
}