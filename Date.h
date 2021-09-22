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

	void ReadTime();	//Ввод только времени
	void ReadDate();	//Ввод только даты

public:
	Date();		//Конструктор
	Date(int day, int month, int year);		//Конструктор с параметром (только дата)
	Date(int seconds, int minutes, int hours, int day, int month, int year);	//Конструктор с параметром (дата и время)
	~Date();	//Деструктор

	void Init(int seconds, int minutes, int hours, int day, int month, int year);	//Инициализация всех полей
	void Read();	//Ввод значений всех полей
	void Display();	//Вывод значений всех полей
	void Now();		//Текущая дата
};