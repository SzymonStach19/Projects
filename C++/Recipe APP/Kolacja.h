#pragma once
#include "AbstraktKategoria.h"
#include "Przepis.h"

/**
 * @file Kolacja.h
 *
 * Plik nagłówkowy zawierający deklaracje dla klasy Sniadanie.
 */

using namespace std;

class Kolacja : public AbstraktKategoria {

public:
    vector<Przepis> ListaPrzepisow;

public:

    /**
     * @param kategoria
     *
     * Konstruktor klasy Kolacja, który przyjmuje nazwę kategorii jako argument.
     */

    Kolacja(const string &kategoria);

    /**
     * Metoda, która zwraca ciąg znaków zawierający nazwy przepisów.
     *
     * @return string
     */

    string wyswietlNazwyPrzepisow();

    /**
     * @param int indeks
     *
     * Metoda, która zwraca nazwy przypraw dla danego przepisu na podstawie indeksu.
     *
     * @return string
     */

    string wyswietlNazwyPrzypraw(int indeks);

    /**
     * Metoda, która zwraca nazwę przepisu na podstawie indeksu.
     *
     * @param int indeks
     *
     * @return string
     */

    string wyswietlNazwePrzepisu(int indeks);

    /**
     * Metoda, która zwraca ciekawostki dotyczące danego przepisu na podstawie indeksu.
     *
     * @param int indeks
     *
     * @return string
     */

    string wyswietlCiekawostki(int indeks);

    /**
     * Metoda, która zwraca ocenę przepisu na podstawie indeksu i wyboru.
     *
     * @param int indeks
     * @param int wybor
     *
     * @return string
     */

    string wyswietlOcenyPrzepisu(int indeks, int wybor);

    /**
     * Metoda, która zwraca składniki danego przepisu na podstawie indeksu.
     *
     * @param int indeks
     *
     * @return string
     */

    string wyswietlSkladnikiPrzepisu(int indeks);

    /**
     * Metoda, która zwraca kroki przygotowania przepisu na podstawie indeksu, decyzji i numeru kroku.
     *
     * @param int indeks
     * @param string decyzja
     * @param int numerkroku
     *
     * @return string
     */

    string wyswietlKrokiPrzepisu(int indeks, string decyzja, int numerkroku);

};