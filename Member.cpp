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

    //check if book with code introduced exists
    if(code!=0){
        if(catalog.searchBook(code)==false){
            return false;
        }
    }
    //check if book with name introduced exists
    if(name!=""){
        if(catalog.searchBook(name)==false){
            return false;
        }
    }

    if ((code == 0) && (name == "")) {
        return false;
    }
    if (code != 0){
        lendRequest.push_back(make_pair(code, date));
        return true;
    } else if (name != "") {
        lendRequest.push_back(make_pair(catalog.convertnametocode(name), date));
        return true;
    }
    return false;
}

bool Member::showLendRequests() const {
    if (lendRequests.size() == 0){
        return false;
    }

    cout << "Pedidos: " << endl;
    for (int i = 0; i < lendRequests.size(); i++){
        cout << "   -" << (*lendRequests[i].first).getTitle() << " por " << (*lendRequests[i].first).getAuthor() << endl;
    }

    return true;
}

void Member::showData() const {
    stringstream temp;

    temp << "Nome: " << name << endl << "NIF: " << nif << endl << "Livros: " << endl;
    showBooks();

    showLendRequests();

    showLendings();

    cout << temp.str();
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
        cout << "   " << i + 1 << " - " << (*lendings[i].first).getTitle() << " por " << (*lendings[i].first).getAuthor() << endl;
    }
}

void Member::saveData() const {
    ofstream file(to_string(nif), ios::binary); //Como dar nomes aos ficheiros através dos dados que possuímos?

    stringstream temp;

    temp << name << "," << nif << ";";
    for (int i = 0; i < books.size(); i++){
        if (i < books.size() - 1 ) {
            temp << (*books[i]).getCode() << ",";
        } else if (i == books.size() - 1){
            temp << (*books[i]).getCode() << ";";
        }
    }

    for (int i = 0; i < lendRequests.size(); i++){
        if (i < lendRequests.size() - 1 ) {
            temp << (*lendRequests[i].first).getCode() << "," << lendRequests[i].second << ",";
        } else if (i == books.size() - 1){
            temp << (*lendRequests[i].first).getCode() << "," << lendRequests[i].second << ";";
        }
    }

    for (int i = 0; i < lendings.size(); i++){
        if (i < lendings.size() - 1 ) {
            temp << (*lendings[i].first).getCode() << "," << lendings[i].second << ",";
        } else if (i == books.size() - 1){
            temp << (*lendings[i].first).getCode() << "," << lendings[i].second << ";";
        }
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

int main() {
    Book a(1, "Aristotle & Dante Discover the Secrets of the Universe", "Benjamin Alire-Saénz", "Contemporary");
    vector<Book*> books;
    books.push_back(&a);
    Member a("João", 123456789, &books);
}