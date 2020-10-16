#include "club.h"
#include "Book.h"

void Club::chargeDelay(int nif, int balance,Book book,int delayp){
    bool isMember;
    float fine = book.getValue()*0.10;

    fine = fine*delayp;

    for(unsigned int i = 0; i < members.size(); i++) {
        if (members[i].getNIF() == nif) {
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
        if(members[i].getNIF() == nif){
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

int Club::findMember(int nif){
    for(unsigned int i=0;i<members.size();i++){
        if(members[i].getNIF()==nif){
            return i;
        }
    }
    return -1;
}

void Club::removeMember(int nif){
    unsigned toDel = findMember(nif);
    members.erase(members.begin()+toDel);
}

void Club::showMembers(){
    for (unsigned int i = 0; i < members.size(); i++){
        cout << "Name: " << members[i].getName() << "/n" << "NIF: "<< members[i].getNIF() << "/n" << "Books:" << endl;
        vector<Book*> books = members[i].getBooks();
        for (unsigned int j = 0; j < books.size(); j++){
            books[j]->showBook();
        }
    }
}

bool Club::makeRequest(){
    int nif, code;
    string date, name;

    cout << "Indique o seu NIF: ";
    cin >> nif;

    cout << "Indique a data no formato DD-MM-YYYY: ";
    cin >> date;

    cout << "Indique o código do livro (se não o souber, introduza 0 e dê ENTER): ";
    cin >> code;

    if (code == 0) {
        cout << "Indique, então, o título do livro: ";
        cin >> name;
    }

    //check if book with code introduced exists
    if(code != 0){
        if(catalog.searchBook(code)== -1){
            cerr << "Não há nenhum livro com esse código!" << endl;
            return false;
        }

        this->lendings.push_back(make_tuple(code, date, nif));
        members[findMember(nif)].registerRequest(code, date);
        return true;
    }

    //Check if book with name introduced exists
    if(name != ""){
        if(catalog.searchBook(name)== -1){
            cerr << "Não há nenhum livro com esse título!" << endl;
            return false;
        }

        lendings.push_back(make_tuple(catalog.convertNameToCode(name), date, nif));
        members[findMember(nif)].registerRequest(code, date);
        return true;
    }

    if ((code == 0) && (name == "")) {
        cerr << "Não podemos adicionar um livro sem nos indicar uma referência dele!" << endl;
        return false;
    }
}