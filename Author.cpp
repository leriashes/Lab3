#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Author.h"

//�����������
Author::Author()
{
	strcpy(full_name, "������ ���� ��������");
	strcpy(country, "������");
}

//����������� � ����������
Author::Author(const char* full_name, Date birth_date, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//����������� � ����������
Author::Author(const char* full_name, int day, int month, int year, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth.Init(0, 0,  0, day, month, year);

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//����������
Author::~Author()
{
}

//������������� �������� ���� �����
void Author::Init(const char* full_name, Date birth_date, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//������������� �������� ���� �����
void Author::Init(const char* full_name, int day, int month, int year, const char* country)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth.Init(0, 0, 0, day, month, year);

	strncpy(this->country, country, 30);
	this->country[29] = '\0';
}

//���� �������� ���� �����
void Author::Read()
{
	printf("������� ��� ������: ");

	char letter;
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r' )
		{
			full_name[i] = '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			full_name[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\n���� ��������\n");
	birth.ReadDate();

	printf("\n������� ������ ������������� ������: ");
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			country[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			country[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

//�������� ������� �� ����� � ��������� ������
bool Author::BornIn(const char* country)
{
	bool result = false;

	if (strcmp(this->country, country) == 0)
		result = true;

	return result;
}