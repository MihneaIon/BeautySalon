#pragma once
#include"Customer.h"
#include <ctime>

class Visit
{
private:
	Customer customer;
	double serviceExpense;
	double productExpense;
	time_t date;
public:
	Visit(Customer, time_t date);
	Visit(Customer customer = Customer(), double services = 0, double products = 0);
	~Visit();

	Customer getCustomer()const;
	double getServiceExpense()const;
	double getProductExpense()const;

	void setCustomer(const Customer&);
	void setServiceExpense(double);
	void setProductExpense(double);

	double getTotalExpense()const;

	friend std::istream& operator >> (std::istream&, Visit&);
	friend std::ostream& operator << (std::ostream&, const Visit&);
};

