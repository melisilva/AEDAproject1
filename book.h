#ifndef AEDAPROJECT1_BOOK_H
#define AEDAPROJECT1_BOOK_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Book {
    int code, units, opinions = 0, edition, owner,oguni;
    float realRating, value, sumRating = 0;
    string title, author, category, writ_ops;
    bool state,multi;

public:
    /**
     * Default constructor for the Book class.
    */
    Book();

    /**
     * Overloaded constructor for the Book class.
     * @param code: integer number specifying the book's unique code.
     * @param title: string specifying the book's title.
     * @param author: string specifying the book's author's name.
     * @param category: string specifying the book's category/genre (ex.: SciFi, for Science Fiction).
     * @param owner: integer number specifying the book's owner's NIF ("Número de Identificação Fiscal", which is unique to each person, in Portugal).
     * @param units: integer number specifying the the number of units available for lending.
     * @param oguni: integer number specifying the total number of units for the book.
    */
    Book(int code, string title, string author, string category,int edition, int owner,int units,int oguni);

    /**
     * Function that adds a lendable unit to the units parameter.
    */
    void addUnits();

    /**
     * Function to add a new opinion to the book's critiques register.
     * @param writ_ops: the new opinion to be added to the object's writ_ops parameter.
    */
    void addWritops(string writ_ops);

    /**
     * Function to calculate a book's value and set it in its value parameter.
    */
    void calculateValue();

    /**
     * Function that calculates the average rating for a book with the added new rating provided in the function's only argument.
     * @param rate: a float number that specifies a new rating given by a member.
    */
    void calculateRating(float rate);

    /**
     * Function to subtract a unit to the book's units parameter.
    */
    void deleteUnit();

    /**
     * Function that returns the book's code parameter.
     * @return: the book's code parameter (integer).
    */
    int getCode() const;

    /**
     * Function that returns the book's owner parameter.
     * @return: the book's owner parameter (integer).
    */
    int getOwner() const;

    /**
     * Function that returns the book's edition parameter.
     * @return: the book's edition parameter (integer).
    */
    int getEdition() const;

    /**
     * Function that returns the book's realRating parameter.
     * @return: the book's realRating parameter (float).
    */
    float getRating() const;

    /**
     * Function that returns the book's title parameter.
     * @return: the book's title parameter (string).
    */
    string getTitle() const;

    /**
     * Function that returns the book's writ_ops parameter.
     * @return: the book's writ_ops parameter (string).
    */
    string getWritops() const;

    /**
     * Function that returns the book's state parameter.
     * @return: the book's state parameter (boolean).
    */
    bool getState() const;

    /**
     * Function that returns the book's multi parameter.
     * @return: the book's multi parameter (boolean).
    */
    bool getMulti() const;

    /**
     * Function that returns the book's author parameter.
     * @return: the book's author parameter (string).
    */
    string getAuthor() const;

    /**
     * Function that returns the book's category parameter.
     * @return: the book's category parameter (string).
    */
    string getCategory() const;

    /**
     * Function that returns the book's value parameter.
     * @return: the book's value parameter (float).
    */
    float getValue() const;

    /**
     * Function that returns the book's iunits parameter.
     * @return: the book's units parameter (integer).
    */
    int getUnits() const;

    /**
     * Function that returns the book's oguni parameter.
     * @return: the book's oguni parameter (integer).
    */
    int getOguni() const;

    /**
     * Function that sets the object from which it is called's owner parameter with the argument provided.
     * @param owner: value to set the owner parameter (integer).
    */
    void setOwner(int owner);

    /**
     * Function that sets the object from which it is called's code parameter with the argument provided.
     * @param code: value to set the code parameter (integer).
    */
    void setCode(int code); //nice

    /**
     * Function that sets the object from which it is called's units parameter with the argument provided.
     * @param owner: value to set the units parameter (integer).
    */
    void setUnits(int units);

    /**
     * Function that sets the object from which it is called's opinions parameter with the argument provided.
     * @param opinions: value to set the opinions parameter (integer).
    */
    void setOpinions(int opinions);

    /**
     * Function that sets the object from which it is called's sumRating parameter with the argument provided.
     * @param sumRating: value to set the owner parameter (float).
    */
    void setSumR(float sumRating);

    /**
     * Function that sets the object from which it is called's realRating parameter with the argument provided.
     * @param realRating: value to set the realRating parameter (float).
    */
    void setRating(float realRating);

    /**
     * Function that sets the object from which it is called's value parameter with the argument provided.
     * @param value: value to set the value parameter (float).
    */
    void setValue(float value);

    /**
     * Function that sets the object from which it is called's title parameter with the argument provided.
     * @param owner: value to set the title parameter (string).
    */
    void setTitle(string title);

    /**
     * Function that sets the object from which it is called's author parameter with the argument provided.
     * @param owner: value to set the author parameter (string).
    */
    void setAuthor(string author);

    /**
     * Function that sets the object from which it is called's category parameter with the argument provided.
     * @param owner: value to set the category parameter (string).
    */
    void setCat(string category);

    /**
     * Function that sets the object from which it is called's state parameter.
    */
    void setState();

    /**
     * Function that sets the object from which it is called's edition parameter with the argument provided.
     * @param edition: value to set the edition parameter (integer).
    */
    void setEdition(int edition);

    /**
     * Function that sets the object from which it is called's oguni parameter with the argument provided.
     * @param oguni: value to set the oguni parameter (integer).
    */
    void setOgunit(int oguni);

    /**
     * Function that prints/outputs the book's data for the user.
    */
    void showBook() const;

    /**
     * Function that returrns the book's needed data for file records.
     * @return: the book's data in string form.
    */
    string getData() const;

    /**
     * Operator to compare two Book objects.
     * @return: true if the books have the same exact parameters and false otherwise (boolean).
    */ 
    bool operator==(Book b1);

    /**
     * Function that substracts 1 to the ogunit parameter of the book object from which it is called, whenever a loss is reported to the program.
    */
    void deleteOgunit();

    /**
     * Function that sets the object from which it is called's multi parameter.
    */
    void setMulti();
};

#endif //AEDAPROJECT1_BOOK_H
