#include "nonMem.h"
int nonMem::getNIF() const{
    return nif;
}

string nonMem::getName() const{
    return name;
}

bool nonMem::showLendRequests() const {
    if (lendRequest.size() == 0){
        return false;
    }

    for (int i = 0; i < lendRequest.size(); i++){
        catalog.showBook(lendRequest[i].first);
    }

    return true;
}

bool nonMem::makeRequest(int code, string name){
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