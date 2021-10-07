#pragma once
#include<vector>
#include <iostream>
#include "Account.h"
#include "TypeAccount.h"
class ManagerAccount
{
protected:
	std::vector<Account> listAccount;
	void addcount();
	void editAccount();
	void PrintLOG();
	bool checkDataList(std::string id);
public:
	ManagerAccount();
};

