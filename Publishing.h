#pragma once
using namespace std;
class Publishing
{
private:
	string name;	//Название
	string city;	//Город

public:
	Publishing();	//Конструктор
	Publishing(string name, string city);		//Конструктор с параметром
	~Publishing();		//Деструктор

	void Init(string name, string city);	//Инициализация всех полей
	bool IsHere(string city);	//Проверка находится ли издательство в заданном городе

	friend class InOut;
};

