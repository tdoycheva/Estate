#include<iostream>
#include <string>
#include"Plot.h"
#include "RealEstate.h"


void testUtilitiesEnum()
{
	Plot asd = Plot("Stud city", "Satellite", 234567, 11, forSale, 9, other);
	std::cout <<"internet: " << asd.hasInternet() << std::endl;
	std::cout << "water: " << asd.hasWater() << std::endl;
	std::cout << "road: " << asd.hasRoad() << std::endl;
	asd.addUtility(water);
	std::cout << "water: " << asd.hasWater() << std::endl;
	asd.removeUtility(internet);
	std::cout << "internet: " << asd.hasInternet() << std::endl;
}


void testChangePlot()
{
	Plot* p = new Plot("Stud city", "Emak", 234567, 11, forSale, 9, other);
	p->print(std::cout);
	RealEstate est = RealEstate();
	est.addEstate(p);
	est.changeEstate(p);
	p->print(std::cout);
}

void testRemoveEstate()
{
	RealEstate est = RealEstate();
	Plot* p1 = new Plot("Stud city", "Emak", 234567, 11, forSale, 9, other);
	Plot* p2 = new Plot("Stud city2", "Smile", 234567, 11, forRent, 9, other);
	est.addEstate(p1);
	est.addEstate(p2);
	est.removeEstate(p1);
}

int main()
{

	testChangePlot();
	testRemoveEstate();
	testUtilitiesEnum();
	return 0;
}