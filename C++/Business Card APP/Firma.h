#include "Wizytowka.h"

class Firma : public Wizytowka {
public:
    std::string nazwa;
    std::string branza;

    Firma(int numer_tel, const std::string& nazwa, const std::string& branza)
            : Wizytowka(numer_tel), nazwa(nazwa), branza(branza) {}

    void wyswietl() const override;
};
