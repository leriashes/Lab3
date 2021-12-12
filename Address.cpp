#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Address.h"

//Конструктор
Address::Address()
{
	this->city = "г. Москва";
	this->street = "Ленинский проспект";
	house = 1;
	flat = 1;
}

//Конструктор с параметром
Address::Address(string city, string street, int house_number, int flat_number)
{
	this->city = city;
	this->street = street;
	house = house_number;
	flat = flat_number;
}

//Деструктор
Address::~Address()
{
}

//Инициализация всех полей
void Address::Init(string city, string street, int house_number, int flat_number)
{
	this->city = city;
	this->street = street;
	house = house_number;
	flat = flat_number;
}

//Проверка совпадения города
bool Address::City(string city)
{
	bool result = false;

	if (this->city == city)
		result = true;

	return result;
}

string Address::ToString()
{
    return city + ", " + street + " " + to_string(house) + ", " + to_string(flat);
}

void operator<<(ostream& o, Address address)
{
	cout << address.city << ", " << address.street << " " << address.house << ", " << address.flat;
}
