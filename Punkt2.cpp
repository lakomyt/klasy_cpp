/*! \file Punkt2.cpp
*
* \brief Zawiera definicj� klasy Punkt2
*
* Plik zawiera implementacj� metod klasy Punkt2.
*
* \author Tomasz �akomy
* \date 2020.02.19
* \version 1.00.00
*/

#include "Punkt2.h"
#include <cmath>

Punkt2::Punkt2()
{
	std::cout << "Uruchomiono konstruktor domyślny." << std::endl;
	amount++;
}

Punkt2::Punkt2(double param1, double param2, bool kartez){
	std::cout << "Uruchomiono konstruktor w pełni sparametryzowany: (" << param1 << ", " << param2 << ", " << kartez << ")" << std::endl;
	if (kartez == 1){
		x = param1;
		y = param2;
	}
	else{
		x = param1 * cos(param2);
		y = param1 * sin(param2);
	}
	amount++;
}

Punkt2::Punkt2(std::initializer_list<double> p){
	std::cout << "Uruchomiono konstruktor initializer_list: (" << *(p.begin()) << ", " << *(p.begin()+1) << ")" << std::endl;
	x = *(p.begin());
	y = *(p.begin() + 1);
	amount++;
}

Punkt2::Punkt2(const Punkt2 & p){
	std::cout << "Uruchomiono konstruktor kopiujący: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
	x = p.getX();
	y = p.getY();
	amount++;
}

Punkt2::Punkt2(Punkt2 && p){
	std::cout << "Uruchomiono konstruktor przenoszący: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
	x = p.getX();
	y = p.getY();

	p.x = 0.0;
	p.y = 0.0;
}

Punkt2::~Punkt2(){
	std::cout << "Uruchomiono destruktor domyślny Punkt2. " << std::endl;
	amount--;
}

void Punkt2::setX(double X)
{
	x = X;
}

void Punkt2::setY(double Y)
{
	y = Y;
}

double Punkt2::getX() const
{
	return x;
}

double Punkt2::getY() const
{
	return y;
}

double Punkt2::getRadius()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Punkt2::getAngle()
{
	return atan2(x, y);
}

double Punkt2::getDistance(Punkt2 _p)
{
	return sqrt((_p.x-x)*(_p.x-x)+(_p.y-y)*(_p.y-y));
}

Punkt2 Punkt2::operator+(const Punkt2 &p) const
{
	return Punkt2(x + p.getX(), y + p.getY());
}

Punkt2 Punkt2::operator-(const Punkt2 &p) const
{
	return Punkt2(x - p.getX(), y - p.getY());
}

Punkt2 & Punkt2::operator=(const Punkt2 &p)
{
    std::cout << "Uruchomiono kopiujący operator przypisania. (Punkt2)" << std::endl;
    x = p.getX();
    y = p.getX();
        
    return *this;
}

Punkt2 & Punkt2::operator= (const Punkt2 &&p)
{
    std::cout << "Uruchomiono przenoszący operator przypisania. (Punkt2)" << std::endl;
    x = p.getX();
    y = p.getY();

    return *this;
}

unsigned int Punkt2::amount = 0;

double operator*(const Punkt2 &p1, const Punkt2 &p2){
	return p1.getX() * p2.getX() + p1.getY() * p2.getY();
}

std::ostream& operator<<(std::ostream& os, const Punkt2& obj)
{
	os << "( " << obj.getX() << ", " << obj.getY() << " )";
    return os;
}
