#pragma once
#include "Book.h"
class ForeignBook : public Book
{
private:
	string language;
public:
	ForeignBook();		//�����������
	ForeignBook(string language);		//����������� � ����� ����������
	~ForeignBook();	//����������
};

