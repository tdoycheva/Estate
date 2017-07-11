#pragma once
#include "Estate.h"
#include <string>

enum typeOfPlot
{
	field,
	garden,
	buildingPlace,
	other
};

enum UtilityEnum
{
	power = 1,
	water = 2,
	road = 4,
	internet = 8
};

class Plot : public Estate
{
public:
	Plot();
	Plot(std::string, std::string, unsigned int, unsigned int, StateStatus, int, typeOfPlot);
	bool hasInternet() const;
	bool hasPower() const;
	bool hasRoad() const;
	bool hasWater() const;
	void addUtility(const UtilityEnum);
	void removeUtility(const UtilityEnum);
	std::ostream& print(std::ostream& out) const;
	Plot* operator() (std::string, std::string, unsigned int, unsigned int, StateStatus, int, typeOfPlot);
	std::istream& read(std::istream& in);

private:
	typeOfPlot m_type;
	int m_listOfUtilities;
};