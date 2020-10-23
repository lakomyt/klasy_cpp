/*! \file MapPoint.cpp
*
* \brief Zawiera definicj� klasy MapPoint
*
* Plik zawiera implementacj� metod klasy MapPoint.
*
* \author Tomasz �akomy
* \date 2020.04.09
* \version 1.00.00
*/

#include "MapPoint.h"

MapPoint::MapPoint():
	MapPoint(0.0,0.0,0,{0,0,0,255})
{}

MapPoint::MapPoint(double x, double y, int radius, RGBA color ):
	Punkt2(x,y), visRadius{radius}, visColor{color}
{}

MapPoint::MapPoint(const MapPoint& mp):
	Punkt2(mp), visRadius{ mp.visRadius }, visColor{ mp.visColor }
{}

MapPoint::MapPoint(MapPoint&& mp):
	Punkt2(std::move(mp)), visRadius{ mp.getVisRadius() }, visColor{ mp.getVisColor() }
{}

int MapPoint::getVisRadius() const{
    return visRadius;
}

RGBA MapPoint::getVisColor() const{
    return visColor;
}

void MapPoint::setVisRadius(int r){
    visRadius = r;
}

void MapPoint::setVisColor(RGBA color){
    visColor = color;
}

MapPoint& MapPoint::operator=(const MapPoint& mp)
{
	if (this != &mp)
	{
		Punkt2::operator=(mp);
		visRadius = mp.visRadius;
		visColor = mp.visColor;
	}

	return *this;
}


MapPoint& MapPoint::operator=(MapPoint&& mp)
{
	if (this != &mp)
	{
		Punkt2::operator=(std::move(mp));
		visRadius = mp.getVisRadius();
		visColor = mp.getVisColor();
	}

	return *this;
}

MapPoint::operator int(){
	return visRadius;
}

MapPoint::operator RGBA(){
	return visColor;
}
/*
std::ostream& operator<<(std::ostream& os, const MapPoint& obj)
{
	Punkt2 p = static_cast (obj); //rzutowanie na klasę bazową

	os << p << obj.getVisColor() << "width(" << obj.getVisRadius() << ")\n";

	return os;
}
*/
