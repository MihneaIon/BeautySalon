#include "BeautySalon.h"

BeautySalon::BeautySalon()
{
	unsigned n;
	std::ifstream f("products.txt");
	f >> n;
	for (unsigned i = 0; i < n; i++) {
		std::string name;
		double baskett;
		f >> name >> baskett;
		products.insert(std::pair<std::string, double>(name, baskett));
	}
	f.close();

	std::ifstream g("services.txt");
	g >> n;
	for (unsigned i = 0; i < n; i++) {
		std::string name;
		double baskett;
		g >> name >> baskett;
		services.insert(std::pair<std::string, double>(name, baskett));
	}
	g.close();
}

BeautySalon::~BeautySalon()
{
	this->products.clear();
	this->services.clear();
}

void BeautySalon::welcome()const
{
	std::cout << "\n     - Welcome to our beauty saloon! -\n";
	std::cout << "\n\n * We offer you the following products:\n\n";
	if (this->products.size() == 0)
		std::cout << " Unfortunately, we no longer have products. Come back tomorrow!";
	else
		for (auto iterator : products)
			std::cout << '(' << iterator.first << ',' << iterator.second << ") ";
	std::cout << "\n\n\n * We offer you the following services:\n\n";
	for (auto iterator : services)
		std::cout << '(' << iterator.first << ',' << iterator.second << ") ";
	std::cout << std::endl << std::endl;
}

void BeautySalon::visit(const Customer& customer) {

	std::map<std::string, double> basket;
	double productsPrice = 0, servicesPrice = 0; std::string choice;
	std::string name;

	do {
		system("cls");
		this->welcome();
		std::cout << "\nWhat do you wish to buy?\n\n";
		bool ok = 0;
		std::cin >> name;
		for (auto iterator : products)
			if (iterator.first == name) {
				basket.insert(iterator);
				ok = 1;
				productsPrice = productsPrice + iterator.second;
				this->products.erase(iterator.first);
				break;
			}
		if (ok == 0)
			for (auto iterator : services)
				if (iterator.first == name) {
					basket.insert(iterator);
					ok = 1;
					servicesPrice = servicesPrice + iterator.second;
					break;
				}

		if (ok == 0)
			std::cout << "\nThe item cannot be found!\n";
		std::cout << "\nDo you want to continue shopping?\n   1. Yes\n   2. No\n";

		bool validation = true;
		do
		{
			std::cout << "\n\nchoice:"; std::cin >> choice;
			if (choice == "1" || choice == "2")
			{
				validation = true;
			}
			else
			{
				validation = false;
			}

		} while (validation == false);

	} while (choice == "1");

	Visit visit(customer, productsPrice, servicesPrice);

	checkout(visit, basket);
}

void BeautySalon::checkout(Visit visit, std::map<std::string, double> basket)
{
	system("cls");
	std::cout << visit.getCustomer();
	if (basket.size() == 0) {
		std::cout << "\nYour basket is empty!\n\nHave a nice day!\n";
	}
	else {
		std::cout << "\nYour products:\n\n";
		for (auto iterator : basket) {
			std::cout << std::right << std::setw(10) << iterator.first << " .......................... ";
			std::cout << std::right << std::setw(4) << iterator.second << "$\n";
		}

		if (visit.getCustomer().isMember() == 0) {
			double bill = visit.getTotalExpense();
			std::cout << "\n\nDiscounts granted:\n\n" << std::right << std::setw(10) << " ";
			std::cout << " .......................... " << std::right << std::setw(6) << "0$\n";
			std::cout << "\n\nTotal:\n\n" << std::right << std::setw(10) << " " << " .......................... ";
			std::cout << std::right << std::setw(4) << bill << "$\n\n";
		}
		else {
			double services_discount = discount.getServiceDiscountRate(visit.getCustomer().getType());
			double products_discount = discount.getProductDiscountRate(visit.getCustomer().getType());
			double total_products = visit.getProductExpense() - (visit.getProductExpense() * products_discount);
			double total_services = visit.getServiceExpense() - (visit.getServiceExpense() * services_discount);
			double bill = total_products + total_services;
			std::cout << "\n\nDiscounts granted:\n\n";
			std::cout << std::right << std::setw(10) << visit.getCustomer().getType() << " discount for services";
			std::cout << " .... " << std::right << std::setw(4) << services_discount * 100 << "%\n";
			std::cout << std::right << std::setw(10) << visit.getCustomer().getType() << " discount for products";
			std::cout << " .... " << std::right << std::setw(4) << products_discount * 100 << "%\n";
			std::cout << "\n\nTotal:\n\n" << std::right << std::setw(10) << " " << " .......................... ";
			std::cout << std::right << std::setw(4) << bill << "$\n\n";
		}
	}
}