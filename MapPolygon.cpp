/*! \file MapPolygon.cpp
*
* \brief Zawiera definicję klasy MapPolygon
*
* Plik zawiera implementację metod klasy MapPolygon.
*
* \author Tomasz Łakomy
* \date 2020.04.01
* \version 1.00.00
*/

#include "MapPolygon.h"

MapPolygon::MapPolygon(unsigned int Count, Punkt2 * Vertices, unsigned int BorderWidth, RGBA BorderColor, RGBA FillColor, unsigned int Opacity):
	Polygon(Count, Vertices), borderWidth{BorderWidth}, borderColor{BorderColor}, fillColor{FillColor}, opacity{Opacity}
{}

MapPolygon::MapPolygon(const MapPolygon & MapPol): Polygon(MapPol)
{
	borderWidth = MapPol.borderWidth;
	borderColor = MapPol.borderColor;
	fillColor = MapPol.fillColor;
	opacity = MapPol.opacity;
}

MapPolygon::MapPolygon(MapPolygon && MapPol): Polygon(std::move(MapPol))
{
	borderWidth = MapPol.borderWidth;
	borderColor = MapPol.borderColor;
	fillColor = MapPol.fillColor;
	opacity = MapPol.opacity;
}

MapPolygon::MapPolygon(unsigned int Count, Punkt2 * Vertices, std::initializer_list<unsigned int> a, std::initializer_list<RGBA> b): Polygon(Count, Vertices)
{
	borderWidth = *(a.begin());
	opacity = *(a.begin()+1);
	borderColor = *(b.begin());
	fillColor = *(b.begin()+1);
}

unsigned int MapPolygon::getBorderWidth(){
	return borderWidth;
}

RGBA MapPolygon::getBorderColor(){
	return borderColor;
}

RGBA MapPolygon::getFillColor(){
	return fillColor;
}

unsigned int MapPolygon::getOpacity(){
	return opacity;
}

void MapPolygon::setBorderWidth(unsigned int BorderWidth){
	borderWidth = BorderWidth;
}

void MapPolygon::setBorderColor(RGBA BorderColor){
	borderColor = BorderColor;
}

void MapPolygon::setFillColor(RGBA FillColor){
	fillColor = FillColor;
}

void MapPolygon::setOpacity(unsigned int Opacity){
	opacity = Opacity;
}
