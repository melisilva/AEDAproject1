#include "catalog.h"
#include <string>
#include <ostream>
#include <sstream>
#include <algorithm>
#include "bst.h"
#include "book.h"
#include "fstream"

/**
 * Class to represent a bookshop.
 * @param name: string containing the shop's name.
 * @param city: string containing the name of the city where the shop is.
 * @param promoValue: float number representing the sale of the book.
 * @param realRating: float number representing the rating of the shop (1-5 scale).
 * @param bookGenreCount: integer number representing the number of different genres that exist in the shop.
 * @param books: vector of Book that contains all the books available in the shop.
*/
class BookShop {
    protected:
        string name, city;
        float promoValue, realRating;
        int bookGenreCount;
        vector<Book> books;
    public:
    /**
     * Default constructor for the BookShop class.
    */
        BookShop();
        /**
         * Overloaded constructor for the Book class.
         * @param name: string specifying the shop's name.
        * @param city: string specifying the shop's city.
         * @param promoValue: float number specifying the sale on every book.
         * @param realRating: float number specifying the rating of the shop.
        * @param bookGenreCount: integer number specifying the quantity of different genres present in the shop.
         * @param books: vector of Book of all the books available in the shop.
         */        
        BookShop(string name, string city, float promoValue, float realRating, int bookGenreCount,vector<Book>books);

        /**
         * Return the name of the shop.
         * @return: string containing the name of the shop.
        */ 
        string getName() const;

        /**
         * Return name of the city where the shop is.
         * @return: string containing the name of the city where the shop is.
        */
        string getCity() const ;

        /**
         * Return float number containing the sale value of every book.
         * @return: float number containing the sale value of every book in the shop.
        */
        float getpromoValue() const;

        /**
         * Return rating of the shop.
         * @return: float number representing the rating of the shop.
        */
        float getRating() const;

        /**
         * Return quantity of book genres available in the shop.
         * @return: integer number containing the quantity of the book genres available in the shop.
        */
        int getGenreCount() const;

        /**
         * Return the books available in the shop.
         * @return: vector of Book available in the shop.
        */
        vector<Book> getBooks()const;

        /**
         * Searches for a certain book in the shop.
         * @param title: string that contains title of the book we wish to search.
         * @param author: string that contains the name of the book's author.
         * @param edition: integer number that specifies the book's edition.
         * @return: bool true if the book exists in the shop, false otherwise.
        */
        bool searchBook(string title,string author,int edition);

        /**
         * Comparison function between bookshops (used in BST).
         * @param bs1: BookShop object we wish to compare our current one with.
         * @return: bool true if name of current shop "comes first in the alphabet" than the name of bs1. If they have the same name, returns true if the current shop has more book genres than bs1. And if they are also the same, returns true if current shop's rating is bigger, false otherwise.
        */
        bool operator<(const BookShop &bs1) const;

        /**
         * Saves the all of the shop's information into a string.
         * @return: string containing all of the shop's information.
        */
        string getData() const;

        /**
         * Shows all of the shop's information.
        */
        void print() const;
};

static BookShop dummy;

/**
 * Class to represent BST of bookshops.
*/
class BStores
{
public:
    /**
     * Binary Search Tree of all the existant shops.
    */
    BST<BookShop> shops;

    /**
     * Overloaded construtor.
    */
    BStores():shops(dummy){};

    /**
     * Returns BST with all the shops.
     * @return: BST with all the shops (shops).
    */
    BST<BookShop> getShop();

    /**
     * Insert BookShop into the BST shops.
     * @param newStore: BookShop we desire to add to BST.
    */
    void addShop(BookShop newStore) { shops.insert(newStore);};

    /**
     * Show Stores by rating (biggest rating to lowest).
    */
    void showStoresByRating();

    /**
     * Show all information present in the BST.
    */
    void print() const;

    /**
     * Sell specified book from a specific shop.
     * @param b: Book needed to sell.
     * @param store: string that specifies the name of the shop from where we need to sell the book from.
     * @return: float number specifying the value of the book's price.
    */
    float sellBook(Book b,string store);

    /**
     * Searches of specified book on all the shops.
     * @param b: Book desired to find.
     * @return: vector of strings with the names of all the shops that have the desired book.
    */
    vector<string> findBook(Book b);

    /**
     * Show all the shops whose ratings are between the two values that are in the parameters.
     * @param min: float number representing lowest rating (lowest limit).
     * @param max: float number representing highest rating (highest limit).
    */
    void showStoresContemplated(float min, float max);

    /**
     * Show all the shops that have a specific book.
     * @param b: Specific book.
    */
    void showStoresbySpecificBook(Book b);
};