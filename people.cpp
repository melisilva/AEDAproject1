#include <fstream>
#include "people.h"
#include "date.h"
using namespace std;

Member::Member(){
    name = "";
    nif = -1;
    balance = 50;
}

Member::Member(string &name, int &nif, vector<Book*> &books) {
    this->name = name;
    this->nif = nif;
    this->books = books;
    this->balance = 50;
}

nonMem::nonMem(string &name, int &nif) : Member() {
    this->name = name;
    this->nif = nif;
    this->balance = 50;
}

int Member::getNIF() const {
    return nif;
}

float Member::getBalance() const {
    return balance;
}

void Member::addBalance(int quantity){
    balance+=quantity;
}

void Member::minusBalance(int quantity){
    balance-=quantity;
}

string Member::getName() const {
    return name;
}

vector<Book*> Member::getBooks() const {
    return books;
}

int Member::findBook(string title) const{
    for (int i = 0; i < books.size(); i++){
        if (name == (*books[i]).getTitle()){
            return i;
        }
        continue;
    }
    return -1;
}

bool Member::registerRequest(int code, struct Date date){
    lendRequest.push_back(make_pair(code, date));
    return true;
}

bool nonMem::registerRequest(int code, struct Date date){
    lendRequest.push_back(make_pair(code, date));
    return true;
}

bool Member::showLendRequests() const {
    if (lendRequest.size() == 0){
        return false;
    }

    for (int i = 0; i < lendRequest.size(); i++){
        cout << "Empréstimo do " << lendRequest[i].first << " a " << getDateStr(lendRequest[i].second) << endl;
    }

    return true;
}

bool nonMem::showLendRequests() const {
    if (lendRequest.size() == 0){
        return false;
    }

    for (int i = 0; i < lendRequest.size(); i++){
        cout << "Empréstimo do " << lendRequest[i].first << " a " << getDateStr(lendRequest[i].second) << endl;
    }

    return true;
}

void Member::showData() const {
    stringstream temp;

    temp << "Nome: " << name << endl << "NIF: " << nif << endl;

    cout << temp.str();
    showBooks();

    showLendRequests();

    showLendings();
}

void Member::showBooks() const {
    cout << "Livros de " << getName() << ": " << endl;
    for (int i = 0; i < books.size(); i++){
        (*books[i]).showBook();
    }
}

void Member::showLendings() const {
    cout << "Empréstimos em Vigor: " << endl;
    for (int i = 0; i < lendings.size(); i++){
        cout << "   " << i + 1 << " - " << lendings[i].first << " a " << getDateStr(lendings[i].second) << endl;
    }
}

string Member::getData() {

    stringstream temp;

    temp << name << "," << nif << endl;
    for (int i = 0; i < books.size(); i++){
        if (i < books.size() - 1 ) {
            temp << (*books[i]).getCode() << ",";
        } else if (i == books.size() - 1){
            temp << (*books[i]).getCode() << ";";
        }
    }

    temp << endl;
    return temp.str();
}

void Member::renovateLending() { //include check if it's last unit in club or where we call this
    int temp;
    string str_temp;

    //Informamos o utilizador dos empréstimos em vigor.
    showLendings();

    cout << "Por favor, indique a ordem do empréstimo: ";
    getline(cin,str_temp);
    temp=stoi(str_temp);
    struct Date dt1=lendings[temp - 1].second;
    if(abs(timePeriod(dttoday, dt1))<=3){
        extendTime(dt1);
    }
}
