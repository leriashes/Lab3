#pragma once
#include <string>
using namespace std;

class Address
{
private:
	string city;	//�������� ���������� ������
	string street;	//�������� �����
	int house;		//����� ����
	int flat;		//����� ��������

public:
	Address();		//�����������
	Address(string city, string street, int house_number, int flat_number);	//����������� � ����������
	~Address();		//����������

	void Init(string city, string street, int house_number, int flat_number);		//������������� ���� �����
	bool City(string city);	//�������� ���������� ������

	friend class InOut;
};

