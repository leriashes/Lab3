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

	return;
}

//���� ���� �����
void Publishing::Read()
{
	printf("������� �������� ������������: ");

	char letter;
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			name[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			name[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\n������� ��������� �����, � ������� ��������� ������������ (��������: �. �������): ");

	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			city[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			city[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

//����� �������� ���� �����
void Publishing::Display()
{
	printf("%s (%s)", name, city);
	return;
}

//�������� ��������� �� ������������ � �������� ������
bool Publishing::IsHere(const char* city)
{
	bool result = false;

	if (strcmp(this->city, city) == 0)
		result = true;

	return result;
}
