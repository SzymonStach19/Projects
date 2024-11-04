#include "Oceny.h"
#include <string>

using namespace std;
template<>
int ocena<int>(int ocena) {
    return ocena;
}

template<>
string ocena<string>(int ocena) {
    string wynik = "";
    for (int i = 0; i < ocena; ++i) {
        wynik += "*";
    }
    return wynik;
}