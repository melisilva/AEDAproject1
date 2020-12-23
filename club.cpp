#include "club.h"
BStores b;

Club::Club() {
    vector<Member> temp;
    vector<tuple<int, Date, int>> temp2, temp3,temp4;
    Catalog temp5;
    //BStores temp6;

    members = temp;
    lendings = temp2;
    lendRequests = temp4;
    delays = temp3;
    catalog = temp5;
    //b=temp6;
}

void Club::run(){
    string input = "";
    bool valid;
    generateGenretable();
    retrieveData();
    beginningInfo();
    do {
        valid=false;
        cout << "O que pretende fazer? ";
        getline(cin, input);
        cout << endl;
        for_each(input.begin(), input.end(), [](char &c) {
            c = ::toupper(c);
        });
        if (input == "ADD_M"){
            valid=true;
            try{
                addMember();
            }
            catch(MemberAlreadyExists(nif)){
                colorText('C');
                cout<< "ERRO: Impossível adicionar o frequentante "<<nif.getInfo()<<" à lista de membros, pois este já é um."<<endl;
                colorText('F');
            }
        }
        if (input == "REM_M"){
            string nif_s;
            int nif;
            cout<<"Insira um NIF para proceder: ";
            while(!valid){
                getline(cin,nif_s);
                if(isdigit(nif_s[0])){
                    nif=stoi(nif_s);
                    valid=true;
                }
                else{
                    valid=false;
                    colorText('C');
                    cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
                    colorText('F');
                }
            }
            try{
                removeMember(nif);
            }
            catch(MemberDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Impossível eliminar o membro "<<nif.getInfo()<<", pois este não existe."<<endl;
                colorText('F');
            }
        }
        if(input == "GU_L"){
            string nif_s;
            int nif;
            cout<<"Insira um NIF para proceder: ";
            while(!valid){
                getline(cin,nif_s);
                if(isdigit(nif_s[0])){
                    nif=stoi(nif_s);
                    valid=true;
                }
                else{
                    valid=false;
                    colorText('C');
                    cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
                    colorText('F');
                }
            }
            try{
                givenuponBook(nif);
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
            catch(RequestDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O pedido especificado pelos dados ("<<code.getInfo().first<<", "<<code.getInfo().second<<") não existe." << endl;
                colorText('F');
            }

        }
        if (input == "ATL_P"){
            valid=true;
            try{
                updatePerson();
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
        }
        if(input == "SP_P"){
            string nif_s;
            int nif;
            cout<<"Insira um NIF para proceder: ";
            while(!valid){
                getline(cin,nif_s);
                if(isdigit(nif_s[0])){
                    nif=stoi(nif_s);
                    valid=true;
                }
                else{
                    valid=false;
                    colorText('C');
                    cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
                    colorText('F');
                }
            }
            try{
                showPersonRequests(nif);
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
        }
        if (input == "ADD_L"){
            valid=true;
            try{
                addBook(0);
            }
            catch(MemberDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum membro possui "<<nif.getInfo() << " como NIF."<<endl;
                colorText('F');
            }
        }
        if (input == "LOSS"){
            valid=true;
            try{
                registerLoss();
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
            catch(BookDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O livro especificado com o código "<<code.getInfo()<<" não existe no Clube." << endl;
                colorText('F');
            }
            catch(RequestDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O pedido especificado pelos dados ("<<code.getInfo().first<<", "<<code.getInfo().second<<") não existe." << endl;
                colorText('F');
            }
        }
        if (input == "REG_P"){
            valid=true;
            try{
                makeRequest();
            }
            catch(BookDoesNotExist(title)){
                colorText('C');
                cout << "ERRO: Não possuímos nenhum livro com o título '" <<title.getInfo()<< "'." << endl;
                colorText('F');
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
            catch(NegativeBalance(nif)){
                colorText('C');
                cout<< "ERRO: O frequentante "<<nif.getInfo()<<" não consegue pagar a taxa indicada, pois possui um balanço negativo."<<endl;
                colorText('F');
            }
        }
        if (input == "MK_L"){
            valid=true;
            try{
                makeLending();
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
            catch(BookDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O livro especificado com o código "<<code.getInfo()<<" não existe no Clube." << endl;
                colorText('F');
            }
            catch(RequestDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O pedido especificado pelos dados ("<<code.getInfo().first<<", "<<code.getInfo().second<<") não existe." << endl;
                colorText('F');
            }
        }
        if (input == "END_L"){
            valid=true;
            try{
                returnLending();
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
            catch(BookDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O livro especificado com o código "<<code.getInfo()<<" não existe no Clube." << endl;
                colorText('F');
            }
            catch(RequestDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O pedido especificado pelos dados ("<<code.getInfo().first<<", "<<code.getInfo().second<<") não existe." << endl;
                colorText('F');
            }
        }
        if(input=="REN_L"){
            valid=true;
            try{
                renovateLending();
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
            catch(BookDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O livro especificado com o código "<<code.getInfo()<<" não existe no Clube." << endl;
                colorText('F');
            }
            catch(RequestDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O pedido especificado pelos dados ("<<code.getInfo().first<<", "<<code.getInfo().second<<") não existe." << endl;
                colorText('F');
            }
            catch(NotAMember(nif)){
                colorText('C');
                cout << "ERRO: Renovar empréstimos é exclusivo para Membros do Clube. O NIF "<<nif.getInfo()<<" não identifica um Membro."<< endl;
                colorText('F');
            }
        }
        if (input == "HELP"){
            valid=true;
            help();
        }
        if (input == "SHO_M"){
            valid=true;
            showMembers();
        }
        if(input=="SHO_F"){
            valid=true;
            showAllFrequentants();
        }
        if(input=="SHO_1F"){
            string nif_s;
            int nif;
            while(!valid){
                cout<<"Insira um NIF para proceder: ";
                getline(cin,nif_s);
                if(isdigit(nif_s[0])){
                    nif=stoi(nif_s);
                    valid=true;
                }
                else{
                    valid=false;
                    colorText('C');
                    cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
                    colorText('F');
                }
            }
            try{
                showFrequentant(nif);
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }
        }
        if(input=="SHO_1L"){
            string code_s, title;
            int code;

            while(!valid){
                cout<<"Indique o código do livro (indique -1 caso não saiba o código): "<< endl;
                getline(cin,code_s);

                if(isdigit(code_s[0])){
                    code=stoi(code_s);
                    valid=true;
                }
                else if (code_s == "-1"){
                    cout << "Indique o título do livro (cada palavra iniciada por maiúscula): " << endl;
                    getline(cin, title);
                    try {
                        if (!catalog.searchBook(title)){
                            throw BookDoesNotExist(title);
                        } else {
                            cout << endl;
                            cout << "Códigos de Exemplares Disponíveis:";
                            for (int i = 0; i < catalog.books.size(); i++){
                                if (catalog.books[i].getTitle() == title){
                                    cout << " " << i;
                                }
                            }
                            cout << "." << endl << endl;
                            continue;
                        }
                    } catch (BookDoesNotExist(title)){
                        colorText('C');
                        cout << "ERRO: O livro especificado com o título "<<title.getInfo()<<" não existe no Clube." << endl;
                        colorText('F');
                    }

                } else {
                    valid = false;
                    colorText('C');
                    cout<<"Por favor, indique um código válido (um número maior que 0)."<<endl;
                    colorText('F');
                }
            }


            try{
                showABook(code);
            }
            catch(BookDoesNotExist(code)){
                colorText('C');
                cout << "ERRO: O livro especificado com o código "<<code.getInfo()<<" não existe no Clube." << endl;
                colorText('F');
            }

        }
        if (input == "SHO_A"){
            valid=true;
            showDelays();
        }
        if (input == "SHO_E"){
            valid=true;
            showLendings();
        }
        if (input == "SHO_N"){
            valid=true;
            showNonMembers();
        }
        if (input == "SHO_Q"){
            valid=true;
           showQueues();
        }
        if (input == "SHO_L"){
            valid=true;
            showBooks();
        }
        if (input == "SH_LR"){
            valid=true;
            showShopsByRating();
        }
        if (input == "SH_LIR"){
            valid=true;
            showShopsInRange();
        }
        if(input == "SH_SB"){
            valid=true;
            showShopsBySpecificBook();
        }
        if(input == "AT_PR"){
            valid=true;
            try{
            updatePreferences();
            }
            catch(EmailDoesNotExist(email)){
                colorText('C');
                cout<< "ERRO: Nenhum membro possui "<<email.getInfo() << " como email." <<endl;
                colorText('F');
            }
        }
        if(input == "BUY_L"){
            bool valid;
            string nif_s;
            int nif;
            cout<<"Insira um NIF para proceder: ";
            while(!valid){
                getline(cin,nif_s);
                if(isdigit(nif_s[0])){
                    nif=stoi(nif_s);
                    valid=true;
                }
                else{
                    valid=false;
                    colorText('C');
                    cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
                    colorText('F');
                }
            }
            try{
            buyBook(nif,-1);
            }
            catch(NIFDoesNotExist(nif)){
                colorText('C');
                cout<< "ERRO: Nenhum frequentante possui "<<nif.getInfo() << " como NIF." <<endl;
                colorText('F');
            }

catch(NotAMember(nif)){
                colorText('C');
                cout << "ERRO: Renovar empréstimos é exclusivo para Membros do Clube. O NIF "<<nif.getInfo()<<" não identifica um Membro."<< endl;
                colorText('F');
            }

catch(NegativeBalance(nif)){
                colorText('C');
                cout<< "ERRO: O frequentante "<<nif.getInfo()<<" não consegue pagar a taxa indicada, pois possui um balanço negativo."<<endl;
                colorText('F');
            }

        }
        if(!valid && (input != "end" && input != "END")){
            colorText('C');
            cout<<"Input inválido...por favor tente de novo"<<endl;
            colorText('F');
        }
    } while(input!="END");
    saveData();
    exit(0);
}

void Club::showBooks(){
    catalog.showBooks();
}

void Club::beginningInfo() {
    cout << "Seja bem-vindo ao Sistema Informático do Clube de Leitura." << endl << endl;
    cout << "Entre quaisquer processos, poderá relembrar-se dos códigos de acesso" << endl;
    cout << "às diferentes operações através da inserção do comando HELP + pressionar ENTER." << endl;
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
    colorText('C');
    cout << " --- PROTOCOLOS AO NÍVEL DE FREQUÊNCIA (por Membros e não-Membros)  ---" << endl;
    cout << " ADD_M: adicionar membro" << endl;
    cout << " REM_M: remover membro" << endl;
    cout << " ATL_P: atualizar frequentador (para adição de saldo, mudança de nome ou e-mail)" << endl;
    cout << " AT_PR: atualizar preferências de um membro" << endl;
    cout << " SHO_M: mostrar membros" << endl;
    cout << " SHO_N: mostrar não-membros" << endl;
    cout << " SHO_1F: mostrar um frequentante" << endl;
    cout << " SHO_F: mostrar frequentantes (membros e não membros)" << endl;
    cout << " BUY_L: possibilidade de frequentantes comprarem um livro"<<endl;
    cout << endl;
    colorText('B');
    cout << " --- PROTOCOLOS AO NÍVEL DO CATÁLOGO --- " << endl;
    cout << " ADD_L: adicionar livro" << endl;
    cout << " LOSS: perda de livro" << endl;
    cout << " REG_P: registar pedido" << endl;
    cout << " MK_L: fazer/iniciar empréstimo" << endl;
    cout << " GU_L: desistir de um empréstimo"<<endl;
    cout << " END_L: finalizar empréstimo" << endl;
    cout << " REN_L: renovar empréstimo" << endl;
    cout << " SHO_L: mostrar livros" << endl;
    cout << " SHO_1L: mostrar um livro" << endl;
    cout << " SHO_E: mostrar empréstimos" << endl;
    cout << " SHO_A: mostrar atrasos" << endl;
    //cout << " SHO_P: mostrar pedidos" << endl;
    cout << "SHO_Q: mostrar filas de espera para cada livro"<<endl;
    cout << endl;
    colorText('D');
    cout << " --- PROTOCOLOS AO NÍVEL DO SICL --- " << endl;
    cout << " SH_LR: mostrar lojas fidelizadas com o Clube (ordenadas por ordem decrescente de avaliação)" << endl;
    cout << " SH_LIR: mostrar lojas fidelizadas com o Clube (de classificação entre um mínimo e máximo - inclusive)" << endl;
    cout << " SH_SB : mostrar lojas fidelizadas com o Clube (que tenham disponível um livro especifico) " << endl;
    cout << " HELP: ajuda" << endl;
    cout << " END: terminar/fechar programa" << endl;
    cout << endl;
    colorText('F');
    cout << " --- A NÃO ESQUECER --- " << endl;
    cout << "- Membros têm prioridade a fazer empréstimos" << endl;
    cout << "- Qualquer frequentante do Clube fica inibido de fazer pedidos ou empréstimos se o seu saldo for nulo/negativo" << endl;
    cout << "- Atrasos são registados automaticamente, havendo taxas cumulativas cobradas dirariamente" << endl;
    cout << "- Para qualquer frequentante poder fazer um empréstimo, tem de fazer pedido do livro primeiro" << endl;
    colorText('C');
    cout << "- Fechar sempre o SICL com o comando END" << endl;
    colorText('F');
    cout << endl;
    cout << endl;
}

void Club::updatePerson() {
    bool valid=false;
    string answer, name, eMail;
    int nif;
    float quantity;
    cout << "Poderá mudar o nome e atualizar o saldo." << endl;
    cout << "Caso só deseje mudar o saldo e/ou o e-mail, insira o mesmo nome abaixo." << endl;
    cout << "Caso só deseje mudar o nome e/ou o e-mail, insira 0 na quantia abaixo." << endl;
    cout << "Caso só deseje mudar o seu nome e/ou saldo, insira o mesmo e-mail abaixo." << endl;
    cout << "Indique o nome: ";
    getline(cin, answer);
    name = answer;
    while(!valid){
        cout << "Indique a quantia a adicionar (ex: 19.43): ";
        getline(cin, answer);
        if(isdigit(answer[0])){
            quantity = stof(answer);
            valid=true;
        }else{
            valid=false;
            colorText('C');
            cout<<"Por favor, indique uma quantia válida."<<endl;
            colorText('F');
        }
    }
    cout << "Indique o mail do frequentante: ";
    getline(cin, eMail);

    valid=false;
    while(!valid){
        cout << "Indique o NIF do frequentante: ";
        getline(cin, answer);
        if(isdigit(answer[0])){
            nif = stoi(answer);
            valid=true;
        }
        else{
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
            colorText('F');
        }
    }

    if (isMember(nif) == isnonMem(nif)){
        //Nenhum frequentante tem o NIF especificado!
        throw NIFDoesNotExist(nif);
    }

    int per = isMember(nif);

    if (per == -1){
        nonmembers[isnonMem(nif)].updateData(name, quantity, eMail);
    } else {
        
        updateTable(members[per].getEmail(),eMail);
        members[per].updateData(name, quantity, eMail);
    }
}

bool Club::makeLending() {
    bool valid=false;
    bool exist=false;
    bool request=false;
    int nif = 0, code = -1, temp, i;
    string name, nif_str, code_str;
    bool nonMem = false;
    int isMem = isMember(nif), isNMem = isnonMem(nif);

    while(!valid){
        cout << "Indique o NIF: ";
        getline(cin, nif_str);
        if(isdigit(nif_str[0])){
            nif = stoi(nif_str);
            isMem = isMember(nif);
            isNMem = isnonMem(nif);
            if(isMem!=isNMem){
                valid=true;
            }
            else{
                throw NIFDoesNotExist(nif);
            }
        }else{
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
            colorText('F');
        }
    }

    valid=false;
    while(!valid){
        cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
        getline(cin, code_str);
        if(isdigit(code_str[0])){
            valid=true;
            code = stoi(code_str);
        }
        if(code_str[0]=='-'){
            valid=true;
            code = stoi(code_str);
        }
        if(!valid){
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um número válido."<<endl;
            colorText('F');
        }
        int id;
        id = catalog.searchBook(code);
        if(id==-1){
            valid=false;
             if(isMember(nif)!=-1){
                members[isMember(nif)].showLendRequests();
            }
            else{
                nonmembers[isnonMem(nif)].showLendRequests();
            }
        }
    }

    //Is it a member or a nonMember?
    int pers = isMem;
    if (pers == -1){
        pers = isNMem;
        nonMem = true;
    }

    int counter=0;

    if (!nonMem){ //Member-->ratio
            int index=catalog.searchBook(code);
            HeapMember line= catalog.books[index].getHeapM();
            if(line.empty()){
                throw RequestDoesNotExist(code,nif);
            }
            if(line.top().getNIF() == members[isMember(nif)].getNIF()){
                 if(catalog.books[index].getUnits()!=0){
                        catalog.books[index].deleteUnit();
                        lendings.push_back(make_tuple(code, today,nif));
                        catalog.books[index].deleteHeapM(members[isMember(nif)]); //delete member from queue
                        members[pers].registerLending(code, today);
                        members[pers].finishRequest(code);
                        members[pers].addBooktaken();
                        updateHeap(nif);
                    }
                    else{
                        colorText('C');
                        cout<<"Infelizmente, o livro especificado não se encontra disponível."<<endl;
                        colorText('F');
                    }
            }
            else{
                colorText('C');
                cout<<"Existem outros frequentantes à sua frente na fila para requisitar este livro. Terá de aguardar a sua vez."<<endl;
                colorText('F');
            }
       
        return true;
    } else {
        //Checking priorities...
        int index=catalog.searchBook(code);
        HeapNonMem line=catalog.books[index].getHeapNM();
        if(line.empty()){
            throw RequestDoesNotExist(code,nif);
        }
        if(catalog.books[index].getHeapM().empty()){
            if(line.top().getNIF()==nonmembers[isnonMem(nif)].getNIF()){
                if(catalog.books[index].getUnits()!=0){
                    catalog.books[index].deleteUnit();
                    lendings.push_back(make_tuple(code, today,nif));
                    catalog.books[index].deleteHeapNM(nonmembers[isnonMem(nif)]);
                    nonmembers[pers].registerLending(code, today);
                    nonmembers[pers].finishRequest(code);
                    nonmembers[pers].addBooktaken();
                    updateHeap(nif);
                    chargeFee(pers, catalog.books[index]);
        }
        else{
            colorText('C');
            cout<<"Infelizmente, o livro especificado não se encontra disponível."<<endl;
            colorText('F');
        }
            }
            else{
                colorText('C');
                cout<<"Existem outros frequentantes à sua frente na fila para requisitar este livro. Terá de aguardar a sua vez."<<endl;
                colorText('F');
            }
        }
        else{
            cout<<"O livro solicitado foi requisitado foi pedido por um membro. Terá de aguardar a sua vez."<<endl;
        }
    }
    return true;
}

bool Club::renovateLending(){
    int nif = 0, code = -1;
    string name, nif_str, code_str, answer;
    bool nonMem = false;
    bool valid=false;
    bool exist=false;
    bool lending=false;
    int isMem = isMember(nif), isNMem = isnonMem(nif);
    while(!valid){
        cout << "Indique o NIF: ";
        getline(cin, nif_str);
        if(isdigit(nif_str[0])){
            nif = stoi(nif_str);
            isMem = isMember(nif);
            isNMem = isnonMem(nif);
            if(isMem!=isNMem){
                valid=true;
            }
            else{
                throw NIFDoesNotExist(nif);
            }
        }else{
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
            colorText('F');
        }
    }
    valid=false;

    if (isMem != -1) {
        while(!valid){
            cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
            getline(cin, code_str);
            if(isdigit(code_str[0])){
                valid=true;
                code = stoi(code_str);
            }
            if(code_str[0]=='-'){
                valid=true;
                code = stoi(code_str);
            }
            if(!valid){
                valid=false;
                colorText('C');
                cout<<"Por favor, indique um número válido."<<endl;
                colorText('F');
            }
            int id;
            id = catalog.searchBook(code);
            if(id==-1){
                valid=false;
                showLendings();
            }
        }
    }else {
        throw NotAMember(nif);
    }
    int index;
    for(int i=0;i<catalog.books.size();i++){
        if(catalog.books[i].getCode()==code){
            index=i;
        }
    }

    if(catalog.books[index].getOguni()==1){
        colorText('C');
        cout<<"O livro especificado está interdito de renovações (por ser a única unidade existente)."<<endl;
        colorText('F');
        return false;
    }
    else{
        bool another=false;
        if(catalog.books[index].getHeapM().empty() && catalog.books[index].getHeapNM().empty()){
            another =true;
        }
        
        if(another==false) {
            for (int i = 0; i < lendings.size(); i++) {
                if (get<0>(lendings[i]) == code) {
                    exist = true;
                }
                if (get<0>(lendings[i]) == code && get<2>(lendings[i]) == nif) {
                    lending = true;
                    Date dt2 = get<1>(lendings[i]);
                    dt2.extendTime();
                    if (abs(today.timePeriod(dt2)) <= 3) {
                        get<1>(lendings[i]) = today;
                        cout << endl;
                        members[isMem].renovateLending(code, today);
                        return true;
                    } else {
                        colorText('C');
                        cout
                                << "A renovação de livros só é possível a três ou menos dias antes do fim do prazo do seu empréstimo."
                                << endl;
                        colorText('F');
                    }
                }
            }
        }
        if(another){
            colorText('C');
            cout
                    << "A renovação de livros só é possível quando não  há  registo  de  um  pedido  em  espera."
                    << endl;
            colorText('F');
        }
        if(!lending){
            throw RequestDoesNotExist(code,nif);
        }
        if(!exist){
            throw BookDoesNotExist(code);
        }
    }
    return false;
}

bool Club::returnLending() {
    int nif = 0, code = -1;
    string name, nif_str, code_str, answer;
    bool nonMem = false;
    bool valid=false;
    bool exist=false;
    bool request=false;
    int isMem = isMember(nif), isNMem = isnonMem(nif);

    while(!valid){
        cout << "Indique o NIF: ";
        getline(cin, nif_str);
        if(isdigit(nif_str[0])){
            nif = stoi(nif_str);
            isMem = isMember(nif);
            isNMem = isnonMem(nif);
            if(isMem!=isNMem){
                valid=true;
            }
            else{
                throw NIFDoesNotExist(nif);
            }
        }else{
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um NIF válido (número de 9 algarismos)."<<endl;
            colorText('F');
        }
    }

    valid=false;
    while(!valid){
        cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
        getline(cin, code_str);
        if(isdigit(code_str[0])){
            valid=true;
            code = stoi(code_str);
        }
        if(code_str[0]=='-'){
            valid=true;
            code = stoi(code_str);
        }
        if(!valid){
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um número válido."<<endl;
            colorText('F');
        }
        int id;
        id = catalog.searchBook(code);
        if(id==-1){
            valid=false;
            showLendings();
            showDelays();
        }
    }

    answer="N";
    for (int i = 0; i < delays.size(); i++){
        if (get<0>(delays[i]) == code){
            exist=true;
            answer="S";
        }
    }

    int pers = isMember(nif);
    if (pers == -1){
        pers = isnonMem(nif);
    }

    int index;
    for(int i=0;i<catalog.books.size();i++){
        if(catalog.books[i].getCode()==code){
            index=i;
        }
    }

    catalog.books[index].addUnits();
    if (answer == "S"){
        for (int i = 0; i < delays.size(); i++){
            if (get<0>(delays[i]) == code && get<2>(delays[i]) == nif){
                request=true;
                delays.erase(delays.begin()+i);
                getOpinions(code);
                if(isMember(nif)!=-1){
                    members[isMember(nif)].subBooktaken();
                    members[isMember(nif)].calculateRatio();
                }
                else{
                    nonmembers[isnonMem(nif)].subBooktaken();
                }
                updateHeap(nif);
                return true;
            }
        }
    } else if (answer == "N"){
        for (int i = 0; i < lendings.size(); i++){
            if(get<0>(lendings[i])==code){
                exist=true;
            }
            if (get<0>(lendings[i]) == code && get<2>(lendings[i]) == nif){
                request=true;
                lendings.erase(lendings.begin()+i);
                getOpinions(code);
                if(isMember(nif)!=-1){
                    members[isMember(nif)].subBooktaken();
                    members[isMember(nif)].calculateRatio();
                }
                else{
                    nonmembers[isnonMem(nif)].subBooktaken();
                }
                updateHeap(nif);
                return true;
            }
        }
    }
    if(!request){
        throw RequestDoesNotExist(code,nif);
    }
    if(!exist){
        throw BookDoesNotExist(code);
    }
    return false;
}

void Club::getOpinions(int code){
    string int_answer,answer,writ_answer;
    int rating;
    bool valid=false;
    while(!valid){
        cout<<"Introduza uma opinião de 1 a 5 sobre o livro, por favor : "<<endl;
        getline(cin,int_answer);
        if(isdigit(int_answer[0])){
            rating = stoi(int_answer);
            valid=true;
        }
        else{
            valid=false;
            colorText('C');
            cout<<"Por favor, indique uma avaliação válida (um número de 0 a 5)."<<endl;
            colorText('F');
        }
    }
    int index;
    for(int i=0;i<catalog.books.size();i++){
        if(catalog.books[i].getCode()==code){
            index=i;
        }
    }
    catalog.books[index].calculateRating(rating);
    valid=false;
    while(!valid){
        cout<<"O frequentante deseja introduzir uma opinião detalhada sobre o livro? ";
        getline(cin,answer);
        if(answer=="Sim"|| answer=="S" || answer=="s" || answer=="sim" || answer == "SIM"){
            valid=true;
            cout<<"Introduza, então, a opinião transcrita: "<<endl;
            getline(cin,writ_answer);
            catalog.books[index].addWritops(writ_answer);
            cout<<"Agradeça ao frequentante pela sua colaboração!"<<endl;
        }
        if(answer=="Não"|| answer=="N" || answer=="n" || answer=="não" || answer == "NÃO"){
            valid=true;
            cout<<"Agradeça ao frequentante pela sua colaboração!"<<endl;

        }
        if(!valid){
            valid=false;
            colorText('C');
            cout<<"Por favor, introduza uma resposta válida (Sim ou Não)."<<endl;
            colorText('F');
        }
    }
}

int Club::isMember(int nif){ //returns member index or -1 if it doesn't exist
    for(int i = 0; i < members.size(); i++) {
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

void Club::addBook(int nif = 0){
    string title, author, category, edition_s, owner_s;
    int edition, owner, code;
    bool valid=false;


    cout <<"Introduza o seu título, por favor: ";
    getline(cin, title);
    cout << endl;
    cout << "Introduza o nome do seu escritor(a), por favor: " ;
    getline(cin, author);
    cout << endl;
    cout<<"Introduza a sua categoria, por favor: ";
    getline(cin,category);
    cout << endl;
    while(!valid){
        cout << "Introduza a sua edição, por favor: ";
        getline(cin, edition_s);
        if(isdigit(edition_s[0])){
            edition = stoi(edition_s);
            valid=true;
        }
        else{
            valid=false;
            colorText('C');
            cout<<"Indique uma edição válida para o livro (um número)."<<endl;
            colorText('F');
        }
    }
    cout << endl;

    valid=false;

    while(!valid){
        if (nif == 0){
            cout << "Introduza, por favor, um NIF, de modo a registarmos o livro na conta respetiva: ";
            getline(cin, owner_s);
        }
        cout << endl;
        owner = nif;

        if (owner == 0){
            if(isdigit(owner_s[0])){
                valid=true;
                owner = stoi(owner_s);
                if(isMember(owner)==-1){
                    throw MemberDoesNotExist(nif);
                }
            }
            else{
                valid=false;
                colorText('C');
                cout<<"Por favor, introduza um NIF válido (número de 9 algarismos associado a um frequentante)."<<endl;
                colorText('F');
            }
        }
        else{
            valid=true;
        }
    }
    if(catalog.books.size()==0){
        code=0;
    }
    else{
        code = catalog.books[catalog.books.size()-1].getCode()+1;
    }
    int unit=1; int oguni=1;
    Book* b = new Book(code,title,author,category,edition, owner,unit,oguni);
    catalog.addBook((*b));
    members[isMember(owner)].addBookgiven();
    members[isMember(owner)].calculateRatio();
    updateHeap(owner);
}

void Club::addMember(){
    string name = "", eMail, answer, title, author, nif_s, edition_s, code_s, category;
    int nif, edition, code;
    Member* mem = new Member;
    bool valid=false;
    cout<<"Introduza o nome, por favor: ";
    getline(cin,name);
    cout << "Introduza o e-mail, por favor: ";
    getline(cin, eMail);
    cout << endl;
    (*mem).setName(name);
    while(!valid){
        cout<<"Introduza o NIF, por favor: ";
        getline(cin,nif_s);
        cout << endl;
        if(isdigit(nif_s[0])){
            valid=true;
            nif=stoi(nif_s);
            if(isMember(nif)!=-1){
                throw MemberAlreadyExists(nif);
            }
            if(isnonMem(nif)!=-1){
                nonmembers.erase(nonmembers.begin() + isnonMem(nif));
            }
        }
        else{
            valid=false;
            colorText('C');
            cout<<"Introduza um NIF válido (número de 9 algarismos)."<<endl;
            colorText('F');
        }
    }
    (*mem).setNif(nif);
    (*mem).setEmail(eMail);
    members.push_back((*mem));
    cout << "Adicione um livro, por favor!" << endl << endl;
    do {
        addBook(nif);
        cout << "Quer adicionar outro livro? ";
        getline(cin,answer);
    } while((answer=="S") || (answer=="Sim") || (answer=="sim") || (answer=="s"));
    vector<string> tempPreferences(5, "ASE");
    Info tempInf(eMail, tempPreferences);
    Preferences.insert(tempInf);
    cout << "Todas as suas preferências estão marcadas como ASE - A Ser Escolhido." << endl << "Daqui em diante, é possível atualizá-las através do comando AT_PR." << endl;
}

bool Club::removeMember(int nif){
    if (isMember(nif) == -1){
        throw MemberDoesNotExist(nif);
    }


    int index = isMember(nif);
    vector<Book> toDelv;
    for(int i=0;i<catalog.books.size();i++){
        if(catalog.books[i].getOwner() == nif){
            toDelv.push_back(catalog.books[i]);
        }
    }

    for (int i = 0; i < toDelv.size(); i++){
        if (toDelv[i].getState() == false || toDelv[i].getMulti()==false){
            colorText('C');
            cout << "A eliminação de um membro só é possível quando este não tem livros a ser emprestados!" << endl;
            cout << "Verifique os empréstimos e informe o membro da data em que poderá deixar o Clube." << endl;
            colorText('F');
            return false;
        }
    }

    for(int i=0;i<lendings.size();i++){
        if(get<2>(lendings[i])==nif){
            colorText('C');
            cout << "A eliminação de um membro só é possível quando este não tem livros emprestados do Clube!" << endl;
            cout << "Peça ao membro para devolver os livros, de modo a sair do Clube." << endl;
            cout<<  "Ou que os declare como perdidos, caso não saiba do paredeiro deles. "<<endl;
            colorText('F');
            return false;
        }
    }

    for(int i=0;i<delays.size();i++){
        if(get<2>(delays[i])==nif){
            colorText('C');
            cout << "A eliminação de um membro só é possível quando este não tem livros emprestados do Clube!" << endl;
            cout << "Peça ao membro para devolver os livros, de modo a sair do Clube." << endl;
            cout<<  "Ou que os declare como perdidos, caso não saiba do paredeiro deles. "<<endl;
            colorText('F');
            return false;
        }
    }

    vector<int> indtoDel;

    for (int i = 0; i < toDelv.size(); i++){
        for(int k=0;k<catalog.books.size();k++){
            if(catalog.books[k]==toDelv[i]){
                catalog.books[k].deleteHeapM(members[index]);
                indtoDel.push_back(k);
            }
        }
    }

    for(int i=0;i<indtoDel.size();i++){
        catalog.books.erase(catalog.books.begin() + indtoDel[i]);
    }

    Preferences.erase(Preferences.find(members[index].getEmail()));
    members.erase(members.begin() + index);
    return true;
}

void Club::removeBook(tuple<int, Date, int> lostBook) {
    float value = catalog.books[get<0>(lostBook)].getValue();
    int owner = isMember(catalog.books[get<0>(lostBook)].getOwner());

    members[owner].addBalance(value);

    int perp = isMember(get<2>(lostBook));
    if (perp == -1) {
        perp = isnonMem(get<2>(lostBook));
        nonmembers[perp].minusBalance(value);
    } else {
        members[perp].minusBalance(value);
    }

    if (catalog.books[get<0>(lostBook)].getUnits() == 0) {
        vector<int> codes, codes2;
        HeapMember test=catalog.books[get<0>(lostBook)].getHeapM();
        int code;
        for (int i = 0; i < lendRequests.size(); i++) {
            if (get<0>(lendRequests[i]) == get<0>(lostBook)) {
                codes.push_back(i);
            }
        }

        for (int i = 0; i < delays.size(); i++) {
            if (get<0>(delays[i]) == get<0>(lostBook)) {
                codes2.push_back(i);
            }
        }

        for (int i = 0; i < codes.size(); i++) {
            if (isMember(get<2>(lendRequests[codes[i]])) == -1) {
                nonmembers[isnonMem(get<2>(lendRequests[codes[i]]))].deleteRequest(get<0>(lostBook));
            } else {

                members[isMember(get<2>(lendRequests[codes[i]]))].deleteRequest(get<0>(lostBook));
            }
            lendRequests.erase(lendRequests.begin() + codes[i]-i);
        }

        for (int i = 0; i < codes2.size(); i++) {
            delays.erase(delays.begin() + codes2[i]-i);
        }

        for(int i=0;i<catalog.books.size();i++){
            if(catalog.books[i].getCode()==get<0>(lostBook)){
                catalog.books.erase(catalog.books.begin() + i);
            }
        }

    }
    else{
        for(int i=0;i<catalog.books.size();i++){
            if(catalog.books[i].getCode()==get<0>(lostBook)){
                catalog.books[i].deleteUnit();
                catalog.books[i].deleteOgunit();
            }
        }
    }
}

void Club::showMembers(){
    for (int i = 0; i < members.size(); i++){
        cout << "Nome: " << members[i].getName() << endl << "NIF: "<< members[i].getNIF() << endl <<setprecision(2)<<members[i].getBalance()<<" euros"<<endl<< "Livros:" << endl;
        vector<Book>books;
        for(int i=0;i<catalog.books.size();i++){
            if(catalog.books[i].getOwner() == members[i].getNIF()){
                books.push_back(catalog.books[i]);
            }
        }

        for (int j = 0; j < books.size(); j++){
            cout << "   - " << books[j].getTitle() << " (" << books[j].getCode() << "), de " << books[j].getAuthor() << ", "<< books[j].getEdition() << " edicao" <<" (" << books[j].getRating() << "/5), do membro " << books[j].getOwner() <<", "<<books[j].getOguni()<<" unidades"<<endl << "Comentários do Livro: " << endl << books[j].getWritops();
        }
        cout << endl << endl;
    }
}

void Club::showFrequentant(int nif){
    int i1=isMember(nif);
    int i2=isnonMem(nif);
    if(i1==i2){
        throw NIFDoesNotExist(nif);
    }
    if(i1==-1){
        int index=isnonMem(nif);
        cout << "Nome: " << nonmembers[i2].getName() << endl << "NIF: "<< nonmembers[i2].getNIF() << endl <<setprecision(2)<<nonmembers[i2].getBalance()<<" euros"<<endl;
    }
    else{
        cout << "Nome: " << members[i1].getName() << endl << "NIF: "<< members[i1].getNIF() << endl <<setprecision(2)<<members[i1].getBalance()<<" euros"<<endl<< "Livros:" << endl;
       vector<Book>books;
        for(int i=0;i<catalog.books.size();i++){
            if(catalog.books[i].getOwner() == members[i].getNIF()){
                books.push_back(catalog.books[i]);
            }
        }
        for (int j = 0; j < books.size(); j++){
            books[j].showBook(0);
        }
        cout << endl << endl;
    }
}

void Club::showABook(int code){
    if(code<0){
        throw BookDoesNotExist(code);
    }
    for(int i=0;i<catalog.books.size();i++){
        if(catalog.books[i].getCode()==code){
            catalog.books[i].showBook(0);
        }
    }
}

void Club::showAllFrequentants(){
    cout<<"---- MEMBROS ----"<<endl;
    showMembers();
    cout<<"---- NÃO MEMBROS ----"<<endl;
    showNonMembers();
}

void Club::showNonMembers(){
    for (unsigned int i = 0; i < nonmembers.size(); i++){
        cout << "Nome: " << nonmembers[i].getName() << endl << "NIF: "<< nonmembers[i].getNIF() << endl<<nonmembers[i].getBalance()<<" euros"<<endl;
        cout << endl;
    }
}

void Club::showQueues() {
    int counter=1;
    for(unsigned int i=0;i<catalog.books.size();i++){
        cout<<"Lista de espera do livro: ";
        catalog.books[i].showBook(0);
        cout<<endl;
        cout<<"----MEMBROS----"<<endl;
        HeapMember test1=catalog.books[i].getHeapM();
        while(!test1.empty()){
            cout<<counter<<" ";
            test1.top().showDetails();
            test1.pop();
        }
        cout<<"----NÃO MEMBROS----"<<endl;
        HeapNonMem test2=catalog.books[i].getHeapNM();
        counter=1;
        while(!test2.empty()){
            cout<<counter<<" ";
            test2.top().showDetails();
            test2.pop();
        }
    }
}

void Club::showPersonRequests(int nif){
    if(isMember(nif)==isnonMem(nif)){
        throw NIFDoesNotExist(nif);
    }
    if(isMember(nif) !=-1){ //is Member
       members[isMember(nif)].showLendRequests();
    }
    else{
        nonmembers[isnonMem(nif)].showLendRequests();
    }
}

void Club::showLendings() {
    cout << "EMPRÉSTIMOS EM VIGOR:" << endl;
    for (unsigned int i = 0; i < lendings.size(); i++){
        cout << get<0>(lendings[i]) << ", a " << get<1>(lendings[i]).getDateStr() << " pelo membro " << get<2>(lendings[i]) << endl;
    }
    cout << endl << endl;
}

void Club::showDelays() {
    cout << "ATRASOS:" << endl;
    for (unsigned int i = 0; i < delays.size(); i++){
        cout << get<0>(delays[i]) << ", desde " << get<1>(delays[i]).getDateStr() << " pelo membro " << get<2>(delays[i]) << endl;
    }
    cout << endl << endl;
}

void Club::showShopsByRating(){
    b.showStoresByRating();
}

void Club::showShopsBySpecificBook(){
    string code_str;
    int code,id;
    bool valid;
    valid=false;
    while(!valid){
        cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
        getline(cin, code_str);
        if(isdigit(code_str[0])){
            valid=true;
            code = stoi(code_str);
        }
        if(code_str[0]=='-'){
            valid=true;
            code = stoi(code_str);
        }
        if(!valid){
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um número válido."<<endl;
            colorText('F');
        }
        id = catalog.searchBook(code);
        if(id==-1){
            valid=false;
            catalog.showBooks();
        }
    }

    b.showStoresbySpecificBook(catalog.books[id]);

}

void Club::updatePreferences(){ 
    string eMail, temp;
    bool valid=false;
    cout << "Indique, por favor, o e-mail do membro: ";
    getline(cin, eMail);

    auto it = Preferences.find(eMail);

    if (it == Preferences.end()){
        throw EmailDoesNotExist(eMail);
    } else {
        it->printPreferences();
        vector<string> preferences = it->getPreferences();
        string eMail = it->getEmail();

        cout << endl << "Indique, do primeiro ao último lugar, as suas novas preferências abaixo." << endl;
        cout << "Se desejar que uma preferência fique vazia, introduza ASE - A Ser Escolhido - no seu lugar." << endl << endl;

        for (int i = 0; i < preferences.size(); i++){
            while(!valid){
            cout << i + 1 << "º LUGAR: ";
            getline(cin, temp);
            if(Genres.find(temp) != Genres.end()){
                cout<<"Hello"<<endl;
                valid=true;
                preferences[i] = temp;
            }
            else{
                valid=false;
                colorText('C');
                cout<<"Por favor, indique um género literário válido. Escolha entre os seguintes: "<<endl;
                for(int i=0;i<book_genres.size();i++){
                    cout<<book_genres[i]<<endl;
                }
                colorText('F');
            }
            }
            valid=false;
        }

        Preferences.erase(it);
        Info tempInf(eMail, preferences);
        Preferences.insert(tempInf);
    }
}

void Club::updateTable(string oldEmail, string newEmail){
    for(auto it = Preferences.begin(); it != Preferences.end(); it++){
        if (it->getEmail() == oldEmail){
            Info temp = *it;
            Preferences.erase(oldEmail);
            temp.setEmail(newEmail);
            Preferences.insert(temp);
        }
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
        if(abs(today.timePeriod(get<1>(lendings[i])))>10){ //Consider lending period is 10 days
            this->delays.push_back(make_tuple(get<0>(lendings[i]),get<1>(lendings[i]).delayDate(),get<2>(lendings[i])));
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
    bool valid=false;
    bool exist=false;
    bool request=false;
    int code, nif;
    cout << "Para registarmos a perda, terá de identificar o empréstimo ou atraso." << endl;
    cout << "O livro perdido ainda estava num período de empréstimo válido? ";
    getline(cin, answer);

    if (answer == "S" || answer == "s" || answer == "sim" || answer == "Sim" || answer == "SIM"){
        lending = true;
        showLendings();

        cout << "A perda afetará o saldo." << endl;
        while(!valid){
            cout << "Indique o código do livro em questão: ";
            getline(cin, code_st);
            if(isdigit(code_st[0])){
                valid=true;
                code = stoi(code_st);
            }
            else{
                valid=false;
                colorText('C');
                cout<<"Introduza um código válido (um número)."<<endl;
                colorText('F');
            }
        }
        valid=false;
        while(!valid){
            cout << "Indique o NIF associado ao empréstimo: ";
            getline(cin, nif_st);
            if(isdigit(nif_st[0])){
                valid=true;
                nif = stoi(nif_st);
                if(isMember(nif)==isnonMem(nif)){
                    throw NIFDoesNotExist(nif);
                }
            }
            else{
                valid=false;
                colorText('C');
                cout<<"Introduza um NIF válido (um número de nove algarismos associado a um frequentante)."<<endl;
                colorText('F');
            }
        }
        for (int i = 0; i < lendings.size(); i++){
            if((get<0>(lendings[i]) == code)){
                exist=true;
            }
            if ((get<0>(lendings[i]) == code) && (get<2>(lendings[i]) == nif)){
                request=true;
                temp=get<1>(lendings[i]);
                removeBook(make_tuple(code, temp, nif));
                lendings.erase(lendings.begin()+ i);
            }
        }
    } else {

        cout << "A perda e o atraso afetarão o saldo." << endl;
        showDelays();
        while(!valid){
            cout << "Indique o código do livro em questão: ";
            getline(cin, code_st);
            if(isdigit(code_st[0])){
                valid=true;
                code = stoi(code_st);
            }
            else{
                valid=false;
                colorText('C');
                cout<<"Introduza um código válido (um número)."<<endl;
                colorText('F');
            }
        }
        valid=false;
        while(!valid){
            cout << "Indique o NIF associado ao empréstimo: ";
            getline(cin, nif_st);
            if(isdigit(nif_st[0])){
                valid=true;
                nif = stoi(nif_st);
            }
            else{
                valid=false;
                colorText('C');
                cout<<"Introduza um NIF válido (um número de nove algarismos associado a um frequentante)."<<endl;
                colorText('F');
            }
        }

        for (int i = 0; i < delays.size(); i++){
            if(get<0>(delays[i])==code){
                exist=true;
            }
            if ((get<0>(delays[i]) == code) && (get<2>(delays[i]) == nif)){
                request=true;
                temp=get<1>(lendings[i]);
                removeBook(make_tuple(code, temp, nif));
                delays.erase(lendings.begin()+ i);
            }
        }
    }
    if(!request){
        throw RequestDoesNotExist(code,nif);
    }
    if(!exist){
        throw BookDoesNotExist(code);
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
    bool valid=false;
    bool exist=false;

    while(!valid){

        cout << "Indique o NIF: ";
        getline(cin, nif_str);
        cout << endl;
        cout << endl;
        if(isdigit(nif_str[0])){
            nif = stoi(nif_str);
            valid=true;
            if(isnonMem(nif)==isMember(nif)){
                throw NIFDoesNotExist(nif);
            }
        }else{
            valid=false;
            colorText('C');
            cout<<"Introduza um NIF válido (um número de nove algarismos associado a um frequentante)."<<endl;
            colorText('F');
        }
    }

    valid=false;

    while(!valid){
        cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
        getline(cin, code_str);
        cout << endl;
        cout << endl;
        if(isdigit(code_str[0])){
            valid=true;
            code = stoi(code_str);
        }
        if(code_str[0]=='-'){
            valid=true;
            code = stoi(code_str);
        }
        if(!valid){
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um número válido."<<endl;
            colorText('F');
        }
    }
    valid=false;
    while ((code <= -1) || cin.fail()) {
        cout << "Indique, então, o título do livro: ";
        getline(cin, name);
        cout << endl;
        cout << endl;

        if (catalog.searchBook(name) == false) {
            throw BookDoesNotExist(name);
        } else {
            cout << "Os livros disponíveis com esse título são: " << endl;
            for (int i = 0; i < catalog.books.size(); i++) {
                if ((catalog.books[i].getTitle() == name) && (catalog.books[i].getState() == true)) {
                    catalog.books[i].showBook(0);
                }
            }
        }

        while(!valid){
            cout << "Indique o código do livro que pretende: ";
            getline(cin, code_str);
            if(isdigit(code_str[0])){
                valid=true;
                code = stoi(code_str);
            }
            else{
                valid=false;
                colorText('C');
                cout<<"Por favor, indique um número válido"<<endl;
                colorText('F');
            }
        }
    }

    //And now, to register it in Members or NonMembers.
    if (isMember(nif) != -1) {
        if (members[isMember(nif)].getBalance() <= 0) {
            throw NegativeBalance(nif);
        }
        members[isMember(nif)].registerRequest(code, today);
        int id=catalog.searchBook(code);
        members[isMember(nif)].calculateRatio();
        catalog.books[id].loadHeapMember(members[isMember(nif)]);
        members[isMember(nif)].registerRequest(code, today);
    } else { //it's not a member then it's a nonMem
        while (true) {
            if (isnonMem(nif) == -1) {
                string namem;
                cout << "Introduza o nome, por favor: ";
                getline(cin, namem);
                float balance = 50;
                nonMem* p = new nonMem(namem, nif, balance);
                (*p).registerRequest(code, today);
                nonmembers.push_back((*p));
                break;
            } else {
                if ((isnonMem(nif) != -1) && (nonmembers[isnonMem(nif)].getBalance() > 0)) {
                    int id=catalog.searchBook(code);
                    catalog.books[id].loadHeapnonMem(nonmembers[isnonMem(nif)]);
                    nonmembers[isnonMem(nif)].registerRequest(code, today);
                    break;
                } else if (nonmembers[isnonMem(nif)].getBalance() <= 0) {
                    throw NegativeBalance(nif);
                } else {
                    continue;
                }
            }
        }
    }
    lendRequests.push_back(make_tuple(code, today, nif)); //registering the request in club
    return true;

}

bool Club::buyBook(int nif,int code){
    if(isMember(nif)==isnonMem(nif)){
        throw NIFDoesNotExist(nif);
    }
    if(isMember(nif) == -1){
        throw NotAMember(nif);
    }
    string code_str,shop_str;
    float price;
    bool valid;
    int id,id_shop;
    vector<string>stores;
    if(code==-1){
    valid=false;
    while(!valid){
        cout<<"Indique o código do livro (indique -1 caso não saiba o código): "<< endl;
        getline(cin, code_str);
        if(isdigit(code_str[0])){
            valid=true;
            code = stoi(code_str);
        }
        if(code_str[0]=='-'){
            valid=true;
            code = stoi(code_str);
        }
        if(!valid){
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um número válido."<<endl;
            colorText('F');
        }
        id = catalog.searchBook(code);
        if(id==-1){
            valid=false;
            catalog.showBooks();
        }
    }
    }
    else{
        id = catalog.searchBook(code);
    }
    stores=b.findBook(catalog.books[id]);
    if(stores.size()==0){
        colorText('C');
        cout<<"Infelizmente, o livro especificado não se encontra disponível em nenhuma loja."<<endl;
        colorText('F');
        return false;
    }
    else{
        cout<<"O livro especificado encontra-se disponível nas seguintes lojas:"<<endl;
        for(int i=0;i<stores.size();i++){
            cout<<i+1<<" - "<<stores[i]<<endl;
        }
        valid=false;
        while(!valid){
            cout<<"Selecione uma das lojas que apresentam o livro especificado disponível (indique o número presente antes do nome da loja): "<<endl;
            getline(cin, shop_str);
            if(isdigit(shop_str[0])){
                valid=true;
                id_shop = stoi(shop_str);
                if(id_shop<1 || id_shop> stores.size()){
                    valid=false;
                }
            }
            if(code_str[0]=='-'){
            valid=false;
            }
            if(!valid){
               valid=false;
               colorText('C');
               cout<<"Por favor, indique um número válido."<<endl;
               colorText('F');
               cout<<"O livro especificado encontra-se disponível nas seguintes lojas:"<<endl;
               for(int i=0;i<stores.size();i++){
                   cout<<i+1<<" - "<<stores[i]<<endl;
        }
        }
        }
        id_shop-=1;
        price=b.sellBook(catalog.books[id],stores[id_shop]);
    }
        if(price != -1){
            if(members[isMember(nif)].getBalance()-price<=0){
                throw NegativeBalance(nif);
            }
            else{
                members[isMember(nif)].minusBalance(price);
                string int_answer,answer,writ_answer;
                int rating;
                bool valid=false;
                while(!valid){
                     cout<<"Introduza uma opinião de 1 a 5 sobre a livraria, por favor : "<<endl;
                     getline(cin,int_answer);
                     if(isdigit(int_answer[0])){
                          rating = stoi(int_answer);
                          valid=true;
                     }
                     else{
                          valid=false;
                          colorText('C');
                          cout<<"Por favor, indique uma avaliação válida (um número de 0 a 5)."<<endl;
                          colorText('F');
        }
                }
                b.findShop(stores[id_shop],rating);
                return true;
            }
        }
        else{
            return false;
        }
        return false;
}

void Club::saveData(){
    ofstream file; //(membs, ios::binary);
    ofstream filee; //(lends, ios::binary);
    ofstream fileee; //(lendRs, ios::binary);
    ofstream fileeee; //(bks, ios::binary);
    ofstream fileeeee; //(dels, ios::binary);
    ofstream fileeeeee; //(nonmembs, ios::binary);
    ofstream fileeeeeee; //(system)
    ofstream fileeeeeeee; //bookshops
    ofstream file9;
    ofstream file10;

    //Yay, file cleaning!
    file.open("members.txt", std::ofstream::out | std::ofstream::trunc);
    filee.open("lendings.txt", std::ofstream::out | std::ofstream::trunc);
    fileee.open("lendRequests.txt", std::ofstream::out | std::ofstream::trunc);
    fileeee.open("books.txt", std::ofstream::out | std::ofstream::trunc);
    fileeeee.open("delays.txt", std::ofstream::out | std::ofstream::trunc);
    fileeeeee.open("nonmembers.txt", std::ofstream::out | std::ofstream::trunc);
    fileeeeeee.open("system.txt", std::ofstream::out | std::ofstream::trunc);
    fileeeeeeee.open("shops.txt", std::ofstream::out | std::ofstream::trunc);
    file9.open("preferences.txt", std::ofstream::out | std::ofstream::trunc);
    file10.open("queues.txt", std::ofstream::out | std::ofstream::trunc);

    stringstream temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;

    for (int i = 0; i < members.size(); i++){
        if (i < members.size() -1) {
            temp1 << members[i].getData() << endl << endl << endl;
        } else if (i == members.size() - 1){
            temp1 << members[i].getData() << endl << endl << "END";
        }
    }

    file << temp1.str();

    for (int i = 0; i < nonmembers.size(); i++){
        if (i < nonmembers.size() -1) {
            temp6 << nonmembers[i].getData() << endl << endl << endl;
        } else if (i == nonmembers.size() - 1){
            temp6 << nonmembers[i].getData() << endl << endl << "END";
        }
    }

    fileeeeee << temp6.str();

    for (int i = 0; i < lendings.size(); i++){
        if (i < lendings.size() -1) {
            temp2 << get<0>(lendings[i]) << endl << get<1>(lendings[i]).getDateStr() << endl << get<2>(lendings[i]) << endl << endl  << endl;  //código do livro, data, membro
        } else if (i == lendings.size() - 1){
            temp2 << get<0>(lendings[i]) << endl << get<1>(lendings[i]).getDateStr() << endl << get<2>(lendings[i]) << endl << endl << "END";
        }
    }

    filee << temp2.str();

    for (int i = 0; i < lendRequests.size(); i++){
        if (i < lendRequests.size() -1) {
            temp3 << get<0>(lendRequests[i]) << endl << get<1>(lendRequests[i]).getDateStr() << endl << get<2>(lendRequests[i]) << endl << endl  << endl;  //código do livro, data, membro
        } else if (i == lendRequests.size() - 1){
            temp3 << get<0>(lendRequests[i]) << endl << get<1>(lendRequests[i]).getDateStr() << endl << get<2>(lendRequests[i]) << endl << endl << "END";
        }
    }

    fileee << temp3.str();

    for (int i = 0; i < catalog.books.size(); i++){
        if (i < catalog.books.size() -1) {
            temp4 << catalog.books[i].getData() << endl << endl  << endl;
        } else if (i == catalog.books.size() - 1){
            temp4 << catalog.books[i].getData() << endl << endl << "END";
        }
    }

    fileeee << temp4.str();

    for (int i = 0; i < delays.size(); i++){
        if (i < delays.size() - 1) {
            temp5 << get<0>(delays[i]) << endl << get<1>(delays[i]).getDateStr() << endl << get<2>(delays[i]) << endl << endl  << endl;  //código do livro, data, membro
        } else if (i == delays.size() - 1){
            temp5 << get<0>(delays[i]) << endl << get<1>(delays[i]).getDateStr() << endl << get<2>(delays[i]) << endl << endl << "END";
        }
    }

    fileeeee << temp5.str();

    temp7 << today.getDateStr() << endl << endl << "END";

    fileeeeeee<<temp7.str();

    BSTItrLevel<BookShop> it(b.shops);
    while (!it.isAtEnd()){
        fileeeeeeee << it.retrieve().getData();
        it.advance();
        if (!it.isAtEnd()){
            fileeeeeeee << endl << endl;
        }
    }

    fileeeeeeee << endl << "END";

    for (auto it = Preferences.begin(); it != Preferences.end(); it++){
        file9 << it->getEmail() << endl;
        vector<string> prefs = it->getPreferences();
        for (int i = 0; i < prefs.size(); i++){
            file9 << prefs[i] << endl;
        }
        file9 << endl;
    }

    file9 << "END";

    stringstream qs;
    for (int i = 0; i < catalog.books.size(); i++){
        if (catalog.books[i].getHeapM().empty()){
            qs << "MEMQ_END" << endl;
        } else {
            HeapMember memQ = catalog.books[i].getHeapM();
            while (!memQ.empty()){
                qs << memQ.top().getNIF() << endl;
                memQ.pop();
            }
            qs << "MEMQ_END" << endl;
        }

        if (catalog.books[i].getHeapNM().empty()){
            qs << "NMEMQ_END" << endl << endl;
        } else {
            HeapNonMem nmemQ = catalog.books[i].getHeapNM();
            while (!nmemQ.empty()){
                qs << nmemQ.top().getNIF() << endl;
                nmemQ.pop();
            }
            qs << "NMEMQ_END" << endl << endl;
        }
    }
    qs << "END";
    file10 << qs.str();    
}

void Club::retrieveData(){
    ifstream memb_file; memb_file.open("members.txt");
    ifstream bks_file; bks_file.open("books.txt");
    ifstream lendRs_file; lendRs_file.open("lendRequests.txt");
    ifstream lends_file; lends_file.open("lendings.txt");
    ifstream dels_file; dels_file.open("delays.txt");
    ifstream nmemb_file; nmemb_file.open("nonmembers.txt");
    ifstream system_file; system_file.open("system.txt");
    ifstream shops_file; shops_file.open("shops.txt");
    ifstream prefs_file; prefs_file.open("preferences.txt");
    ifstream queues_file; queues_file.open("queues.txt");

    bool d_exist=false;
    bool l_exist=false;
    bool empty=false;
    string temp;
    char sep = ',';
    stringstream membs, bks, lendRs, lends, dels, nmembs, sys, shop;

    //Getting Books data.
    empty=bks_file.peek() == std::ifstream::traits_type::eof();

    if(!(empty)){
        string title, author, category, writ_ops;
        int code_bk, units, opinions, sumRating, edition, owner, oguni;
        float realRating, value;
        bool state, multi;
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
            bks >> oguni;
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
            getline(bks_file, temp);
            bks.str("");
            bks.clear();
            bks << temp;
            bks >> multi;

            vector<string> reviews;
            while (1){
                getline(bks_file, temp);
                if (temp == "END_REVS"){
                    break;
                }
                reviews.push_back(temp);
            }
            Book bk;
            bk.setAuthor(author); bk.setTitle(title); bk.setCat(category); bk.setCode(code_bk); bk.setUnits(units);
            bk.setOpinions(opinions); bk.setRating(realRating); bk.setSumR(sumRating); bk.setValue(value); bk.setState();
            bk.setEdition(edition); bk.setOwner(owner); bk.setOgunit(oguni); bk.setMulti();

            for (int i = 0; i < reviews.size(); i++){
                bk.addWritops(reviews[i]);
            }

            catalog.books.push_back(bk);
            getline(bks_file, temp);
            bks.str("");
            bks.clear();
            getline(bks_file, temp);
            bks.str("");
            bks.clear();
        }
    }

    empty=false;

    empty=memb_file.peek() == std::ifstream::traits_type::eof();

    //Getting Member data.
    if(!(empty)){
        temp = "BEGIN";
        string name, eMail;
        int nif, code, books_taken, books_given;
        float balance;
        while (temp != "END"){
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
            membs >> name;
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
            membs >> eMail;
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
            membs >> nif;
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
            membs >> books_given;
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
            membs >> books_taken;
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            membs << temp;
            balance = stof(temp);
            /*do {
                getline(memb_file, temp);
                membs.str("");
                membs.clear();
                membs << temp;
                membs >> code >> sep;
                int ind = catalog.searchBook(code);
            } while (sep != ';');*/
            Member newMem(name, eMail, nif, balance,books_given);
           //newMem.setBooksGiven(books_given);
            newMem.setBooksTaken(books_taken);
            members.push_back(newMem);
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
            getline(memb_file, temp);
            membs.str("");
            membs.clear();
        }
    }

    empty=false;
    empty=nmemb_file.peek() == std::ifstream::traits_type::eof();

    //Getting nonMembers data.
    if(!(empty)){
        temp = "BEGIN";
        string name;
        int nif, code;
        float balance;
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
            balance = stof(temp);
            nonmembers.push_back(nonMem(name, nif, balance));
            getline(nmemb_file, temp);
            nmembs.str("");
            nmembs.clear();
            getline(nmemb_file, temp);
            nmembs.str("");
            nmembs.clear();
        }
    }

    empty=false;
    empty=lendRs_file.peek() == std::ifstream::traits_type::eof();

    //Getting lendRequests data.
    if(!(empty)){
        temp = "BEGIN";
        string date = "temp";
        Date tmp;
        int nif, code;
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
    }

    empty=false;
    empty=lends_file.peek() == std::ifstream::traits_type::eof();

    //Getting lendings data.
    if(!(empty)){
        l_exist=true;
        temp = "BEGIN";
        string date = "temp";
        int nif, code;
        Date tmp,tmp2;
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
    }

    empty=false;
    empty=dels_file.peek() == std::ifstream::traits_type::eof();

    //Getting delays data.
    if(!(empty)){
        d_exist=true;
        temp = "BEGIN";
        Date tmp3;
        string date = "temp";
        int nif, code;
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
    }

    empty=false;
    empty=system_file.peek() == std::ifstream::traits_type::eof();

    //Getting System data
    if(!(empty)){
        string d, str_counter;
        int temp_counter;
        bool already=false;
        getline(system_file,temp);
        sys.str("");
        sys.clear();
        sys<<temp;
        sys>>d;

        //If we're in the same day, then we don't need to checkDelays().
        if(d != today.getDateStr()){
            checkDelays();
        }
    }
    else{
        if(d_exist || l_exist){
            checkDelays();
        }
    }

    //Getting shops data.
    empty=false;
    empty=shops_file.peek() == std::ifstream::traits_type::eof();
    if(!(empty)){
        string name, city, temp,title, author, category, writ_ops,store;
        float promoValue, realRating,realRatingBook, value;
        int bookGenreCount, code_bk, units, opinions, sumRating, edition, owner, oguni;
        bool state, multi;
        
        while (temp != "END") {
            vector<Book> shop_books;
            getline(shops_file, temp);
            shop.str("");
            shop.clear();
            name = temp;
            getline(shops_file, temp);
            shop.str("");
            shop.clear();
            city = temp;
            getline(shops_file, temp);
            shop.str("");
            shop.clear();
            shop << temp;
            shop >> promoValue;
            getline(shops_file, temp);
            shop.str("");
            shop.clear();
            shop << temp;
            shop >> realRating;
            getline(shops_file, temp);
            shop.str("");
            shop.clear();
            shop << temp;
            shop >> bookGenreCount;
            sep = '0';
            do {
                stringstream sps;
                int code;
                getline(shops_file, temp);
                sps.str("");
                sps.clear();
                sps << temp;
                sps >> code >> sep;
                int ind = catalog.searchBook(code);
                shop_books.push_back(catalog.books[ind]);
            } while (sep != ';');
        
            BookShop newShop(name, city, promoValue, realRating, bookGenreCount,shop_books);
            b.addShop(newShop);
            shop_books.clear();
            getline(shops_file, temp);
        }
    }

    //Getting preferences data.
    empty = false;
    empty = prefs_file.peek() == std::ifstream::traits_type::eof();

    if (!empty){
        string temp, eMail;
        getline(prefs_file, temp);
        while (temp != "END") {
            vector<string> preferences;
            eMail = temp;
            getline(prefs_file, temp);
            preferences.push_back(temp);
            getline(prefs_file, temp);
            preferences.push_back(temp);
            getline(prefs_file, temp);
            preferences.push_back(temp);
            getline(prefs_file, temp);
            preferences.push_back(temp);
            getline(prefs_file, temp);
            preferences.push_back(temp);
            Info info_temp(eMail,preferences);
            Preferences.insert(info_temp);
            getline(prefs_file, temp);
            getline(prefs_file, temp);
        }
    }

    empty = false;
    empty = queues_file.peek() == std::ifstream::traits_type::eof();

    if (!empty){
        for (int i = 0; i < catalog.books.size(); i++){
            string temp = "";
            getline(queues_file, temp);
            if (temp != "END"){
                while (temp != "MEMQ_END"){
                    catalog.books[i].loadHeapMember(members[isMember(stoi(temp))]);
                    getline(queues_file, temp);
                }
                getline(queues_file, temp);
                while (temp != "NMEMQ_END"){
                    catalog.books[i].loadHeapnonMem(nonmembers[isnonMem(stoi(temp))]);
                    getline(queues_file, temp);
                }
                getline(queues_file, temp);
            } else {
                break;
            }

            
        }
    }

}

void Club::showShopsInRange(){
    float min, max;
    bool valid = false;
    while (!valid){
        string temp, temp1;
        cout << "Indique a classificação mínima requerida para contemplar uma loja: ";
        getline(cin, temp);
        min = stof(temp);
        cout << "Indique a classificação máxima requerida para contemplar uma loja: ";
        getline(cin, temp1);
        max = stof(temp1);
        if (min < 0 || max > 5){
            cout << "Os valores fornecidos não são válidos. Forneça números entre 0 e 5 (inclusive)." << endl << endl;
            continue;
        } else {
            valid = true;
        }
    }
    b.showStoresContemplated(min, max);
}

void Club::generateGenretable(){ 
    Genres.clear();
    for(int i=0;i<book_genres.size();i++){
        Genres.insert(book_genres[i]);

    }
}

void Club::givenuponBook(int nif){
    int id,code;
    string code_str;

    if(isMember(nif)==isnonMem(nif)){
        throw NIFDoesNotExist(nif);
    }

    bool valid=false;
    while(!valid){
        cout << "Indique o código do livro (se não o souber, insira -1 e dê ENTER): ";
        getline(cin, code_str);
        if(isdigit(code_str[0])){
            valid=true;
            code = stoi(code_str);
        }
        if(code_str[0]=='-'){
            valid=true;
            code = stoi(code_str);
        }
        if(!valid){
            valid=false;
            colorText('C');
            cout<<"Por favor, indique um número válido."<<endl;
            colorText('F');
        }
        id = catalog.searchBook(code);
        if(id==-1){
            valid=false;
            if(isMember(nif)!=-1){
                members[isMember(nif)].showLendRequests();
            }
            else{
                nonmembers[isnonMem(nif)].showLendRequests();
            }
        }
    }



    if(isMember(nif)!=-1){ //is Member
       if(!catalog.books[id].checkMember(members[isMember(nif)])){
           throw RequestDoesNotExist(code,nif);
       }
       else{
           catalog.books[id].deleteHeapM(members[isMember(nif)]);
           members[isMember(nif)].finishRequest(code);
       }
    }
    else{
        if(!catalog.books[id].checknonMem(nonmembers[isnonMem(nif)])){
           throw RequestDoesNotExist(code,nif);
       }
       else{
           catalog.books[id].deleteHeapNM(nonmembers[isnonMem(nif)]);
           nonmembers[isnonMem(nif)].finishRequest(code);
       }
    }
}

void Club::updateHeap(int nif){ 
    vector<int>codes;
    if(isnonMem(nif) != -1){ //is nonMem
       for(int i=0;i<nonmembers[isnonMem(nif)].getlendRequest().size();i++){
           if(find(codes.begin(),codes.end(),catalog.searchBook(nonmembers[isnonMem(nif)].getlendRequest()[i].first)) != codes.end()){
              codes.push_back(catalog.searchBook(nonmembers[isnonMem(nif)].getlendRequest()[i].first));
           }
       }

       for(int i=0;i<codes.size();i++){
           catalog.books[codes[i]].deleteHeapNM(nonmembers[isnonMem(nif)]);
           catalog.books[codes[i]].loadHeapnonMem(nonmembers[isnonMem(nif)]);
       }
    }
    else{
         for(int i=0;i<members[isMember(nif)].getlendRequest().size();i++){
           if(find(codes.begin(),codes.end(),catalog.searchBook(members[isMember(nif)].getlendRequest()[i].first)) != codes.end()){
              codes.push_back(catalog.searchBook(members[isMember(nif)].getlendRequest()[i].first));
           }
       }

       for(int i=0;i<codes.size();i++){
           catalog.books[codes[i]].deleteHeapM(members[isMember(nif)]);
           catalog.books[codes[i]].loadHeapMember(members[isMember(nif)]);
       }
    }
}

void Club::colorText(char ch)
{
    if (ch == 'A')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA);    //VERDE
    else if (ch == 'B')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xB);  //AZUL
    else if (ch == 'C')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC);  //VERMELHO
    else if (ch == 'D')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD);  //ROSA
    else if (ch == 'E')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE);  //AMARELO
    else if (ch == 'F')
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF);  //BRANCO
}




