#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
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
	Display("DD.MM.YYYY");
	printf(" ");
	Display("hh:mm:ss");
	return;
}

//Вывод значений всех полей
void Date::Display(const char* format) 
{
	char form[][16] = {"hh:mm:ss", "hh:mm", "mm:ss", "DD.MM.YYYY", "DD/MM/YYYY", "MM.DD.YYYY", "DD-MM-YYYY", "YYYY-MM-DD", "CompareResult", "CompareResultRU"};
	int f = 1;
	for (int i = 0; i < 10 && f; i++)
	{
		if (strcmp(format, form[i]) == 0)
		{
			if (i == 0)
				printf("%02d:%02d:%02d", hour, min, sec);
			else if (i == 1)
				printf("%02d:%02d", hour, min);
			else if (i == 2)
				printf("%02d:%02d", min, sec);
			else if (i == 3)
				printf("%02d.%02d.%02d", day, month, year);
			else if (i == 4)
				printf("%02d/%02d/%02d", day, month, year);
			else if (i == 5)
				printf("%02d.%02d.%02d", month, day, year);
			else if (i == 6)
				printf("%02d-%02d-%02d", day, month, year);
			else if (i == 7)
				printf("%02d-%02d-%02d", year, month, day);
			else if (i == 8)
			{
				int k = 0;

				if (year > 0)
				{
					if (year > 1)
						printf("%d years ", year);
					else
						printf("%d year ", year);
					k++;
				}

				if (day > 0)
				{
					if (day > 1)
						printf("%d days ", day);
					else
						printf("%d day ", day);
					k++;
				}

				if (hour > 0)
				{
					if (hour > 1)
						printf("%d hours ", hour);
					else
						printf("%d hour ", hour);
					k++;
				}

				if (min > 0)
				{
					if (min > 1)
						printf("%d minutes ", min);
					else
						printf("%d minute ", min);
					k++;
				}

				if (sec > 0)
				{
					if (sec > 1)
						printf("%d seconds ", sec);
					else
						printf("%d second ", sec);
					k++;
				}

				if (k == 0)
					printf("The time has already come. ");
			}
			else
			{
				int k = 0;

				if (year > 0)
				{
					printf("%d ", year);
					if (year % 10 == 1 && year % 100 != 11)
						printf("год ");
					else if (year % 10 >= 2 && year % 10 <= 4 && (year % 100 < 12 || year % 100 > 14))
						printf("года ");
					else
						printf("лет ");
					k++;
				}

				if (day > 0)
				{
					printf("%d ", day);
					if (day % 10 == 1 && day % 100 != 11)
						printf("день ");
					else if (day % 10 >= 2 && day % 10 <= 4 && (day % 100 < 12 || day % 100 > 14))
						printf("дня ");
					else
						printf("дней ");
					k++;
				}

				if (hour > 0)
				{
					printf("%d ", hour);
					if (hour % 10 == 1 && hour % 100 != 11)
						printf("час ");
					else if (hour % 10 >= 2 && hour % 10 <= 4 && (hour % 100 < 12 || hour % 100 > 14))
						printf("часа ");
					else
						printf("часов "); 
					k++;
				}

				if (min > 0)
				{
					printf("%d ", min);
					if (min % 10 == 1 && min % 100 != 11)
						printf("минута ");
					else if (min % 10 >= 2 && min % 10 <= 4 && (min % 100 < 12 || min % 100 > 14))
						printf("минуты ");
					else
						printf("минут ");
					k++;
				}

				if (sec > 0)
				{
					printf("%d ", sec);
					if (sec % 10 == 1 && sec % 100 != 11)
						printf("секунда ");
					else if (sec % 10 >= 2 && sec % 10 <= 4 && (sec % 100 < 12 || sec % 100 > 14))
						printf("секунды ");
					else
						printf("секунд ");
					k++;
				}

				if (k == 0)
					printf("The time has already come. ");
			}
		}
	}

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
	Date date;

	date.year = end_date.year - year;

	if (month > end_date.month)
	{
		for (int i = 1; i < 13; i++)
		{
			if (i >= month || i < end_date.month)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					date.day += 31;
				else if (i == 2)
				{
					date.day += 28;
					if (i >= month && year % 4 == 0 || i < end_date.month && end_date.year % 4 == 0)
						date.day++;
				}
				else
					date.day += 30;
			}

		}

		if (date.year > 0)
			date.year--;
	}
	else if (month == end_date.month)
	{
		date.day = end_date.day - day;
		if (date.day < 0)
		{
			date.year--;
			for (int i = 1; i < 13; i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
					date.day += 31;
				else if (i == 2)
				{
					date.day += 28;
					if (i >= month && year % 4 == 0 || i < end_date.month && end_date.year % 4 == 0)
						date.day++;
				}
				else
					date.day += 30;
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
					date.day += 31;
				else if (i == 2)
				{
					date.day += 28;
					if (i >= month && year % 4 == 0 || i < end_date.month && end_date.year % 4 == 0)
						date.day++;
				}
				else
					date.day += 30;
			}

		}

		date.day += end_date.day - day - 1;
	}

	date.month = 0;

	if (date.day >= 0)
	{
		date.hour = 24 - hour + end_date.hour;
		if (date.day + date.year == 0)
			date.hour -= 24;
		else
		{
			if (date.hour >= 24)
				date.hour -= 24;
			else
				date.day--;
		}

		date.min = 60 - min + end_date.min;
		if (date.hour + date.day + date.year == 0)
			date.min -= 60;
		else
		{
			if (date.min >= 60)
				date.min -= 60;
			else
				date.hour--;
		}

		date.min = 60 - min + end_date.min;
		if (date.hour + date.day + date.year == 0)
			date.min -= 60;
		else
		{
			if (date.min >= 60)
				date.min -= 60;
			else
				date.hour--;
		}

		date.sec = 60 - sec + end_date.sec;
		if (date.min + date.hour + date.day + date.year == 0)
			date.sec -= 60;
		else
		{
			if (date.sec >= 60)
				date.sec -= 60;
			else
				date.min--;
		}
	}

	if (date.day < 0 || date.year < 0 || date.hour < 0 || date.min < 0 || date.sec < 0)
		date.year = date.day = date.hour = date.min = date.sec = 0;

	return date;
}