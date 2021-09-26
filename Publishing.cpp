#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Publishing.h"

//Конструктор
Publishing::Publishing()
{
	strcpy(name, "Издательство №1");
	strcpy(city, "г. Москва");
}

//Конструктор с параметром
Publishing::Publishing(const char* name, const char* city)
{
	strncpy(this->name, name, 30);
	this->name[29] = '\0';

	strncpy(this->city, city, 30);
	this->city[29] = '\0';
}

//Деструктор
Publishing::~Publishing()
{
}

void Publishing::Init(const char* name, const char* city)
{
	strncpy(this->name, name, 30);
	this->name[29] = '\0';

	strncpy(this->city, city, 30);
	this->city[29] = '\0';

	return;
}

//Ввод всех полей
void Publishing::Read()
{
	printf("Введите название издательства: ");

	char letter;
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			name[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			name[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nВведите населённый пункт, в котором находится издательство (например: г. Барнаул): ");

	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			city[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			city[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

//Вывод значений всех полей
void Publishing::Display()
{
	printf("%s (%s)", name, city);
	return;
}

//Проверка находится ли издательство в заданном городе
bool Publishing::IsHere(const char* city)
{
	bool result = false;

	if (strcmp(this->city, city) == 0)
		result = true;

	return result;
}
