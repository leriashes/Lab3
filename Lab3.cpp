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

	Author baby;
	Date data, data1;
	data.Init(59, 0, 1, 28, 9, 2020);
	data1.Now();
	(data.Compare(data1)).Display("CompareResultRU");
	return 0;
}