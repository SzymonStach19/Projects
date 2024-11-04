#include <iostream>
#include <string>
#include "Sniadanie.h"
#include "Obiad.h"
#include "Kolacja.h"

using namespace std;

int main() {
    string flag = "tak";
    int indeks;
    int numerkroku = 0;
    string decyzja;
    string przepis;
    string kategoria;
    int wybor;

    cout << "W jaki sposób chcesz widzieć ocenę: \n'1' jeśli liczby | '2' jesli gwiazdki" << endl;
    cin >> wybor;

    cout << "\n1. Śniadanie\n2. Obiad\n3. Kolacja\n"<< endl;
    cout << "Wybierz kategorie: ";

    cin >> kategoria;
    cout << endl;

    /**
     * @brief Obsługuje wybór kategorii "Sniadanie" i wyświetla informacje o przepisach.
     *
     * Ta funkcja obsługuje wybór kategorii "Sniadanie" w programie i umożliwia użytkownikowi
     * wybór konkretnego przepisu oraz wyświetla różne informacje na jego temat, takie jak nazwa,
     * oceny, składniki, ciekawostki, przyprawy i kroki przygotowania.
     */

    if (kategoria == "1"){
        AbstraktKategoria *sniadanie = new Sniadanie("Sniadanie");

        cout << sniadanie->wyswietlNazwyPrzepisow() << endl;
        cin >> indeks;

        cout << "Wybrany PRZEPIS: " + sniadanie->wyswietlNazwePrzepisu(indeks) << endl;

        cout << sniadanie->wyswietlOcenyPrzepisu(indeks, wybor) << "\n" <<endl;

        cout << "CIEKAWOSTKA o " + sniadanie->wyswietlNazwePrzepisu(indeks) + ":" << endl;
        cout << sniadanie->wyswietlCiekawostki(indeks) << endl;

        cout << "SKLADNIKI: " << endl;
        cout << sniadanie->wyswietlSkladnikiPrzepisu(indeks) << endl;

        if (sniadanie->wyswietlNazwyPrzypraw(indeks) == "pusto"){
            cout << "Do tego przepisu nie potrzebujesz Przypraw, jedynie pieprz i sól :)\n" << endl;
        }else{
            cout << "PRZYPRAWY: " << endl;
            cout << sniadanie->wyswietlNazwyPrzypraw(indeks) << endl;
        }

        cout << "Czy chcesz poznać Kroki?\n't' jeśli tak, jeśli nie 'n': " << endl;
        cin >> decyzja;
        cout << "KROKI: " << "\n" << endl;
        while(decyzja == "t") {
            cout << sniadanie->wyswietlKrokiPrzepisu(indeks, decyzja, numerkroku) << endl;
            if (sniadanie->wyswietlKrokiPrzepisu(indeks, decyzja, numerkroku).empty()){
                cout << "To już Koniec przepisu" << endl;
                break;
            }
            cout << "Dalej - 't', Koniec - 'n': " << endl;
            numerkroku += 1;
            cin >> decyzja;
        }
    }

    /**
     * @brief Obsługuje wybór kategorii "Obiad" i wyświetla informacje o przepisach.
     *
     * Ta funkcja obsługuje wybór kategorii "Obiad" w programie i umożliwia użytkownikowi
     * wybór konkretnego przepisu oraz wyświetla różne informacje na jego temat, takie jak nazwa,
     * oceny, składniki, ciekawostki, przyprawy i kroki przygotowania.
     */

    if (kategoria == "2") {
        AbstraktKategoria *obiad = new Obiad("Obiad");

        cout << obiad->wyswietlNazwyPrzepisow() << endl;
        cin >> indeks;

        cout << "Wybrany PRZEPIS: " + obiad->wyswietlNazwePrzepisu(indeks) << endl;

        cout << obiad->wyswietlOcenyPrzepisu(indeks, wybor) << "\n" <<endl;

        cout << "CIEKAWOSTKA o " + obiad->wyswietlNazwePrzepisu(indeks) + ":" << endl;
        cout << obiad->wyswietlCiekawostki(indeks) << endl;

        cout << "SKLADNIKI: " << endl;
        cout << obiad->wyswietlSkladnikiPrzepisu(indeks) << endl;

        if (obiad->wyswietlNazwyPrzypraw(indeks) == "pusto"){
            cout << "Do tego przepisu nie potrzebujesz Przypraw, jedynie pieprz i sól :)\n" << endl;
        }else{
            cout << "PRZYPRAWY: " << endl;
            cout << obiad->wyswietlNazwyPrzypraw(indeks) << endl;
        }

        cout << "Czy chcesz poznać Kroki?\n't' jeśli tak, jeśli nie 'n': " << endl;
        cin >> decyzja;
        cout << "KROKI: " << "\n" << endl;
        while(decyzja == "t") {
            cout << obiad->wyswietlKrokiPrzepisu(indeks, decyzja, numerkroku) << endl;
            if (obiad->wyswietlKrokiPrzepisu(indeks, decyzja, numerkroku).empty()){
                cout << "To już Koniec przepisu" << endl;
                break;
            }
            cout << "Dalej - 't', Koniec - 'n': " << endl;
            numerkroku += 1;
            cin >> decyzja;
        }
    }

    /**
     * @brief Obsługuje wybór kategorii "Kolacja" i wyświetla informacje o przepisach.
     *
     * Ta funkcja obsługuje wybór kategorii "Kolacja" w programie i umożliwia użytkownikowi
     * wybór konkretnego przepisu oraz wyświetla różne informacje na jego temat, takie jak nazwa,
     * oceny, składniki, ciekawostki, przyprawy i kroki przygotowania.
     */

    if (kategoria == "3") {
        AbstraktKategoria *kolacja = new Kolacja("Kolacja");

        cout << kolacja->wyswietlNazwyPrzepisow() << endl;
        cin >> indeks;

        cout << "Wybrany PRZEPIS: " + kolacja->wyswietlNazwePrzepisu(indeks) << endl;

        cout << kolacja->wyswietlOcenyPrzepisu(indeks, wybor) << "\n" <<endl;

        cout << "CIEKAWOSTKA o " + kolacja->wyswietlNazwePrzepisu(indeks) + ":" << endl;
        cout << kolacja->wyswietlCiekawostki(indeks) << endl;

        cout << "SKLADNIKI: " << endl;
        cout << kolacja->wyswietlSkladnikiPrzepisu(indeks) << endl;

        if (kolacja->wyswietlNazwyPrzypraw(indeks) == "pusto"){
            cout << "Do tego przepisu nie potrzebujesz Przypraw, jedynie pieprz i sól :)\n" << endl;
        }else{
            cout << "PRZYPRAWY: " << endl;
            cout << kolacja->wyswietlNazwyPrzypraw(indeks) << endl;
        }

        cout << "Czy chcesz poznać Kroki?\n't' jeśli tak, jeśli nie 'n': " << endl;
        cin >> decyzja;
        cout << "KROKI: " << "\n" << endl;
        while(decyzja == "t") {
            cout << kolacja->wyswietlKrokiPrzepisu(indeks, decyzja, numerkroku) << endl;
            if (kolacja->wyswietlKrokiPrzepisu(indeks, decyzja, numerkroku).empty()){
                cout << "To już Koniec przepisu" << endl;
                break;
            }
            cout << "Dalej - 't', Koniec - 'n': " << endl;
            numerkroku += 1;
            cin >> decyzja;
        }
    }

    return 0;
}