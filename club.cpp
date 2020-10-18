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

void Club::run(){
    /*
     * Esta função irá ditar como corre o programa desde o início, inciando com uma descrição
     * de como utilizar o programa e recuperando os dados em ficheiros já guardados,
     * (códigos de execução e por aí fora) e depois o seu uso. Quando esta
     * função terminar, o programa fecha, guardando os dados todos possuídos no clube em ficheiros.
     */
}

void Club::beginningInfo() {
    /*
     * Pura e simplesmente ajuda o utilizador com o inicial, para diminuir o tamanho de run.
     */
}

bool Club::makeLending() {
    /*
     * Deverá checar se um empréstimo que se quer fazer está já registado como pedido.
     * Se sim, irá adicioná-lo a "lendings" (no Club e no membro respetivo) e tirá-lo de
     * "lendRequests" (no Club e Membro respetivo), atualizando o estado do livro no catalog.
     * Deverá lançar exceções nos seguintes casos:
     * - o pedido não foi feito (o pedido não está em lendRequests);
     * - o pedido não pode ser feito (por haver um membro que fez um pedido antes de não-Membro);
     */
}

bool Club::returnLending() {
    /*
     * Deverá retornar um livro ao catálogo, passando por:
     * - adicionar um exemplar ao livro correto (catalog);
     * - retirar o livro do registo de empréstimos (ao nivel de Club e Member respetivo);
     * - pedir opinião do livro em questão e registá-la na Book respetiva;
     * Deverá lançar exceção no seguinte caso:
     * - caso o empréstimo não exista.
     */
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

int Club::calculateDelay(){
    int delayp;
    string date1;
    int day1,month1,year1;
    for (unsigned int i = 0; i < delays.size(); i++){
        date1=get<1>(delays[i]);
        delayp=abs(timePeriod(dttoday,getDate(date1)));
    }
    return delayp;
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
        addBook();
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

    //Remover todos os livros do membro!
    for (int i = 0; i < catalog.books.size(); i++){
        if (catalog.books[i].owner == nif) {
            catalog.books.erase(catalog.books.begin() + i);
        }
    }
}

void Club::addBook(Book book){
    string title, author, category, edition_s, owner_s;
    int edition, owner;

    cout <<"Introduza o seu título, por favor:"<< endl;
    getline(cin, title);
    cout << "Introduza o nome do seu escritor(a), por favor:" << endl;
    getline(cin, author);
    cout<<"Introduza a sua categoria, por favor:"<<endl;
    getline(cin,category);
    cout << "Introduza a sua edição, por favor:" << endl;
    getline(cin, edition_s);
    cout << "Introduza o dono do livro, por favor (NIF):" << endl;
    getline(cin, owner);
    edition = stoi(edition_s);
    owner = stoi(owner_s);
    code = catalog.books.size();
    Book b(code,title,author,category,edition);
    catalog.addBook(b);
}

void Catalog::removeBook(string title, int balance,int edition){
    for(unsigned int i=0;i<books.size();i++){
        if(books[i].getTitle()==title) {
            if (books[i].getEdition() == edition) {
                balance += books[i].getValue();
                books[i].deleteUnit(true);
            }
        }
    }
}


void Club::showMembers(){
    for (unsigned int i = 0; i < members.size(); i++){
        cout << "Nome: " << members[i].getName() << "/n" << "NIF: "<< members[i].getNIF() << '/n' << "Livros:" << endl;
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

void Club::checkDelays(){
    string date1;
    int day1,month1,year1;
    for (unsigned int i = 0; i < lendings.size(); i++){
        date1=get<1>(lendings[i]);
        if(abs(timePeriod(dttoday, getDate(date1)))>=10){ //Consider lending period is 10 days
            this->delays.push_back(make_tuple(get<0>(lendings[i]),get<1>(lendings[i]),get<2>(lendings[i])));
        }
    }
}

bool Club::makeRequest(){
    int nif, code;
    string date, name,nif_str,date_str,code_str;

    cout << "Indique o seu NIF: ";
    getline(cin,nif_str);
    nif=stoi(nif_str);

    cout << "Indique a data no formato DD-MM-AAAA: ";
    getline(cin,date);

    cout << "Indique o código do livro (se não o souber, introduza -1 e dê ENTER): ";
    getline(cin,code_str);
    code=stoi(code_str);

    if (code == -1 ){
        cout << "Indique, então, o título do livro: ";
        getline(cin,name);
    }

    //check if book with code introduced exists
    if(code != -1){
        if(catalog.searchBook(code)== -1){
            cerr << "Não há nenhum livro com esse código!" << endl;
            return false;
        }

        this->lendRequests.push_back(make_tuple(code,date,nif));
        if(findMember(nif)!=-1) {
            members[findMember(nif)].registerRequest(code, date);
        }
        else{ //it's not a member than it's a nonMem
            string namem,nif_s;
            int nif;
            cout<<"Introduza o seu nome, por favor:"<<endl;
            getline(cin,namem);
            cout<<"Introduza o seu nif, por favor:"<<endl;
            getline(cin,nif_s);
            nif=stoi(nif_s);
            nonMem m(namem,nif);
            nonmembers.push_back(m);
            m.registerRequest(code, date);
        }
        return true;
    }

    //Check if book with name introduced exists
    if(name != ""){
        if(catalog.searchBook(name)== -1){
            cerr << "Não há nenhum livro com esse título!" << endl; //EXCEÇÃO
            return false;
        }

        vector<Book> possibleBooks;
        vector<int> possibleCodes;
        for (int i = 0; i < catalog.books.size(); i++){
            if ((catalog.books[i].title == name) && (catalog.books[i].state == true)){
                possibleBooks.push_back(catalog.books[i]);
                possibleCodes.push_back(catalog.books[i].getCode());
            }
        }

        cout << "Estas são as edições dos livros que pode escolher: " << endl;
        for (int i = 0; i < possibleBooks.size(); i++){
            possibleBooks[i].showBook();
        }

        do {
            cout << "Indique o código do livro que prefere requisitar: " << endl;
            getline(cin, code_str);
            code = stoi(code_str);

            for (int i = 0; i < possibleCodes.size(); i++){
                if (code == possibleCodes[i]){
                    break;
                } else {
                    continue;
                }
            }
        } while (true);

        this->lendRequests.push_back(make_tuple(code,date,nif));

        if(findMember(nif)!=-1) {
            members[findMember(nif)].registerRequest(code, date);
        }
        else{ //it's not a member than it's a nonMem
            string namem,nif_s;
            int nif;
            cout<<"Introduza o seu nome, por favor:"<<endl;
            getline(cin,namem);
            cout<<"Introduza o seu nif, por favor:"<<endl;
            getline(cin,nif_s);
            nif=stoi(nif_s);
            nonMem m(namem,nif);
            nonmembers.push_back(m);
            m.registerRequest(code, date);
        }
        return true;
    }

    if ((code == -1) && (name == "")) {
        cerr << "Não podemos adicionar um livro sem nos indicar uma referência dele!" << endl;
        return false;
    }

    return false;
}

void Club::saveData(){
    string membs = "members.txt", lends = "lendings.txt", lendRs = "lendRequests.txt", bks = "books.txt", fileeeee = "delays.txt";

    ofstream file(membs, ios::binary);
    ofstream filee(lends, ios::binary);
    ofstream fileee(lendRs, ios::binary);
    ofstream fileeee(bks, ios::binary);
    ofstream fileeeee(dels, ios::binary);

    stringstream temp1, temp2, temp3, temp4, temp5;

    for (int i = 0; i < members.size(); i++){
        if (i < members.size() -1) {
            temp1 << members[i].getData() << endl << endl;
        } else if (i = members.size() - 1){
            temp1 << members[i].getData() << endl << "END";
        }
    }

    file << temp1.str();

    for (int i = 0; i < lendings.size(); i++){
        if (i < members.size() -1) {
            temp2 << get<0>(lendings[i]) << ", " << get<1>(lendings[i]).showDate() << get<2>(lendings[i]) << endl;  //código do livro, data, membro
        } else if (i = members.size() - 1){
            temp2 << get<0>(lendings[i]) << ", " << get<1>(lendings[i]).showDate() << get<2>(lendings[i]) << endl << "END";
        }
    }

    filee << temp2.str();

    for (int i = 0; i < lendRequests.size(); i++){
        if (i < members.size() -1) {
            temp3 << get<0>(lendRequests[i]) << ", " << get<1>(lendRequests[i]).showDate() << get<2>(lendRequests[i]) << endl;  //código do livro, data, membro
        } else if (i = members.size() - 1){
            temp3 << get<0>(lendRequests[i]) << ", " << get<1>(lendRequests[i]).showDate() << get<2>(lendRequests[i]) << endl << "END";
        }
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

    for (int i = 0; i < delays.size(); i++){
        if (i < members.size() -1) {
            temp5 << get<0>(delays[i]) << ", " << get<1>(delays[i]) << get<2>(delays[i]) << endl;  //código do livro, data, membro
        } else if (i = members.size() - 1){
            temp5 << get<0>(delays[i]) << ", " << get<1>(delays[i]) << get<2>(delays[i]) << endl << "END";
        }
    }

    fileeeee << temp5.str();
}

void Club::retrieveData(){
    ifstream memb_file; memb_file.open("members.txt");
    ifstream bks_file; bks_file.open("books.txt");
    ifstream lendRs_file; lendRs_file.open("lendRequests.txt");
    ifstream lends_file; lends_file.open("lendings.txt");
    ifstream dels_file; dels_file.open("delays.txt");
    string temp;
    char sep = ',';
    stringstream membs, bks, lendRs, lends, dels;


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


