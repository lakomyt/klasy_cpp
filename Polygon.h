/*! \file Polygon.h
*
* \brief Zawiera deklaracj� klasy Polygon
*
* Plik zawiera deklaracj� klasy Polygon.h.
* Wsp�rz�dne punktu s� podawane w uk�adzie kartezja�skim.
* Klasa zawiera kilka metod skladowych
*
* \author Tomasz �akomy
* \date 2020.02.26
* \version 1.00.00
*/

#pragma once
#include <iostream>
#include "Punkt2.h"

class Polygon
{
	unsigned int count; /*!< Ilość wierzchołków wielokąta */

	Punkt2 * vertices; /*!< Tablica wierzochołków */

	double getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3) const; /*!< Metoda zwracająca pole trójkąta */

public:
	//! Konstruktor domyślny.
	Polygon();

	//! Kontruktor przyjmujący jako argumenty kolejno ilość wierzchołków i tablicę Punktów.
	Polygon(unsigned int count, Punkt2 * vertices);

	//! Konstruktor kopiujący.
	Polygon(const Polygon &polygon);

	//! Konstruktor przenoszący.
	Polygon(Polygon &&polygon);

	//! Destruktor.
	~Polygon();

	//! Metoda konstruuj�ca tablic� wierzcho�k�w.
	/*!
	\param Vertices  argument typu Punkt*  przekazuj�cy tablic� wierzcho�k�w wielok�ta
	\param Count argument typu  unsigned int przekazuj�cy ilo�� wierzcho�k�w.
	\sa changeVertex()
	*/
	void setVertices(Punkt2 * Vertices, int Count);

	//! Metoda ustawiaj�ca ilo�� wierzcho�k�w.
	/*!
	\param n argument typu int przekazuj�cy ilo�� wiercho�k�w
	\sa setVeritces()
	*/
	void setCount(int n);

	//! Metoda zmieniaj�ca wsp�lrz�dne i-tego wierzcho�ka.
	/*!
	\param i argument typu int  przekazuj�cy numer wiercho�ka do zmiany
	\param x argument typu  double przekazuj�cy now� warto�� do wsp�rz�dnej x.
	\param y argument typu  double przekazuj�cy now� warto�� do wsp�rz�dnej y.
	\sa setVertices()
	*/
	void changeVertex(int i, double x, double y);

	//! Getter dla i-tego wierzchołka.
	/*!
	\param i argument typu int przekazujący index wierzchołka
	\sa changeVeritces()
	*/
	Punkt2 getVertex(int i) const;

	Punkt2 * getVertices() const;/*!< Metoda zwracająca tablicę wierzchołków*/

	int getCount() const;/*!< Getter dla ilości wierzchołków. */

	double getPerimeter() const;/*!< Metoda obliczająca obwód wielokąta */

	double getConvexArea() const;/*!< Metoda zwracająca pole wielkokąta*/

	double getArea() const;/*!< Metoda zwracająca pole wielokątów*/

	static unsigned int amount;/*!< Ilość elementów klasy Polygon */

	friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);

	Punkt2 & operator[](int i) const;

	Polygon & operator=(const Polygon &pol);

	Polygon & operator=(Polygon &&pol);

	explicit operator Punkt2*();

	operator int();
};

std::ostream& operator<<(std::ostream& os, const Polygon& polygon);