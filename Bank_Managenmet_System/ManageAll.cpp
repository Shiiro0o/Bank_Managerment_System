#include "ManageAll.h"

void ManageAll::openMangerAdmin()
{
    system("CLS");
    int index;
    cout << "\n\t*********** WELCOME ADMIN ***********\n";
    cout << "\n\t\t>>Please Choose Any Option To login \n";
    cout << "\n\t\t1. Show Infor All Customer \n";
    cout << "\n\t\t2. Open Account \n";
    cout << "\n\t\t3. Edit Account \n";
    cout << "\n\t\t4. Deposit Money \n";
    cout << "\n\t\t5. Withdrawal \n";
    cout << "\n\t\t6. Data Export \n";
    cout << "\n\t\t7. Transfers Money \n";
    cout << "\n\t\t8. Go To Main Menu \n";
    cout << "\n\t\t0. Close Application \n";
    cout << "\n\t\tEnter your choice : "; cin >> index;
    switch (index)
    {
    case 1: mngAdd.showListInforAccount(); system("pause"); openMangerAdmin(); break;
    case 2: mngAdd.addcount(); system("pause"); openMangerAdmin(); break;
    case 3: mngAdd.editAccount();
    case 4: mngAdd.depositMoney(); openMangerAdmin(); break;
    case 5: mngAdd.withdrawal(); system("pause"); openMangerAdmin(); break;
    case 6: mngAdd.PrintLOG(); break;
    case 7: mngAdd.transfersMoney(); openMangerAdmin(); break;
    case 8: system("CLS"); Wellcome(); break;
    case 0: exit(0);
    
    
    default:
        cout << "\n\t\tPlease enter correct option :(";
        openMangerAdmin();
        break;
    }
}

void ManageAll::openMangerCustomer()
{
    int index;
    cout << "\n\t*********** WELCOME CUSTOMER ***********\n";
    cout << "\n\t\t>>Please Choose Any Option To login \n";
    cout << "\n\t\t1. Show Infor Accounts \n";
    cout << "\n\t\t2. Deposit Money \n";
    cout << "\n\t\t3. Transactions \n";
    cout << "\n\t\t4. Withdraw \n";
    cout << "\n\t\t5. Go To Main Menu \n";
    cout << "\n\t\t0. Close Application \n";
    cout << "\n\t\tEnter your choice : "; cin >> index;
    switch (index)
    {
    case 1: {
        string cusID;
        system("CLS");
        cout << "\n\t\tInput your CustomerID: "; cin >> cusID;
        mngAdd.showListInforAccount(cusID); openMangerCustomer(); break;
    }
    case 2: mngAdd.depositMoney(); openMangerAdmin(); break;
    case 3: mngAdd.transfersMoney(); openMangerAdmin(); break;
    case 4: mngAdd.withdrawal(); system("pause"); openMangerAdmin(); break;
    case 5: system("CLS"); Wellcome(); break;
    case 0: exit(0); break;
    default:
        cout << "\n\t\tPlease enter correct option :(";
        openMangerCustomer();
        break;
    }
}

void ManageAll::login()
{
    system("cls");
    string user, pass;
    cout << "\n\t\tEnter UserName: "; cin >> user;
    cout << "\n\t\tEnter Password: "; cin >> pass;
    if (user== "admin"&& pass== "123")
    {
        openMangerAdmin();
    }
    else {
        cout << "\n\t\tUserName or PassWord Is Incorrect :( ";
        system("pause");
        login();
    }

}

void ManageAll::Wellcome()
{
    int i;
    cout << "\n\t*********** BANK MANAGEMENT SYSTEM ***********\n";
    cout << "\n\t\t>>Please Choose Any Option To login \n";
    cout << "\n\t\t1.Customer\n\n\t\t2.Admin\n\n\t\t0.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1)
    {
        system("CLS");
        openMangerCustomer();
    }
    else if (i == 2) {
        login();
        
    }
    else if (i == 0) {
        exit(0);

    }
    else
    {
        cout << "\n\t\tPlease Enter Correct Option :(";

        Wellcome();
    }
}
