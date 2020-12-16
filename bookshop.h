#include "catalog.h"
#include <string>
#include <ostream>
#include <sstream>
#include <algorithm>
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
        int searchBook(string title,string author,int edition);
        bool operator<(const BookShop &bs1) const;
        string getData() const;
        void removeBook(int index);
        void print() const;
};

static BookShop dummy;

class BStores
{
public:
    BST<BookShop> shops;
    BStores():shops(dummy){};
    BST<BookShop> getShop();
    void addShop(BookShop newStore) { shops.insert(newStore);};
    void showStoresByRating();
    //BST<BookShop> getNames()const;
    //BST<BookShop> getCities()const;
    //string searchFor(string name) const;
    void readFile(ifstream &f); //working function, no idea how files are being structured 
    void print() const;
    bool sellBook(Book b,string store);
    vector<string> findBook(Book b);
    void showStoresContemplated(float min, float max);
};