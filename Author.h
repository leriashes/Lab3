#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Author : public Person	//�����
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

	void Init(string full_name, Date birth_date);
	void Init(string full_name, Date birth_date, string country);		 //������������� ���� �����
	void Init(string full_name, int day, int month, int year, string country);	//������������� ���� �����
	bool BornIn(string country);	//�������� ������� �� ����� � ��������� ������
	string About();

	friend void operator<<(ostream& o, Author author);
	friend class InOut;
};

