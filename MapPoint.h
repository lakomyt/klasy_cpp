/*! \file MapPoint.h
*
* \brief Zawiera deklaracje klasy MapPoint
*
* Plik zawiera deklaracje klasy MapPoint.h.
*
* \author Tomasz Lakomy
* \date 2020.04.09
* \version 1.00.00
*/

#pragma once
#include <iostream>
#include "Punkt2.h"
#include "RGBA.h"

class MapPoint: Punkt2 // po dwukropku podajemy klasę, którą dziedziczy klasa MapPoint
{
	int visRadius; // promień koła reprezentującego punkt na mapie (w pikselach)
	RGBA visColor; // kolor koła reprezentującego punkt na mapie

public:

    MapPoint();
    MapPoint(double x, double y, int radius, RGBA color);

    MapPoint(const MapPoint& mp);
    MapPoint(MapPoint&& mp);

	int getVisRadius() const;
	RGBA getVisColor() const;

	void setVisRadius(int r);
	void setVisColor(RGBA color);

    MapPoint& operator=(const MapPoint& mp);
    MapPoint& operator=(MapPoint&& mp);

    explicit operator int();
    operator RGBA();

};

//std::ostream& operator<<(std::ostream& os, const MapPoint& obj);