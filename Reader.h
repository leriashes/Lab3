#pragma once
#include "Date.h"
#include "Address.h"
class Reader
{
private:
	char full_name[50];	//���
	Date birth;			//���� ��������
	Address address;	//�����
	char doc_number[26];		//����� ���������, ��������������� ��������

public:
	Reader();	//�����������
	Reader(const char* full_name, Date birth_date, Address address, const char* doc_number);	//����������� � ����������
	Reader(const char* full_name, Date birth_date, Address address, int doc_number);	//����������� � ����������
	~Reader();	//����������
};

