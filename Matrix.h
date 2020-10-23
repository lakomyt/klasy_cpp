/*! \file Matrix.h
*
* \brief Zawiera deklaracje klasy Matrix
*
* Plik zawiera deklaracje klasy Matrix.
*
* \author Tomasz Lakomy
* \date 2020.04.01
* \version 1.00.00
*/

#pragma once
#include <iostream>

class Matrix{
    double ** tab;
    int sizeX; // wymiar poziomy tablicy
    int sizeY; // wymiar pionowy tablicy

public:

    double * operator[](unsigned int row);
};