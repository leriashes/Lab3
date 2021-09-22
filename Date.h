#pragma once
class Date	//Дата
{
private:
	int sec;	//Секунды
	int min;	//Минуты
	int hour;	//Часы
	int day;	//День
	int month;	//Месяц
	int year;	//Год

public:
	void Init(int seconds, int minutes, int hours, int day, int month, int year);	//Инициализация всех полей
	void Read();	//Ввод значений всех полей
	void Display();	//Вывод значений всех полей
	void Now();		//Текущая дата
};