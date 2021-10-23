#pragma once
#include "Author.h"
#include "Reader.h"
#include "Publishing.h"

class Book
{
private:
	char title[30];			//�������� �����
	Author author;		//�����
	int pages_number;		//���������� �������
	char genre[30];			//����
	Reader* reader = NULL;	//��������
	Publishing publishing;	//������������
	int publ_year;			//���

public:
	Book();		//�����������
	Book(const char* title, Author author, int pages_number, const char* genre, Publishing publishing, int publication_year);		//����������� � ����������
	Book(const char* title, Author author, int pages_number, const char* genre, Reader* reader, Publishing publishing, int publication_year);		//����������� � ����������
	~Book();	//����������

	void Init(const char* title, Author author, int pages_number, const char* genre, Publishing publishing, int publication_year);		//������������� ���� �����
	void Init(const char* title, Author author, int pages_number, const char* genre, Reader* reader, Publishing publishing, int publication_year);		//������������� ���� �����
	void Read();	//���� �������� ���� �����
	//void Display();		//����� �������� ���� �����
	void AddReader(Reader* reader);		//�������� ��������
	bool InLib();	//�������� ��������� �� ����� � ����������
	bool CmpReader(Book second_book);		//��������� ��������� ����
	bool Belongs(Reader *reader);	//�������� �������������� ����� ��������

	friend class InOut;
};

