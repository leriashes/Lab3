#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Author.h"
using namespace std;

//�����������
Author::Author()
{
	full_name = "������ ���� ��������";
	country = "������";
}

//����������� � ����������
Author::Author(string full_name, Date birth_date, string country)
{
	this->full_name = full_name;
	birth = birth_date;
	this->country = country;
}

//����������� � ����������
Author::Author(string full_name, int day, int month, int year, string country)
{
	this->full_name = full_name;
	birth.Init(0, 0,  0, day, month, year);
	this->country = country;
}

//����������
Author::~Author()
{
}

//������������� �������� ���� �����
void Author::Init(string full_name, Date birth_date, string country)
{
	this->full_name = full_name;
	birth = birth_date;
	this->country = country;
}

//������������� �������� ���� �����
void Author::Init(string full_name, int day, int month, int year, string country)
{
	this->full_name = full_name;
	birth.Init(0, 0, 0, day, month, year);
	this->country = country;
}

//�������� ������� �� ����� � ��������� ������
bool Author::BornIn(string country)
{
	bool result = false;

	if (this->country == country)
		result = true;

	return result;
}

void operator<<(ostream& o, Author author)
{
	cout << author.full_name << " (" << author.birth;
	cout << ", " << author.country << ")";
}
