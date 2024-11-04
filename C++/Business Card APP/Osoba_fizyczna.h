#include "Wizytowka.h"

class Osoba_fizyczna : public Wizytowka {
public:
    std::string imie;
    std::string nazwisko;

    Osoba_fizyczna(int numer_tel, const std::string& imie, const std::string& nazwisko)
            : Wizytowka(numer_tel), imie(imie), nazwisko(nazwisko) {}

    void wyswietl() const override;
};

