#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "Date.h"
#include "Author.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Date data, data1;
	data.Init(0, 0, 0, -28, 0, 0);
	data1.Now();
	(data.Compare(data1)).Display("CompareResultRU");
	data1.Add(data);

	Author baby("Пушкин А.С.", data1, "Россия");
	printf("\n");
	baby.Read();
	return 0;
}