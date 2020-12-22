#ifndef AEDAPROJECT1_CLUB_H
#define AEDAPROJECT1_CLUB_H
#include "catalog.h"
#include "date.h"
#include "exception.h"
#include <windows.h>
#include <fstream>
#include <istream>
#include "people.h"
#include "bookshop.h"
#include "bst.h"
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <unordered_set>
//static BookShop dummy("", "", 0.05, 2.5, 10);

/*
struct PeopleHash {
    int operator()(const Member& ar) const {
        int v=0;
        for(int i=0;i<ar.getEmail().size();i++){
            v=37*v+ar.getEmail()[i];
        }
        return v;
    }

    bool operator()(const Member& ar1, const Member& ar2) const {
       return (ar1.getEmail()==ar2.getEmail());
    }
};
*/

typedef unordered_set <string> tabHstring;

struct PeopleHash {
    int operator()(const Info& ar) const {
        int v=0;
        for(int i=0;i<ar.getEmail().size();i++){
            v=37*v+ar.getEmail()[i];
        }
        return v;
    }

    bool operator()(const Info& ar1, const Info& ar2) const {
       return (ar1.getEmail()==ar2.getEmail());
    }
};

typedef unordered_set<Info, PeopleHash, PeopleHash> HashTablePeople;

/**
 * Class that represents the Book Club - to be a little informal: this is where most magic happens!
 * @param members: vector of Member objects representing the Club's members.
 * @param nonmembers: vector of nonMem objects representing the Club's nonmembers.
 * @param lendings: vector of three-element tuples representing each current lending in the club.
 * @param lendRequests: vector of three-element tuples representing each current lending request in the club.
 * @param delays: vector of three-element tuples representing each current delay (lending that's gone over its own due date) in the club.
 * @param catalog: Catalog class that deals with everything related to the Club's books.
 * @param today: Date object that keeps the date at the time of execution of the program.
*/
class Club {
private:
    vector<Member> members;
    vector<nonMem> nonmembers;
    vector<tuple<int, Date, int>> lendings, delays, lendRequests;
    Catalog catalog;
    Date today;
    HashTablePeople Preferences;
    tabHstring Genres;
    const vector<string> book_genres={ "ASE", "Comedy", "Comics", "Fantasy", "Graphic Novel","Health", "LGBTQIA","Memoir", "Mystery", "Non-Fiction",  "Play", "Poetry", "Recipes","Romance","Sci-fi", "Self-Help","Thriller","Young Adult"};

    //BStores b;

public:
    /**
     * Default constructor for the Club class.
    */
    Club();

    /**
     * Function that coordinates the flow of the program.
    */
    void run();

    /**
     * Simple function that outputs some instructions for a first time user.
    */
    void beginningInfo();

    /**
     * Function that outputs a set of codes used by the user to manage the Club's data.
    */
    void help();

    /**
     * Function that coordinates output of all the data of the books in the Club's catalog.
    */
    void showBooks();

    /**
     * Function that coordinates the updating of a Club frequentant's data (using input).
    */
    void updatePerson();

    /**
     * Function that adds a member to the Club's data (using input).
    */
    void addMember();

    /**
     * Function that removes a member from the Club (after checking if it's possible).
     * @param nif: integer number specifying the to-be-removed member's NIF.
     * @return: true if the removal goes by smoothly, false otherwise (boolean).
    */
    bool removeMember(int nif);

    /**
     * Function that adds a book to a member's data.
     * @param nif: integer number specifying a member's NIF.
    */
    void addBook(int nif);

    /**
     * Function that coordinates the loss of a book (specified through input from the user).
    */
    void registerLoss();

    /**
     * Function that "executes" the loss of a book (removes it from the Club's data entirely and pays fees where fees are due).
     * @param lostBook: tuple containing the data of the lost book's delay or lending.
    */
    void removeBook(tuple<int, Date, int> lostBook);

    /**
     * Function that coordinates the requesting of a book.
     * @return: true if the request is nicely registered, false otherwise (boolean).
    */
    bool makeRequest();

