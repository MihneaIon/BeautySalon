#include "DiscountRate.h"

DiscountRate::DiscountRate()
{
	this->serviceDiscountPremium = 0.2;
	this->serviceDiscountGold = 0.15;
	this->serviceDiscountSilver = 0.1;
	this->productDiscountPremium = 0.1;
	this->productDiscountGold = 0.1;
	this->productDiscountSilver = 0.1;
}

DiscountRate::~DiscountRate()
{
}

double DiscountRate::getServiceDiscountRate(std::string type)const
{
	return getDiscount("service", type);
}
double DiscountRate::getProductDiscountRate(std::string type)const
{
	return getDiscount("product", type);
}

double DiscountRate::getDiscount(std::string type1, std::string type2)const
{
	if (type1._Equal("service"))
	{
		if (type2._Equal("premium"))
		{
			return serviceDiscountPremium;
		}
		else if (type2._Equal("gold"))
		{
			return serviceDiscountGold;
		}
		else if (type2._Equal("silver"))
		{
			return serviceDiscountSilver;
		}
		else
		{
			return 0;
		}
	}
	else if (type1._Equal("product"))
	{
		if (type2._Equal("premium") || type2._Equal("gold") || type2._Equal("silver"))
		{
			return 0.1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}



}