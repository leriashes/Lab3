#include "ForeignBook.h"

//Конструктор
ForeignBook::ForeignBook()
{
	language = "Немецкий";
}

//Конструктор с параметром
ForeignBook::ForeignBook(string language)
{
	this->language = language;
}

ForeignBook::~ForeignBook()
{
}
