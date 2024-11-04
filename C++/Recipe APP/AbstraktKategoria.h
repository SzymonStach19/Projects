#include <iostream>
#include <fstream>
#include <list>
#include <string>
#pragma once

using namespace std;


class AbstraktKategoria{
public:

    /**
     * @brief Wirtualna funkcja zwracająca nazwy przepisów.
     *
     * Każda dziedzicząca klasa powinna dostarczyć własną implementację.
     *
     * @return string
     *
     * Zwraca ciąg znaków zawierający nazwy przepisów.
     */

    virtual string wyswietlNazwyPrzepisow() = 0;

    /**
     * @brief Wirtualna funkcja zwracająca nazwę przepisu na podstawie indeksu.
     *
     * Każda dziedzicząca klasa powinna dostarczyć własną implementację.
     *
     * @param int indeks
     *
     * @return string
     *
     * Zwraca nazwe przepisu
     */

    virtual string wyswietlNazwePrzepisu(int indeks) = 0;

    /**
     * @brief Wirtualna funkcja zwracająca ciekawostki o przepisie na podstawie indeksu.
     *
     * Każda dziedzicząca klasa powinna dostarczyć własną implementację.
     *
     * @param int indeks Indeks przepisu.
     *
     * @return string
     *
     * Zwraca ciąg znaków zawierający ciekawostki o przepisie.
     */

    virtual string wyswietlCiekawostki(int indeks) = 0;

    /**
     * @brief Wirtualna funkcja zwracająca oceny przepisu na podstawie indeksu i wyboru.
     *
     * Każda dziedzicząca klasa powinna dostarczyć własną implementację.
     *
     * @param int indeks
     * @param int wybor Wybór, który może wpłynąć na sposób obliczenia oceny.
     *
     * @return string
     *
     * Zwraca ciąg znaków zawierający oceny przepisu.
     */

    virtual string wyswietlOcenyPrzepisu(int indeks, int wybor) = 0;
    /**
     * @brief Wirtualna funkcja zwracająca składniki przepisu na podstawie indeksu.
     *
     * Każda dziedzicząca klasa powinna dostarczyć własną implementację.
     *
     * @param int indeks
     *
     * @return string
     *
     * Zwraca ciąg znaków zawierający składniki przepisu.
     */

    virtual string wyswietlSkladnikiPrzepisu(int indeks) = 0;

    /**
     * @brief Wirtualna funkcja zwracająca nazwy przypraw przepisu na podstawie indeksu.
     *
     * Każda dziedzicząca klasa powinna dostarczyć własną implementację.
     *
     * @param int indeks
     *
     * @return Ciąg znaków zawierający nazwy przypraw przepisu.
     *
     * Zwraca ciąg znaków zawierający nazwy przypraw przepisu.
     */

    virtual string wyswietlNazwyPrzypraw(int indeks) = 0;

    /**
     * @brief Wirtualna funkcja zwracająca kroki przepisu na podstawie indeksu, decyzji i numeru kroku.
     *
     * Każda dziedzicząca klasa powinna dostarczyć własną implementację.
     *
     * @param int indeks
     * @param string decyzja
     * @param int numerkroku
     *
     * @return string
     *
     * Zwraca ciąg znaków zawierający kroki przygotowania przepisu.
     */

    virtual string wyswietlKrokiPrzepisu(int indeks, string decyzja, int numerkroku) = 0;

};

