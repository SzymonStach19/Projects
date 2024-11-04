#include "Firma.h"
#include <iostream>

void Firma::wyswietl() const {
    std::cout << "Firma: " << nazwa << ", Branża: " << branza << ", Telefon: " << numer_tel << std::endl;
}
