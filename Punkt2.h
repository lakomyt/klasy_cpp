/*! \file Punkt2.h
*
* \brief Zawiera deklaracje klasy Punkt2
*
* Plik zawiera deklaracje klasy Punkt2.h.
* Wspolrzedne punktu sa podawane w ukladzie kartezjanskim.
* Klasa zawiera kilka metod skladowych
*
* \author Tomasz Lakomy
* \date 2020.02.19
* \version 1.00.00
*/

#pragma once
#include <iostream>

class Punkt2
{
	double x{ 0.0 };
	double y{ 0.0 };

public:
	//konstruktory
	Punkt2();
	Punkt2(double param1, double param2, bool kartez=1);
	Punkt2(std::initializer_list<double> p);
	Punkt2(const Punkt2 & p);
	Punkt2(Punkt2 && p);

	//destruktory
	~Punkt2();

	//settery
	void setX(double X);
	void setY(double Y);

	//gettery
	double getX() const;
	double getY() const;

	//wsporzedne biegunowe
	double getRadius();
	double getAngle();

	//odleglosc punktu od punktu _p
	double getDistance(Punkt2 _p);

	//przeładowanie operatorów w klasie
	Punkt2 operator+(const Punkt2 &p) const;
	Punkt2 operator-(const Punkt2 &p) const;
	Punkt2 & operator=(const Punkt2 &p);
	Punkt2 & operator=(const Punkt2 &&p);

	// ilość elementów klasy Punkt2
	static unsigned int amount;
};

double operator*(const Punkt2 &p1, const Punkt2 &p2);

std::ostream& operator<<(std::ostream& os, const Punkt2& obj);

