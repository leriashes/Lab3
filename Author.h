#pragma once
#include "Date.h"
#include <string>
using namespace std;

class Author	//�����
{
private:
	string full_name;	//���
	Date birth;			//���� ��������
	string country;	//������

public:
	Author();	//�����������
	Author(string full_name, Date birth_date, string country);	//����������� � ����������
	Author(string full_name, int day, int month, int year, string country);	//����������� � ����������
	~Author();		//����������

	void Init(string full_name, Date birth_date, string country);		 //������������� ���� �����
	void Init(string full_name, int day, int month, int year, string country);	//������������� ���� �����
	bool BornIn(string country);	//�������� ������� �� ����� � ��������� ������

	friend void operator<<(ostream& o, Author author);
	friend class InOut;
};

