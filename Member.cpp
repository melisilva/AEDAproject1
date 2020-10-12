#include "Member.h"

Member::Member(string name, int nif, vector<Book*> books) {
    this->name = name;
    this->nif = nif;
    this->books = books;
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
    if ((code == 0) && (name == "")) {
        return false;
    }
    if (code != 0){
        lendRequests.push_back(*books[code]);
        return true;
    } else if ((name != "") && (findBook(name) != -1)) {
        lendRequests.push_back(*books[findBook(name)]);
        return true;
    }
    return false;
}

bool Member::showLendRequests() const {
    if (lendRequests.size() == 0){
        return false;
    }

    for (int i = 0; i < lendRequests.size(); i++){
        cout << (*lendRequests[i]).getTitle() << " by " << (*lendRequests[i]).getAuthor();
    }

    return true;
}

