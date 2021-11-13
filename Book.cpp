#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Book.h"

int Book::counter = 0;

int Book::GetCounter()
{
	return counter;
}

//�����������
Book::Book()
{
	title = "�������";
	pages_number = 50;
	genre = "������";
	publ_year = 2021;
	counter++;
	id = counter;
}

//����������� � ����������
Book::Book(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year)
{
	this->title = title;
	this->author = author;
	this->pages_number = abs(pages_number);
	this->genre = genre;
	this->publishing = publishing;
	this->publ_year = abs(publication_year);
	counter++;
	id = counter;
}

//����������� � ����������
Book::Book(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year)
{
	this->title = title;
	this->author = author;
	this->pages_number = abs(pages_number);
	this->genre = genre;
	this->reader = reader;
	this->publishing = publishing;
	this->publ_year = abs(publication_year);
	counter++;
	id = counter;
}

//����������
Book::~Book()
{
}

//������������� ���� �����
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

//������������� ���� �����
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

//�������� ��������
void Book::AddReader(Reader* reader)
{
	this->reader = reader;
	return;
}

//�������� ��������� �� ����� � ����������
bool Book::InLib()
{
	bool result = false;

	if (reader == NULL)
		result = true;

	return result;
}

//��������� ��������� ����
bool Book::CmpReader(Book second_book)
{
	return (reader == second_book.reader);
}

//�������� �������������� ����� ��������
bool Book::Belongs(Reader *reader)
{
	return this->reader == reader;
}
