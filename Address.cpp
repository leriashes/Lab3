#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Address.h"

//Конструктор
Address::Address()
{
	strcpy(this->city, "г. Москва");

	strcpy(this->street, "Ленинский проспект");

	house = 1;
	flat = 1;
}

//Конструктор с параметром
Address::Address(const char* city, const char* street, int house_number, int flat_number)
{
	strncpy(this->city, city, 30);
	this->city[29] = '\0';

	strncpy(this->street, street, 40);
	this->street[39] = '\0';

	house = house_number;
	flat = flat_number;
}

//Деструктор
Address::~Address()
{
}

//Инициализация всех полей
void Address::Init(const char* city, const char* street, int house_number, int flat_number)
{
	strncpy(this->city, city, 30);
	this->city[29] = '\0';

	strncpy(this->street, street, 40);
	this->street[39] = '\0';

	house = house_number;
	flat = flat_number;
}

//Ввод значений всех полей
void Address::Read()
{
	printf("Введите название населённого пункта (например: г. Барнаул): ");

	char letter;
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

	printf("\nВведите название улицы (например: ул. Попова): ");
	for (int i = 0; i < 40; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			street[i] = '\0';
			i = 40;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 39)
		{
			street[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	char result[5];
	printf("\nВведите номер дома: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	house = 0;
	for (int i = 0; result[i] != '\0'; i++)
		house = house * 10 + result[i] - 48;

	printf("\nВведите номер квартиры: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	flat = 0;
	for (int i = 0; result[i] != '\0'; i++)
		flat = flat * 10 + result[i] - 48;

	return;
}