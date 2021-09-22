#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>

//Инициализация всех полей
void Date::Init(int seconds, int minutes, int hours, int day, int month, int year) {
	sec = seconds;
	min = minutes;
	hour = hours;
	this->day = day;
	this->month = month;
	this->year = year;
	return;
}

//Ввод значений всех полей
void Date::Read() {
	scanf("%d %d %d %d %d %d", &hour, &min, &sec, &day, &month, &year);
	while (getchar() != '\n');
	return;
}

//Вывод значений всех полей
void Date::Display() {
	printf("%02d:%02d:%02d, %02d.%02d.%04d", hour, min, sec, day, month, year);
	return;
}