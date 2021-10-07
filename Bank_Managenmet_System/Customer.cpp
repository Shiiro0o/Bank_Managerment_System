#include "Customer.h"

Customer::Customer()
{
	//defaul contructor
}

Customer::Customer(std::string customerID, std::string name, std::string address, std::string phone, std::string email)
{
	this->cusID = customerID;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->email = email;
}


void Customer::setName(std::string name)
{
	Customer::name = name;
}

void Customer::setAddress(std::string address)
{
	Customer::address = address;
}
void Customer::setPhone(std::string phone)
{
	Customer::phone = phone;
}
void Customer::setEmail(std::string email)
{
	Customer::email = email;
}

void Customer::setCusID(std::string newID)
{
	this->cusID = newID;
}

std::string Customer::getName() const
{
	return name;
}

std::string Customer::getAddress() const
{
	return address;
}
std::string Customer::getPhone() const
{
	return phone;
}
std::string Customer::getEmail() const
{
	return email;
}

std::string Customer::toString()
{
	return "customerID: "+cusID+
		"\n\tName: " + name +
		"\n\tAddress: " + address +
		"\n\tPhone: " + phone +
		"\n\tEmail: " + email;
}

std::string Customer::getCusID()
{
	return cusID;
}
