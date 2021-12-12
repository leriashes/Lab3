#pragma once
#include <string>
using namespace std;

class Date	//����
{
private:
	int sec;	//�������
	int min;	//������
	int hour;	//����
	int day;	//����
	int month;	//�����
	int year;	//���

public:
	static Date Today();

	Date();		//�����������
	Date(int day, int month, int year);		//����������� � ���������� (������ ����)
	Date(int seconds, int minutes, int hours, int day, int month, int year);	//����������� � ���������� (���� � �����)
	~Date();	//����������

	Date operator+(Date otherdate);
	Date& operator++();
	Date operator++(int);

	void ReadTime();	//���� ������ �������
	void ReadDate();	//���� ������ ����

	void Init(int seconds, int minutes, int hours, int day, int month, int year);	//������������� ���� �����
	Date& Now();		//������� ����
	Date Compare(Date end_date);		//��������� ���
	Date Add(Date add_date);		//����������� ������� � ����
	bool IsAnniversary(Date second_date);	//�������� �������� �� ���� ���������� ������
	string ToString();

	friend void operator<<(ostream& o, Date date);
	friend class InOut;
};