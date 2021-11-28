#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Address.h"

//�����������
Address::Address()
{
	this->city = "�. ������";
	this->street = "��������� ��������";
	house = 1;
	flat = 1;
}

//����������� � ����������
Address::Address(string city, string street, int house_number, int flat_number)
{
	this->city = city;
	this->street = street;
	house = house_number;
	flat = flat_number;
}

//����������
Address::~Address()
{
}

//������������� ���� �����
void Address::Init(string city, string street, int house_number, int flat_number)
{
	this->city = city;
	this->street = street;
	house = house_number;
	flat = flat_number;
}

//�������� ���������� ������
bool Address::City(string city)
{
	bool result = false;

	if (this->city == city)
		result = true;

	return result;
}

void operator<<(ostream& o, Address address)
{
	cout << address.city << ", " << address.street << " " << address.house << ", " << address.flat;
}
