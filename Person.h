#pragma once
#include "Date.h"
#include <string>
using namespace std;

class Person
{
protected:
	string full_name;	//���
	Date birth;			//���� ��������

public:
	virtual void Init(string full_name, Date birth_date) = 0;
	virtual string About() = 0;
};

