#pragma once
#include <iostream>
class PrintLog
{
private:
	PrintLog();
	~PrintLog();
	static PrintLog* m_instance;
public:
	static PrintLog* getInsatance();
	void WriteLog(std::string data,std::string nameFile);
};


