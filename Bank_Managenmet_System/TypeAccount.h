#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class TypeAccount
{
private:
	float interestRate;
	int savingAccount;
	int normalAccount;
public:
	TypeAccount();
	TypeAccount(int savingAccount, int normalAccount);
	void setInterestRate(float interestRate);
	void setSavingAccount(int newMoney);
	void setNormalAccount(int newMoney);
	float getInterstRate();
	int getSavingAccount();
	int getNormailAccount();
	string toString();
};

