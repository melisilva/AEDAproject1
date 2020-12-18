#include <iostream>
using namespace std;


/**
 * Exception class for when the user tries to add a Member identified by a NIF already present in the Club's data.
 * @param nif: the repeated NIF number in question (integer).
*/
class MemberAlreadyExists{
    private:
    int nif;

    public:
    /**
     * Constructor for exception class MemberAlreadyExists.
     * @param nif: the integer number representing a repeated NIF.
    */
    MemberAlreadyExists(const int nif){
        this->nif=nif;
    }

    /**
     * Function that returns the repeated NIF that's at the core of the exception.
     * @return: the integer number representing a repeated NIF.
    */
    int getInfo(){
        return this->nif;
    }

};


/**
 * Exception class for when the user inputs a NIF that isn't saved in the Club's data (in the context of a process like a lending or lending request).
 * @param nif: the NIF number in question (integer).
*/
class NIFDoesNotExist{
    private:
    int nif;

    public:
    /**
     * Constructor for exception class NIFDoesNotExist.
     * @param nif: the integer number representing the never-before-seen NIF.
    */
    NIFDoesNotExist(const int nif){
        this->nif=nif;
    }

    /**
     * Function that returns the NIF that's at the core of the exception.
     * @return: the integer number representing a never-before-seen NIF.
    */
    int getInfo(){
        return this->nif;
    }
};

/**
 * Exception class for when the user inputs a book title or code that doesn't identify a book in the Club's catalog.
 * @param id: a way to identify the book in question, either a numerical code or a title (string).
*/
class BookDoesNotExist{
private:
    string id;
public:
    /**
     * Constructor for exception class BookDoesNotExist.
     * @param title: the title in question (string).
    */
    BookDoesNotExist(const string title){
        this->id = title;
    }

    /**
     * Constructor for exception class BookDoesNotExist.
     * @param code: the integer number of the code in question.
    */
    BookDoesNotExist(const int code){
        this->id=to_string(code);
    }

    /**
     * Function that returns the string at the core of the exception.
     * @return: the string representing a never-before-seen book's identifier.
    */
    string getInfo(){
        return this->id;
    }

};

/**
 * Exception class for when the program tries to find someone without any data in the Club.
 * @param nif: the integer number representing the supposed "member".
*/
class MemberDoesNotExist{
private:
    int nif;
public:
    /**
     * Constructor for exception class MemberDoesNotExist.
     * @param nif: the integer number of the "member" in question.
    */
    MemberDoesNotExist(const int nif){
        this->nif=nif;
    }

    /**
     * Function that returns the NIF at the core of the exception.
     * @return: the integer number representing the never-before-seen NIF.
    */
    int getInfo(){
        return this->nif;
    }

};

/**
 * Exception class for when the user tries to find a request that wasn't made/registered.
 * @param code: the integer number representing supposedly requested book's code.
 * @param nif: the integer number representing the Club's frequentant who supposedly did the request.
*/
class RequestDoesNotExist{
    int code;
    int nif;

public:
    /**
     * Constructor for exception class RequestDoesNotExist.
     * @param code: the integer number representing supposedly requested book's code.
     * @param nif: the integer number representing the Club's frequentant who supposedly did the request.
    */
    RequestDoesNotExist(const int code, const int nif){
        this->code=code;
        this->nif=nif;
    }

    /**
     * Function that returns the "request" at the core of the exception.
     * @param code: the integer number representing supposedly requested book's code.
     * @param nif: the integer number representing the Club's frequentant who supposedly did the request.
     * @return: the integer number representing the never-before-seen request in a pair of integer numbers.
    */
    pair<int,int> getInfo(){
        pair<int,int> info;
        info.first=this->code;
        info.second=this->nif;
        return info;
    }
};


/**
 * Exception class for when the user tries to force something only a member can do - for example: a lending renovation.
 * @param nif: the integer number representing a Club's nonMember.
*/
class NotAMember{
private:
    int nif;
public:
    /**
     * Constructor for exception class NotAMember.
     * @param nif: the integer number representing a Club's nonMember.
    */
    NotAMember(const int nif){
        this->nif=nif;
    }

    /**
     * Function that returns the NIF at the core of the exception.
     * @return: the integer number representing a non-member's NIF.
    */
    int getInfo(){
        return this->nif;
    }

};

/**
 * Exception class for when a frequentant tries to do a lending when his balance is on the negative. If this exception is thrown it's 'cause somebody has some delays to resolve.
 * @param nif: the integer number representing a Club's frequentant.
*/
class NegativeBalance{
private:
    int nif;
public:
    /**
     * Constructor for exception class NegativeBalance.
     * @param nif: the integer number representing a NIF from a Club's frequentant with negative balance.
    */
    NegativeBalance(const int nif){
        this->nif=nif;
    }

    /**
     * Function that returns the NIF from the Club frequentant at the core of the exception.
     * @return: the integer number representing a NIF from a Club's frequentant with negative balance.
    */
    int getInfo(){
        return this->nif;
    }

};

/**
 * Exception class for when the program tries to find an email that doesn't exist in the club.
 * @param email: string containing said email.
*/
class EmailDoesNotExist{
private:
    string email;
public:
    /**
     * Constructor for exception class EmailDoesNotExist.
     * @param email: string containing said email.
    */
    EmailDoesNotExist(const string email){
        this->email=email;
    }

    /**
     * Function that returns the email at the core of the exception.
     * @return: the string representing the never-before-seen email.
    */
    string getInfo(){
        return this->email;
    }

};