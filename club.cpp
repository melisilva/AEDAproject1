#include "club.h"
using namespace std;

Club::Club() {
    vector<Member> temp;
    vector<tuple<int, Date, int>> temp2, temp3,temp4;
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
    return true;
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
    return true;
}

int Club::isMember(int nif){ //returns member index or -1 if it doesn't exist
    for(unsigned int i = 0; i < members.size(); i++) {
        if (members[i].getNIF() == nif) {
            return i;
        }
    }
    return -1;
}

int Club::isnonMem(int nif){ //returns member index or -1 if it doesn't exist
    for(unsigned int i = 0; i < nonmembers.size(); i++) {
        if (nonmembers[i].getNIF() == nif) {
            return i;
        }
    }
    return -1;
}

void Club::chargeDelay(int nif,Book book,int delayp){
    float fine = book.getValue()*0.10;

    fine = fine*delayp;

    int index=isMember(nif);

    if(isMember(nif)!=-1){
        members[index].minusBalance(fine);
    }
    else{
        nonmembers[isnonMem(nif)].minusBalance(fine*2);
    }
}

void Club::chargeFee(int nif, Book book){
    float fee = book.getValue()*0.05;
    int index=isnonMem(nif);
    if(isnonMem(nif)!=-1){
        nonmembers[index].minusBalance(fee);
    }
}

int Club::calculateDelay(){
    int delayp;
    for (unsigned int i = 0; i < delays.size(); i++){
        delayp=abs(today.timePeriod(get<1>(delays[i])));
    }
    return delayp;
}

void Club::addBook(){
    string title, author, category, edition_s, owner_s;
    int edition, owner, code;

    cout <<"Introduza o seu título, por favor:"<< endl;
    getline(cin, title);
    cout << "Introduza o nome do seu escritor(a), por favor:" << endl;
    getline(cin, author);
    cout<<"Introduza a sua categoria, por favor:"<<endl;
    getline(cin,category);
    cout << "Introduza a sua edição, por favor:" << endl;
    getline(cin, edition_s);
    cout << "Introduza o dono do livro, por favor (NIF):" << endl;
    getline(cin, owner_s);
    edition = stoi(edition_s);
    owner = stoi(owner_s);
    code = catalog.books.size();
    Book b(code,title,author,category,edition, owner);
    catalog.addBook(b);
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
    vector <unsigned int> toDelv;
    members.erase(members.begin()+toDel);

    //Remover todos os livros do membro!
    for (unsigned int i = 0; i < catalog.books.size(); i++){
        if (catalog.books[i].getOwner() == nif) {
            toDelv.push_back(i);
        }
    }
    for(unsigned int j=0;j<toDelv.size();j++){
        if(j==0){
            catalog.books.erase(catalog.books.begin() + toDelv[j]);
        }
        else{
            catalog.books.erase(catalog.books.begin() + (toDelv[j]-j));
        }
    }

    catalog.updateCodes();
}

void Club::removeBook(string title,string owner,int edition){
    string memName;
    int value;
    for(unsigned int i=0;i<catalog.books.size();i++){
        if(catalog.books[i].getTitle()==title) {
            if (catalog.books[i].getEdition() == edition) {
                memName=catalog.books[i].getOwner();
                value=catalog.books[i].getValue();
                catalog.books[i].deleteUnit(true);
            }
        }
    }
    for(unsigned int i=0;i<members.size();i++){
        if(members[i].getName()==memName){
            members[i].addBalance(value);
        }
    }
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
        cout << get<0>(lendRequests[i]) << ", a " << get<1>(lendRequests[i]).getDateStr()<< " pelo " << get<2>(lendRequests[i]) << endl;
    }
}

void Club::showLendings() {
    for (unsigned int i = 0; i < lendings.size(); i++){
        cout << get<0>(lendings[i]) << ", a " << get<1>(lendings[i]).getDateStr() << " pelo " << get<2>(lendings[i]) << endl;
    }
}

void Club::showDelays() {
    for (unsigned int i = 0; i < delays.size(); i++){
        cout << get<0>(delays[i]) << ", desde " << get<1>(delays[i]).getDateStr() << " pelo " << get<2>(delays[i]) << endl;
    }
}

