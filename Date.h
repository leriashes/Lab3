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
	void Init(int seconds, int minutes, int hours, int day, int month, int year);	//������������� ���� �����
	void Read();	//���� �������� ���� �����
	void Display();	//����� �������� ���� �����
	void Now();		//������� ����
};