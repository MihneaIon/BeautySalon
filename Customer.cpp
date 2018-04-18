#include "Customer.h"



Customer::Customer(std::string name)
{
	this->name = name;
	this->member = false;
	this->type = std::string();
}

Customer::~Customer()
{
	this->name.clear();
	this->type.clear();
}

std::string Customer::getName()const
{
	return this->name;
}
bool Customer::isMember()const
{
	return this->member;
}
std::string Customer::getType()const
{
	return this->type;
}

void Customer::setName(std::string name)
{
	this->name = name;
}
void Customer::setMember(bool member)
{
	this->member = member;
}
void Customer::setType(std::string type)
{
	this->type = type;
}

std::istream& operator >> (std::istream& stream, Customer& customer)
{
	std::cout << "\nName: "; getline(stream, customer.name);
	std::string aux; bool ok = true;
	do
	{
		std::cout << "\nMembru: "; stream >> aux;
		if (aux == "0")
		{
			customer.member = 0;
			ok = true;
		}
		else if (aux == "1")
		{
			customer.member = 1;
			ok = true;
		}
		else
		{
			ok = false;
		}
	} while (ok == false);

	if (customer.member == 1)
	{
		do
		{
			std::cout << "\nType: "; stream >> customer.type;
		} while (customer.type != "gold" && customer.type != "silver" && customer.type != "premium");
	}
	return stream;
}

std::ostream& operator << (std::ostream& stream, const Customer& customer)
{
	std::cout << std::endl << std::left << std::setw(10) << "Name: " << customer.name << std::endl;
	std::cout << std::left << std::setw(10) << "Status: ";
	if (customer.member) {
		std::cout << "member\n";
		std::cout << std::left << std::setw(10) << "Type: " << customer.type << "\n\n";
	}
	else
		std::cout << "non-member\n\n";
	return stream;
}