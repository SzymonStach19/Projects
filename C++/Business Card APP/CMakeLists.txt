cmake_minimum_required(VERSION 3.23)
project(Projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt main.cpp Wizytowka.cpp Wizytowka.h Osoba_fizyczna.cpp Osoba_fizyczna.h Firma.cpp Firma.h ListaWizytowek.cpp ListaWizytowek.h)
