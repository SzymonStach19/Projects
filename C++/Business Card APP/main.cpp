#include "ListaWizytowek.h"
#include "Osoba_fizyczna.h"
#include "Firma.h"

int main() {
    ListaWizytowek lista;

    // Przykładowe dodawanie wizytówek
    lista.dodajWizytowke(new Osoba_fizyczna(123456789, "Jan", "Kowalski"));
    lista.dodajWizytowke(new Firma(987654321, "FirmaXYZ", "Informatyka"));

    // Wyświetlanie wszystkich wizytówek
    lista.wyswietlWszystkie();

    // Importowanie wizytówek z pliku
    lista.importujZPliku("/Users/szymon/PK3/Projekt/import.txt");

    // Wyszukiwanie wizytówki po numerze telefonu
    lista.wyszukajWizytowkiPoNumerze(123456789);

    // Usuwanie wizytówki po numerze telefonu
    lista.usunWizytowke(987654321);

    // Wyświetlanie wszystkich wizytówek
    lista.wyswietlWszystkie();

    return 0;
}
