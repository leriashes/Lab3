#pragma once
#include <iostream>
#include "Book.h"

class ForeignBook : public Book
{
private:
	string language;
public:
	ForeignBook();		//�����������
	ForeignBook(string language);		//����������� � ����� ����������
	ForeignBook(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year, string language);		//����������� � ����������
	ForeignBook(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year, string language);		//����������� � ����������
	ForeignBook(const ForeignBook& source);	//����������� �����������
	~ForeignBook();	//����������

	void Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year, string language);		//������������� ���� �����
	void Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year, string language);		//������������� ���� �����
	string Category();
	string vCategory();

	friend void operator<<(ostream& o, ForeignBook foreign_book);
	void operator=(Book source);
};

