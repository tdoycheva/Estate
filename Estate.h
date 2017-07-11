#pragma once
#include <string>

enum StateStatus
{
	forRent,
	forSale,
	sold,
	unknown
};

enum EstateTypeEnum
{
	flat,
	house,
	plot
};

class Estate
{
public:
	Estate(EstateTypeEnum);
	Estate(std::string, std::string, unsigned int, unsigned int, StateStatus, EstateTypeEnum);
	std::ostream& print(std::ostream& out) const;
	Estate* operator()(std::string, std::string, unsigned int, unsigned int, StateStatus, EstateTypeEnum);
	EstateTypeEnum get_type() const;
	virtual std::istream& read(std::istream& in);

private:
	std::string m_address;
	std::string m_owner;
	unsigned int m_price;
	unsigned int m_surface;
	StateStatus m_stateStatus;
	EstateTypeEnum m_estateType;
};