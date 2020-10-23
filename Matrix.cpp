/*! \file Matrix.cpp
*
* \brief Zawiera definicję klasy Matrix
*
* Plik zawiera implementacje metod klasy Matrix.
*
* \author Tomasz Łakomy
* \date 2020.04.01
* \version 1.00.00
*/

#include "Matrix.h"

double * Matrix::operator[](unsigned int row)
{
    return tab[row];
}
