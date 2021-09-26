#pragma once
#include "Date.h"
#include "Address.h"
class Reader
{
private:
	char full_name[50];	//ФИО
	Date birth;			//Дата рождения
	Address address;	//Адрес
	char doc_number[26];		//Номер документа, удостоверяющего личность

public:
	Reader();	//Конструктор
	Reader(const char* full_name, Date birth_date, Address address, const char* doc_number);	//Конструктор с параметром
	Reader(const char* full_name, Date birth_date, Address address, int doc_number);	//Конструктор с параметром
	~Reader();	//Деструктор

	void Init(const char* full_name, Date birth_date, Address address, const char* doc_number);		//Инициализация всех полей
	void Init(const char* full_name, Date birth_date, Address address, int doc_number);		//Инициализация всех полей
	void Read();	//Ввод всех полей
};

