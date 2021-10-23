#pragma once
#include "Book.h"
class InOut
{
public:	
	static void Display(Address address);		//Печать объекта класса Address
	static void Display(Author author, const char* format);		//Печать объекта класса Author
	static void Display(Book book);	//Печать объекта класса Book
	static void Display(Date date, const char* format);		//Печать объекта класса Date
	static void Display(Publishing publishing);		//Печать объекта класса Publishing
	static void Display(Reader reader, const char* format);		//Печать объекта класса Reader
};

