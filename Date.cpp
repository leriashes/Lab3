#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
	scanf("%d %d %d %d %d %d", &hour, &min, &sec, &day, &month, &year);
	while (getchar() != '\n');
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