void Club::checkDelays(){
    string date1;
    int day1,month1,year1;
    for (unsigned int i = 0; i < lendings.size(); i++){
        if(abs(today.timePeriod(get<1>(lendings[i])))>=10){ //Consider lending period is 10 days
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

        this->lendRequests.push_back(make_tuple(code,today,nif));
        if(findMember(nif)!=-1) {
            members[findMember(nif)].registerRequest(code, today);
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
            m.registerRequest(code, today);
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
            if ((catalog.books[i].getTitle() == name) && (catalog.books[i].getState() == true)){
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

        this->lendRequests.push_back(make_tuple(code,today,nif));

        if(findMember(nif)!=-1) {
            members[findMember(nif)].registerRequest(code, today);
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
            m.registerRequest(code, today);
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
    string membs = "members.txt", lends = "lendings.txt", lendRs = "lendRequests.txt", bks = "books.txt", dels = "delays.txt";

    ofstream file(membs, ios::binary);
    ofstream filee(lends, ios::binary);
    ofstream fileee(lendRs, ios::binary);
    ofstream fileeee(bks, ios::binary);
    ofstream fileeeee(dels, ios::binary);

    stringstream temp1, temp2, temp3, temp4, temp5;

    for (int i = 0; i < members.size(); i++){
        if (i < members.size() -1) {
            temp1 << members[i].getData() << endl << endl << endl;
        } else if (i = members.size() - 1){
            temp1 << members[i].getData() << endl << endl << "END";
        }
    }

    file << temp1.str();

    for (int i = 0; i < lendings.size(); i++){
        if (i < lendings.size() -1) {
            temp2 << get<0>(lendings[i]) << endl << get<1>(lendings[i]).getDateStr() << endl << get<2>(lendings[i]) << endl << endl  << endl;  //código do livro, data, membro
        } else if (i = members.size() - 1){
            temp2 << get<0>(lendings[i]) << endl << get<1>(lendings[i]).getDateStr() << endl << get<2>(lendings[i]) << endl << endl << "END";
        }
    }

    filee << temp2.str();

    for (int i = 0; i < lendRequests.size(); i++){
        if (i < lendRequests.size() -1) {
            temp3 << get<0>(lendRequests[i]) << endl << get<1>(lendRequests[i]).getDateStr() << endl << get<2>(lendRequests[i]) << endl << endl  << endl;  //código do livro, data, membro
        } else if (i = members.size() - 1){
            temp3 << get<0>(lendRequests[i]) << endl << get<1>(lendRequests[i]).getDateStr() << endl << get<2>(lendRequests[i]) << endl << endl << "END";
        }
    }

    fileee << temp3.str();

    for (int i = 0; i < catalog.books.size(); i++){
        if (i < catalog.books.size() -1) {
            temp4 << catalog.books[i].getData() << endl << endl  << endl;
        } else if (i = members.size() - 1){
            temp4 << catalog.books[i].getData() << endl << endl << "END";
        }
    }

    fileeee << temp4.str();

    for (int i = 0; i < delays.size(); i++){
        if (i < members.size() -1) {
            temp5 << get<0>(delays[i]) << endl << get<1>(delays[i]).getDateStr() << endl << get<2>(delays[i]) << endl << endl  << endl;  //código do livro, data, membro
        } else if (i = members.size() - 1){
            temp5 << get<0>(delays[i]) << endl << get<1>(delays[i]).getDateStr() << endl << get<2>(delays[i]) << endl << endl << "END";
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
    int code_bk, units, opinions, sumRating, edition, owner;
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
        bks >> owner;
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
        bk.setEdition(edition); bk.setOwner(owner);
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
        do {
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
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

    //Getting lendRequests data.
    temp = "";
    string date;
    Date tmp;
    while (temp != "END") {
        getline(lendRs_file, temp);
        lendRs.str("");
        lendRs.clear();
        lendRs << temp;
        lendRs >> code;
        getline(lendRs_file, temp);
        lendRs.str("");
        lendRs.clear();
        lendRs << temp;
        lendRs >> date;
        getline(lendRs_file, temp);
        lendRs.str("");
        lendRs.clear();
        lendRs << temp;
        lendRs >> nif;
        lendRequests.push_back(make_tuple(code, tmp.getDate(date), nif));
        members[findMember(nif)].registerRequest(code, tmp.getDate(date));
        getline(lendRs_file, temp);
        lendRs.str("");
        lendRs.clear();
        getline(lendRs_file, temp);
        lendRs.str("");
        lendRs.clear();
    }

    //Getting lendings data.
    temp = "";
    Date tmp2;
    while (temp != "END") {
        getline(lends_file, temp);
        lends.str("");
        lends.clear();
        lends << temp;
        lends >> code;
        getline(lends_file, temp);
        lends.str("");
        lends.clear();
        lends << temp;
        lends >> date;
        getline(lends_file, temp);
        lends.str("");
        lends.clear();
        lends << temp;
        lends >> nif;
        lendings.push_back(make_tuple(code, tmp.getDate(date), nif));
        members[findMember(nif)].registerLending(code, tmp.getDate(date));
        getline(lends_file, temp);
        lends.str("");
        lends.clear();
        getline(lends_file, temp);
        lends.str("");
        lends.clear();
    }

    //Getting delays data.
    temp = "";
    Date tmp3;
    while (temp != "END") {
        getline(dels_file, temp);
        dels.str("");
        dels.clear();
        dels << temp;
        dels >> code;
        getline(dels_file, temp);
        dels.str("");
        dels.clear();
        dels << temp;
        dels >> date;
        getline(dels_file, temp);
        dels.str("");
        dels.clear();
        dels << temp;
        dels >> nif;
        delays.push_back(make_tuple(code, tmp3.getDate(date), nif));
        getline(dels_file, temp);
        dels.str("");
        dels.clear();
        getline(dels_file, temp);
        dels.str("");
        dels.clear();
    }    

    //This cleans the files.
    bks_file.close();
    bks_file.open("books.txt", std::ofstream::out | std::ofstream::trunc);
    memb_file.close();
    memb_file.open("members.txt", std::ofstream::out | std::ofstream::trunc);
    dels_file.close();
    dels_file.open("delays.txt", std::ofstream::out | std::ofstream::trunc);
    lends_file.close();
    lends_file.open("lendings.txt", std::ofstream::out | std::ofstream::trunc);
    lendRs_file.close();
    lendRs_file.open("lendRequests.txt", std::ofstream::out | std::ofstream::trunc);
    
    cout << "Files successfully removed!";
}
