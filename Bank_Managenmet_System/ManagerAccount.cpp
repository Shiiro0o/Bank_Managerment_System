#include "ManagerAccount.h"
#include<iostream>
#include<vector>
#include"PrintLog.h"
using namespace std;

bool ManagerAccount::checkDataList(std::string id)
{
	for (int i = 0; i < listAccount.size(); i++) {
		if (listAccount[i].getAccountID()==id)
		{
			return false;
		}
	}
	return true;
}



ManagerAccount::ManagerAccount()
{
}

void ManagerAccount::addcount()
{
	string accountID, username, pass, name, address, phone, email,cusID;
	system("CLS");
	cout << "\n\t*********** ADD ACCOUNT ***********\n";
	cout << "\n\t\tEnter Your Customer ID: "; cin >> cusID;
	cout << "\n\t\tEnter Your Account ID : "; cin >> accountID;
	cout << "\n\t\tEnter Your Name: "; cin >> name;
	cout << "\n\t\tEnter Your Address: "; cin >> address;
	cout << "\n\t\tEnter Your Phone: "; cin >> phone;
	cout << "\n\t\tEnter Your Email: "; cin >> email;
	cout << "\n\t\tEnter Your Username: "; cin >> username;
	cout << "\n\t\tEnter Your Password: "; cin >> pass;
	Customer cus(cusID,name, address, phone, email);
	TypeAccount type(0, 0);
	Account acc(accountID, cus, username, pass, type);
	if (checkDataList(accountID)) {
		listAccount.push_back(acc);
	}
	else {
		cout << "\n\t\tID Already Exists... Pls Try Another!!"<<endl;
		addcount();
	}
	
}

void ManagerAccount::editAccount()
{
	string idAcc, idCus, name, address, phone, email;
	cout << "\n\t\tEnter Account ID : "; cin >> idAcc;
	cout << "\n\t\tEnter Customer ID : "; cin >> idCus;
	if (checkDataList(idAcc) == true)
	{
		cout << "\n\t\tAccount ID Is Incorrect :( " << endl;
		editAccount();
	}
	cout << "\n\t\tEnter New Name: "; cin >> name;
	cout << "\n\t\tEnter New Address: "; cin >> address;
	cout << "\n\t\tEnter New Phone: "; cin >> phone;
	cout << "\n\t\tEnter New Email: "; cin >> email;
	for (int i = 0; i < listAccount.size(); i++) {
		if (listAccount[i].getAccountID() == idAcc && listAccount[i].getCustomer().getCusID() == idCus)
		{
			Customer cus(idCus,name,address,phone,email);
			TypeAccount type = listAccount[i].getType();
			Account acc(listAccount[i].getAccountID()
				, cus, listAccount[i].getUsername(), listAccount[i].getPassWord(), type);
			listAccount.erase(listAccount.begin() + i);
			listAccount.push_back(acc);
		}
	}
	cout << "\n\t\tEdit Successfully :)";
	
	
}

void ManagerAccount::PrintLOG()
{
}
