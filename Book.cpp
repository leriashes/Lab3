#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Book.h"

//Конструктор
Book::Book()
{
	title = "Котофей";
	pages_number = 50;
	genre = "Сказки";
	publ_year = 2021;
}

//Конструктор с параметром
Book::Book(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year)
{
	this->title = title;
	this->author = author;
	this->pages_number = abs(pages_number);
	this->genre = genre;
	this->publishing = publishing;
	this->publ_year = abs(publication_year);
}

//Конструктор с параметром
Book::Book(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year)
{
	this->title = title;
	this->author = author;
	this->pages_number = abs(pages_number);
	this->genre = genre;
	this->reader = reader;
	this->publishing = publishing;
	this->publ_year = abs(publication_year);
}

//Деструктор
Book::~Book()
{
}

//Инициализация всех полей
void Book::Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year)
{
	this->title = title;
	this->author = author;
	this->pages_number = abs(pages_number);
	this->genre = genre;
	this->publishing = publishing;
	this->publ_year = abs(publication_year);

	return;
}

//Инициализация всех полей
void Book::Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year)
{
	this->title = title;
	this->author = author;
	this->pages_number = abs(pages_number);
	this->genre = genre;
	this->reader = reader;
	this->publishing = publishing;
	this->publ_year = abs(publication_year);

	return;
}

//Привязка читателя
void Book::AddReader(Reader* reader)
{
	this->reader = reader;
	return;
}

//Проверка находится ли книга в библиотеке
bool Book::InLib()
{
	bool result = false;

	if (reader == NULL)
		result = true;

	return result;
}

//Сравнение читателей книг
bool Book::CmpReader(Book second_book)
{
	return (reader == second_book.reader);
}

//Проверка принадлежности книги читателю
bool Book::Belongs(Reader *reader)
{
	return this->reader == reader;
}
