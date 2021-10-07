#pragma once
#include <iostream>
class Customer
{
private:
	std::string cusID, name, address, phone, email;
public:
	Customer();
	Customer( std::string customerID,std::string name, std::string address, std::string phone, std::string email);
	void setName(std::string name);
	void setAddress(std::string address);
	void setPhone(std::string phone);
	void setEmail(std::string email);
	void setCusID(std::string newID);
	std::string getName() const;
	std::string getAddress() const;
	std::string getPhone() const;
	std::string getEmail() const;
	std::string toString();
	std::string getCusID();

};

