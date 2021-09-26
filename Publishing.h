#pragma once
class Publishing
{
private:
	char name[30];	//Название
	char city[30];	//Город

public:
	Publishing();	//Конструктор
	Publishing(const char* name, const char* city);		//Конструктор с параметром
	~Publishing();		//Деструктор

	void Init(const char* name, const char* city);	//Инициализация всех полей
	void Read();	//Ввод всех полей
};

