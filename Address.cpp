#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Address.h"

//�����������
Address::Address()
{
	strcpy(this->city, "�. ������");

	strcpy(this->street, "��������� ��������");

	house = 3;
	flat = 3;
}

//����������� � ����������
Address::Address(const char* city, const char* street, int house_number, int flat_number)
{
	strncpy(this->city, city, 30);
	this->city[29] = '\0';

	strncpy(this->street, street, 40);
	this->street[39] = '\0';

	house = house_number;
	flat = flat_number;
}

//����������
Address::~Address()
{
}