/*! \file Polygon.cpp
*
* \brief Zawiera definicję klasy Polygon
*
* Plik zawiera implementację metod klasy Polygon.
*
* \author Tomasz Łakomy
* \date 2020.02.26
* \version 1.00.00
*/

#include "Polygon.h"
#include "Punkt2.h"
#include <cmath>

double Polygon::getTriangleArea(Punkt2 p1, Punkt2 p2, Punkt2 p3) const {
	return 0.5*abs(
		(p2.getX() - p1.getX())*
		(p3.getY() - p1.getY()) -
		(p2.getY() - p1.getY())*
		(p3.getX() - p1.getX())
		);
}

Polygon::Polygon(){
	std::cout << "Uruchomiono konstruktor domyślny." << std::endl;
	amount++;
}

Polygon::Polygon(unsigned int Count, Punkt2 * Vertices): count{Count}, vertices{Vertices}
{
	std::cout << "Uruchomiono konstruktor w pełni sparametryzowany." << std::endl;
	amount++;
}

Polygon::Polygon(const Polygon &polygon){
	std::cout << "Uruchomiono konstruktor kopiujący." << std::endl;
	count = polygon.count;
	vertices = new Punkt2[count];
	for (int i=0; i<count; i++){
		vertices[i] = polygon.vertices[i];
	}
	amount++;
}

Polygon::Polygon(Polygon &&polygon){
	std::cout << "Uruchomiono konstruktor przenoszący." << std::endl;
	count = polygon.count;
	vertices = polygon.vertices;
}

Polygon::~Polygon(){
	std::cout << "Uruchomiono destruktor domyślny Polygon." << std::endl;
	if (vertices){
		delete[] vertices;
	}
	amount--;
}

void Polygon::setVertices(Punkt2 * Vertices, int Count){
	vertices = Vertices;
	count = Count;
}

void Polygon::setCount(int n){
	count = n;
}

void Polygon::changeVertex(int i, double x, double y){
	vertices[i].setX(x);
	vertices[i].setY(y);
}

Punkt2 Polygon::getVertex(int i) const
{
	return vertices[i];
}

Punkt2 * Polygon::getVertices() const{
	return vertices;
}

int Polygon::getCount() const{
	return count;
}

double Polygon::getPerimeter() const{
	double perimeter = 0.0;
	perimeter = perimeter + vertices[0].getDistance(vertices[count - 1]);
	for (unsigned int x = 0; x < count-2; x++){
		perimeter = perimeter + vertices[x].getDistance(vertices[x + 1]);
	}
	return perimeter;
}

double Polygon::getConvexArea() const{
	double area = 0;

	for (unsigned int i = 0; i < count - 2; i++)
	{
		area += getTriangleArea(vertices[0], vertices[i + 1], vertices[i + 2]);
	}

	return area;
}

double Polygon::getArea() const{
	double area = 0;

	for (unsigned int i = 1; i < count - 1; i++)
	{
		area += vertices[i].getX() * (vertices[i + 1].getY() - vertices[i - 1].getY());
	}
	area += vertices[0].getX() * (vertices[1].getY() - vertices[count - 1].getY());
	area += vertices[count - 1].getX() * (vertices[0].getY() - vertices[count - 2].getY());

	return 0.5 * abs(area);
}

unsigned int Polygon::amount=0;

Punkt2 & Polygon::operator[](int i) const
{
	return vertices[i];
}

Polygon & Polygon::operator=(const Polygon &pol){
	if (&pol != this){
		delete[] vertices;
		count = pol.count;
		vertices = new Punkt2[count];
		for (int i=0; i< count; i++){
			vertices[i] = pol.vertices[i];
		}
		amount++;
	}
	return *this;
}

Polygon & Polygon::operator=(Polygon &&pol){
	if (&pol != this){
		delete[] vertices;
		vertices = pol.vertices;
		count = pol.count;

		pol.count = 0;
		pol.vertices = nullptr;
	}
	
	return *this;
}

Polygon::operator Punkt2*(){
	return vertices;
}

Polygon::operator int(){
	return count;
}

std::ostream& operator<<(std::ostream& os, const Polygon& polygon){
	for (int i=0; i<polygon.count; i++){
		os << i << ":" << polygon.vertices[i] << std::endl;
	}
	return os;
}