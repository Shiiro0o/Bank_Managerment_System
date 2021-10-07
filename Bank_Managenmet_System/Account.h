#pragma once
#include <iostream>
#include "Customer.h"
#include "TypeAccount.h"
class Account
{
private:
	Customer customer;
	std::string accountid,username,pass;
	TypeAccount type;
public:
	Account(std::string accountid, Customer cus,string username,string pass,TypeAccount type);
	void setAccountID(std::string accountid);
	std::string getAccountID() ;
	std::string getPassWord() ;
	std::string getUsername() ;
	void setPass(string newPass);
	std::string toString();
	TypeAccount getType();
	Customer getCustomer();
};

