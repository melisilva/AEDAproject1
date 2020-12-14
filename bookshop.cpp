#include "bookshop.h"

BookShop::BookShop(){
    name = "";
    city = "";
    promoValue = 0.05;
    realRating = 2.5;
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
        return name < bs1.getName();
    }
    return realRating < bs1.getRating();
}


void BStores::readFile(ifstream &f){
    string name,city,pValue,rRating,bGC;
    float promoValue,realRating;
    int bookGenreCount;
    while(!f.eof()){
        getline(f,name);
        getline(f,city);
        getline(f,pValue);
        promoValue=stof(pValue);
        getline(f,rRating);
        realRating=stof(rRating);
        getline(f,bGC);
        bookGenreCount=stoi(bGC);
        //BookShop b1(name,city,promoValue,realRating,bookGenreCount);
        //shops.insert(b1);
    }
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
            b[i].showBook();
            cout<<endl<<endl;
        }
        it.advance();
    }
}
