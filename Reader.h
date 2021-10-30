#pragma once
#include "Date.h"
#include "Address.h"
class Reader
{
private:
	string full_name;	//���
	Date birth;			//���� ��������
	Address address;	//�����
	string doc_number;		//����� ���������, ��������������� ��������

public:
	Reader();	//�����������
	Reader(string full_name, Date birth_date, Address address, string doc_number);	//����������� � ����������
	Reader(string full_name, Date birth_date, Address address, int doc_number);	//����������� � ����������
	~Reader();	//����������

	void Init(string full_name, Date birth_date, Address address, string doc_number);		//������������� ���� �����
	void Init(string full_name, Date birth_date, Address address, int doc_number);		//������������� ���� �����
	bool IsBirthday(Date day);		//�������� �������� �� ���� ��� �������� ��������

	friend class InOut;
};

