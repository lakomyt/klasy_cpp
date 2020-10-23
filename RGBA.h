/*! \file RGBA.h
*
* \brief Zawiera deklaracje klasy RGBA
*
* Plik zawiera deklaracje klasy RGBA.h.
*
* \author Tomasz Lakomy
* \date 2020.04.09
* \version 1.00.00
*/

#pragma once
#include <iostream>

class RGBA
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a{255};//ta składowa zwykle nie jest używana, więc ją inicjalizujemy w klasie

public:

    RGBA() = default;
    RGBA(unsigned char R, unsigned char G, unsigned char B, unsigned char A);


	friend std::ostream& operator<<(std::ostream& os, const RGBA& obj);
};

std::ostream& operator<<(std::ostream& os, const RGBA& obj);