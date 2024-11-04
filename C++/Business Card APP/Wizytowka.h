#pragma once
#include <iostream>

class Wizytowka {
public:
    int numer_tel;
    Wizytowka* next;

    Wizytowka(int numer_tel) : numer_tel(numer_tel), next(nullptr) {}
    virtual ~Wizytowka() {}

    virtual void wyswietl() const = 0;
};

