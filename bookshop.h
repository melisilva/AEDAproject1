#include "catalog.h"
#include <string>
#include <ostream>
#include <sstream>
#include "bts.h"

class BookShop {
    protected:
        string name, city;
        float promoValue, realRating;
        int bookGenreCount;
    public:
        BookShop();
        BookShop(string name, string city, float promoValue, float realRating, int bookGenreCount);
        string getName() const;
        string getCity() const ;
        float getpromoValue() const;
        float getRating() const;
        int getGenreCount() const;
        bool operator<(const BookShop &bs1) const;
        string operator<<(ostream &out);
};

class BStores
{
    BST<BookShop> shops;
public:
    BStores():shops(BookShop("","",0,0,0)){};
    //BST<BookShop> getNames()const;
    //BST<BookShop> getCities()const;
    //string searchFor(string name) const;
    void readFile(ifstream &f); //working function, no idea how files are being structured 
    void print() const;
};