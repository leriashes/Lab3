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
	Author(const char* full_name, int day, int month, int year, const char* country);	//Конструктор с параметром
	~Author();		//Деструктор

	void Init(const char* full_name, Date birth_date, const char* country);		 //Инициализация всех полей
	void Init(const char* full_name, int day, int month, int year, const char* country);	//Инициализация всех полей
	bool BornIn(const char* country);	//Проверка родился ли автор в указанной стране

	friend class InOut;
};

