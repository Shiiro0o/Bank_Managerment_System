#include "managerAdmin.h"
#include<iostream>
#include <fstream>
#include"PrintLog.h"
using namespace std;

ManagerAdmin::ManagerAdmin()
{
}


void ManagerAdmin::showListInforAccount()
{
	ifstream fileInput("F:/HUBT/project/Data.txt");
	for (int i = 0; i < listAccount.size(); i++) {
		cout << listAccount[i].toString() << endl;
	}
}

void ManagerAdmin::showListInforAccount(string idCus)
{
	ifstream fileInput("F:/HUBT/project/Data.txt");
	for (int i = 0; i < listAccount.size(); i++) {
		if (listAccount[i].getCustomer().getCusID()==idCus)
		{
			cout << listAccount[i].toString();
		}
	}
}

void ManagerAdmin::withdrawal()
{
	string id;
	int money;
	int index;
	system("CLS");
	cout << "\n\t*********** WITHDRAW ***********\n";
	cout << "\n\t\tEnter your Account ID: "; cin >> id;
	if (checkDataList(id) == true)
	{
		cout << "\n\t\tAccount ID Is Incorrect :( " << endl;
		depositMoney();
	}
	cout << "\n\t\tEnter The Amount You Need To Withdraw: "; cin >> money;
	cout << "\n\t\tChoose Account Would You Like To Withdraw: " << endl;
	cout << "\n\t\t1. Saving Account" << endl;
	cout << "\n\t\t2. Current  Account" << endl;
	cout << "\n\t\tEnter your choice : "; cin >> index;
	if (index == 1)
	{
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getAccountID() == id)
			{
				Customer cus = listAccount[i].getCustomer();
				TypeAccount type = listAccount[i].getType();
				type.setSavingAccount(listAccount[i].getType().getSavingAccount() - money);
				Account acc(listAccount[i].getAccountID()
					, cus, listAccount[i].getUsername(), listAccount[i].getPassWord(), type);
				listAccount.erase(listAccount.begin() + i);
				listAccount.push_back(acc);
				return;
			}
		}
	}
	else if (index == 2) {
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getAccountID() == id)
			{
				Customer cus = listAccount[i].getCustomer();
				TypeAccount type = listAccount[i].getType();
				type.setNormalAccount(listAccount[i].getType().getNormailAccount() - money);
				Account acc(listAccount[i].getAccountID()
					, cus, listAccount[i].getUsername(), listAccount[i].getPassWord(), type);
				listAccount.erase(listAccount.begin() + i);
				listAccount.push_back(acc);
				return;
			}
		}
	}
	else
	{
		cout << "\n\t\tPlease enter correct option :(" << endl;
		depositMoney();
	}
}

