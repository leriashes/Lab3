#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Author.h"
using namespace std;

//Конструктор
Author::Author()
{
	full_name = "Иванов Иван Иванович";
	country = "Россия";
}

//Конструктор с параметром
Author::Author(string full_name, Date birth_date, string country)
{
	this->full_name = full_name;
	birth = birth_date;
	this->country = country;
}

//Конструктор с параметром
Author::Author(string full_name, int day, int month, int year, string country)
{
	this->full_name = full_name;
	birth.Init(0, 0,  0, day, month, year);
	this->country = country;
}

//Деструктор
Author::~Author()
{
}

//Инициализация значений всех полей
void Author::Init(string full_name, Date birth_date, string country)
{
	this->full_name = full_name;
	birth = birth_date;
	this->country = country;
}

//Инициализация значений всех полей
void Author::Init(string full_name, int day, int month, int year, string country)
{
	this->full_name = full_name;
	birth.Init(0, 0, 0, day, month, year);
	this->country = country;
}

//Проверка родился ли автор в указанной стране
bool Author::BornIn(string country)
{
	bool result = false;

	if (this->country == country)
		result = true;

	return result;
}