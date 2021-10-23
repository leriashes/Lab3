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
	Date();		//Конструктор
	Date(int day, int month, int year);		//Конструктор с параметром (только дата)
	Date(int seconds, int minutes, int hours, int day, int month, int year);	//Конструктор с параметром (дата и время)
	~Date();	//Деструктор

	void ReadTime();	//Ввод только времени
	void ReadDate();	//Ввод только даты

	void Init(int seconds, int minutes, int hours, int day, int month, int year);	//Инициализация всех полей
	void Now();		//Текущая дата
	Date Compare(Date end_date);		//Сравнение дат
	Date Add(Date add_date);		//Прибавление времени к дате
	bool IsAnniversary(Date second_date);	//Проверка является ли дата годовщиной другой

	friend class InOut;
};