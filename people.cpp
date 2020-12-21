#include <fstream>
#include "people.h"
using namespace std;

Member::Member(){
    name = "";
    nif = -1;
    balance = 50;
}

Member::Member(string &name, string &eMail, int &nif, float &balance, int books_given) {
    this->name = name;
    this->eMail = eMail;
    this->nif = nif;
    this->balance = balance;
    books_taken = 0;
    this->books_given=books_given;
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


bool Member::registerRequest(int code, Date date){
    lendRequest.push_back(make_pair(code, date));
    return true;
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

    showLendRequests();

    showLendings();
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

    temp << name << endl << eMail << endl << nif << endl << books_given << endl << books_taken << endl << to_string(balance) << endl;
    
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

void Member::updateData(string &name, float quantity, string eMail){
    this->name = name;
    this->eMail = eMail;
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

string Member::getEmail() const{
    return eMail;
}

void Member::setEmail(string eMail) {
    this->eMail = eMail;
}

void Member::addBookgiven(){
    books_given++;
}

void Member::addBooktaken(){
    books_taken++;
}

void Member::setBooksGiven(int given){
    this->books_given = given;
}

void Member::setBooksTaken(int taken){
    this->books_taken = taken;
}

float Member::getRatio(){
    if(books_taken==0){
        ratio=books_given;
    }
    else{
        ratio=(books_given)/(books_taken);
    }
    return ratio;
}

bool Member::operator>(Member& m1) {
    return(getRatio() > m1.getRatio());
}


string nonMem::getData() {

    stringstream temp;

    temp << name << endl << nif << endl << to_string(balance);
    return temp.str();
}

int nonMem::getBooksTaken(){
    return books_taken;
}

bool nonMem::operator<(const nonMem& nm1) const{
    return(books_taken< nm1.books_taken);
}

Info::Info(string e):eMail(e){
}

Info::Info(string email,vector<string> preferences){
    this->eMail=email;
    this->preferences=preferences;
}

string Info::getEmail() const{
    return eMail;
}

vector<string> Info::getPreferences() const{
    return preferences;
}

void Info::setEmail(string email){
    eMail=email;
}

void Info::printPreferences() const{
    for (int i = 0; i < preferences.size(); i++){
        cout << i + 1 << "º LUGAR: " << preferences[i] << endl;
    }
}
