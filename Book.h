#pragma once
#include "Author.h"
#include "Reader.h"
#include "Publishing.h"

class Book
{
private:
	char title[30];			//Название книги
	Author author;		//Автор
	int pages_number;		//Количество страниц
	char genre[30];			//Жанр
	Reader* reader = NULL;	//Читатель
	Publishing publishing;	//Издательство
	int publ_year;			//Год

public:
	Book();		//Конструктор
	Book(const char* title, Author author, int pages_number, const char* genre, Publishing publishing, int publication_year);		//Конструктор с параметром
	Book(const char* title, Author author, int pages_number, const char* genre, Reader* reader, Publishing publishing, int publication_year);		//Конструктор с параметром
	~Book();	//Деструктор

	void Init(const char* title, Author author, int pages_number, const char* genre, Publishing publishing, int publication_year);		//Инициализация всех полей
	void Init(const char* title, Author author, int pages_number, const char* genre, Reader* reader, Publishing publishing, int publication_year);		//Инициализация всех полей
	void Read();	//Ввод значений всех полей
};

