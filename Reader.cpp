#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Reader.h"

Reader::Reader()
{
	strcpy(full_name, "Иванов Иван Иванович");
	strcpy(doc_number, "01 10 123456");
}

Reader::Reader(const char* full_name, Date birth_date, Address address, const char* doc_number)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;
	this->address = address;

	strncpy(this->doc_number, doc_number, 26);
	this->full_name[25] = '\0';
}

Reader::Reader(const char* full_name, Date birth_date, Address address, int doc_number)
{
	strncpy(this->full_name, full_name, 50);
	this->full_name[49] = '\0';

	birth = birth_date;
	this->address = address;

	for (int i = 0; doc_number > 0 && i < 25; i++)
	{
		for (int j = i; j > 0; j--)
			this->doc_number[j] = this->doc_number[j - 1];

		this->doc_number[0] = doc_number % 10 + 48;
		doc_number /= 10;
		if (doc_number == 0)
			this->doc_number[i + 1] = '\0';
	}

	if (doc_number <= 0)
		strcpy(this->doc_number, "01 10 123456");
}

Reader::~Reader()
{
}
