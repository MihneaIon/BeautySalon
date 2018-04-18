#include "Visit.h"


Visit::Visit(Customer customer, time_t date)
{
	this->customer = customer;
	this->productExpense = 0;
	this->serviceExpense = 0;
	this->date = date;
}

Visit::Visit(Customer customer, double services, double products)
{
	this->customer = customer;
	this->productExpense = services;
	this->serviceExpense = products;
	this->date = time(0);
}

Visit::~Visit()
{
	this->customer.~Customer();
}

Customer Visit::getCustomer()const
{
	return this->customer;
}
double Visit::getServiceExpense()const
{
	return this->serviceExpense;
}
double Visit::getProductExpense()const
{
	return this->productExpense;
}

void Visit::setCustomer(const Customer& customer)
{
	this->customer = customer;
}
void Visit::setServiceExpense(double serviceExpense)
{
	this->serviceExpense = serviceExpense;
}
void Visit::setProductExpense(double productExpense)
{
	this->productExpense = productExpense;
}

double Visit::getTotalExpense()const
{
	return this->productExpense + this->serviceExpense;
}

std::istream& operator >> (std::istream& stream, Visit& visit)
{
	stream >> visit.customer;
	std::cout << "Service expense: "; stream >> visit.serviceExpense;
	std::cout << "Product expense: "; stream >> visit.productExpense;
	return stream;
}

std::ostream& operator << (std::ostream& stream, const Visit& visit) // echivalentul toString-ului()
{
	stream << "Client: " << visit.customer << ", total:  " << visit.serviceExpense << " + " << visit.productExpense;
	return stream;
}