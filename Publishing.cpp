#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Publishing.h"

//�����������
Publishing::Publishing()
{
	strcpy(name, "������������ �1");
	strcpy(city, "�. ������");
}

//����������� � ����������
Publishing::Publishing(const char* name, const char* city)
{
	strncpy(this->name, name, 30);
	this->name[29] = '\0';

	strncpy(this->city, city, 30);
	this->city[29] = '\0';
}

//����������
Publishing::~Publishing()
{
}

void Publishing::Init(const char* name, const char* city)
{
	strncpy(this->name, name, 30);
	this->name[29] = '\0';

	strncpy(this->city, city, 30);
	this->city[29] = '\0';
}
