#include "bookshop.h"

BookShop::BookShop(){
    name = "";
    city = "";
    promoValue = 0.05;
    realRating = 2.5;
    vector<Book> temp;
    books = temp;
}

BookShop::BookShop(string name, string city, float promoValue, float realRating, int bookGenreCount,vector<Book> books)
    : name(name), city(city), promoValue(promoValue), realRating(realRating), bookGenreCount(bookGenreCount), books(books) {}
    
string BookShop::getName() const { return name; }
        
string BookShop::getCity() const { return city; }

float BookShop::getpromoValue() const { return promoValue; }

float BookShop::getRating() const { return realRating; }

int BookShop::getGenreCount() const { return bookGenreCount; }

vector<Book> BookShop::getBooks()const{return books;}
        
bool BookShop::operator<(const BookShop& bs1) const{
    if (bs1.getRating() == realRating){
        if (bs1.getGenreCount() == getGenreCount()){
            return name < bs1.getName();
        }
        return getGenreCount() > bs1.getGenreCount();
    }
    return realRating > bs1.getRating();
}


string BookShop::getData() const{
    stringstream ss;
    ss << name << endl << city << endl << promoValue << endl << realRating << endl << bookGenreCount << endl;

    for (int i = 0; i < books.size(); i++){
        if (i != books.size() - 1){
            ss << books[i].getCode() << "," << endl;
        } else {
            ss << books[i].getCode() << ";";
        }
    }

    return ss.str();
}

bool BookShop::searchBook(string title,string author,int edition){
    for(int i=0;i<books.size();i++){
        if(books[i].getTitle() == title && books[i].getAuthor() == author && books[i].getEdition() ==edition){
            return true;
        }
    }
    return false;
}

void BookShop::print() const
{
    cout<< "NOME: " << getName()<<endl<< "LOCALIDADE: " << getCity()<<endl<< "PROMOÇÃO (%): " << 100*getpromoValue()<<endl<< "CLASSIFICAÇÃO: " << getRating()<< " em 5" << endl<< "NÚMERO DE GÉNEROS DISPONÍVEIS: " << getGenreCount()<<endl;
    cout<<"Livros Disponíveis na Livraria: "<<endl;
    for(int i=0;i<books.size();i++){
        books[i].showBook(true);
    }

}




//BStores

BST<BookShop> BStores::getShop(){
    return shops;
}

void BStores::print() const
{
    BSTItrIn<BookShop> it(shops);
    vector<Book>b;
    while(!it.isAtEnd()){
        b=it.retrieve().getBooks();
        cout<<it.retrieve().getName()<<endl<<it.retrieve().getCity()<<endl<<it.retrieve().getpromoValue()<<endl<<it.retrieve().getRating()<<endl<<it.retrieve().getGenreCount()<<endl;
        cout<<"Livros Disponíveis na Livraria: "<<endl;
        for(int i=0;i<b.size();i++){
            b[i].showBook(1);
            cout<<endl<<endl;
        }
        it.advance();
    }
}

float BStores::sellBook(Book b,string store){ //return price of the book wanted
    BSTItrIn<BookShop> it(shops);
    float price;
    while(!it.isAtEnd()){
        auto test=it.retrieve();
           if(test.getName() == store){
               if(test.searchBook(b.getTitle(),b.getAuthor(),b.getEdition())){
                   price=test.getpromoValue()*b.getValue();
               }
              
        }
        it.advance();
    }
    return -1;
}

vector<string> BStores::findBook(Book b){
    vector<string> stores;
    BSTItrIn<BookShop> it(shops);
    bool exist=false;
    while(!it.isAtEnd()){
        auto test=it.retrieve();
        if(test.searchBook(b.getTitle(),b.getAuthor(),b.getEdition())){
            stores.push_back(test.getName());
        }
        it.advance();
    }
    return stores;
}

void BStores::showStoresByRating(){
    BST<BookShop> temp = shops;
    BSTItrIn<BookShop> it(temp);
    
    while (!it.isAtEnd()){
        it.retrieve().print();
        cout << endl;
        it.advance();
    }
}

void BStores::showStoresContemplated(float min, float max){
    BSTItrLevel<BookShop> it(shops);

    while (!it.isAtEnd()){
        if (it.retrieve().getRating() >= min && it.retrieve().getRating() <= max){
            it.retrieve().print();
        }
        it.advance();
        cout << endl;
    }
}

void BStores::showStoresbySpecificBook(Book b){
    BST<BookShop> temp=shops;
    BSTItrIn<BookShop> it(temp);
    bool exist=false;
    while(!it.isAtEnd()){
        auto test=it.retrieve();
        if(test.searchBook(b.getTitle(),b.getAuthor(),b.getEdition())){
            it.retrieve().print();
        }
        it.advance();
    }
}
