#include "bookshop.h"

BookShop::BookShop(){
    name = "";
    city = "";
    promoValue = 0.05;
    realRating = 2.5;
}

BookShop::BookShop(string name, string city, float promoValue, float realRating, int bookGenreCount)
    : name(name), city(city), promoValue(promoValue), realRating(realRating), bookGenreCount(bookGenreCount) {}
    
string BookShop::getName() const { return name; }
        
string BookShop::getCity() const { return city; }

float BookShop::getpromoValue() const { return promoValue; }

float BookShop::getRating() const { return realRating; }

int BookShop::getGenreCount() const { return bookGenreCount; }
        
bool BookShop::operator<(const BookShop& bs1) const{
    if (bs1.getRating() == realRating){
        return name < bs1.getName();
    }
    return realRating < bs1.getRating();
}

string BookShop::operator<<(ostream &out) {
    stringstream ss;
    ss << name << endl << city << endl << promoValue << endl << realRating << endl << bookGenreCount << endl << endl;
    return ss.str();
}