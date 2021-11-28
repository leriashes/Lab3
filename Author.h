#pragma once
#include "Date.h"
#include <string>
using namespace std;

class Author	//Автор
{
private:
	string full_name;	//ФИО
	Date birth;			//Дата рождения
	string country;	//Страна

public:
	Author();	//Конструктор
	Author(string full_name, Date birth_date, string country);	//Конструктор с параметром
	Author(string full_name, int day, int month, int year, string country);	//Конструктор с параметром
	~Author();		//Деструктор

	void Init(string full_name, Date birth_date, string country);		 //Инициализация всех полей
	void Init(string full_name, int day, int month, int year, string country);	//Инициализация всех полей
	bool BornIn(string country);	//Проверка родился ли автор в указанной стране

	friend class InOut;
};

