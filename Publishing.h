#pragma once
class Publishing
{
private:
	char name[30];	//��������
	char city[30];	//�����

public:
	Publishing();	//�����������
	Publishing(const char* name, const char* city);		//����������� � ����������
	~Publishing();		//����������

	void Init(const char* name, const char* city);	//������������� ���� �����
	bool IsHere(const char* city);	//�������� ��������� �� ������������ � �������� ������

	friend class InOut;
};

