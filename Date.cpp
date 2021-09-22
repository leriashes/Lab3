#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "date.h"
#include "Date.h"
#include <ctime>

//Конструктор
Date::Date()
{
	sec = min = hour = 0;
	day = 1;
	month = 1;
	year = 1900;
}

//Конструктор с параметром (только дата)
Date::Date(int day, int month, int year)
{
	sec = min = hour = 0;
	this->day = day;
	this->month = month;
	this->year = year;
}

//Конструктор с параметром (дата и время)
Date::Date(int seconds, int minutes, int hours, int day, int month, int year)
{
	sec = seconds;
	min = minutes;
	hour = hours;
	this->day = day;
	this->month = month;
	this->year = year;
}

//Деструктор
Date::~Date()
{

}

//Ввод времени
void Date::ReadTime()
{
	char time[6], digit;

	printf("Введите время (в формате HH:MM:SS): ");
	for (int i = 0; i < 7; i++)
	{
		digit = _getch();
		if (i == 6 && digit == '\r')
			i++;
		else if (i < 6 && digit >= '0' && digit <= '9' &&
			(digit <= '2' ||
				i == 1 && (digit == '3' || time[0] <= '1') ||
				(i == 2 || i == 4) && digit <= '5' ||
				i == 3 || i == 5))
		{
			time[i] = digit;
			printf("%c", digit);
			if (i % 2 == 1 && i < 5)
				printf(":");
		}
		else if (digit == '\b' && i > 0)
		{
			i -= 2;
			if (i % 2 == 0 && i < 4)
				printf("\b \b");
			printf("\b \b");

		}
		else
			i--;
	}

	hour = time[0] * 10 + time[1] - 528;
	min = time[2] * 10 + time[3] - 528;
	sec = time[4] * 10 + time[5] - 528;

	return;
}

//Ввод даты
void Date::ReadDate()
{
	char date[8], digit;

	printf("Введите дату (в формате YYYY.MM.DD): ");
	for (int i = 0; i < 9; i++)
	{
		digit = _getch();
		if (i == 8 && digit == '\r')
			i++;
		else if (i < 8 && digit >= '0' && digit <= '9' &&
			(i == 0 && digit <= '2' ||
				i == 1 && (digit == '0' || date[0] <= '1') ||
				i == 2 ||
				i == 3 && (digit >= '1' || digit == '0' && (date[0] != '0' || date[1] != '0' || date[2] != '0')) ||
				i == 4 && digit <= '1' ||
				i == 5 && (date[4] == '0' && digit >= '1' || date[4] == '1' && digit <= '2') ||
				i == 6 && (digit <= '2' || (date[4] != '0' || date[5] != '2') && digit == '3') ||
				i == 7 && (digit == '0' && date[6] != '0' || 
					digit == '1' && (date[6] <= '2' || date[4] == '0' && (date[5] == '1' || date[5] == '3' || date[5] == '5' || date[5] == '7' || date[5] == '8') || date[4] == '1' && (date[5] == '0' || date[5] == '2')) ||
					digit >= '2' && digit <= '8' && date[6] <= '2' ||
					digit == '9' && (date[6] <= '2' && (date[4] != '0' || date[5] != '2') || (date[6] <= '1' || date[6] == '2' && (date[2] * 10 + date[3]) % 4 == 0)))))
		{
			date[i] = digit;
			printf("%c", digit);
			if (i % 2 == 1 && i < 7 && i > 2)
				printf(".");
		}
		else if (digit == '\b' && i > 0)
		{
			i -= 2;
			if (i % 2 == 0 && i > 0 && i < 6)
				printf("\b \b");
			printf("\b \b");

		}
		else
			i--;
	}

	year = 0;
	for (int i = 0; i < 4; i++)
		year += (date[i] - 48) * pow(10, 3 - i);

	month = date[4] * 10 + date[5] - 528;
	day = date[6] * 10 + date[7] - 528;

	return;
}

//Инициализация всех полей
void Date::Init(int seconds, int minutes, int hours, int day, int month, int year) 
{
	sec = seconds;
	min = minutes;
	hour = hours;
	this->day = day;
	this->month = month;
	this->year = year;
	return;
}

//Ввод значений всех полей
void Date::Read() 
{
	ReadTime();
	printf("\n");
	ReadDate();
	Display();
	return;
}

//Вывод значений всех полей
void Date::Display() 
{
	printf("%02d:%02d:%02d, %02d.%02d.%04d", hour, min, sec, day, month, year);
	return;
}

//Текущая дата
void Date::Now() 
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	Init(timeinfo->tm_sec, timeinfo->tm_min, timeinfo->tm_hour, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	return;
}