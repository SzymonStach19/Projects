#include "Osoba_fizyczna.h"
#include <iostream>

void Osoba_fizyczna::wyswietl() const {
    std::cout << "Osoba fizyczna: " << imie << " " << nazwisko << ", Telefon: " << numer_tel << std::endl;
}
