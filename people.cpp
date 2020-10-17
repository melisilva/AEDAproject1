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

bool Member::registerRequest(int code, string date){
    lendRequest.push_back(make_pair(code, date));
    return true;
}

bool nonMem::registerRequest(int code, string date){
    lendRequest.push_back(make_pair(code, date));
    return true;
}

bool Member::showLendRequests() const {
    if (lendRequest.size() == 0){
        return false;
    }

    for (int i = 0; i < lendRequest.size(); i++){
        cout << "Empréstimo do " << lendRequest[i].first << " a " << lendRequest[i].second << endl;
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
        cout << "   " << i + 1 << " - " << lendings[i].first << " a " << lendings[i].second << endl;
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

void Member::renovateLending() {
    int temp;
    string date1,date2,str_temp;
    int month1,year1,day1,month2,year2,day2;

    //Informamos o utilizador dos empréstimos em vigor.
    showLendings();

    cout << "Por favor, indique a ordem do empréstimo: ";
    getline(cin,str_temp);
    temp=stoi(str_temp);
    /*cout << "Por favor, indique a data de hoje (formato DD-MM-YY): ";
    getline(cin,date1);

    if(date1.size()!=10){
        cerr<<"Data inválida"<<endl;
    }

    day1 = stoi(date1.substr(0, 2));
    month1 = stoi(date1.substr(3, 2));
    year1 = stoi(date1.substr(6));*/


    lendings[temp - 1].second = date2;
    day2 = stoi(date2.substr(0, 2));
    month2 = stoi(date2.substr(3, 2));
    year2 = stoi(date2.substr(6));
    Date dt2 = { day2,month2,year2 };

    if(abs(timePeriod(dttoday, dt2))<=3){
        extendTime(dt2);
    }
    /*
     if(abs(timePeriod(dt1, dt2))<=3){
        extendTime(dt2);
    }
     */
}