    /**
     * Function that coordinates a lending of a pressuposedly already requested book.
     * @return: true if the lending is registered nicely, false otherwise (boolean).
    */
    bool makeLending();

    /**
     * Function that coordinated a lending/delay's end.
     * @return: true if the returning is nicely registered and done with, false otherwise (boolean).
    */
    bool returnLending();

    /**
     * Special function to charge a bigger value whenever a delay is first spotted in the program.
     * @param nif: integer number specifying the person at fault's NIF.
     * @param book: the Book object representing the book involved in the delay.
    */
    void chargeFirstDelay(int nif, Book book);

    /**
     * Function used for charging a lending to a non-member.
     * @param nif: integer number specifying the non-member's NIF.
     * @param book: the Book object that represents the book to-be-lended.
    */
    void chargeFee(int nif,Book book);

    /**
     * Function that outputs each and every member's data.
    */
    void showMembers();

    /**
     * Function that outputs every data of a specific frequentant.
     * @param nif: integer number representing a frequentant's NIF whose data should be shown.
    */
    void showFrequentant(int nif);

    /**
     * Function that outputs every data of a specific book.
     * @param code: integer number specifying the book whose data should be shown.
    */
    void showABook(int code);

    /**
     * Function that outputs each and every frequentants'(member and non member alike) data.
    */
    void showAllFrequentants();

    /**
     * Function that coordinates a lending renovation requested by a member. Lendings can only be renewed in one of the 3 days before a lending's due date.
     * @return: true if the renovation passes through, false otherwise.
    */
    bool renovateLending();

    /**
     * Function that outputs every non-member's data.
    */
    void showNonMembers();

    /**
     * Function that checks if there are any new delays (through the lendings vector attribute).
    */
    void checkDelays();

    /**
     * Function that retrieves all data saved in files by saveData().
    */
    void retrieveData();

    /**
     * Function that verifies if a NIF provided belongs to any nmember frequenting the Club.
     * @param nif: integer number specifying the NIF to be searched for in the members vector.
    */
    int isMember(int nif);

    /**
     * Function that verifies if a NIF provided belongs to any non-member frequenting the Club.
     * @param nif: integer number specifying the NIF to be searched for in the nonmembers vector.
    */
    int isnonMem(int nif);

    /**
    * Function that outputs all the Club's registered (and non-finished) lendings.
   */
    void showLendings();

    /**
     * Function that outputs all the Club's registered (and resolved) delays.
    */
    void showDelays();

    /**
     * Function that outputs all the Club's registered (and non-finished) lending requests.
    */
    void showQueues();

    void showPersonRequests(int nif);

    /**
     * Function that saves all the Club's data in files.
    */
    void saveData();

    /**
    * Function that coordinates the rating and commenting of a book.
    * @param code: integer number specifying the book to be rated and commented.
   */
    void getOpinions(int code);

    /**
     * Function that sets the outputed text's color.
     * @param ch: char identifying the color needed when outputing.
    */
    void colorText(char ch); //add color to the interface

    bool buyBook(int nif,int code);

    /**
     * Prints all shops with an agreement with the Club from their highest to lowest rating. 
    */
    void showShopsByRating();

    /**
     * Prints all shops with an agreement with the Club that have a rating in between a minimum and maximum value provided by user input.
    */
    void showShopsInRange();

    void showShopsBySpecificBook();

    /**
     * Updates the table with a new e-mail address.
     * @param oldEmail: the old e-mail address, to be deprecated but useful as a key before the change.
     * @param newEmail: the new e-mail address.
    */
    void updateTable(string oldEmail, string newEmail);

    /*
    * Lets the user change a member's preference. Asks for an e-mail address through input.
    */
    void updatePreferences();

    void generateGenretable();

    void givenuponBook(int nif);

    //nif to know who's the cause of the update
    void updateHeap(int nif);

};

#endif //AEDAPROJECT1_CLUB_H
