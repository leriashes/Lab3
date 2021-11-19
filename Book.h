#pragma once
#include "Author.h"
#include "Reader.h"
#include "Publishing.h"

class Book
{
private:
	
	static int counter;		//������� ����
	static int time;		//�����, �� ������� ����� ����� �����

	string title;			//�������� �����
	Author author;			//�����
	int pages_number;		//���������� �������
	string genre;			//����
	Reader* reader = NULL;	//��������
	Publishing publishing;	//������������
	int publ_year;			//���
	int id;					//ID �����
	Date borrow_date;		//���� ������ �����

public:
	static int GetCounter();
	static int GetTime();
	static void SetTime(int days);
	static bool BorrowBook(Book& book, Reader& reader, Date date);
	static int BorrowBook(Book* book, int num, Reader& reader, Date date);

	Book();		//�����������
	Book(string title);		//����������� � ����� ����������
	Book(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//����������� � ����������
	Book(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//����������� � ����������
	Book(const Book& source);	//����������� �����������
	~Book();	//����������

	void Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//������������� ���� �����
	void Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//������������� ���� �����
	void AddReader(Reader* reader);		//�������� ��������
	bool InLib();	//�������� ��������� �� ����� � ����������
	bool CmpReader(Book second_book);		//��������� ��������� ����
	bool Belongs(Reader *reader);	//�������� �������������� ����� ��������

	friend class InOut;
};