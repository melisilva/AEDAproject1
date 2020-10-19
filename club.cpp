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

    //m.minusBalance(0.10*catalog.books[code].getValue());
    //nonmembers[isnonMem(nif)].minusBalance(0.10*catalog.books[code].getValue());
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

int Club::calculateDelay(Date date){
    /*int delayp;
    for (unsigned int i = 0; i < delays.size(); i++){
        delayp=abs(today.timePeriod(get<1>(delays[i])));
    }*/
    return abs(today.timePeriod(date));
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
    catalog.books.push_back(b);
    members[isMember(owner)].addBook(b);
}

void Club::addMember(){
    string name, answer, title, author, nif_s, edition_s, code_s, category;
    int nif, edition, code;
    Member mem;
    vector<Book*>books;
    cout<<"Introduza o seu nome, por favor:"<<endl;
    getline(cin,name);
    mem.setName(name);
    cout<<"Introduza o seu nif, por favor:"<<endl;
    getline(cin,nif_s);
    nif=stoi(nif_s);
    mem.setNif(nif);
    members.push_back(mem);
    cout << "Adicione um livro, por favor:"<< endl;
    do {
        addBook();
        cout << "Quer adicionar outro livro?"<<endl;
        getline(cin,answer);

    } while((answer=="S") || (answer=="Sim") || (answer=="sim") || (answer=="s"));

}

void Club::removeMember(int nif){
    if (isMember(nif) == -1){
        //exceção
    }

    int index = isMember(nif);
    vector<Book*> toDelv = members[index].getBooks();

    for (int i = 0; i < toDelv.size(); i++){
        catalog.books.erase(catalog.books.begin() + (*toDelv[i]).getCode());
    }
    
    /*unsigned toDel = isMember(nif);
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
    }*/

    catalog.updateCodes();
    members.erase(members.begin() + index);
}

void Club::removeBook(tuple<int, Date, int> lostBook){
    float value = catalog.books[get<0>(lostBook)].getValue();
    int owner = isMember(catalog.books[get<0>(lostBook)].getOwner());
    int perp = isMember(get<2>(lostBook));
    int index = members[owner].findBook(get<0>(lostBook));

    members[owner].addBalance(value);
    members[perp].minusBalance(value);
    members[perp].removeBook(index);
    catalog.books.erase(catalog.books.begin() + get<0>(lostBook));


    catalog.updateCodes();
    
    /*string memName;
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
    }*/
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
        cout << get<0>(lendings[i]) << ", a " << get<1>(lendings[i]).getDateStr() << " pelo membro " << get<2>(lendings[i]) << endl;
    }
}

void Club::showDelays() {
    for (unsigned int i = 0; i < delays.size(); i++){
        cout << get<0>(delays[i]) << ", desde " << get<1>(delays[i]).getDateStr() << " pelo membro " << get<2>(delays[i]) << endl;
    }
}

void Club::checkDelays(){
    string date1;
    int day1,month1,year1;
    for (unsigned int i = 0; i < lendings.size(); i++){
        if(abs(today.timePeriod(get<1>(lendings[i])))>=10){ //Consider lending period is 10 days
            this->delays.push_back(make_tuple(get<0>(lendings[i]),today,get<2>(lendings[i])));
            chargeDelay(get<2>(lendings[i]), catalog.getBook(get<0>(lendings[i])), calculateDelay(get<1>(lendings[i])));
            
            if (isMember(get<2>(lendings[i])) == -1){
                nonmembers[isnonMem(get<2>(lendings[i]))].finishLending(get<0>(lendings[i]), get<1>(lendings[i]));
            } else {
                members[isMember(get<2>(lendings[i]))].finishLending(get<0>(lendings[i]), get<1>(lendings[i]));
            }

            lendings.erase(lendings.begin() + i);
        }
    }
}