void ManagerAdmin::transfersMoney()
{
	string id,id2;
	int money;
	int index;
	system("CLS");
	cout << "\n\t*********** TRANSFERSMONEY ***********\n";
	cout << "\n\t\tEnter Your Account ID: "; cin >> id;
	cout << "\n\t\\tEnter The Recipient's Account ID: "; cin >> id2;
	if (checkDataList(id) == true && checkDataList(id2)==true)
	{
		cout << "\n\t\tAccount ID Is Incorrect :( " << endl;
		depositMoney();
	}
	cout << "\n\t\tEnter The Amount You Need To Transfersmoney: "; cin >> money;
	cout << "\n\t\tChoose Account Would You Like To Transfersmoney: " << endl;
	cout << "\n\t\t1. Saving Account" << endl;
	cout << "\n\t\t2. Current  Account" << endl;
	cout << "\n\t\tEnter your choice : "; cin >> index;
	if (index == 1)
	{
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getAccountID() == id)
			{
				for (int j = 0; j < listAccount.size(); j++) {
					if (listAccount[j].getAccountID()==id2)
					{
						Customer cus = listAccount[j].getCustomer();
						TypeAccount type = listAccount[j].getType();
						type.setSavingAccount(listAccount[j].getType().getSavingAccount() + money);
						Account acc(listAccount[j].getAccountID()
							, cus, listAccount[j].getUsername(), listAccount[j].getPassWord(), type);
						listAccount.erase(listAccount.begin() + j);
						listAccount.push_back(acc);
						return;
					}
				}
				Customer cus = listAccount[i].getCustomer();
				TypeAccount type = listAccount[i].getType();
				type.setSavingAccount(listAccount[i].getType().getSavingAccount() - money);
				Account acc(listAccount[i].getAccountID()
					, cus, listAccount[i].getUsername(), listAccount[i].getPassWord(), type);
				listAccount.erase(listAccount.begin() + i);
				listAccount.push_back(acc);
				return;
			}
		}
	}
	else if (index == 2) {
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getAccountID() == id)
			{
				for (int j = 0; j < listAccount.size(); j++) {
					if (listAccount[j].getAccountID() == id2)
					{
						Customer cus = listAccount[j].getCustomer();
						TypeAccount type = listAccount[j].getType();
						type.setNormalAccount(listAccount[j].getType().getNormailAccount() + money);
						Account acc(listAccount[j].getAccountID()
							, cus, listAccount[j].getUsername(), listAccount[j].getPassWord(), type);
						listAccount.erase(listAccount.begin() + j);
						listAccount.push_back(acc);
						return;
					}
				}
				Customer cus = listAccount[i].getCustomer();
				TypeAccount type = listAccount[i].getType();
				type.setNormalAccount(listAccount[i].getType().getNormailAccount() - money);
				Account acc(listAccount[i].getAccountID()
					, cus, listAccount[i].getUsername(), listAccount[i].getPassWord(), type);
				listAccount.erase(listAccount.begin() + i);
				listAccount.push_back(acc);
				return;
			}
		}
	}
	else
	{
		cout << "\n\t\tPlease enter correct option :(" << endl;
		depositMoney();
	}
}

void ManagerAdmin::depositMoney()
{
	string id;
	int money;
	int index;
	system("CLS");
	cout << "\n\t*********** DEPOSITMONEY ***********\n";
	cout << "\n\t\tEnter Your Account ID: "; cin >> id;
	if (checkDataList(id)==true)
	{
		cout << "\n\t\tAccount ID Is Incorrect :( "<<endl;
		depositMoney();
	}
	cout << "\n\t\tEnter The Amount You Need To Depositmoney: "; cin >> money;
	cout << "\n\t\tChoose Account Would You Like To Depositmoney: " << endl;
	cout << "\n\t\t1. Saving Account" << endl;
	cout << "\n\t\t2. Current  Account" << endl;
	cout << "\n\t\tEnter your choice : "; cin >> index;
	if (index == 1)
	{
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getAccountID() == id)
			{
				Customer cus = listAccount[i].getCustomer();
				TypeAccount type = listAccount[i].getType();
				type.setSavingAccount(listAccount[i].getType().getSavingAccount()+money);
				Account acc(listAccount[i].getAccountID()
					, cus, listAccount[i].getUsername(), listAccount[i].getPassWord(), type);
				listAccount.erase(listAccount.begin() + i);
				listAccount.push_back(acc);
				return;
			}
		}
	}
	else if (index == 2) {
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getAccountID() == id)
			{
				Customer cus = listAccount[i].getCustomer();
				TypeAccount type = listAccount[i].getType();
				type.setNormalAccount(listAccount[i].getType().getNormailAccount() + money);
				Account acc(listAccount[i].getAccountID()
					, cus, listAccount[i].getUsername(), listAccount[i].getPassWord(), type);
				listAccount.erase(listAccount.begin() + i);
				listAccount.push_back(acc);
				return;
			}
		}
	}
	else
	{
		cout << "\n\t\tPlease enter correct option :(" << endl;
		depositMoney();
	}
}



void ManagerAdmin::PrintLOG()
{
	string data = "";
	for (int i = 0; i < listAccount.size(); i++) {
		data += listAccount[i].toString();
	}
	cout << "Successful Data Export, Please Check The Folder F:/Log.txt" << endl;
	PrintLog::getInsatance()->WriteLog(data, "Data");
}
