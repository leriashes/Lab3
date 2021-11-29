#pragma once
#include <iostream>
#include "Book.h"

class ForeignBook : public Book
{
private:
	string language;
public:
	ForeignBook();		//Конструктор
	ForeignBook(string language);		//Конструктор с одним параметром
	ForeignBook(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year, string language);		//Конструктор с параметром
	ForeignBook(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year, string language);		//Конструктор с параметром
	ForeignBook(const ForeignBook& source);	//Конструктор копирования
	~ForeignBook();	//Деструктор

	void Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year, string language);		//Инициализация всех полей
	void Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year, string language);		//Инициализация всех полей
	string Category();
	string vCategory();

	friend void operator<<(ostream& o, ForeignBook foreign_book);
	void operator=(Book source);
};

