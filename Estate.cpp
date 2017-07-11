#include "Estate.h"
#include <string>
#include <iostream>

Estate::Estate(EstateTypeEnum estType)
{
	m_address = "";
	m_owner = "";
	m_price = 0;
	m_surface = 0;
	m_stateStatus = unknown;
	m_estateType = estType;
}

Estate::Estate(std::string address, std::string owner, unsigned int price, unsigned int surface, StateStatus status, EstateTypeEnum estType)
{
	m_address = address;
	m_owner = owner;
	m_price = price;
	m_surface = surface;
	m_stateStatus = status;
	m_estateType = estType;
}

std::ostream& Estate::print(std::ostream& out) const
{
	out << "Address: " << m_address << std::endl
		<< "Owner: " << m_owner << std::endl
		<< "Price: " << m_price << std::endl
		<< "Surface: " << m_surface << std::endl
		<< "Status: " << m_stateStatus << std::endl;

	return out;
}

Estate* Estate::operator() (std::string address, std::string owner, unsigned int price, unsigned int surface, StateStatus status, EstateTypeEnum estType)
{
	m_address = address;
	m_owner = owner;
	m_price = price;
	m_surface = surface;
	m_stateStatus = status;
	m_estateType = estType;

	return this;
}

EstateTypeEnum Estate::get_type() const
{
	return m_estateType;
}

std::istream& Estate::read(std::istream& in)
{
	std::ostream& out = std::cout;
	out << "Enter address: ";
	in >> m_address;
	out << "Enter owner: "; 
	in >> m_owner; 
	out << "Enter price: ";
	in >> m_price;
	out << "Enter surface: ";
	in >> m_surface;
	int status;
	out << "Enter status: ";
	in >> status;
	m_stateStatus = (StateStatus)status;

	return in;
}
