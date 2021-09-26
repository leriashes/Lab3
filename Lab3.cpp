#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include "Book.h"

int main() 
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Date data, data1;
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
	printf("\n%d", pers.IsBirthday(data));*/


	//Статические переменные
	Address address_st;
	Publishing publ_st;
	Reader reader_st;
	Author author_st;
	Book book_st;

	//Динамические переменные
	Address* address_d;
	Publishing* publ_d;
	Reader* reader_d;
	Author* author_d;
	Book* book_d;


	//Работа с объектами класса Date
	printf("Работа со объектами класса Date\n");

	//Статические переменные
	Date date_st,	//Создание через конструктор без параметров
		//Создание через конструкторы с параметрами
		date_st1(12, 02, 2004), 
		date_st2(26, 35, 12, 13, 05, 1997);

	//Динамические переменные
	Date* date_d, *date_d1, *date_d2;
	date_d = new Date();	//Создание через конструктор без параметров
	//Создание через конструкторы с параметрами
	date_d1 = new Date(31, 8, 1998);
	date_d2 = new Date(45, 41, 0, 7, 3, 1789);

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\ndate_st = ");
	date_st.Display("all");
	printf("\ndate_st1 = ");
	date_st1.Display("all");
	printf("\ndate_st2 = ");
	date_st2.Display("all");
	printf("\n");

	printf("\nПечать данных динамических объектов\n*date_d = ");
	date_d->Display("all");
	printf("\n*date_d1 = ");
	date_d1->Display("all");
	printf("\n*date_d2 = ");
	date_d2->Display("all");
	printf("\n");

	//Ввод только времени
	printf("\nВвод только времени\n");

	date_st.ReadTime();
	printf("\ndate_st = ");
	date_st.Display("all");
	printf("\n");

	date_d->ReadTime();
	printf("\n*date_d = ");
	date_d->Display("all");

	//Ввод только даты
	printf("\n\nВвод только даты\n");

	date_st.ReadDate();
	printf("\ndate_st = ");
	date_st.Display("all");
	printf("\n");

	date_d->ReadDate();
	printf("\n*date_d = ");
	date_d->Display("all");

	//Вывод значений полей в выбранном формате
	printf("\n\nВывод значений полей в выбранном формате (помимо полного вывода)\ndate_st (hh:mm:ss) = ");
	date_st.Display("hh:mm:ss");
	printf("\ndate_st (hh:mm) = ");
	date_st.Display("hh:mm");
	printf("\ndate_st (mm:ss) = ");
	date_st.Display("mm:ss");
	printf("\ndate_st (DD.MM.YYYY) = ");
	date_st.Display("DD.MM.YYYY");
	printf("\ndate_st (DD/MM/YYYY) = ");
	date_st.Display("DD/MM/YYYY");
	printf("\ndate_st (MM.DD.YYYY) = ");
	date_st.Display("MM.DD.YYYY");
	printf("\ndate_st (DD-MM-YYYY) = ");
	date_st.Display("DD-MM-YYYY");
	printf("\ndate_st (YYYY-MM-DD) = ");
	date_st.Display("YYYY-MM-DD");

	printf("\n\n*date_d (hh:mm:ss) = ");
	date_d->Display("hh:mm:ss");
	printf("\n*date_d (hh:mm) = ");
	date_d->Display("hh:mm");
	printf("\n*date_d (mm:ss) = ");
	date_d->Display("mm:ss");
	printf("\n*date_d (DD.MM.YYYY) = ");
	date_d->Display("DD.MM.YYYY");
	printf("\n*date_d (DD/MM/YYYY) = ");
	date_d->Display("DD/MM/YYYY");
	printf("\n*date_d (MM.DD.YYYY) = ");
	date_d->Display("MM.DD.YYYY");
	printf("\n*date_d (DD-MM-YYYY) = ");
	date_d->Display("DD-MM-YYYY");
	printf("\n*date_d (YYYY-MM-DD) = ");
	date_d->Display("YYYY-MM-DD");

	//Получение текущей даты и времени
	printf("\n\nТекущая дата и время\ndate_st1 = ");
	date_st1.Now();
	date_st1.Display("all");
	printf("\n*date_d1 = ");
	date_d1->Now();
	date_d1->Display("all");

	//Сравнение дат
	printf("\n\n\nСравнение дат (сколько времени от первой даты до второй)\n");
	date_st1.Display("all");
	printf(" и ");
	date_st2.Display("all");
	printf("\n");
	(date_st1.Compare(date_st2)).Display("CompareResult");
	printf("\n");
	(date_st1.Compare(date_st2)).Display("CompareResultRU");

	printf("\n\n");
	date_d2->Display("all");
	printf(" и ");
	date_d1->Display("all");
	printf("\n");
	(date_d2->Compare(*date_d1)).Display("CompareResult");
	printf("\n");
	(date_d2->Compare(*date_d1)).Display("CompareResultRU");

	//Инициализация значений
	printf("\n\nИнициализация значений");
	date_st.Init(30, 5, 11, 27, 6, 2010);
	printf("\ndate_st = ");
	date_st.Display("all");

	date_d->Init(30, 5, 7, 2, 2, 1);
	printf("\n*date_d = ");
	date_d->Display("all");

	date_d1->Init(0, 34, 16, 27, 6, 2021);
	printf("\n*date_d1 = ");
	date_d1->Display("all");

	//Прибавление времени к дате
	printf("\n\nПрибавление времени *date_d к дате date_st: ");
	(date_st.Add(*date_d)).Display("all");

	//Проверка является дата годовщиной другой
	printf("\n\nПроверка является ли вторая дата 'годовщиной' первой\n");
	date_st.Display("all");
	printf(" и ");
	date_d1->Display("all");
	if (date_st.IsAnniversary(*date_d1))
		printf(": да.\n");
	else
		printf(": нет.\n");

	date_st.Display("all");
	printf(" и ");
	date_st1.Display("all");
	if (date_st.IsAnniversary(date_st1))
		printf(": да.");
	else
		printf(": нет.");

	delete date_d;
	delete date_d1;
	delete date_d2;

	/*//Работа со структурой address
	printf("\n\n\nРабота со структурой address\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	address_st = enterAddress();

	printf("\nВвод данных в динамическую переменную\n");
	*address_d = enterAddress();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printAddress(address_st);

	printf("\n\nПечать данных динамической переменной\n");
	printAddress(*address_d);

	free(address_d);



	//Работа со структурой publishing
	printf("\n\n\nРабота со структурой publishing\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	publ_st = enterPublishing();

	printf("\nВвод данных в динамическую переменную\n");
	*publ_d = enterPublishing();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printPublishing(publ_st);

	printf("\n\nПечать данных динамической переменной\n");
	printPublishing(*publ_d);

	free(publ_d);



	//Работа со структурой reader
	printf("\n\n\nРабота со структурой reader\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	reader_st = enterReader();

	printf("\nВвод данных в динамическую переменную\n");
	*reader_d = enterReader();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printReader(reader_st);

	printf("\n\nПечать данных динамической переменной\n");
	printReader(*reader_d);



	//Работа со структурой author
	printf("\n\n\nРабота со структурой author\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	author_st = enterAuthor();

	printf("\nВвод данных в динамическую переменную\n");
	*author_d = enterAuthor();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printAuthor(author_st);

	printf("\n\nПечать данных динамической переменной\n");
	printAuthor(*author_d);

	free(author_d);



	//Работа со структурой book
	printf("\n\n\nРабота со структурой book\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	book_st = enterBook();

	printf("\n\nВвод данных в динамическую переменную\n");
	*book_d = enterBook();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printBook(book_st);

	printf("\n\nПечать данных динамической переменной\n");
	printBook(*book_d);


	//Добавление читателя
	book_st.reader_info = &reader_st;
	printf("\n\n\nПечать данных статической переменной\n");
	printBook(book_st);

	book_st.reader_info = reader_d;
	printf("\n\nПечать данных статической переменной\n");
	printBook(book_st);

	book_d->reader_info = &reader_st;
	printf("\n\nПечать данных динамической переменной\n");
	printBook(*book_d);

	book_d->reader_info = reader_d;
	printf("\n\nПечать данных динамической переменной\n");
	printBook(*book_d);

	free(book_d);
	free(reader_d);*/


	return 0;
}