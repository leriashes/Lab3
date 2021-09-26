#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Book.h"

//Конструктор
Book::Book()
{
	strcpy(title, "Котофей");
	pages_number = 50;
	strcpy(genre, "Сказки");
	publ_year = 2021;
}

//Конструктор с параметром
Book::Book(const char* title, Author author, int pages_number, const char* genre, Publishing publishing, int publication_year)
{
	strncpy(this->title, title, 30);
	this->title[29] = '\0';

	this->author = author;
	this->pages_number = abs(pages_number);

	strncpy(this->genre, genre, 30);
	this->genre[29] = '\0';

	this->publishing = publishing;
	this->publ_year = abs(publication_year);
}

//Конструктор с параметром
Book::Book(const char* title, Author author, int pages_number, const char* genre, Reader* reader, Publishing publishing, int publication_year)
{
	strncpy(this->title, title, 30);
	this->title[29] = '\0';

	this->author = author;
	this->pages_number = abs(pages_number);

	strncpy(this->genre, genre, 30);
	this->genre[29] = '\0';

	this->reader = reader;

	this->publishing = publishing;
	this->publ_year = abs(publication_year);
}

//Деструктор
Book::~Book()
{
}

//Инициализация всех полей
void Book::Init(const char* title, Author author, int pages_number, const char* genre, Publishing publishing, int publication_year)
{
	strncpy(this->title, title, 30);
	this->title[29] = '\0';

	this->author = author;
	this->pages_number = abs(pages_number);

	strncpy(this->genre, genre, 30);
	this->genre[29] = '\0';

	this->publishing = publishing;
	this->publ_year = abs(publication_year);

	return;
}

//Инициализация всех полей
void Book::Init(const char* title, Author author, int pages_number, const char* genre, Reader* reader, Publishing publishing, int publication_year)
{
	strncpy(this->title, title, 30);
	this->title[29] = '\0';

	this->author = author;
	this->pages_number = abs(pages_number);

	strncpy(this->genre, genre, 30);
	this->genre[29] = '\0';

	this->reader = reader;

	this->publishing = publishing;
	this->publ_year = abs(publication_year);

	return;
}
