#pragma once
#include"Visit.h"
#include"DiscountRate.h"
#include<vector>
#include<iomanip>
#include <utility>
#include<fstream>

class BeautySalon
{
private:
	std::vector<std::pair<std::string, double>> products;
	std::vector < std::pair<std::string, double>> services;
	DiscountRate table;

public:
	BeautySalon();
	~BeautySalon();

	void Welocome()const;

	void vizit(Customer);

	void casa_de_marcat(Visit, std::vector<std::pair<std::string, double>>);
};

