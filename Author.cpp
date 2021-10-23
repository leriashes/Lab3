#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Author.h"

//Конструктор
Author::Author()
{
	strcpy(full_name, "Иванов Иван Иванович");
	strcpy(country, "Россия");
}

//Конструктор с параметром
Author::Author(const char* full_name, Date birth_date, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//Конструктор с параметром
Author::Author(const char* full_name, int day, int month, int year, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth.Init(0, 0,  0, day, month, year);

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//Деструктор
Author::~Author()
{
}

//Инициализация значений всех полей
void Author::Init(const char* full_name, Date birth_date, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//Инициализация значений всех полей
void Author::Init(const char* full_name, int day, int month, int year, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth.Init(0, 0, 0, day, month, year);

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//Проверка родился ли автор в указанной стране
bool Author::BornIn(const char* country)
{
	bool result = false;

	if (strcmp(this->country, country) == 0)
		result = true;

	return result;
}