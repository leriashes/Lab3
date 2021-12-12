#pragma once
#include "Person.h"
#include "Address.h"

class Reader : public Person
{
private:
	Address address;	//Адрес
	string doc_number;		//Номер документа, удостоверяющего личность

public:
	Reader();	//Конструктор
	Reader(string full_name, Date birth_date, Address address, string doc_number);	//Конструктор с параметром
	Reader(string full_name, Date birth_date, Address address, int doc_number);	//Конструктор с параметром
	~Reader();	//Деструктор

	void Init(string full_name, Date birth_date);
	void Init(string full_name, Date birth_date, Address address, string doc_number);		//Инициализация всех полей
	void Init(string full_name, Date birth_date, Address address, int doc_number);		//Инициализация всех полей
	bool IsBirthday(Date day);		//Проверка является ли день днём рождения читателя
	string About();

	friend void operator<<(ostream& o, Reader reader);
	friend class InOut;
};

