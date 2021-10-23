#pragma once
#include "Book.h"
class InOut
{
public:	
	static void Read(Address* address);	//¬вод значений всех полей объекта класса Address
	static void Read(Author* author);	//¬вод значений всех полей объекта класса Author
	static void Read(Book* book);	//¬вод значений всех полей объекта класса Book
	static void Read(Date* date);	//¬вод значений всех полей объекта класса Date
	static void Read(Publishing* publishing);	//¬вод значений всех полей объекта класса Publishing
	static void Read(Reader* reader);	//¬вод значений всех полей объекта класса Reader

	static void Display(Address address);		//ѕечать объекта класса Address
	static void Display(Author author, const char* format);		//ѕечать объекта класса Author
	static void Display(Book book);	//ѕечать объекта класса Book
	static void Display(Date date, const char* format);		//ѕечать объекта класса Date
	static void Display(Publishing publishing);		//ѕечать объекта класса Publishing
	static void Display(Reader reader, const char* format);		//ѕечать объекта класса Reader
};

