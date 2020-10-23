/*! \file MapPolygon.h
*
* \brief Zawiera deklarację klasy MapPolygon
*
* \author Tomasz Łakomy
* \date 2020.04.01
* \version 1.00.00
*/

#pragma once
#include <iostream>
#include "Polygon.h"
#include "RGBA.h"

class MapPolygon: Polygon
{
	unsigned int borderWidth; /*!< grubość krawędzi wielokąta, w pixelach */
	RGBA borderColor; /*!< kolor krawędzi */
	RGBA fillColor; /*!< kolor wnętrza */
	unsigned int opacity; /*!< poziom nieprzezroczystości */

public:
	// konstruktory
	MapPolygon() = default;

	MapPolygon(unsigned int count, Punkt2 * vertices, unsigned int BorderWidth, RGBA BorderColor, RGBA FillColor, unsigned int Opacity);

	MapPolygon(const MapPolygon & MapPol);

	MapPolygon(MapPolygon && MapPol);

	MapPolygon(unsigned int Count, Punkt2 * Vertices, std::initializer_list<unsigned int> a, std::initializer_list<RGBA> b);

	~MapPolygon();

	//gettery
	unsigned int getBorderWidth();
	RGBA getBorderColor();
	RGBA getFillColor();
	unsigned int getOpacity();

	//settery
	void setBorderWidth(unsigned int BorderWidth);
	void setBorderColor(RGBA BorderColor);
	void setFillColor(RGBA FillColor);
	void setOpacity(unsigned int Opacity);

};