#pragma once
#include "Author.h"
#include "Reader.h"
#include "Publishing.h"

class Book
{
private:
	
	static int counter;		//Счётчик книг
	static int time;		//Время, на которое можно брать книги

	string title;			//Название книги
	Author author;			//Автор
	int pages_number;		//Количество страниц
	string genre;			//Жанр
	Reader* reader = NULL;	//Читатель
	Publishing publishing;	//Издательство
	int publ_year;			//Год
	int id;					//ID книги
	Date borrow_date;		//Дата взятия книги

public:
	static int GetCounter();
	static int GetTime();
	static void SetTime(int days);
	static bool BorrowBook(Book& book, Reader& reader, Date date);
	static int BorrowBook(Book* book, int num, Reader& reader, Date date);

	Book();		//Конструктор
	Book(string title);		//Конструктор с одним параметром
	Book(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//Конструктор с параметром
	Book(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//Конструктор с параметром
	Book(const Book& source);	//Конструктор копирования
	~Book();	//Деструктор

	Book& operator=(const Book& source);

	void Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//Инициализация всех полей
	void Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//Инициализация всех полей
	void AddReader(Reader* reader);		//Привязка читателя
	bool InLib();	//Проверка находится ли книга в библиотеке
	bool CmpReader(Book second_book);		//Сравнение читателей книг
	bool Belongs(Reader *reader);	//Проверка принадлежности книги читателю

	friend class InOut;
};