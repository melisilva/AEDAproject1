#include "club.h"

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
    string input;
    retrieveData();
    beginningInfo();
    do {
        cout << "O que pretende fazer? ";
        getline(cin, input);
        for_each(input.begin(), input.end(), [](char &c) {
            c = ::toupper(c);
        });
        if (input == "ADD_M"){
            addMember();
        }
        if (input == "REM_M"){
            string nif_s;
            int nif;
            cout<<"Lamentamos que nos esteja a deixar..."<<endl;
            cout<<"Por favor, insira o seu NIF para proceder: ";
            getline(cin,nif_s);
            nif=stoi(nif_s);
            removeMember(nif);
        }
        if (input == "ATL_P"){
            updatePerson();
        }
        if (input == "ADD_L"){
            addBook();
        }
        if (input == "LOSS"){
            registerLoss();
        }
        if (input == "REG_P"){
            makeRequest();
        }
        if (input == "MK_L"){
            makeLending();
        }
        if (input == "END_L"){
            returnLending();
        }
        if (input == "HELP"){
            help();
        }
    } while(input!="END");
    saveData();
}

void Club::beginningInfo() {
	cout << "Seja bem-vindo ao Sistema Informático do Clube de Leitura." << endl;
	cout << "Entre quaisquer processos, poderá relembrar-se dos códigos de acesso às" << endl;
	cout << "diferentes operações através da inserção do comando HELP/help seguida de ENTER." << endl;
	cout << "Durante a execução de uma operação (ex.: adição de um livro ao catálogo)," << endl;
	cout << "o que precisar de saber ser-lhe-à pedido de forma simples e sempre a procurar ajudá-lo." << endl;
	cout << "Poderá fechar o programa entre operações, inserindo o comando END/end seguida de ENTER." << endl;
	cout << "ATENÇÃO: Os dados do programa não são guardados (e, portanto, passa a ser impossível" << endl;
	cout << "recuperá-los na próxima vez que abrir o programa) caso não efetue a operação de término" << endl;
	cout << "especificada acima! O programa não possui implementação de protocolos de recuperação de dados:" << endl;
	cout << "dados perdidos, ficam perdidos para sempre!"<< endl;
	cout << "Desejamos que o SICL seja do seu agrado!" << endl;
	cout << endl;
	cout << endl;
	help();
}

void Club::help() {
	cout << "----- CÓDIGOS DE EXECUÇÃO -----" << endl;
	cout << endl;
	cout << " --- PROTOCOLOS AO NÍVEL DE FREQUÊNCIA (por Membros e não-Membros)  ---" << endl;
	cout << " ADD_M: adicionar membro" << endl;
	cout << " REM_M: remover membro" << endl;
	cout << " ATL_P: atualizar frequentador (para adição de saldo ou mudança de nome)" << endl;
	cout << endl;
	cout << " --- PROTOCOLOS AO NÍVEL DO CATÁLOGO --- " << endl;
	cout << " ADD_L: adicionar livro" << endl;
	cout << " LOSS: perda de livro" << endl;
	cout << " REG_P: registar pedido" << endl;
	cout << " MK_L: fazer/iniciar empréstimo" << endl;
	cout << " END_L: finalizar empréstimo" << endl;
	cout << endl;
	cout << " --- PROTOCOLOS AO NÍVEL DO SICL --- " << endl;
	cout << " HELP: ajuda" << endl;
	cout << " END: terminar/fechar programa" << endl;
	cout << endl;
	cout << " --- A NÃO ESQUECER --- " << endl;
	cout << "- Membros têm prioridade a fazer empréstimos" << endl;
	cout << "- Qualquer frequentante do Clube fica inibido de fazer pedidos ou empréstimos se o seu saldo for nulo/negativo" << endl;
	cout << "- Atrasos são registados automaticamente, havendo taxas cumulativas cobradas dirariamente" << endl;
	cout << "- Para qualquer frequentante poder fazer um empréstimo, tem de fazer pedido do livro primeiro" << endl;
	cout << "- Fechar sempre o SICL com o comando END" << endl;
    cout << endl;
    cout << endl;
}

