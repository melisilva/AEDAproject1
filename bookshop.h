#include "catalog.h"
#include <string>
#include <ostream>
#include <sstream>

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