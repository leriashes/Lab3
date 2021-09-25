#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Address.h"

//Конструктор
Address::Address()
{
	strcpy(this->city, "г. Москва");

	strcpy(this->street, "Ленинский проспект");

	house = 3;
	flat = 3;
}

//Конструктор с параметром
Address::Address(const char* city, const char* street, int house_number, int flat_number)
{
	strncpy(this->city, city, 30);
	this->city[29] = '\0';

	strncpy(this->street, street, 40);
	this->street[39] = '\0';

	house = house_number;
	flat = flat_number;
}

//Деструктор
Address::~Address()
{
}