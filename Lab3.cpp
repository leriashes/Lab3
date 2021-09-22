#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "Date.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Date date;

	date.Init(31, 12, 14, 1, 1, 13);
	date.Display();
	printf("\n\n");

	date.Read();
	printf("\n\n");
	date.Display();
	printf("\n\n");

	date.Now();
	date.Display();

	return 0;
}