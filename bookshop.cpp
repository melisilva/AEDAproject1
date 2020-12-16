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
        return name < bs1.getName();
    }
    return realRating < bs1.getRating();
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

BST<BookShop> BStores::getShop(){
    return shops;
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
            b[i].showBook(true);
            cout<<endl<<endl;
        }
        it.advance();
    }
}

void BookShop::print() const
{
    cout<< "NOME: " << getName()<<endl<< "LOCALIDADE: " << getCity()<<endl<< "PROMOÇÃO (%): " << 100*getpromoValue()<<endl<< "CLASSIFICAÇÃO: " << getRating()<< " em 5" << endl<< "NÚMERO DE GÉNEROS DISPONÍVEIS: " << getGenreCount()<<endl;
    cout<<"Livros Disponíveis na Livraria: "<<endl;
    for(int i=0;i<books.size();i++){
        books[i].showBook(true);
    }

}

void BStores::showStoresByRating(){
    BST<BookShop> temp = shops;
    BSTItrLevel<BookShop> it(temp);
    vector<BookShop> stores;
    while (!it.isAtEnd()){
        stores.push_back(it.retrieve());
        it.advance();
    }

    sort(stores.begin(), stores.end(), [](BookShop &b1, BookShop &b2){
        if (b1.getRating() == b2.getRating()){
            return b1.getName() < b2.getName();
        }
        return b1.getRating() > b2.getRating();
    });

    for (int i = 0; i < stores.size(); i++){
        stores[i].print();
        cout << endl;
    }
    
}