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

//����������
Author::~Author()
{
}