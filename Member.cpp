#include <fstream>
#include "Member.h"
using namespace std;

Member::Member(string &name, int &nif, vector<Book*> &books) {
    this->name = name;
    this->nif = nif;
    this->books = books;
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

bool Member::makeRequest(int code, string name){
    string date;

    cout << "Indique a data no formato DD-MM-YYYY: ";
    cin >> date;

    if ((code == 0) && (name == "")) {
        return false;
    }
    if (code != 0){
        lendRequests.push_back(make_pair(books[code], date));
        return true;
    } else if ((name != "") && (findBook(name) != -1)) {
        lendRequests.push_back(make_pair(books[findBook(name)], date));
        return true;
    }
    return false;
}

bool Member::showLendRequests() const {
    if (lendRequests.size() == 0){
        return false;
    }

    for (int i = 0; i < lendRequests.size(); i++){
        cout << (*lendRequests[i].first).getTitle() << " por " << (*lendRequests[i].first).getAuthor();
    }

    return true;
}

void Member::showData() const {
    stringstream temp;

    temp << "Nome: " << name << endl << "NIF: " << nif << endl << "Livros: " << endl;
    for (int i = 0; i < books.size(); i++){
        temp << "   -" << (*books[i]).getTitle() << " por " << (*books[i]).getAuthor() << endl;
    }

    temp << "Pedidos: " << endl;
    for (int i = 0; i < lendings.size(); i++){
        temp << "   -" << (*lendings[i].first).getTitle() << " por " << (*lendings[i].first).getAuthor() << endl;
    }

    temp << "Empréstimos em Vigor: " << endl;
    for (int i = 0; i < lendings.size(); i++){
        temp << "   -" << (*lendings[i].first).getTitle() << " por " << (*lendings[i].first).getAuthor() << endl;
    }

    cout << temp.str();
}

void Member::showBooks() const {
    cout << "Livros de " << getName() << ": " << endl;
    for (int i = 0; i < books.size(); i++){
        cout << "   -" << (*books[i]).getTitle() << " por " << (*books[i]).getAuthor() << endl;
    }
}

void Member::showLendings() const {
    cout << "Empréstimos em Vigor: " << endl;
    for (int i = 0; i < lendings.size(); i++){
        cout << "   " << i + 1 << " - " << (*lendings[i].first).getTitle() << " por " << (*lendings[i].first).getAuthor() << endl;
    }
}

void Member::outputData() const {
    ofstream file("Member.txt");

    stringstream temp;

    temp << "Nome: " << name << endl << "NIF: " << nif << endl << "Livros: " << endl;
    for (int i = 0; i < books.size(); i++){
        temp << "   -" << (*books[i]).getTitle() << " por " << (*books[i]).getAuthor() << endl;
    }

    temp << "Pedidos: " << endl;
    for (int i = 0; i < lendings.size(); i++){
        temp << "   -" << (*lendings[i].first).getTitle() << " por " << (*lendings[i].first).getAuthor() << endl;
    }

    temp << "Empréstimos em Vigor: " << endl;
    for (int i = 0; i < lendings.size(); i++){
        temp << "   -" << (*lendings[i].first).getTitle() << " por " << (*lendings[i].first).getAuthor() << endl;
    }

    file << temp.str();
}

void Member::renovateLending() const {
    int temp;
    string date;

    //Informamos o utilizador dos empréstimos em vigor.
    showLendings();

    cout << "Por favor, indique a ordem do empréstimo: ";
    cin >> temp;
    cout << "Por favor, indique a data de hoje (formato DD-MM-YY): ";
    cin >> date;

    //Preciso testar que a data está nos últimos 3 dias do empréstimo em vigor!
    replace(lendings.begin(), lendings.end(), lendings[temp - 1], pair<Book*, string>(lendings[temp - 1].first, date));

}

