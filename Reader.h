#pragma once
#include "Person.h"
#include "Address.h"

class Reader : public Person
{
private:
	Address address;	//�����
	string doc_number;		//����� ���������, ��������������� ��������

public:
	Reader();	//�����������
	Reader(string full_name, Date birth_date, Address address, string doc_number);	//����������� � ����������
	Reader(string full_name, Date birth_date, Address address, int doc_number);	//����������� � ����������
	~Reader();	//����������

	void Init(string full_name, Date birth_date);
	void Init(string full_name, Date birth_date, Address address, string doc_number);		//������������� ���� �����
	void Init(string full_name, Date birth_date, Address address, int doc_number);		//������������� ���� �����
	bool IsBirthday(Date day);		//�������� �������� �� ���� ��� �������� ��������
	string About();

	friend void operator<<(ostream& o, Reader reader);
	friend class InOut;
};

