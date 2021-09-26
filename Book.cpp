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

//Ввод значений всех полей
void Book::Read()
{
	printf("Введите название книги: ");

	char letter;
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			title[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			title[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}


	printf("\n");
	author.Read();


	printf("\nВведите количество страниц в книге: ");
	char result[5];
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	pages_number = 0;
	for (int i = 0; result[i] != '\0'; i++)
		pages_number = pages_number * 10 + result[i] - 48;


	printf("\nВведите жанр: ");

	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			genre[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			genre[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\n");
	publishing.Read();


	printf("\nВведите год издания книги: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	publ_year = 0;
	for (int i = 0; result[i] != '\0'; i++)
		publ_year = publ_year * 10 + result[i] - 48;

	return;
}

//Вывод значений всех полей
void Book::Display()
{
	printf("Название: \"%s\"", title);
	printf("\nЖанр: %s", genre);
	printf("\nКоличество страниц: %d", pages_number);
	printf("\nГод публикации: %d", publ_year);
	printf("\nАвтор: ");
	author.Display("FullName");
	printf("\nИздательство: ");
	publishing.Display();
	if (reader != NULL) {
		printf("\nЧитатель: ");
		reader->Display("[DocNumber] FullName");
	}

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
