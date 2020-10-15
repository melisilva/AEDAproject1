#include "Club.h"
#include "Book.h"

void Club::chargeDelay(int nif, int balance,Book book){
    bool ismember;
    float fine=book.getValue()*0.10;
    for(unsigned int i=0;i<members.size();i++){
        if(members[i].getNIF()==nif){
            balance-=fine;
            ismember=true;
        }
    }
    if(ismember==false){
        balance-=(fine*2);
    }
}

void Club::chargeFee(int nif, int balance,Book book){
    bool ismember;
    float fee=book.getValue()*0.05;
    for(unsigned int i=0;i<members.size();i++){
        if(members[i].getNIF()==nif){
            ismember=true;
        }
    }
    if(ismember==false){
        balance-=fee;
    }
}

void Club::addMember(){
    string name,answer,title,author,nif_s,edition_s,code_s;
    int nif,edition,code;
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
        cout << "What's its edition?" << endl;
        getline(cin, edition_s);
        edition = stoi(edition_s);
        cout << "What's its code?" << endl;
        getline(cin, code_s);
        code = stoi(code_s);
        catalog.addBook(title,edition,code,author);
        Book b(code,title,author);
        books.push_back(&b);
        cout<<"Do you want to add another one?"<<endl;
        getline(cin,answer);
    }while(answer=="Y"||answer=="Yes"||answer=="yes"||answer=="y");
    Member m(name,nif,books);
    members.push_back(m);
}

void Club::removeMember(int nif){
    unsigned todel;
    for(unsigned int i=0;i<members.size();i++){
        if(members[i].getNIF()==nif){
            todel=i;
        }
    }
    members.erase(members.begin()+todel);
}

void Club::showMembers(){
    for(unsigned int i=0;i<members.size();i++){
        cout<<"Name: "<<members[i].getName()<<"/n"<<"NIF: "<<members[i].getNIF()<<"/n"<<"Books:"<<endl;
        vector<Book*>books=members[i].getBooks();
        for(unsigned int j=0;j<books.size();j++){
            books[j]->showBook();
        }
    }
}
