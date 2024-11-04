#include "ListaWizytowek.h"
#include "Osoba_fizyczna.h"
#include "Firma.h"
#include <fstream>

ListaWizytowek::~ListaWizytowek() {
    while (head) {
        Wizytowka* temp = head;
        head = head->next;
        delete temp;
    }
}

void ListaWizytowek::dodajWizytowke(Wizytowka* wizytowka) {
    if (!head) {
        head = wizytowka;
    } else {
        Wizytowka* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = wizytowka;
    }
}

void ListaWizytowek::usunWizytowke(int numer_tel) {
    Wizytowka* temp = head;
    Wizytowka* poprzedni = nullptr;

    while (temp && temp->numer_tel != numer_tel) {
        poprzedni = temp;
        temp = temp->next;
    }

    if (!temp) {
        std::cout << "Wizytowka o numerze telefonu " << numer_tel << " nie istnieje." << std::endl;
        return;
    }

    if (!poprzedni) {
        head = temp->next;
    } else {
        poprzedni->next = temp->next;
    }

    delete temp;
    std::cout << "Wizytowka o numerze telefonu " << numer_tel << " usunieta." << std::endl;
}

void ListaWizytowek::importujZPliku(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku do importu." << std::endl;
        return;
    }

    int numer_tel;
    std::string typ;
    std::string imie, nazwisko, nazwa, branza;

    while (plik >> typ >> numer_tel) {
        if (typ == "Osoba") {
            if (plik >> imie >> nazwisko) {
                dodajWizytowke(new Osoba_fizyczna(numer_tel, imie, nazwisko));
            } else {
                std::cerr << "Bledny format danych w pliku." << std::endl;
                break;
            }
        } else if (typ == "Firma") {
            if (plik >> nazwa >> branza) {
                dodajWizytowke(new Firma(numer_tel, nazwa, branza));
            } else {
                std::cerr << "Bledny format danych w pliku." << std::endl;
                break;
            }
        } else {
            std::cerr << "Nieznany typ wizytowki: " << typ << std::endl;
            break;
        }
    }

    plik.close();
}

void ListaWizytowek::wyszukajWizytowkiPoNumerze(int numer_tel) const {
    Wizytowka* temp = head;

    while (temp) {
        if (temp->numer_tel == numer_tel) {
            temp->wyswietl();
            return;
        }
        temp = temp->next;
    }

    std::cout << "Brak wizytowki o numerze telefonu " << numer_tel << std::endl;
}

void ListaWizytowek::wyswietlWszystkie() const {
    Wizytowka* temp = head;

    while (temp) {
        temp->wyswietl();
        temp = temp->next;
    }
}
