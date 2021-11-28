#pragma once
#include "Book.h"
class ForeignBook : public Book
{
private:
	string language;
public:
	ForeignBook();		//Конструктор
	ForeignBook(string language);		//Конструктор с одним параметром
	~ForeignBook();	//Деструктор
};

