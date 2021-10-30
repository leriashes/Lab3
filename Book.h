#pragma once
#include "Author.h"
#include "Reader.h"
#include "Publishing.h"

class Book
{
private:
	string title;			//Название книги
	Author author;		//Автор
	int pages_number;		//Количество страниц
	string genre;			//Жанр
	Reader* reader = NULL;	//Читатель
	Publishing publishing;	//Издательство
	int publ_year;			//Год

public:
	Book();		//Конструктор
	Book(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//Конструктор с параметром
	Book(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//Конструктор с параметром
	~Book();	//Деструктор

	void Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//Инициализация всех полей
	void Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//Инициализация всех полей
	void AddReader(Reader* reader);		//Привязка читателя
	bool InLib();	//Проверка находится ли книга в библиотеке
	bool CmpReader(Book second_book);		//Сравнение читателей книг
	bool Belongs(Reader *reader);	//Проверка принадлежности книги читателю

	friend class InOut;
};

