#pragma once
#include<iostream>
#include<string>
class DiscountRate
{
private:
	double serviceDiscountPremium;
	double serviceDiscountGold;
	double serviceDiscountSilver;
	double productDiscountPremium;
	double productDiscountGold;
	double productDiscountSilver;

	double getDiscount(std::string, std::string)const;

public:
	DiscountRate();
	~DiscountRate();

	double getServiceDiscountRate(std::string)const;
	double getProductDiscountRate(std::string)const;

};