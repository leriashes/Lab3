#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Publishing.h"
using namespace std;

//Конструктор
Publishing::Publishing()
{
	name = "Издательство №1";
	city = "г. Москва";
}

//Конструктор с параметром
Publishing::Publishing(string name, string city)
{
	this->name = name;
	this->city = city;
}

//Деструктор
Publishing::~Publishing()
{
}

void Publishing::Init(string name, string city)
{
	this->name = name;
	this->city = city;

	return;
}

//Проверка находится ли издательство в заданном городе
bool Publishing::IsHere(string city)
{
	bool result = false;

	if (this->city == city)
		result = true;

	return result;
}

void operator<<(ostream& o, Publishing publishing)
{
	cout << publishing.name + " (" + publishing.city + ")";
}
