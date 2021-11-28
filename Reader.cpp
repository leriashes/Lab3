#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Reader.h"

//�����������
Reader::Reader()
{
	full_name = "������ ���� ��������";
	doc_number = "01 10 123456";
}

//����������� � ����������
Reader::Reader(string full_name, Date birth_date, Address address, string doc_number)
{
	this->full_name = full_name;
	birth = birth_date;
	this->address = address;
	this->doc_number = doc_number;
}

//����������� � ���������� 
Reader::Reader(string full_name, Date birth_date, Address address, int doc_number)
{
	this->full_name = full_name;
	birth = birth_date;
	this->address = address;

	if (doc_number <= 0)
		this->doc_number = "01 10 123456";

	for (int i = 0; doc_number > 0 && i < 25; i++)
	{
		this->doc_number += " ";

		for (int j = i; j > 0; j--)
			this->doc_number[j] = this->doc_number[j - 1];

		this->doc_number[0] = doc_number % 10 + 48;
		doc_number /= 10;
		if (doc_number == 0)
			this->doc_number += '\0';
	}
}

//����������
Reader::~Reader()
{
}

//������������� ���� �����
void Reader::Init(string full_name, Date birth_date, Address address, string doc_number)
{
	this->full_name = full_name;
	birth = birth_date;
	this->address = address;
	this->doc_number = doc_number;

	return;
}

//������������� ���� �����
void Reader::Init(string full_name, Date birth_date, Address address, int doc_number)
{
	this->full_name = full_name;
	birth = birth_date;
	this->address = address;

	if (doc_number <= 0)
		this->doc_number = "01 10 123456";

	for (int i = 0; doc_number > 0 && i < 25; i++)
	{
		this->doc_number += " ";

		for (int j = i; j > 0; j--)
			this->doc_number[j] = this->doc_number[j - 1];

		this->doc_number[0] = doc_number % 10 + 48;
		doc_number /= 10;
		if (doc_number == 0)
			this->doc_number += '\0';
	}

	return;
}

//�������� �������� �� ���� ��� �������� ��������
bool Reader::IsBirthday(Date day)
{
	return birth.IsAnniversary(day);
}

void operator<<(ostream& o, Reader reader)
{
	cout << "[" + reader.doc_number + "] " + reader.full_name + " (���� ��������: " << reader.birth;
	cout << ". ����� ����������: " << reader.address;
	cout << ") ";
}
