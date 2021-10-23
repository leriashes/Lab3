#pragma once
class Address
{
private:
	char city[30];	//�������� ���������� ������
	char street[40];	//�������� �����
	int house;		//����� ����
	int flat;		//����� ��������

public:
	Address();		//�����������
	Address(const char* city, const char* street, int house_number, int flat_number);	//����������� � ����������
	~Address();		//����������

	void Init(const char* city, const char* street, int house_number, int flat_number);		//������������� ���� �����
	void Read();	//���� �������� ���� �����
	bool City(const char* city);	//�������� ���������� ������

	friend class InOut;
};

