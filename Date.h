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

	void ReadTime();	//���� ������ �������
	void ReadDate();	//���� ������ ����

public:
	Date();		//�����������
	Date(int day, int month, int year);		//����������� � ���������� (������ ����)
	Date(int seconds, int minutes, int hours, int day, int month, int year);	//����������� � ���������� (���� � �����)
	~Date();	//����������

	void Init(int seconds, int minutes, int hours, int day, int month, int year);	//������������� ���� �����
	void Read();	//���� �������� ���� �����
	void Display();	//����� �������� ���� �����
	void Now();		//������� ����
	Date Compare(Date end_date);		//��������� ���
};