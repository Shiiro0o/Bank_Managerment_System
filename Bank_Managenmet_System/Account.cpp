#include "Account.h"

Account::Account(std::string accountid,Customer cus,string user,string password, TypeAccount type)
{
	this->accountid = accountid;
	this->customer = cus;
	this->username = user;
	this->pass = password;
	this->type = type;
	
}

void Account::setAccountID(std::string accountid)
{
	Account::accountid = accountid;
}


std::string Account::getAccountID() 
{
	return accountid;
}


std::string Account::getPassWord() 
{
	return this->pass;
}

std::string Account::getUsername() 
{
	return username;
}

void Account::setPass(string newPass)
{
	this->pass = newPass;
}


std::string Account::toString()
{
	return "\n\tAccountID: " + accountid +
		"\n\t"+customer.toString()+
		"\n\t"+type.toString();
}

TypeAccount Account::getType()
{
	return type;
}

Customer Account::getCustomer()
{
	return customer;
}
