#pragma once
#include "Author.h"
#include "Reader.h"
#include "Publishing.h"
#include <string>
using namespace std;

class Book
{
protected:
	
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

	Book& operator=(const Book& source);

	string GetTitle();
	Author GetAuthor();
	int GetPagesNumber();
	string GetGenre();
	Reader* GetReader();
	Publishing GetPublishing();
	int GetPublicationYear();
	int GetID();
	Date GetBorrowDate();

	void Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year);		//������������� ���� �����
	void Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year);		//������������� ���� �����
	void AddReader(Reader* reader);		//�������� ��������
	bool InLib();	//�������� ��������� �� ����� � ����������
	bool CmpReader(Book second_book);		//��������� ��������� ����
	bool Belongs(Reader *reader);	//�������� �������������� ����� ��������
	string Category();
	virtual string vCategory();
	bool CmpCategory(string category);
	bool vCmpCategory(string category);

	friend void operator<<(ostream& o, Book book);
	friend class InOut;
};