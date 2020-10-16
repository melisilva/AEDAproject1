#include <iostream>
#include "book.h"
#include "club.h"
#include "member.h"
using namespace std;

int main() {
    string nome = "Joao", livro = "Aristotle & Dante Discover the Secrets of the Universe", aut = "Benjamin Alire-Saénz", gen = "Cont";
    int nif = 123456789, code = 1;
    vector<Book*> books;
    Book a(code, livro, aut, gen);
    books.push_back(&a);
    Member b(nome, nif, books);

    b.saveData();
    b.showData();
}