#include "Plot.h"
#include "Estate.h"
#include <string>
#include <iostream>
#include <assert.h>

Plot::Plot() : Estate(plot)
{
	m_type = other;
	m_listOfUtilities = 0;
}

Plot::Plot (std::string address, std::string owner, unsigned int price, unsigned int surface, StateStatus status, int utilities, typeOfPlot type)
		  : Estate(address, owner, price, surface, status, plot)
{
	m_listOfUtilities = utilities;
	m_type = type;
}

bool Plot::hasInternet() const 
{
	return (m_listOfUtilities & internet) == internet;
}

bool Plot::hasPower() const 
{
	return (m_listOfUtilities & power) == power;
}

bool Plot::hasWater() const 
{
	return (m_listOfUtilities & water) == water;
}

bool Plot::hasRoad() const
{
	return (m_listOfUtilities & road) == road;
}

void Plot::addUtility(const UtilityEnum newUtil)
{
	assert(!(m_listOfUtilities & newUtil));
	m_listOfUtilities |= newUtil;
}

void Plot::removeUtility(const UtilityEnum toBeRemoved)
{
	assert(m_listOfUtilities & toBeRemoved);
	m_listOfUtilities ^= toBeRemoved;
}

std::ostream& Plot::print(std::ostream& out) const
{
	Estate::print(out);
	out << "Type of plot: " << m_type << std::endl
		<< "Utilities: " << std::endl
		<< "	Power: " << hasPower() << std::endl
		<< "	Water: " << hasWater() << std::endl
		<< "	Road: " << hasRoad() << std::endl
		<< "	Internet: " << hasInternet() << std::endl;
	return out;
}

Plot* Plot::operator()(std::string address, std::string owner, unsigned int price, unsigned int surface, StateStatus status, int utilities, typeOfPlot type)
{
	Estate::operator()(address, owner, price, surface, status, plot);
	m_listOfUtilities = utilities;
	m_type = type;

	return this;
}

std::istream& Plot::read(std::istream& in)
{
	std::ostream& out = std::cout;
	Estate::read(in);
	int type;
	out << "Enter type: ";
	in >> type;
	m_type = (typeOfPlot)type;
	out << "Enter utilities code: ";
	in >> m_listOfUtilities;

	return in;
}