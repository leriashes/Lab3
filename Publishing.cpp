#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Publishing.h"
using namespace std;

//�����������
Publishing::Publishing()
{
	name = "������������ �1";
	city = "�. ������";
}

//����������� � ����������
Publishing::Publishing(string name, string city)
{
	this->name = name;
	this->city = city;
}

//����������
Publishing::~Publishing()
{
}

void Publishing::Init(string name, string city)
{
	this->name = name;
	this->city = city;

	return;
}

//�������� ��������� �� ������������ � �������� ������
bool Publishing::IsHere(string city)
{
	bool result = false;

	if (this->city == city)
		result = true;

	return result;
}
