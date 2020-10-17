#include "catalog.h"

Catalog::Catalog(){
    vector<Book> temp;
    this->books = temp;
}

Catalog::Catalog(vector<Book> books){
    this->books = books;
}

void Catalog::addBook(Book book){
    bool newb=true;
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==book.getCode()){
            if(books[i].getEdition()==book.getEdition()){
                books[i].addUnits();
                newb=false;
            }
        }
    }
    if(newb) {
        book.calculateValue();
        books.push_back(book);
    }
}

void Catalog::removeBook(string title, int balance,int edition){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==title) {
            if (books[i].getEdition() == edition) {
                balance += books[i].getValue();
                books[i].deleteUnit(true);
            }
        }
    }
}

void Catalog::showRating(int code){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            cout<<"Classificação do livro: "<<books[i].getRating()<<endl;
        }
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

void Catalog::showComments(int code){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            cout<<"Comentários sobre o livro: "<<books[i].getWritops()<<endl;
        }
    }
}

void Catalog::registerComments(int code){
    string comments,answer;
    cout<<"Deseja deixar um comentário sobre o livro?"<<endl;
    getline(cin,answer);
    if(answer=="sim"||answer=="s"||answer=="Sim"||answer="S"){
        cout<<"Escreva o seu comentário:"<<endl;
        getline(cin,comments);
        for(unsigned int i=0;i<books.size();i++){
            books[i].setWritops(comments);
        }
    }
}

void Catalog::showBooks(){
    for(unsigned int i=0;i<books.size();i++){
        books[i].showBook();
    }
}

int Catalog::searchBook(int code){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            return i;
        }
    }
    return -1;
}

int Catalog::searchBook(string name){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==name){
            return i;
        }
    }
    return -1;
}

int Catalog::convertNameToCode(string name){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==name){
            return books[i].getCode();
        }
    }
    return -1;
}

void Catalog::showBook(int code){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getCode()==code){
            books[i].showBook();
        }
    }
}

Book Catalog::getBook(int code = 0, string name = ""){
    if (code != 0){
        return books[searchBook(code)];
    }
    return books[searchBook(name)];
}