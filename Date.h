#pragma once
class Date	//Дата
{
	int sec;	//Секунды
	int min;	//Минуты
	int hour;	//Часы
	int day;	//День
	int month;	//Месяц
	int year;	//Год

public:
	void InitDate();
	void ReadDate();
	void DisplayDate();
};