#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Date.h"

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

	printf("Введите время (в формате hh:mm:ss): ");
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

//Текущая дата
void Date::Now() 
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	Init(timeinfo->tm_sec, timeinfo->tm_min, timeinfo->tm_hour, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	return;
}

//Сравнение дат
Date Date::Compare(Date end_date)
{
	Date result;

	result.year = end_date.year - year;

	if (month > end_date.month)
	{
		for (int i = 1; i < 13; i++)
		{
			if (i >= month || i < end_date.month)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					result.day += 31;
				else if (i == 2)
				{
					result.day += 28;
					if (i >= month && year % 4 == 0 || i < end_date.month && end_date.year % 4 == 0)
						result.day++;
				}
				else
					result.day += 30;
			}

		}

		if (result.year > 0)
			result.year--;
	}
	else if (month == end_date.month)
	{
		result.day = end_date.day - day;
		if (result.day < 0)
		{
			result.year--;
			for (int i = 1; i < 13; i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					result.day += 31;
				else if (i == 2)
				{
					result.day += 28;
					if (i >= month && year % 4 == 0 || i < end_date.month && end_date.year % 4 == 0)
						result.day++;
				}
				else
					result.day += 30;
			}
		}

	}
	else
	{
		for (int i = 1; i < 13; i++)
		{
			if (i >= month && i < end_date.month)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					result.day += 31;
				else if (i == 2)
				{
					result.day += 28;
					if (i >= month && year % 4 == 0 || i < end_date.month && end_date.year % 4 == 0)
						result.day++;
				}
				else
					result.day += 30;
			}

		}

		result.day += end_date.day - day - 1;
	}

	result.month = 0;

	if (result.day >= 0)
	{
		result.hour = 24 - hour + end_date.hour;
		if (result.day + result.year == 0)
			result.hour -= 24;
		else
		{
			if (result.hour >= 24)
				result.hour -= 24;
			else
				result.day--;
		}

		result.min = 60 - min + end_date.min;
		if (result.hour + result.day + result.year == 0)
			result.min -= 60;
		else
		{
			if (result.min >= 60)
				result.min -= 60;
			else
				result.hour--;
		}

		result.min = 60 - min + end_date.min;
		if (result.hour + result.day + result.year == 0)
			result.min -= 60;
		else
		{
			if (result.min >= 60)
				result.min -= 60;
			else
				result.hour--;
		}

		result.sec = 60 - sec + end_date.sec;
		if (result.min + result.hour + result.day + result.year == 0)
			result.sec -= 60;
		else
		{
			if (result.sec >= 60)
				result.sec -= 60;
			else
				result.min--;
		}
	}

	if (result.day < 0 || result.year < 0 || result.hour < 0 || result.min < 0 || result.sec < 0)
		result.year = result.day = result.hour = result.min = result.sec = 0;

	return result;
}

//Прибавление времени к дате
Date Date::Add(Date add_date)
{
	Date result(sec + add_date.sec, min + add_date.min, hour + add_date.hour, day + add_date.day, month + add_date.month, year + add_date.year);

	while (result.sec >= 60)
	{
		result.sec -= 60;
		result.min += 1;
	}

	while (result.min >= 60)
	{
		result.min -= 60;
		result.hour += 1;
	}

	while (result.hour >= 24)
	{
		result.hour -= 24;
		result.day += 1;
	}

	int f = 1;

	while (f)
	{
		if (result.day > 31 && (result.month == 1 || result.month == 3 || result.month == 5 || result.month == 7 || result.month == 8 || result.month == 10 || result.month == 12))
			result.day -= 31;
		else if (result.month == 2 && result.day > 28)
		{
			if (result.day > 29 && result.year % 4 == 0)
				result.day -= 29;
			else
				result.day -= 28;
		}
		else if (result.day > 30)
			result.day -= 30;
		else
			f = 0;

		if (f)
		{
			result.month++;

			if (result.month >= 13)
			{
				result.month -= 12;
				result.year++;
			}
		}
	}

	return result;
}

//Проверка является ли дата годовщиной другой
bool Date::IsAnniversary(Date second_date)
{
	return (day == second_date.day && month == second_date.month && year <= second_date.year);
}

Date Date::operator+(Date otherdate)
{
	return this->Add(otherdate);
}

Date& Date::operator++()
{
	Date one(1, 0, 0);
	*this = this->Add(one);
	return *this;
}

Date Date::operator++(int)
{
	Date copy = *this;
	++(*this);
	return copy;
}