/*! \file main.cpp
*
* \brief Kod programu testuj�cego klas� Punkt2
*
* Plik zawiera funkcj� main(),
* w kt�rej wykonano kilka podstawowych test�w
* dotycz�cych klasy Punkt2
*
* \author Tomasz �akomy
* \date 2020.02.19
* \version 1.00.00
*/

#include <iostream>
#include "Punkt2.h"
#include "Polygon.h"
#include "MapPoint.h"
#include "MapPolygon.h"

int main()
{
	MapPoint mp1 = MapPoint(); //konstruktor domyślny

	MapPoint mp2 = MapPoint(10.0, 20.0, 7, { 255,0,255,255 }); //zwykły konstruktor

	MapPoint mp3 = mp2; //konstruktor kopiujący

	mp2 = mp3; //kopiujący operator przypisania

	MapPoint mp4 = (MapPoint(10.0, 20.0, 7, { 255,0,255,255 })); //konstruktor przenoszący

	mp3 =  MapPoint(10.0, 20.0, 7, { 255,0,255,255 }); //przenoszący operator przypisania



	Punkt2 p = static_cast (mp3);

	return 0;
}
