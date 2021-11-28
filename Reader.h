#pragma once
#include "Date.h"
#include "Address.h"

class Reader
{
private:
	string full_name;	//ФИО
	Date birth;			//Дата рождения
	Address address;	//Адрес
	string doc_number;		//Номер документа, удостоверяющего личность

public:
	Reader();	//Конструктор
	Reader(string full_name, Date birth_date, Address address, string doc_number);	//Конструктор с параметром
	Reader(string full_name, Date birth_date, Address address, int doc_number);	//Конструктор с параметром
	~Reader();	//Деструктор

	void Init(string full_name, Date birth_date, Address address, string doc_number);		//Инициализация всех полей
	void Init(string full_name, Date birth_date, Address address, int doc_number);		//Инициализация всех полей
	bool IsBirthday(Date day);		//Проверка является ли день днём рождения читателя

	friend class InOut;
};

