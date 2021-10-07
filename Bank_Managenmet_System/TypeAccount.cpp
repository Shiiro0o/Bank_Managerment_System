#include "TypeAccount.h"



TypeAccount::TypeAccount()
{
}

TypeAccount::TypeAccount(int savingAccount, int normalAccount)
{
	this->savingAccount = savingAccount;
	this->normalAccount = normalAccount;
}

void TypeAccount::setInterestRate(float interestRate)
{
	this->interestRate = interestRate;
}

void TypeAccount::setSavingAccount(int newMoney)
{
	this->savingAccount = newMoney;
}

void TypeAccount::setNormalAccount(int newMoney)
{
	this->normalAccount = newMoney;
}

float TypeAccount::getInterstRate()
{
	return interestRate;
}

int TypeAccount::getSavingAccount()
{
	return savingAccount;
}

int TypeAccount::getNormailAccount()
{
	return normalAccount;
}

string TypeAccount::toString()
{
	string normail = std::to_string(normalAccount);
	//string saving = std::to_string(savingAccount);
	return "\n\tCurrent Balance: "+ normail
		+"\n\tCurrent Saving Account: "+ to_string(savingAccount)
		;
}
