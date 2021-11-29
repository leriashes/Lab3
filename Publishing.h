#pragma once
#include <string>
using namespace std;

class Publishing
{
private:
	string name;	//��������
	string city;	//�����

public:
	Publishing();	//�����������
	Publishing(string name, string city);		//����������� � ����������
	~Publishing();		//����������

	void Init(string name, string city);	//������������� ���� �����
	bool IsHere(string city);	//�������� ��������� �� ������������ � �������� ������

	friend void operator<<(ostream& o, Publishing publishing);
	friend class InOut;
};

