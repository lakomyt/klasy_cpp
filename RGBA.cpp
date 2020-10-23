/*! \file RGBA.cpp
*
* \brief Zawiera definicj� klasy RGBA
*
* Plik zawiera implementacj� metod klasy RGBA.
*
* \author Tomasz �akomy
* \date 2020.04.09
* \version 1.00.00
*/

#include "RGBA.h"

RGBA::RGBA(unsigned char R, unsigned char G, unsigned char B, unsigned char A): r{R}, g{G}, b{B}, a{A}
{}

std::ostream& operator<<(std::ostream& os, const RGBA& obj)
{
	os << "color(" << (int)obj.r << ", " << (int)obj.g << ", " << (int)obj.b << ", " << (int)obj.a << ") ";

	return os;
}