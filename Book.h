#pragma once
#include "Author.h"
#include "Reader.h"
#include "Publishing.h"

class Book
{
private:
	string title;			//�������� �����
	Author author;		//�����
	int pages_number;		//���������� �������
	string genre;			//����
	Reader* reader = NULL;	//��������
	Publishing publishing;	//������������
	int publ_year;			//���

public:
	Book();		//�����������
	Book(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//����������� � ����������
	Book(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//����������� � ����������
	~Book();	//����������

	void Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//������������� ���� �����
	void Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//������������� ���� �����
	void AddReader(Reader* reader);		//�������� ��������
	bool InLib();	//�������� ��������� �� ����� � ����������
	bool CmpReader(Book second_book);		//��������� ��������� ����
	bool Belongs(Reader *reader);	//�������� �������������� ����� ��������

	friend class InOut;
};

