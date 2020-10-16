#include "club.h"
#include "Book.h"

void Club::chargeDelay(int nif, int balance,Book book,int delayp){
    bool isMember;
    float fine = book.getValue()*0.10;

    fine = fine * delayp; //fine is measured by the book value plus the number of delay days

    for (unsigned int i = 0; i < members.size(); i++) {
        if ((members[i]).getNIF() == nif) {
            balance -= fine;
            isMember = true;
        }
    }
    if(isMember == false){
        balance -= (fine * 2);
    }
}

void Club::chargeFee(int nif, int balance,Book book){
    bool isMember;
    float fee = book.getValue()*0.05;

    for (unsigned int i = 0; i < members.size(); i++){
        if((members[i]).getNIF() == nif){
            isMember=true;
        }
    }
    if(isMember == false){
        balance -= fee;
    }
}

void Club::addMember(){
    string name, answer, title, author, nif_s, edition_s, code_s, category;
    int nif, edition, code;
    vector<Book*>books;
    cout<<"What's your name?"<<endl;
    getline(cin,name);
    cout<<"What's your nif?"<<endl;
    getline(cin,nif_s);
    nif=stoi(nif_s);
    cout << "Add a book please" << endl;
    do {
        cout << "What's its title" << endl;
        getline(cin, title);
        cout << "What's its author's name?" << endl;
        getline(cin, author);
        cout<<"What's its category?"<<endl;
        getline(cin,category);
        cout << "What's its edition?" << endl;
        getline(cin, edition_s);
        edition = stoi(edition_s);
        cout << "What's its code?" << endl;
        getline(cin, code_s);
        //Adding the book.
        code = stoi(code_s);
        Book b(code,title,author,category);
        catalog.addBook(b,edition);
        books.push_back(&b);
        //Repeating.
        cout << "Do you want to add another one?"<<endl;
        getline(cin,answer);
    } while((answer=="Y") || (answer=="Yes") || (answer=="yes") || (answer=="y"));
    Member m(name,nif,books);
    members.push_back(m);
}

void Club::removeMember(int nif){
    unsigned toDel;
    for(unsigned int i=0;i<members.size();i++){
        if((members[i]).getNIF()==nif){
            toDel=i;
        }
    }
    members.erase(members.begin()+toDel);
}

void Club::showMembers(){
    for (unsigned int i = 0; i < members.size(); i++){
        cout << "Name: " << (members[i]).getName() << "/n" << "NIF: "<< (members[i]).getNIF() << "/n" << "Books:" << endl;
        vector<Book*> books = (members[i]).getBooks();
        for (unsigned int j = 0; j < books.size(); j++){
            books[j]->showBook();
        }
    }
}
