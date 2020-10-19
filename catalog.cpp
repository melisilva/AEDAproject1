#include "catalog.h"

Catalog::Catalog(){
    vector<Book> temp;
    this->books = temp;
}

Catalog::Catalog(vector<Book> books){
    this->books = books;
}

void Catalog::updateCodes(){
    for (int i = 0; i < books.size(); i++){
        books[i].setCode(i);
    }
}

/*void Catalog::showRating(int code){
    cout<<"Classificação do livro: "<< books[code].getRating() << endl;
}*/

void Catalog::addBook(Book book){
    //book.addUnits();
    books.push_back(book);
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

/*void Catalog::showComments(int code){
    cout<<"Comentários sobre o livro: "<< endl;
    cout << books[code].getWritops() << endl;
}*/

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

bool Catalog::searchBook(string name){
    int count = 0;
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==name){
            showBook(i);
            count++;
        }
    }
    
    if (count == 0){
        cout << "Não há livros com esse nome." << endl;
        return false;
    }
    
    return true;
}


/*int Catalog::convertNameToCode(string name){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==name){
            return books[i].getCode();
        }
    }
    return -1;
}*/

void Catalog::showBook(int code){
    books[code].showBook();
}

Book Catalog::getBook(int code){
    return books[searchBook(code)];
}