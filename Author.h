#pragma once
#include "Date.h"
class Author	//Автор
{
private:
	char full_name[50];	//ФИО
	Date birth;			//Дата рождения
	char country[30];	//Страна

public:
	Author();	//Конструктор
	Author(const char* full_name, Date birth_date, const char* country);	//Конструктор с параметром
	~Author();		//Деструктор
};

