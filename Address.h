#pragma once
class Address
{
private:
	char city[30];	//Название населённого пункта
	char street[40];	//Название улицы
	int house;		//Номер дома
	int flat;		//Номер квартиры

public:
	Address();		//Конструктор
	Address(const char* city, const char* street, int house_number, int flat_number);	//Конструктор с параметром
	~Address();		//Деструктор

	void Init(const char* city, const char* street, int house_number, int flat_number);		//Инициализация всех полей
};