void Club::updatePerson() {
	string answer, name;
    int nif;
    float quantity;
	cout << "Poderá mudar o nome e atualizar o saldo." << endl;
    cout << "Caso só deseje mudar o saldo, insira o mesmo nome abaixo." << endl;
    cout << "Caso só deseje mudar o nome, insira 0 na quantia abaixo." << endl;
    cout << "Indique o nome: ";
    getline(cin, answer);
    name = answer;
    cout << "Indique a quantia a adicionar (ex: 19.43): ";
    getline(cin, answer);
    quantity = stof(answer);
    cout << "Indique o NIF do frequentante: ";
	getline(cin, answer);
    nif = stoi(answer);
	

    if (true){
        //erros
    }

    int per = isMember(nif);

    if (per == -1){
        nonmembers[isnonMem(nif)].updateData(name, quantity);
    } else {
        members[per].updateData(name, quantity);
    }
}

bool Club::makeLending() {
    int nif = 0, code = -1, temp, i;
    string name, nif_str, code_str;
    bool nonMem = false;

    while (isMember(nif) == isnonMem(nif) || ((catalog.searchBook(code) == -1) && (code != -1))){
        cout << "Indique o seu NIF: ";
        getline(cin, nif_str);
        nif = stoi(nif_str);

        cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
        getline(cin, code_str);
        code = stoi(code_str);
        code = catalog.searchBook(code);

        if (code == -1){
            showLendRequests();
        }
    }

    //Is it a member or a nonMember?
    int pers = isMember(nif);
    if (pers == -1){
        pers = isnonMem(nif);
        nonMem = true;
    } 
    
    if (!nonMem){
        //Members do lendings per order of arrival.
        for (int i = 0; i < lendRequests.size(); i++){
            if ((get<0>(lendRequests[i]) == code) && (get<2>(lendRequests[i]) == nif)){
                catalog.books[code].deleteUnit();
                lendings.push_back(make_tuple(get<0>(lendRequests[i]), today, get<2>(lendRequests[i])));
                lendRequests.erase(lendRequests.begin()+ i);
                members[pers].registerLending(code, today);
                members[pers].finishRequest(code);
                break;
            }
        }
        return true;
    } else {
        //Checking priorities...
        for (int i = 0; i < lendRequests.size(); i++){
            if ((get<0>(lendRequests[i]) == code) && (get<2>(lendRequests[i]) != nif)){
                //throw
                return false;
            } else {
                temp = i;
            }
        }
        catalog.books[code].deleteUnit();
        lendings.push_back(make_tuple(get<0>(lendRequests[temp]), today, get<2>(lendRequests[temp])));
        lendRequests.erase(lendRequests.begin()+ i);
        nonmembers[pers].registerLending(code, today);
        nonmembers[pers].finishRequest(code);
    }
    return true;
}

