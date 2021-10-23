#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Publishing.h"

//Конструктор
Publishing::Publishing()
{
	strcpy(name, "Издательство №1");
	strcpy(city, "г. Москва");
}

//Конструктор с параметром
Publishing::Publishing(const char* name, const char* city)
{
	strncpy(this->name, name, 30);
	this->name[29] = '\0';

	strncpy(this->city, city, 30);
	this->city[29] = '\0';
}

//Деструктор
Publishing::~Publishing()
{
}

void Publishing::Init(const char* name, const char* city)
{
	strncpy(this->name, name, 30);
	this->name[29] = '\0';

	strncpy(this->city, city, 30);
	this->city[29] = '\0';

	return;
}

//Проверка находится ли издательство в заданном городе
bool Publishing::IsHere(const char* city)
{
	bool result = false;

	if (strcmp(this->city, city) == 0)
		result = true;

	return result;
}
