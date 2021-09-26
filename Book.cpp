#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Book.h"

//�����������
Book::Book()
{
	strcpy(title, "�������");
	pages_number = 50;
	strcpy(genre, "������");
	publ_year = 2021;
}

//����������� � ����������
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

//����������� � ����������
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

//����������
Book::~Book()
{
}

//������������� ���� �����
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

//������������� ���� �����
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
