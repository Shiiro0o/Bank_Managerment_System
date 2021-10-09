#include "PrintLog.h"
#include<iostream>
#include <fstream>
using namespace std;
PrintLog* PrintLog::m_instance = 0;

PrintLog::PrintLog()
{
}

PrintLog::~PrintLog()
{
}

PrintLog* PrintLog::getInsatance()
{
	if (m_instance == 0)
	{
		m_instance = new PrintLog();
	}
	return m_instance;
}

void PrintLog::WriteLog(string data,string nameFile)
{
	ofstream of;
	of.open("D:/"+nameFile+".txt", ios::out);
	of << data;
	of.close();
}
