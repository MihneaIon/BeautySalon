#pragma once
#include<iostream>
#include<string>
#include<iomanip>

class Customer
{
private:
	std::string name;
	bool member;
	std::string type;
public:
	Customer(std::string name = std::string());
	~Customer();

	std::string getName()const;
	bool isMember()const;
	std::string getType()const;

	void setName(std::string);
	void setMember(bool);
	void setType(std::string);

	friend std::istream& operator >>(std::istream&, Customer&);
	friend std::ostream& operator << (std::ostream&, const Customer&);

};

