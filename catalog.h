#ifndef AEDAPROJECT1_CATALOG_H
#define AEDAPROJECT1_CATALOG_H
#include "book.h"
#include <vector>
#include <iostream>
using namespace std;

class Catalog{
public:
    vector<Book> books;

    /**
     * Default constructor for the Catalog class.
    */
    Catalog(); 

    /**
     * Overloaded constructor for the Catalog class.
     * @param books: a vector of Book objects, each specifying a Book offered by the club for lending.
    */
    Catalog(vector<Book> books); 

    /**
     * Function that adds a book to the club's catalog (in the books vector attribute).
     * @param book: Book object that represents the book to be added in the books vector attribute!
    */
    void addBook(Book book); 

    /**
     * Function that returns the book specified by the code in the function's argument.
     * @param code: integer number specifying the looked-for book in question.
     * @return: the Book object that was once looked-for.
    */
    Book getBook(int code); 

    /**
     * Function that lends the book specified by the function's arguments.
     * @param code: integer number specifying the to-be-lended book in question.
     * @param nif: integer number specifying the lendee's NIF.
    */
    void lendBook(int code, int nif);

    /**
     * Function that "receives" the book specified by the function's arguments (i.e., "ends" a lending).
     * @param code: integer number specifying the to-be-received book in question.
     * @param nif: integer number specifying the lendee's NIF.
    */
    void receiveBook(int code, int nif);

    /**
     * Function that obtains a new comment for a book and registers it in the respective Book object (identified by the code argument).
     * @param code: integer number specifying the book being commented.
    */
    void registerComments(int code);

    /**
     * Function that obtains a rating for a book and registers it in the respective Book object (identified by the code argument).
     * @param code: integer number specifying the book being rated.
    */
    void registerRating(int code); 

    /**
     * Function that looks for a book in the catalog (in the books vector attribute).
     * @param code: integer number specifying the looked-for book.
     * @return: the Book object's code if found or -1 otherwise.
    */
    int searchBook(int code); 

    /**
     * Function that looks for a book in the catalog (in the books vector attribute) and says if it exists.
     * @param name: string with the title of the looked-for book.
     * @return: true if a book with the title provided is found, false otherwise.
    */
    bool searchBook(string name); 

    /**
     * Function that coordinates the output of a catalogued book's data.
     * @param code: integer number that specifies the book whose data will be outputed's code.
    */
    void showBook(int code); 

     /**
     * Function that coordinates the output of all catalogued books' data.
    */
    void showBooks(); 

     /**
     * Function that coordinates the updating of the catalogued books' codes (whenever there's a loss reported).
    */
    void updateCodes(); 
};

#endif //AEDAPROJECT1_CATALOG_H
