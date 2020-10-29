#include <iostream>
using namespace std;

class MemberAlreadyExists{
    private:
    int nif;
    public:
    MemberAlreadyExists(const int nif){
this->nif=nif;
    }
    int getInfo(){
        return this->nif;
    }

};

class NIFDoesNotExist{
    private:
    int nif;
    public:
    NIFDoesNotExist(const int nif){
this->nif=nif;
    }
    int getInfo(){
        return this->nif;
    }
};

class CodeDoesNotExist{
private:
    int code;
    public:
    CodeDoesNotExist(const int code){
this->code=code;
    }
    int getInfo(){
        return this->code;
    }

};

class BookDoesNotExist{
private:
    string title;
    public:
    BookDoesNotExist(const string title){
this->title=title;
    }
    BookDoesNotExist(const int code){
        this->title=to_string(code);
    }
    string getInfo(){
        return this->title;
    }

};

class MemberDoesNotExist{
private:
    int nif;
    public:
    MemberDoesNotExist(const int nif){
this->nif=nif;
    }
    int getInfo(){
        return this->nif;
    }

};

class RequestDoesNotExist{
    int code;
    int nif;
    public:
    RequestDoesNotExist(const int code, const int nif){
        this->code=code;
        this->nif=nif;
    }
    pair<int,int> getInfo(){
        pair<int,int> info;
        info.first=this->code;
        info.second=this->nif;
        return info;
    }
};

class NotAMember{
    private:
    int nif;
    public:
    NotAMember(const int nif){
this->nif=nif;
    }
    int getInfo(){
        return this->nif;
    }

};

class NegativeBalance{
    private:
    int nif;
    public:
    NegativeBalance(const int nif){
this->nif=nif;
    }
    int getInfo(){
        return this->nif;
    }

};

