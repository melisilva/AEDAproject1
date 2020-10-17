#include <fstream>
#include "people.h"
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
            temp << (*books[i]).getCode() << endl;
        }
    }

    temp << endl;
    return temp.str();
}

void Member::renovateLending() {
    int temp;
    string date;

    //Informamos o utilizador dos empréstimos em vigor.
    showLendings();

    cout << "Por favor, indique a ordem do empréstimo: ";
    cin >> temp;
    cout << "Por favor, indique a data de hoje (formato DD-MM-YY): ";
    cin >> date;

    //Preciso testar que a data está nos últimos 3 dias do empréstimo em vigor!
    lendings[temp - 1].second = date;

}
