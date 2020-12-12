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
        BookShop(string name, string city, float promoValue, float realRating, int bookGenreCount)
            : name(name), city(city), promoValue(promoValue), realRating(realRating), bookGenreCount(bookGenreCount) {};
    
        string getName() { return name; }
        
        string getCity() { return city; }

        float getpromoValue() { return promoValue; }

        float getRating() { return realRating; }

        int getGenreCount() { return bookGenreCount; }
        
        bool operator<(BookShop &bs1){
            if (bs1.getRating() == realRating){
                return name < bs1.getName();
            }
            return realRating < bs1.getRating();
        };

        string operator<<(ostream &out) {
            stringstream ss;
            ss << name << endl << city << endl << promoValue << endl << realRating << endl << bookGenreCount << endl << endl;
            return ss.str();
        };
};