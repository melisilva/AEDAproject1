#include "club.h"

Club::Club() {
    vector<Member> temp;
    vector<tuple<int, string, int>> temp2, temp3,temp4;
    Catalog temp5;

    members = temp;
    lendings = temp2;
    lendRequests = temp4;
    delays = temp3;
    catalog = temp5;
}

bool Club::isMember(int nif){
    for(unsigned int i = 0; i < members.size(); i++) {
        if (members[i].getNIF() == nif) {
            return true;
        }
    }
    return false;
}

void Club::chargeDelay(int nif, int balance,Book book,int delayp){
    float fine = book.getValue()*0.10;

    fine = fine*delayp;

    if(isMember(nif)){
        balance -= fine;
    }
    else{
        balance -= (fine * 2);
    }
}

void Club::chargeFee(int nif, int balance,Book book){
    float fee = book.getValue()*0.05;
    if(!isMember(nif)){
        balance -= fee;
    }
}

void Club::addMember(){
    string name, answer, title, author, nif_s, edition_s, code_s, category;
    int nif, edition, code;
    vector<Book*>books;
    cout<<"Introduza o seu nome, por favor:"<<endl;
    getline(cin,name);
    cout<<"Introduza o seu nif, por favor:"<<endl;
    getline(cin,nif_s);
    nif=stoi(nif_s);
    cout << "Adicione um livro, por favor:"<< endl;
    do {
        cout <<"Introduza o seu título, por favor:"<< endl;
        getline(cin, title);
        cout << "Introduza o nome do seu escritor(a), por favor:" << endl;
        getline(cin, author);
        cout<<"Introduza a sua categoria, por favor:"<<endl;
        getline(cin,category);
        cout << "Introduza a sua edição, por favor:" << endl;
        getline(cin, edition_s);
        edition = stoi(edition_s);

        //Adding the book.
        code = catalog.books.size();
        Book b(code,title,author,category,edition);
        catalog.addBook(b);
        books.push_back(&b);

        //Repeating.
        cout << "Quer adicionar outro livro?"<<endl;
        getline(cin,answer);
    } while((answer=="S") || (answer=="Sim") || (answer=="sim") || (answer=="s"));
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
        cout << "Nome: " << members[i].getName() << "/n" << "NIF: "<< members[i].getNIF() << "/n" << "Livros:" << endl;
        vector<Book*> books = members[i].getBooks();
        for (unsigned int j = 0; j < books.size(); j++){
            books[j]->showBook();
        }
    }
}

void Club::showLendRequests() {
    for (unsigned int i = 0; i < lendRequests.size(); i++){
        cout << get<0>(lendRequests[i]) << ", a " << get<1>(lendRequests[i]) << " pelo " << get<2>(lendRequests[i]) << endl;
    }
}

void Club::showLendings() {
    for (unsigned int i = 0; i < lendings.size(); i++){
        cout << get<0>(lendings[i]) << ", a " << get<1>(lendings[i]) << " pelo " << get<2>(lendings[i]) << endl;
    }
}

void Club::showDelays() {
    for (unsigned int i = 0; i < delays.size(); i++){
        cout << get<0>(delays[i]) << ", desde " << get<1>(delays[i]) << " pelo " << get<2>(delays[i]) << endl;
    }
}

bool Club::makeRequest(){
    int nif, code;
    string date, name;

    cout << "Indique o seu NIF: ";
    cin >> nif;

    cout << "Indique a data no formato DD-MM-AAAA: ";
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

    return false;
}

void Club::saveData(){
    string membs = "members.txt", lends = "lendings.txt", lendRs = "lendRequests.txt", bks = "books.txt";

    ofstream file(membs, ios::binary);
    ofstream filee(lends, ios::binary);
    ofstream fileee(lendRs, ios::binary);

    stringstream temp1, temp2, temp3;

    for (int i = 0; i < members.size(); i++){
        if (i < members.size() -1) {
            temp1 << members[i].getData() << endl << endl;
        } else if (i = members.size() - 1){
            temp1 << members[i].getData() << endl << "END";
        }
    }

    file << temp1.str();

    for (int i = 0; i < lendings.size(); i++){
        temp2 << get<0>(lendings[i]) << ", " << get<1>(lendings[i]) << get<2>(lendings[i]) << endl;
    }

    filee << temp2.str();

    for (int i = 0; i < lendRequests.size(); i++){
        temp3 << get<0>(lendRequests[i]) << ", " << get<1>(lendRequests[i]) << get<2>(lendRequests[i]) << endl;
    }

    fileee << temp3.str();

    for (int i = 0; i < catalog.books.size(); i++){
        if (i < catalog.books.size() -1) {
             temp4 << catalog.books[i].getData() << endl << endl;
        } else if (i = members.size() - 1){
            temp4 << catalog.books[i].getData() << endl << "END";
        }
    }
    
    fileeee << temp4.str();
}

void Club::retrieveData(){
    ifstream memb_file; memb_file.open("members.txt");
    ifstream bks_file; bks_file.open("books.txt");
    ifstream lendRs_file; lendRs_file.open("lendRequests.txt");
    ifstream lends_file; lends_file.open("lendings.txt");
    string temp;
    char sep = ',';
    stringstream membs, bks, lendRs, lends;


    //Getting Books data.
    string title, author, category;
    int code_bk, units, opinions, sumRating, edition;
    float realRating, value;
    bool state;
    while (temp != "END"){
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> code_bk;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        title = bks.str();
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        author = bks.str();
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> edition;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> category;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> value;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> realRating;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> units;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> opinions;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> sumRating;
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        bks << temp;
        bks >> state;
        Book bk;
        bk.setAuthor(author); bk.setTitle(title); bk.setCat(category); bk.setCode(code_bk); bk.setUnits(units);
        bk.setOpinions(opinions); bk.setRating(realRating); bk.setSumR(sumRating); bk.setValue(value); bk.setState();
        bk.setEdition(edition);
        catalog.books.push_back(bk);
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
        getline(bks_file, temp);
        bks.str("");
        bks.clear();
    }

    //Getting Member data.
    temp = "";
    string name;
    int nif, code;
    while (temp != "END"){
        vector<Book *> memb_bks;
        getline(memb_file, temp);
        membs.str("");
        membs.clear();
        membs << temp;
        membs >> name;
        getline(memb_file, temp);
        membs.str("");
        membs.clear();
        membs << temp;
        membs >> nif;
        getline(memb_file, temp);
        membs.str("");
        membs.clear();
        membs << temp;
        do {
            membs >> code >> sep;
            int ind = catalog.searchBook(code);
            memb_bks.push_back(&catalog.books[ind]);
        } while (sep != ';');
        members.push_back(Member(name, nif, memb_bks));
        getline(memb_file, temp);
        membs.str("");
        membs.clear();
        getline(memb_file, temp);
        membs.str("");
        membs.clear();
    } 
}