bool Club::returnLending() {
    int nif = 0, code = -1;
    string name, nif_str, code_str, answer;
    bool nonMem = false;

    while (isMember(nif) == isnonMem(nif) || ((catalog.searchBook(code) == -1) && (code != -1))){
        cout << "Indique o seu NIF: ";
        getline(cin, nif_str);
        nif = stoi(nif_str);

        cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
        getline(cin, code_str);
        code = stoi(code_str);
        code = catalog.searchBook(code);

        cout << "Este é um atraso (S/N)? " << endl;
        getline(cin, answer);

        if (code == -1){
            showLendings();
            showDelays();
        }
    }

    int pers = isMember(nif);
    if (pers == -1){
        pers = isnonMem(nif);
    }

    catalog.books[code].addUnits();
    if (answer == "S" || answer == "s"){
        for (int i = 0; i < delays.size(); i++){
            if (get<0>(delays[i]) == code && get<2>(delays[i]) == nif){
                delays.erase(delays.begin()+i);
                return true;
            }
        }
    } else if (answer == "N" || answer == "n"){
        for (int i = 0; i < lendings.size(); i++){
            if (get<0>(lendings[i]) == code && get<2>(lendings[i]) == nif){
                lendings.erase(lendings.begin()+i);
                return true;
            }
        }
    }
    //throw a tantrum!
    return false;
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

void Club::chargeFirstDelay(int nif,Book book){
    float fine = book.getValue()*0.10;

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
    cout << "Introduza o seu NIF, por favor, para registarmos o livro na sua conta:" << endl;
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
    catalog.updateCodes();
    members.erase(members.begin() + index);
}

void Club::removeBook(tuple<int, Date, int> lostBook){
    float value = catalog.books[get<0>(lostBook)].getValue();
    int owner = isMember(catalog.books[get<0>(lostBook)].getOwner());
    int perp = isMember(get<2>(lostBook));
    if(perp==-1){
        perp=isnonMem(get<2>(lostBook));
    }
    int index = members[owner].findBook(get<0>(lostBook));

    members[owner].addBalance(value);
    if(perp!=-1){
        members[perp].minusBalance(value);
    }
    else{
        nonmembers[perp].minusBalance(value);
    }
    members[owner].removeBook(index);
    vector<int> codes, codes2;
    int code;
    for (int i = 0; i < lendRequests.size(); i++){
        if (get<0>(lendRequests[i]) == get<0>(lostBook)){
            codes.push_back(i);
        }
    }

    for (int i = 0; i < delays.size(); i++){
        if (get<0>(delays[i]) == get<0>(lostBook) && get<2>(delays[i]) == get<2>(delays[i])){
            codes2.push_back(i);
        }
    }
    
    for (int i = 0; i < codes.size(); i++){
        if (isMember(get<2>(lendings[codes[i]])) == -1){
            nonmembers[isnonMem(get<2>(lendings[codes[i]]))].deleteRequest(get<0>(lostBook));
        } else {
            members[isMember(get<2>(lendings[codes[i]]))].deleteRequest(get<0>(lostBook));
        }
        lendRequests.erase(lendRequests.begin() + codes[i]);
    }
    for (int i = 0; i < codes2.size(); i++){
        delays.erase(delays.begin() + codes2[i]);
    }
    catalog.books.erase(catalog.books.begin() + get<0>(lostBook));



    catalog.updateCodes();
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
    cout << "EMPRÉSTIMOS EM VIGOR:" << endl;
    for (unsigned int i = 0; i < lendings.size(); i++){
        cout << get<0>(lendings[i]) << ", a " << get<1>(lendings[i]).getDateStr() << " pelo membro " << get<2>(lendings[i]) << endl;
    }
}

void Club::showDelays() {
    cout << "ATRASOS:" << endl;
    for (unsigned int i = 0; i < delays.size(); i++){
        cout << get<0>(delays[i]) << ", desde " << get<1>(delays[i]).getDateStr() << " pelo membro " << get<2>(delays[i]) << endl;
    }
}

void Club::checkDelays(){
    string date1;
    int day1,month1,year1;

    for (int i = 0; i < delays.size(); i++){
        int perp = isMember(get<2>(delays[i]));
        if (perp == -1){
            perp = isnonMem(get<2>(delays[i]));
            nonmembers[perp].minusBalance(4);
        } else {
            members[perp].minusBalance(2);
        }
    }

    for (unsigned int i = 0; i < lendings.size(); i++){
        if(abs(today.timePeriod(get<1>(lendings[i])))>=10){ //Consider lending period is 10 days
            this->delays.push_back(make_tuple(get<0>(lendings[i]),today,get<2>(lendings[i])));
            chargeFirstDelay(get<2>(lendings[i]), catalog.getBook(get<0>(lendings[i])));
            
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

bool Club::makeRequest() {
    int nif, code;
    string date, name, nif_str, date_str, code_str;

    cout << "Indique o seu NIF: ";
    getline(cin, nif_str);
    nif = stoi(nif_str);

    cout << "Indique o código do livro (se não o souber, introduza -1 e dê ENTER): ";
    getline(cin, code_str);
    code = stoi(code_str);

    while ((code <= -1) || code >= catalog.books.size() || cin.fail()) {
        cout << "Indique, então, o título do livro: ";
        getline(cin, name);

        if (catalog.searchBook(name) == false) {
            cerr << "EXCEÇÃO: não há livro com esse título.";
            continue;
        } else {
            cout << "Os livros disponíveis com esse título são: " << endl;
            for (int i = 0; i < catalog.books.size(); i++) {
                if ((catalog.books[i].getTitle() == name) && (catalog.books[i].getState() == true)) {
                    catalog.books[i].showBook();
                }
            }
        }

        cout << "Indique o código do livro que pretende: ";
        getline(cin, code_str);
        code = stoi(code_str);
    }

    //And now, to register it in Members or NonMembers.
    if (isMember(nif) != -1) {
        if (members[isMember(nif)].getBalance() <= 0) {
            //EXCEÇÃO! NÃO PODE FAZER PEDIDOS CASO O BALANÇO ESTEJA NEGATIVO/NULO.
            return false;
        }
        members[isMember(nif)].registerRequest(code, today);
        catalog.books[code].deleteUnit();
    } else { //it's not a member then it's a nonMem
        while (true) {
            if (isnonMem(nif) == -1) {
                string namem, nif_s;
                int nif;
                cout << "Introduza o seu nome, por favor: " << endl;
                getline(cin, namem);
                float balance = 50;
                nonMem m(namem, nif, balance);
                m.registerRequest(code, today);
                catalog.books[code].deleteUnit();
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

    lendRequests.push_back(make_tuple(code, today, nif)); //registering the request in club
    return true;

}

void Club::saveData(){
    string membs = "members.txt", nonmembs = "nonmembers.txt", lends = "lendings.txt", lendRs = "lendRequests.txt", bks = "books.txt", dels = "delays.txt";

    ofstream file(membs, std::ofstream::out | std::ofstream::trunc);
    ofstream filee(lends, std::ofstream::out | std::ofstream::trunc);
    ofstream fileee(lendRs, std::ofstream::out | std::ofstream::trunc);
    ofstream fileeee(bks, std::ofstream::out | std::ofstream::trunc);
    ofstream fileeeee(dels, std::ofstream::out | std::ofstream::trunc);
    ofstream fileeeeee(nonmembs, std::ofstream::out | std::ofstream::trunc);

    stringstream temp1, temp2, temp3, temp4, temp5, temp6;

    for (int i = 0; i < members.size(); i++){
        if (i < members.size() -1) {
            temp1 << members[i].getData() << endl << endl << endl;
        } else if (i = members.size() - 1){
            temp1 << members[i].getData() << endl << endl << "END";
        }
    }

    file << temp1.str();

    for (int i = 0; i < nonmembers.size(); i++){
        if (i < nonmembers.size() -1) {
            temp6 << nonmembers[i].getData() << endl << endl;
        } else if (i = members.size() - 1){
            temp6 << nonmembers[i].getData() << endl << "END";
        }
    }

    fileeeeee << temp6.str();

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
    ifstream nmemb_file; nmemb_file.open("nonmembers.txt");
    string temp;
    char sep = ',';
    stringstream membs, bks, lendRs, lends, dels, nmembs;


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
    float balance;
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
        membs >> balance;
        do {
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
            membs >> code >> sep;
            int ind = catalog.searchBook(code);
            memb_bks.push_back(&catalog.books[ind]);
        } while (sep != ';');
        members.push_back(Member(name, nif, memb_bks, balance));
        getline(memb_file, temp);
        membs.str("");
        membs.clear();
        getline(memb_file, temp);
        membs.str("");
        membs.clear();
    }

    //Getting nonMembers data.
    temp = "";
    while (temp != "END"){
        getline(nmemb_file, temp);
        nmembs.str("");
        nmembs.clear();
        nmembs << temp;
        nmembs >> name;
        getline(nmemb_file, temp);
        nmembs.str("");
        nmembs.clear();
        nmembs << temp;
        nmembs >> nif;
        getline(nmemb_file, temp);
        nmembs.str("");
        nmembs.clear();
        nmembs << temp;
        nmembs >> balance;
        nonmembers.push_back(nonMem(name, nif, balance));
        getline(nmemb_file, temp);
        nmembs.str("");
        nmembs.clear();
        getline(nmemb_file, temp);
        nmembs.str("");
        nmembs.clear();
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
        if (isMember(nif) != -1){
            members[isMember(nif)].registerRequest(code, tmp.getDate(date));
        } else {
            nonmembers[isnonMem(nif)].registerRequest(code, tmp.getDate(date));
        }
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
        if (isMember(nif) != -1){
            members[isMember(nif)].registerLending(code, tmp.getDate(date));
        } else {
            nonmembers[isnonMem(nif)].registerLending(code, tmp.getDate(date));
        }
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

    checkDelays();
}
