#pragma once
#include "Date.h"
class Author	//�����
{
private:
	char full_name[50];	//���
	Date birth;			//���� ��������
	char country[30];	//������

public:
	Author();	//�����������
	Author(const char* full_name, Date birth_date, const char* country);	//����������� � ����������
	~Author();		//����������
};

