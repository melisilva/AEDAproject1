#ifndef PROJETO_MEMBERS_H
#define PROJETO_MEMBERS_H

class Member{
    vector<Book> books, lendRequests, lendings;
    string name;
    int nif, account;

    public:
        void showData(ofstream file) const;
        void updateData(ofstream file, string name, string account);
        void showLendRequests() const;
        void makeRequest() const;
        void renovateRequest() const;
        int getNIF() const;
        int getAccount() const;
        string getName() const;
        vector<Book> getBooks() const;
        vector<Book> lendRequests() const;
};





#endif //PROJETO_MEMBERS_H
