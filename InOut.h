#pragma once
#include "Book.h"
class InOut
{
public:	
	static void Read(Address* address);	//���� �������� ���� ����� ������� ������ Address
	static void Read(Author* author);	//���� �������� ���� ����� ������� ������ Author
	static void Read(Book* book);	//���� �������� ���� ����� ������� ������ Book
	static void Read(Date* date);	//���� �������� ���� ����� ������� ������ Date
	static void Read(Publishing* publishing);	//���� �������� ���� ����� ������� ������ Publishing
	static void Read(Reader* reader);	//���� �������� ���� ����� ������� ������ Reader

	static void Read(Address& address);	//���� �������� ���� ����� ������� ������ Address
	static void Read(Author& author);	//���� �������� ���� ����� ������� ������ Author
	static void Read(Book& book);	//���� �������� ���� ����� ������� ������ Book
	static void Read(Date& date);	//���� �������� ���� ����� ������� ������ Date
	static void Read(Publishing& publishing);	//���� �������� ���� ����� ������� ������ Publishing
	static void Read(Reader& reader);	//���� �������� ���� ����� ������� ������ Reader

	static void Display(Address address);		//������ ������� ������ Address
	static void Display(Author author, const char* format);		//������ ������� ������ Author
	static void Display(Book book);	//������ ������� ������ Book
	static void Display(Date date, const char* format);		//������ ������� ������ Date
	static void Display(Publishing publishing);		//������ ������� ������ Publishing
	static void Display(Reader reader, const char* format);		//������ ������� ������ Reader
};

