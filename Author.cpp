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

//Ввод значений всех полей
void Author::Read()
{
	printf("Введите ФИО автора: ");

	char letter;
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r' )
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

	printf("\nВведите страну происхождения автора: ");
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			country[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			country[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}