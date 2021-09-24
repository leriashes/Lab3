#pragma once
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
	Date();		//�����������
	Date(int day, int month, int year);		//����������� � ���������� (������ ����)
	Date(int seconds, int minutes, int hours, int day, int month, int year);	//����������� � ���������� (���� � �����)
	~Date();	//����������

	void ReadTime();	//���� ������ �������
	void ReadDate();	//���� ������ ����

	void Init(int seconds, int minutes, int hours, int day, int month, int year);	//������������� ���� �����
	void Read();	//���� �������� ���� �����
	void Display(const char* format);	//����� �������� ���� �����
	void Now();		//������� ����
	Date Compare(Date end_date);		//��������� ���
	Date Add(Date add_date);		//����������� ������� � ����
};