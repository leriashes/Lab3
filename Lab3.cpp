﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include "Date.h"
#include "Author.h"
#include "Address.h"
#include "Reader.h"

int main() 
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Date data, data1;
	data.Init(0, 0, 0, 26, 9, 2019);
	data1.Now();
	(data.Compare(data1)).Display("all");
	data1.Add(data);

	Address house;
	printf("\n\n");
	house.Display();

	Reader pers("Мария", data, house, 1234567890);
	//pers.Read();
	pers.Display("all");
	printf("\n%d", pers.IsBirthday(data1));
	data.Init(0, 0, 0, 28, 0, 21);
	printf("\n%d", pers.IsBirthday(data));
	return 0;
}