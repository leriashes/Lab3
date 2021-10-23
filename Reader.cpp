#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Reader.h"

//Конструктор
Reader::Reader()
{
	strcpy(full_name, "Иванов Иван Иванович");
	strcpy(doc_number, "01 10 123456");
}

//Конструктор с параметром
Reader::Reader(const char* full_name, Date birth_date, Address address, const char* doc_number)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;
	this->address = address;

	strncpy(this->doc_number, doc_number, 26);
	this->full_name[25] = '\0';
}

//Конструктор с параметром 
Reader::Reader(const char* full_name, Date birth_date, Address address, int doc_number)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;
	this->address = address;

	if (doc_number <= 0)
		strcpy(this->doc_number, "01 10 123456");

	for (int i = 0; doc_number > 0 && i < 25; i++)
	{
		for (int j = i; j > 0; j--)
			this->doc_number[j] = this->doc_number[j - 1];

		this->doc_number[0] = doc_number % 10 + 48;
		doc_number /= 10;
		if (doc_number == 0)
			this->doc_number[i + 1] = '\0';
	}
}

//Деструктор
Reader::~Reader()
{
}

//Инициализация всех полей
void Reader::Init(const char* full_name, Date birth_date, Address address, const char* doc_number)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;
	this->address = address;

	strncpy(this->doc_number, doc_number, 26);
	this->full_name[25] = '\0';

	return;
}

//Инициализация всех полей
void Reader::Init(const char* full_name, Date birth_date, Address address, int doc_number)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;
	this->address = address;

	if (doc_number <= 0)
		strcpy(this->doc_number, "01 10 123456");
	
	for (int i = 0; doc_number > 0 && i < 25; i++)
	{
		for (int j = i; j > 0; j--)
			this->doc_number[j] = this->doc_number[j - 1];

		this->doc_number[0] = doc_number % 10 + 48;
		doc_number /= 10;
		if (doc_number == 0)
			this->doc_number[i + 1] = '\0';
	}

	return;
}

//Ввод всех полей
void Reader::Read()
{
	printf("Введите ФИО читателя: ");

	char letter;
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			full_name[i] = '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			full_name[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nДата рождения\n");
	birth.ReadDate();

	printf("\nАдрес проживания\n");
	address.Read();

	printf("\nВведите номер документа, удостовряющего личность: ");
	for (int i = 0; i < 26; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			doc_number[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			doc_number[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

//Проверка является ли день днём рождения читателя
bool Reader::IsBirthday(Date day)
{
	return birth.IsAnniversary(day);
}
