#ifndef AEDAPROJECT1_MEMBER_H
#define AEDAPROJECT1_MEMBER_H
#include "book.h"
#include "date.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

/**
 * Class to represent members.
 * @param lendRequest: vector with data from the member's lending requests.
 * @param lendings: vector with data from the member's current lendings.
 * @param books: vector with the Book objects that represent the member's books.
 * @param name: string with the name of the member.
 * @param nif: integer number with the NIF of the member.
 * @param balance: float number with the member's associated balance.
*/
class Member {
protected:
    vector<pair<int, Date>> lendRequest, lendings;
    vector<Book> books;
    string name;
    int nif;
    float balance;

public:
    /**
     * Default constructor for class Member.
    */
    Member();

    /**
     * Overloaded constructor for class Member.
     * @param name: string specifying the Member's name.
     * @param nif: integer number specifying the Member's NIF ("Número de Identificação Fiscal").
     * @param books: vector of Book class objects representing the books owned and offered by the member.
     * @param balance: float number representing the Member's "bank account" balance.
    */
    Member(string &name, int &nif, vector<Book> &books, float &balance);

    /**
     * Function that deletes an ended request from a Member's lendRequest attribute (because of a lending). Works just the same for the nonMem class.
     * @param code: integer number specifying the book's code.
    */
    void deleteRequest(int code);

    /**
     * Function that adds quantity to the Member's balance attribute. Since the only argument is an integer number, only Euro quantities are accepted (ex.: 2€). Works just the same for the nonMem class.
     * @param quantity: integer number representing the value to be added to the balance attribute (float).
    */
    void addBalance(float quantity);

    /**
     * Function that searches for a book (with its code attribute equal to the "code" argument) and returns its position in the "books" vector attribute. Function is virtual to take into account that it's useless in the derived Member class nonMem.
     * @param code: code of the book to be found in the books vector (integer).
    */
    virtual int findBook(int code) const;

    /**
     * Function that returns the Member's relevant data in string form for the file records. Function is virtual to take the derived Member class nonMem into account.
     * @return: the Member's data (string).
    */
    virtual string getData();

    /**
     * Returns the Member's NIF attribute. Works just the same for the nonMem class.
     * @return: the NIF attribute's value (integer).
    */
    int getNIF() const;

    /**
     * Returns the Member's name attribute. Works just the same for the nonMem class.
     * @return: the name attribute's value (string).
    */
    string getName() const;

    /**
     * Returns the Member's books vector attribute. Declared virtual to take the nonMem class, where the function isn't needed.
     * @return: the books vector attribute (vector<Book>).
    */
    virtual vector<Book> getBooks() const;

    /**
     * Returns the Member's balance attribute. Works just the same for the nonMem class.
     * @return: the NIF attribute's value (integer).
    */
    float getBalance() const;

    /**
     * Substracts quantity to the Member's balance attribute. Works just the same for the nonMem class.
     * @param quantity: the value to be subtracted to the balance attribute.
    */
    void minusBalance(float quantity);

    /**
     * Function that registers a request in the lendRequests vector attribute.
     * @param code: integer number specifying the requested book's code.
     * @param date: Date object specifying the Date when the request was made.
     * @return: true if the request is registered, false otherwise (boolean).
    */
    bool registerRequest(int code, Date date);

    /**
     * Function that registers a lending in the lendings vector attribute.
     * @param code: integer number specifying the lended book's code.
     * @param date: Date object specifying the Date when the lending was started.
     * @return: true if the lending is registered, false otherwise (boolean).
    */
    bool registerLending(int code, Date date);

    /**
     * Function that updates a lending registered in the lendings vector attribute (identifiable by the functions arguments). Declared virtual as non-Members (class nonMem) can't renovate lendings, thus the function is not required.
     * @param code: integer number specifying the lending-to-be-renewed book's code.
     * @param date: Date object specifying the Date to identify the lending-to-be-renewed.
    */
    virtual void renovateLending(int code, Date date);

    /**
     * Function that removes a book from a Member's books vector attribute. Declared virtual as it's not required in nonMem.
     * @param code: integer number specifying the to-be-removed-book's code.
    */
    virtual void removeBook(int index);

    /**
     * Function that sets the Member's name attribute with the name provided in the function's argument. Works just the same in the nonMem class.
     * @param name: string specifying the Member's name.
    */
    void setName(string name);

    /**
     * Function that sets the Member's nif attribute with the NIF provided in the function's argument. Works just the same in the nonMem class.
     * @param nif: integer number specifying the Member's NIF.
    */
    void setNif(int nif);

    /**
     * Function that outputs the contents of the Member's lend request. Works just the same in the nonMem class. Works just the same in the nonMem class.
     * @return: true if there's data to be outputed (the size of the lendRequest attribute isn't 0), false otherwise.
    */
    bool showLendRequests() const;

    /**
     * Function that outputs a Member's data. Works just the same for the nonMem derived class.
    */
    void showData() const;

    /**
     * Function that outputs a Member's lendings vector attribute. Works just the same for the nonMem derived class.
    */
    void showLendings() const;

    /**
     * Function that outputs a Member's books vector attribute. Declared virtual as it's not required for nonMem objects.
    */
    virtual void showBooks() const;

    /**
     * Function that updates a member's data (either their name, balance or both). Works just the same for the nonMem class.
     * @param name: the Member's new name (string).
     * @param quantity: the value to be added to the Member's balance.
    */
    void updateData(string &name, float quantity);

    /**
     * Function that "finishes" a lending (i.e., deletes its register in the lendings vector attribute), as per identified through the function's arguments. Works just the same for the nonMem class.
     * @param code: integer number specifying the lended book's code.
     * @param date: Date object specifying the date where the lending was first made.
    */
    void finishLending(int code, Date date);

    /**
     * Function that "finishes" a request (i.e., deletes its register in the lendRequests vector attribute), as per identified through the function's argument. Works just the same for the nonMem class.
     * @param code: integer number specifying the requested book's code.
    */
    void finishRequest(int code);

    /**
     * Function that adds a book to a Member's books vector attribute. Declared virtual as it's not needed in the nonMem class.
     * @param book: the Book to be added to the books vector.
    */
    virtual void addBook(Book &book);
};

/**
 * Class to represent non-members, derived from Member.
 * @param lendRequest: vector with data from the member's lending requests.
 * @param lendings: vector with data from the member's current lendings.
 * @param name: string with the name of the member.
 * @param nif: integer number with the NIF of the member.
 * @param balance: float number with the member's associated balance.
*/
class nonMem : public Member {
public:
    /**
     * Overloaded constructor for the derived nonMem class.
     * @param name: string specifying the nonMember's name.
     * @param nif: integer number specifying the non-member's NIF.
     * @param balance: float number specifying the non-member's balance.
    */
    nonMem(string &name, int &nif, float &balance); 

    /**
     * Redefinition of the getData function.
     * @return: string containing the non-member's data in string form.
    */
    string getData();
};



#endif //AEDAPROJECT1_MEMBER_H
