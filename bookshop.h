#include "catalog.h"
#include <string>
#include <ostream>
#include <sstream>
#include "bst.h"
#include "book.h"
#include "fstream"

class BookShop {
    protected:
        string name, city;
        float promoValue, realRating;
        int bookGenreCount;
        vector<Book> books;
    public:
        BookShop();
        BookShop(string name, string city, float promoValue, float realRating, int bookGenreCount,vector<Book>books);
        string getName() const;
        string getCity() const ;
        float getpromoValue() const;
        float getRating() const;
        int getGenreCount() const;
        vector<Book> getBooks()const;
        bool operator<(const BookShop &bs1) const;
        string operator<<(ostream &out);
};

class BStores
{
public:
    BST<BookShop> shops;
    vector<Book>books;
    BStores():shops(BookShop("","",0,0,0,books)){};
    //BST<BookShop> getNames()const;
    //BST<BookShop> getCities()const;
    //string searchFor(string name) const;
    void readFile(ifstream &f); //working function, no idea how files are being structured 
    void print() const;
};