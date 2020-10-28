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
     * Function that adds a lendable unit to the units attribute.
    */
    void addUnits();

    /**
     * Function to add a new opinion to the book's critiques register.
     * @param writ_ops: the new opinion to be added to the object's writ_ops attribute.
    */
    void addWritops(string writ_ops);

    /**
     * Function to calculate a book's value and set it in its value attribute.
    */
    void calculateValue();

    /**
     * Function that calculates the average rating for a book with the added new rating provided in the function's only argument.
     * @param rate: a float number that specifies a new rating given by a member.
    */
    void calculateRating(float rate);

    /**
     * Function to subtract a unit to the book's units attribute.
    */
    void deleteUnit();

    /**
     * Function that returns the book's code attribute.
     * @return: the book's code attribute (integer).
    */
    int getCode() const;

    /**
     * Function that returns the book's owner attribute.
     * @return: the book's owner attribute (integer).
    */
    int getOwner() const;

    /**
     * Function that returns the book's edition attribute.
     * @return: the book's edition attribute (integer).
    */
    int getEdition() const;

    /**
     * Function that returns the book's realRating attribute.
     * @return: the book's realRating attribute (float).
    */
    float getRating() const;

    /**
     * Function that returns the book's title attribute.
     * @return: the book's title attribute (string).
    */
    string getTitle() const;

    /**
     * Function that returns the book's writ_ops attribute.
     * @return: the book's writ_ops attribute (string).
    */
    string getWritops() const;

    /**
     * Function that returns the book's state attribute.
     * @return: the book's state attribute (boolean).
    */
    bool getState() const;

    /**
     * Function that returns the book's multi attribute.
     * @return: the book's multi attribute (boolean).
    */
    bool getMulti() const;

    /**
     * Function that returns the book's author attribute.
     * @return: the book's author attribute (string).
    */
    string getAuthor() const;

    /**
     * Function that returns the book's category attribute.
     * @return: the book's category attribute (string).
    */
    string getCategory() const;

    /**
     * Function that returns the book's value attribute.
     * @return: the book's value attribute (float).
    */
    float getValue() const;

    /**
     * Function that returns the book's iunits attribute.
     * @return: the book's units attribute (integer).
    */
    int getUnits() const;

    /**
     * Function that returns the book's oguni attribute.
     * @return: the book's oguni attribute (integer).
    */
    int getOguni() const;

    /**
     * Function that sets the object from which it is called's owner attribute with the argument provided.
     * @param owner: value to set the owner attribute (integer).
    */
    void setOwner(int owner);

    /**
     * Function that sets the object from which it is called's code attribute with the argument provided.
     * @param code: value to set the code attribute (integer).
    */
    void setCode(int code); //nice

    /**
     * Function that sets the object from which it is called's units attribute with the argument provided.
     * @param owner: value to set the units attribute (integer).
    */
    void setUnits(int units);

    /**
     * Function that sets the object from which it is called's opinions attribute with the argument provided.
     * @param opinions: value to set the opinions attribute (integer).
    */
    void setOpinions(int opinions);

    /**
     * Function that sets the object from which it is called's sumRating attribute with the argument provided.
     * @param sumRating: value to set the owner attribute (float).
    */
    void setSumR(float sumRating);

    /**
     * Function that sets the object from which it is called's realRating attribute with the argument provided.
     * @param realRating: value to set the realRating attribute (float).
    */
    void setRating(float realRating);

    /**
     * Function that sets the object from which it is called's value attribute with the argument provided.
     * @param value: value to set the value attribute (float).
    */
    void setValue(float value);

    /**
     * Function that sets the object from which it is called's title attribute with the argument provided.
     * @param owner: value to set the title attribute (string).
    */
    void setTitle(string title);

    /**
     * Function that sets the object from which it is called's author attribute with the argument provided.
     * @param owner: value to set the author attribute (string).
    */
    void setAuthor(string author);

    /**
     * Function that sets the object from which it is called's category attribute with the argument provided.
     * @param owner: value to set the category attribute (string).
    */
    void setCat(string category);

    /**
     * Function that sets the object from which it is called's state attribute.
    */
    void setState();

    /**
     * Function that sets the object from which it is called's edition attribute with the argument provided.
     * @param edition: value to set the edition attribute (integer).
    */
    void setEdition(int edition);

    /**
     * Function that sets the object from which it is called's oguni attribute with the argument provided.
     * @param oguni: value to set the oguni attribute (integer).
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
     * @return: true if the books have the same exact attributes and false otherwise (boolean).
    */ 
    bool operator==(Book b1);

    /**
     * Function that substracts 1 to the ogunit attribute of the book object from which it is called, whenever a loss is reported to the program.
    */
    void deleteOgunit();

    /**
     * Function that sets the object from which it is called's multi attribute.
    */
    void setMulti();
};

#endif //AEDAPROJECT1_BOOK_H
