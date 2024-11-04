#include "Wizytowka.h"

class ListaWizytowek {
private:
    Wizytowka* head;

public:
    ListaWizytowek() : head(nullptr) {}
    ~ListaWizytowek();

    void dodajWizytowke(Wizytowka* wizytowka);
    void usunWizytowke(int numer_tel);
    void importujZPliku(const std::string& nazwaPliku);
    void wyszukajWizytowkiPoNumerze(int numer_tel) const;
    void wyswietlWszystkie() const;
};

