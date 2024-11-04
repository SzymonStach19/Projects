cmake_minimum_required(VERSION 3.23)
project(Obiektowe)

set(CMAKE_CXX_STANDARD 14)

add_executable(Obiektowe main.cpp AbstraktKategoria.h Sniadanie.h Obiad.h Kolacja.h Przepis.h Sniadanie.cpp Obiad.cpp Kolacja.cpp Oceny.cpp Oceny.h)
