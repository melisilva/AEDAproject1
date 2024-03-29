#ifndef AEDAPROJECT1_MEMBER_H
#define AEDAPROJECT1_MEMBER_H
#include "date.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;


/**
 * A class to save the member's preferences.
 * @param eMail: a Member's e-mail address. Serves as a key in the hashtable.
 * @param preferences: a string vector with the Member's preferences. 
*/
class Info {
    string eMail;
    vector<string> preferences;
public: 
    /**
     * Overloaded constructor for the Info class.
     * @param email: string Member's e-mail address.
     * @param preferences: a string vector with the Member's preferences.
    */
    Info(string email);

    Info(string email,vector<string>preferences);

    /**
     * Returns e-mail address.
     * @return: return string Member's e-mail address.
    */
    string getEmail() const;

    /**
     * Returns Member's preferences.
     * @return: return string vector with the Member's preferences.
    */
    vector<string> getPreferences()const;

    /**
     * Function that sets the object from which it is called's e-mail attribute with the argument provided.
     * @param email: value to set the email attribute (string).
    */
    void setEmail(string email);

    /**
     * Outputs the member's preferences.
    */
    void printPreferences() const;

    /**
     * Updates a member's preferences.
     * @param newPrefs: string vector representing the member's new preferences.
    */
    void setPreferences(vector<string> newPrefs);
   };

/**
 * Class to represent members.
 * @param lendRequest: vector with data from the member's lending requests.
 * @param lendings: vector with data from the member's current lendings.
 * @param name: string with the name of the member.
 * @param eMail: string with the e-mail address of the member.
 * @param nif: integer number with the NIF of the member.
 * @param books_given: number of books that member gave to the Club.
 * @param books_taken: number of books that member currently has from the Club.
 * @param balance: float number with the member's associated balance.
 * @param ratio: float number that specifies the books_given/books_taken ratio, used to order the Member's priority queues in books (Member exclusive variable).
*/
class Member {
protected:
    vector<pair<int, Date>> lendRequest, lendings;
    string name, eMail;
    int nif, books_taken=0,books_given=0;
    float balance,ratio;

public:
    /**
     * Default constructor for class Member.
    */
    Member();

    /**
     * Overloaded constructor for class Member.
     * @param name: string specifying the Member's name.
     * @param eMail: string specifying the Member's e-mail address.
     * @param nif: integer number specifying the Member's NIF ("Número de Identificação Fiscal").
     * @param books: vector of Book class objects representing the books owned and offered by the member.
     * @param balance: float number representing the Member's "bank account" balance.
     * @param books_given: integer number specifying the number of books given by the Member to the Club.
     * 
    */
    Member(string &name, string &eMail, int &nif, float &balance, int books_given);


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
     * Function that adds quantity to the Member's books_given attribute. Called everytime Member gives a book to the CLub.
    */
    virtual void addBookgiven();

    /**
     * Function that adds quantity to the books_taken attribute. Called everytime a frequentant takes a book from the Club.
    */
    void addBooktaken();
    
    /**
     * Function that subtracts quantity to the books_taken attribute. Called everytime a frequentant returns a book to the Club.
    */
    void subBooktaken();

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
     * Returns the Member's balance attribute. Works just the same for the nonMem class.
     * @return: the NIF attribute's value (integer).
    */
    float getBalance() const;

    /**
     * Returns the Member's e-mail. Works just the same for the nonMem class.
     * @return: the person's e-mail address (string).
    */
    string getEmail() const;

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
     * Function that sets the Member's e-mail attribute with the e-mail provided in the function's argument. Isn't used in the nonMem class.
     * @param eMail: string specifying the Member's e-mail address.
    */
    virtual void setEmail(string eMail);

    /**
     * Function that sets the Member's books_given attribute with the number provided in the function's argument. Isn't used in the nonMem class.
     * @param given: integer number for the number of given books.
    */
    virtual void setBooksGiven(int given);

    /**
     * Function that sets the Member's books_taken attribute with the number provided in the function's argument. Isn't used in the nonMem class.
     * @param given: integer number for the number of taken books.
    */
    void setBooksTaken(int taken);

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
     * Function that updates a member's data (either their name, balance or both). Works just the same for the nonMem class.
     * @param name: the Member's new name (string).
     * @param quantity: the value to be added to the Member's balance.
     * @param eMail: a new e-Mail to be put in the 
    */
    void updateData(string &name, float quantity, string eMail);

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
     * Function exclusive to Member. Calculates the ratio between attributes: books_taken & books_given.
    */
    virtual void calculateRatio();

    /**
     * Function exclusive to Member. Returns ratio.
     * @return: float number specifying the ratio of the Member.
    */
    virtual float getRatio() const;

    /**
     * Function comparison of two Members (used in Member's priority queue).
     * @param m1: The other Member object we wish to compare the current Member object with.
     * @return: bool true if Member has a bigger ratio than m1, false otherwise.
    */
    virtual bool operator<(const Member& m1)const;
    
    /**
     * Shows frequentant's information.
    */
    void showDetails() const;
    
    /**
     * Returns lendRequest vector.
     * @return: vector with data from the frequentant's lending requests.
    */
    vector<pair<int, Date>>getlendRequest()const;

    /**
     * Show the frequentant's lending requests.
    */
    void showLendRequests();
};

/**
 * Class to represent non-members, derived from Member.
 * @param lendRequest: vector with data from the frequentant's lending requests.
 * @param lendings: vector with data from the frequentant's current lendings.
 * @param name: string with the frequentant's name.
 * @param nif: integer number with the NIF of the frequentant.
 * @param balance: float number with the frequentant's associated balance.
  * @param books_taken: number of books that frequentant currently has from the Club.
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

     /**
     * Function comparison of two nonMembers (used in nonMem's priority queue).
     * @param nm1: The other nonMem object we wish to compare the current nonMem object with.
     * @return: bool true if nonMem has a bigger ratio than nm1, false otherwise.
    */
    bool operator<(const nonMem& nm1) const;

    /**
     * Returns number of books that nonMem currently has from the Club.
     * @return: integer number books_taken attribute.
    */
    int getBooksTaken() const;

};



#endif //AEDAPROJECT1_MEMBER_H
