#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Book.h"

int Book::counter = 0;
int Book::time = 30;

int Book::GetCounter()
{
	return counter;
}

int Book::GetTime()
{
	return time;
} 

void Book::SetTime(int days)
{
	if (days >= 1)
	{
		time = days;
	}

	return;
}

bool Book::BorrowBook(Book& book, Reader& reader, Date date)
{
	bool result = false;

	if (book.InLib())
	{
		book.AddReader(&reader);
		book.borrow_date = date;
		result = true;
	}

	return result;
}

int Book::BorrowBook(Book* book, int num, Reader& reader, Date date)
{
	int result = 0;

	for (int i = 0; i < num; i++)
	{
		if (BorrowBook(*(book + i), reader, date))
		{
			result += 1;
		}
	}
	return result;
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

//����������� � 1 ����������
Book::Book(string title)
{
	this->title = title;
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

//����������� �����������
Book::Book(const Book& source)
{
	title = source.title;
	author = source.author;
	pages_number = source.pages_number;
	genre = source.genre;

	if (source.reader != NULL)
	{
		reader = new Reader;
		*reader = *source.reader;
		borrow_date = source.borrow_date;
	}
	
	publishing = source.publishing;
	publ_year = source.publ_year;
	id = source.id;
}

//����������
Book::~Book()
{
}

Book& Book::operator=(const Book& source)
{
	if (this != &source)
	{
		/*if (reader != NULL)
			delete reader;*/

		//reader = NULL;
		title = source.title;
		author = source.author;
		pages_number = source.pages_number;
		genre = source.genre;

		if (source.reader != NULL)
		{
			//reader = new Reader;
			//*reader = *source.reader;
			reader = source.reader;
			borrow_date = source.borrow_date;
		}

		publishing = source.publishing;
		publ_year = source.publ_year;
		id = source.id;
	}

	return *this;
}

string Book::GetTitle()
{
	return title;
}

Author Book::GetAuthor()
{
	return author;
}

int Book::GetPagesNumber()
{
	return pages_number;
}

string Book::GetGenre()
{
	return genre;
}

Reader* Book::GetReader()
{
	return reader;
}

Publishing Book::GetPublishing()
{
	return publishing;
}

int Book::GetPublicationYear()
{
	return publ_year;
}

int Book::GetID()
{
	return id;
}

Date Book::GetBorrowDate()
{
	return borrow_date;
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
