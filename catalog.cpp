#include "catalog.h"
using namespace std;

Catalog::Catalog(){
    vector<Book> temp;
    this->books = temp;
}

Catalog::Catalog(vector<Book> books){
    this->books = books;
}

void Catalog::addBook(Book book){
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


void Catalog::registerRating(int code){
    float rate;
    cout<<"Classifique o livro, de 1 a 5: "<<endl;
    cin>>rate;
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            books[i].calculateRating(rate);
        }
    }
}

void Catalog::registerComments(int code){
    string comments,answer;
    cout<<"Deseja deixar um comentário sobre o livro?"<<endl;
    getline(cin,answer);
    if(answer=="sim"||answer=="s"||answer=="Sim"||answer=="S"){
        cout<<"Escreva o seu comentário:"<<endl;
        getline(cin,comments);
        for(unsigned int i=0;i<books.size();i++){
            books[i].addWritops(comments);
        }
    }
}

void Catalog::showBooks(){
    for(int i=0;i<books.size();i++){
        books[i].showBook();
    }
}

int Catalog::searchBook(int code){
    for(int i=0; i<books.size(); i++){
        if(books[i].getCode()==code){
            return i;
        }
    }
    return -1;
}

bool Catalog::searchBook(string name){
    int count = 0;
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==name){
            count++;
        }
    }

    if (count == 0){
        cout << "Não há livros com esse nome." << endl;
        return false;
    }

    return true;
}

void Catalog::showBook(int code){
    books[code].showBook();
}

Book Catalog::getBook(int code = -1){
    if (code == -1){
        //throw shit;
    }
    return books[searchBook(code)];
}
