#include <iostream>
#include "club.h"
using namespace std;
#include "windows.h"

int main() {
   SetConsoleOutputCP(CP_UTF8);
    SetConsoleTextAttribute( GetStdHandle( STD_INPUT_HANDLE ), 0x5B );
    Club a;
    a.run();
}