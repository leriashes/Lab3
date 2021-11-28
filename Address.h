#pragma once
#include <string>
using namespace std;

class Address
{
private:
	string city;	//Название населённого пункта
	string street;	//Название улицы
	int house;		//Номер дома
	int flat;		//Номер квартиры

public:
	Address();		//Конструктор
	Address(string city, string street, int house_number, int flat_number);	//Конструктор с параметром
	~Address();		//Деструктор

	void Init(string city, string street, int house_number, int flat_number);		//Инициализация всех полей
	bool City(string city);	//Проверка совпадения города

	friend void operator<<(ostream& o, Address address);
	friend class InOut;
};

