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

//���� �������� ���� �����
void Book::Read()
{
	printf("������� �������� �����: ");

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


	printf("\n������� ���������� ������� � �����: ");
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


	printf("������� ����: ");

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


	publishing.Read();


	printf("\n������� ��� ������� �����: ");
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
