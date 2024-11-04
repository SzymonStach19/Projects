#pragma once

using namespace std;

class Przepis{
public:

    /**
     * @brief Nazwa przepisu.
     */

    string nazwa;

    /**
     * @brief Składniki główne przepisu.
     */

    vector<string> SkladnikiGlowne;

    /**
     * @brief Przyprawy używane w przepisie.
     */

vector<string> Przyprawy;

    /**
     * @brief Ciekawostki dotyczące przepisu.
     */

vector<string> Ciekawostka;

    /**
     * @brief Kroki przygotowania przepisu.
     */

vector<string> Krok;

    /**
     * @brief Ocena smaku przepisu.
     */

int ocenasmaku;

};