void Club::registerLoss(){
    string answer, code_st, date_st, nif_st;
    Date temp;
    bool lending = false;
    int code, nif;
    cout << "Para registarmos a perda, terá de identificar o empréstimo ou atraso." << endl;
    cout << "O livro perdido ainda estava num período de empréstimo válido? ";
    getline(cin, answer);

    if (answer == "S" || answer == "s" || answer == "sim" || answer == "Sim" || answer == "SIM"){
        lending = true;
        showLendings();

        cout << "A perda afetará o saldo." << endl;
        cout << "Indique o código do livro em questão: ";
        getline(cin, code_st);
        code = stoi(code_st);
        cout << "Indique a data de empréstimo (formato DD/MM/AAAA): ";
        getline(cin, date_st);
        temp = temp.getDate(date_st);
        cout << "Indique o NIF associado ao empréstimo: ";
        getline(cin, nif_st);
        nif = stoi(nif_st);

        for (int i = 0; i < lendings.size(); i++){
            if ((get<0>(lendings[i]) == code) && (get<1>(lendings[i]) == temp) && (get<2>(lendings[i]) == nif)){
                removeBook(make_tuple(code, temp, nif));
                lendings.erase(lendings.begin()+ i);
            }
        }
    } else {
        showDelays();

        cout << "A perda e o atraso afetarão o saldo." << endl;
        cout << "Indique o código do livro em questão: ";
        getline(cin, code_st);
        code = stoi(code_st);
        cout << "Indique a data de empréstimo (formato DD/MM/AAAA): ";
        getline(cin, date_st);
        temp = temp.getDate(date_st);
        cout << "Indique o NIF associado ao empréstimo: ";
        getline(cin, nif_st);
        nif = stoi(nif_st);

        for (int i = 0; i < delays.size(); i++){
            if ((get<0>(delays[i]) == code) && (get<1>(delays[i]) == temp) && (get<2>(delays[i]) == nif)){
                removeBook(make_tuple(code, temp, nif));
                delays.erase(lendings.begin()+ i);
            }
        }
    }

    if (isMember(nif) == -1){
        nonmembers[isnonMem(nif)].finishLending(code, temp);
    } else {
        members[isMember(nif)].finishLending(code, temp);
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

    while((code <= -1) || code >= catalog.books.size() || cin.fail() || code == ""){
        cout << "Indique, então, o título do livro: ";
        getline(cin,name);

        if (catalog.searchBook(name) == false){
            cerr << "EXCEÇÃO: não há livro com esse título.";
            continue;
        } else {
            cout << "Os livros disponíveis com esse título são: " << endl;
            for (int i = 0; i < catalog.books.size(); i++){
                if ((catalog.books[i].getTitle() == name) && (catalog.books[i].getState() == true)){
                    catalog.books[i].showBook();
                }
            }
        }

        cout << "Indique o código do livro que pretende: ";
        getline(cin, code_str);
        code = stoi(code_str);
    }

    //And now, to register it in Members or NonMembers.
    if(isMember(nif)!=-1) {
        if (members[isMember(nif)].getBalance() <= 0){
            //EXCEÇÃO! NÃO PODE FAZER PEDIDOS CASO O BALANÇO ESTEJA NEGATIVO/NULO.
            return false;
        }
        members[isMember(nif)].registerRequest(code, today);
        catalog.books[code].deleteUnit(true);
    } else { //it's not a member then it's a nonMem
        while (true){
            if (isnonMem(nif) == -1){
                string namem,nif_s;
                int nif;
                cout<<"Introduza o seu nome, por favor: "<<endl;
                getline(cin,namem);
                nonMem m(namem,nif);
                m.registerRequest(code, today);
                catalog.books[code].deleteUnit(true);
                nonmembers.push_back(m);
                break;
            } else {
                if ((isnonMem(nif) != -1) && (nonmembers[isnonMem(nif)].getBalance() > 0)) {
                    nonmembers[isnonMem(nif)].registerRequest(code, today);
                    break;
                } else if (nonmembers[isnonMem(nif)].getBalance() <= 0) {
                    //Exceção!
                    return false;
                } else {
                    continue;
                }
            }
        }
    }

        lendRequests.push_back(make_tuple(code,today,nif)); //registering the request in club
        return true;

    /*//Check if book with name introduced exists
    if(name != ""){

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

        if(isMember(nif)!=-1) {
            members[isMember(nif)].registerRequest(code, today);
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

    return false;*/
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
        members[isMember(nif)].registerRequest(code, tmp.getDate(date));
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
        members[isMember(nif)].registerLending(code, tmp.getDate(date));
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
