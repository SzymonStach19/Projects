#include "Sniadanie.h"
#include "Oceny.h"
#include <string>

using namespace std;

Sniadanie::Sniadanie(const std::string &kategoria) {
    string linia;
    ifstream plik("/Users/szymon/Clion_Projekty/Projekt Końcowy nr. - Programowanie Komputerowe/przepisy.txt");
    while (getline(plik, linia)) {
        if (linia == kategoria + "Przepis") {
            Przepis przepis;
            getline(plik, linia);
            przepis.nazwa = linia;
            while (getline(plik, linia)) {
                if (linia == kategoria + "Ocena") {
                    getline(plik, linia);
                    przepis.ocenasmaku = stoi(linia);
                }
                if (linia == kategoria + "Ciekawostka"){
                    getline(plik, linia);
                    przepis.Ciekawostka.push_back(linia);
                }
                if (linia == kategoria + "SkladnikGlowny") {
                    getline(plik, linia);
                    przepis.SkladnikiGlowne.push_back(linia);
                }
                if (linia == kategoria + "Przyprawa") {
                    getline(plik, linia);
                    przepis.Przyprawy.push_back(linia);
                }
                if (linia == kategoria + "Krok") {
                    getline(plik, linia);
                    if (linia == "Koniec") {
                        break;
                    }
                    przepis.Krok.push_back(linia);
                }
            }
            ListaPrzepisow.push_back(przepis);
        }
    }
};

string Sniadanie::wyswietlNazwyPrzepisow() {
    string nazwaprzepisu;
    for (int i = 0; i < ListaPrzepisow.size(); ++i) {
        nazwaprzepisu += to_string(i + 1) + ". " + ListaPrzepisow[i].nazwa + "\n";
    }
    return nazwaprzepisu;
};

string Sniadanie::wyswietlNazwePrzepisu(int indeks){
    string nazwaprzepisu;
    nazwaprzepisu = ListaPrzepisow[indeks -1].nazwa;
    return nazwaprzepisu;

}

string Sniadanie::wyswietlOcenyPrzepisu(int indeks, int wybor) {
    string nazwaoceny;
    if (wybor == 1) {
        nazwaoceny = "Ocena: " + to_string(ocena<int>(ListaPrzepisow[indeks - 1].ocenasmaku)) + "/5";
    } else if (wybor == 2) {
        nazwaoceny = "Ocena: " + ocena<string>(ListaPrzepisow[indeks - 1].ocenasmaku) + "/*****";
    }
    return nazwaoceny;
};

string Sniadanie::wyswietlCiekawostki(int indeks) {
    string ciekawostki;
    for (const string &ciekawostka : ListaPrzepisow[indeks - 1].Ciekawostka) {
        ciekawostki += ciekawostka + "\n";
    }
    return ciekawostki;
}

string Sniadanie::wyswietlSkladnikiPrzepisu(int indeks) {
    string nazwaskladnikow;
    for (int j = 0; j < ListaPrzepisow[indeks - 1].SkladnikiGlowne.size(); ++j) {
        nazwaskladnikow += to_string(j + 1) + ". " + ListaPrzepisow[indeks -1].SkladnikiGlowne[j] + "\n";
    }
    return nazwaskladnikow;
};

string Sniadanie::wyswietlNazwyPrzypraw(int indeks) {
    string nazwyprzypraw;
    for (int j = 0; j < ListaPrzepisow[indeks - 1].Przyprawy.size(); ++j) {
        nazwyprzypraw += to_string(j + 1) + ". " + ListaPrzepisow[indeks -1].Przyprawy[j] + "\n";
        }
    if (nazwyprzypraw.empty()){
        return "pusto";
    }
    return nazwyprzypraw;
}

string Sniadanie::wyswietlKrokiPrzepisu(int indeks, std::string decyzja, int numerkroku) {
    string nazwakroku;
    if (decyzja == "t") {
        for (int j = 0; j < ListaPrzepisow[indeks - 1].Krok.size(); ++j) {
            nazwakroku = ListaPrzepisow[indeks - 1].Krok[numerkroku];
            if (nazwakroku.empty()){
                break;
            }
            break;
        }
    }
    return nazwakroku;
}