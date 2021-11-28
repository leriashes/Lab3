#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include "Book.h"
#include "InOut.h"
#include "ForeignBook.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//Работа с объектами класса Date
	printf("Работа со объектами класса Date\n");

	//Статические переменные
	Date date_st,	//Создание через конструктор без параметров
		//Создание через конструкторы с параметрами
		date_st1(12, 02, 2004),
		date_st2(26, 35, 12, 13, 05, 1997);

	//Динамические переменные
	Date* date_d, * date_d1, * date_d2;
	date_d = new Date();	//Создание через конструктор без параметров
	//Создание через конструкторы с параметрами
	date_d1 = new Date(31, 8, 1998);
	date_d2 = new Date(45, 41, 0, 7, 3, 1789);

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\ndate_st = ");
	InOut::Display(date_st, "all");
	printf("\ndate_st1 = ");
	InOut::Display(date_st1, "all");
	printf("\ndate_st2 = ");
	InOut::Display(date_st2, "all");
	printf("\n");

	printf("\nПечать данных динамических объектов\n*date_d = ");
	InOut::Display(*date_d, "all");
	printf("\n*date_d1 = ");
	InOut::Display(*date_d1, "all");
	printf("\n*date_d2 = ");
	InOut::Display(*date_d2, "all");
	printf("\n");

	//Ввод только времени
	printf("\nВвод только времени\n");

	date_st.ReadTime();
	printf("\ndate_st = ");
	InOut::Display(date_st, "all");
	printf("\n");

	date_d->ReadTime();
	printf("\n*date_d = ");
	InOut::Display(*date_d, "all");

	//Ввод только даты
	printf("\n\nВвод только даты\n");

	date_st.ReadDate();
	printf("\ndate_st = ");
	InOut::Display(date_st, "all");
	printf("\n");

	date_d->ReadDate();
	printf("\n*date_d = ");
	InOut::Display(*date_d, "all");

	//Вывод значений полей в выбранном формате
	printf("\n\nВывод значений полей в выбранном формате (помимо полного вывода)\ndate_st (hh:mm:ss) = ");
	InOut::Display(date_st, "hh:mm:ss");
	printf("\ndate_st (hh:mm) = ");
	InOut::Display(date_st, "hh:mm");
	printf("\ndate_st (mm:ss) = ");
	InOut::Display(date_st, "mm:ss");
	printf("\ndate_st (DD.MM.YYYY) = ");
	InOut::Display(date_st, "DD.MM.YYYY");
	printf("\ndate_st (DD/MM/YYYY) = ");
	InOut::Display(date_st, "DD/MM/YYYY");
	printf("\ndate_st (MM.DD.YYYY) = ");
	InOut::Display(date_st, "MM.DD.YYYY");
	printf("\ndate_st (DD-MM-YYYY) = ");
	InOut::Display(date_st, "DD-MM-YYYY");
	printf("\ndate_st (YYYY-MM-DD) = ");
	InOut::Display(date_st, "YYYY-MM-DD");

	printf("\n\n*date_d (hh:mm:ss) = ");
	InOut::Display(*date_d, "hh:mm:ss");
	printf("\n*date_d (hh:mm) = ");
	InOut::Display(*date_d, "hh:mm");
	printf("\n*date_d (mm:ss) = ");
	InOut::Display(*date_d, "mm:ss");
	printf("\n*date_d (DD.MM.YYYY) = ");
	InOut::Display(*date_d, "DD.MM.YYYY");
	printf("\n*date_d (DD/MM/YYYY) = ");
	InOut::Display(*date_d, "DD/MM/YYYY");
	printf("\n*date_d (MM.DD.YYYY) = ");
	InOut::Display(*date_d, "MM.DD.YYYY");
	printf("\n*date_d (DD-MM-YYYY) = ");
	InOut::Display(*date_d, "DD-MM-YYYY");
	printf("\n*date_d (YYYY-MM-DD) = ");
	InOut::Display(*date_d, "YYYY-MM-DD");

	//Получение текущей даты и времени
	printf("\n\nТекущая дата и время\ndate_st1 = ");
	InOut::Display(date_st1.Now(), "all");
	printf("\n*date_d1 = ");
	InOut::Display(date_d1->Now(), "all");

	//Сравнение дат
	printf("\n\n\nСравнение дат (сколько времени от первой даты до второй)\n");
	InOut::Display(date_st1, "all");
	printf(" и ");
	InOut::Display(date_st2, "all");
	printf("\n");
	InOut::Display(date_st1.Compare(date_st2), "CompareResult");
	printf("\n");
	InOut::Display(date_st1.Compare(date_st2), "CompareResultRU");

	printf("\n\n");
	InOut::Display(*date_d2, "all");
	printf(" и ");
	InOut::Display(*date_d1, "all");
	printf("\n");
	InOut::Display(date_d2->Compare(*date_d1), "CompareResult");
	printf("\n");
	InOut::Display(date_d2->Compare(*date_d1), "CompareResultRU");

	//Инициализация значений
	printf("\n\nИнициализация значений");
	date_st.Init(30, 5, 11, 27, 6, 2010);
	printf("\ndate_st = ");
	InOut::Display(date_st, "all");

	date_d->Init(30, 5, 7, 2, 2, 1);
	printf("\n*date_d = ");
	InOut::Display(*date_d, "all");

	date_d1->Init(0, 34, 16, 27, 6, 2021);
	printf("\n*date_d1 = ");
	InOut::Display(*date_d1, "all");

	//Прибавление времени к дате
	printf("\n\nПрибавление времени *date_d к дате date_st: ");
	date_st = date_st.Add(*date_d);
	InOut::Display(date_st, "all");

	printf("\n\nПрибавление времени *date_d к дате date_st (+): ");
	InOut::Display(date_st + *date_d, "all");

	++date_st;
	printf("\n\n++date_st: ");
	InOut::Display(date_st++, "all");

	printf("\n\ndate_st++: ");
	InOut::Display(date_st, "all");

	//Проверка является дата годовщиной другой
	printf("\n\nПроверка является ли вторая дата 'годовщиной' первой\n");
	InOut::Display(date_st, "all");
	printf(" и ");
	InOut::Display(*date_d1, "all");
	if (date_st.IsAnniversary(*date_d1))
		printf(": да.\n");
	else
		printf(": нет.\n");

	InOut::Display(date_st, "all");
	printf(" и ");
	InOut::Display(date_st1, "all");
	if (date_st.IsAnniversary(date_st1))
		printf(": да.");
	else
		printf(": нет.");

	delete date_d;
	delete date_d1;
	delete date_d2;



	//Работа с объектами класса Author
	printf("\n\n\n\nРабота со объектами класса Author\n");

	//Статические переменные
	Author author_st,	//Создание через конструктор без параметров
		//Создание через конструкторы с параметрами
		author_st1("Петров Пётр Петрович", date_st, "Украина"),
		author_st2("Сидорова Светлана Сергеевна", 12, 12, 1972, "Беларусь");

	//Динамические переменные
	Author* author_d, * author_d1, * author_d2;
	author_d = new Author();	//Создание через конструктор без параметров
	//Создание через конструкторы с параметрами
	author_d1 = new Author("Кузнецов Кирилл Корнеевич", date_st2, "Казахстан");
	author_d2 = new Author("Третьякова Таисия Тимуровна", date_st1, "Россия");

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\nauthor_st = ");
	InOut::Display(author_st, "all");
	printf("\nauthor_st1 = ");
	InOut::Display(author_st1, "all");
	printf("\nauthor_st2 = ");
	InOut::Display(author_st2, "all");
	printf("\n");

	printf("\nПечать данных динамических объектов\n*author_d = ");
	InOut::Display(*author_d, "all");
	printf("\n*author_d1 = ");
	InOut::Display(*author_d1, "all");
	printf("\n*author_d2 = ");
	InOut::Display(*author_d2, "all");
	printf("\n");

	//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта (передача и возврат по указателю)\n");

	InOut::Read(&author_st);
	printf("\nauthor_st = ");
	InOut::Display(author_st, "all");
	printf("\n\n");

	InOut::Read(author_d);
	printf("\n*author_d = ");
	InOut::Display(*author_d, "all");

	printf("\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n");

	InOut::Read(author_st);
	printf("\nauthor_st = ");
	InOut::Display(author_st, "all");
	printf("\n\n");

	InOut::Read(*author_d);
	printf("\n*author_d = ");
	InOut::Display(*author_d, "all");


	//Вывод значений полей в выбранном формате
	printf("\n\nВывод значений полей в выбранном формате (помимо полного вывода)\nauthor_st (FullName) = ");
	InOut::Display(author_st, "FullName");
	printf("\nauthor_st (FullName (Country)) = ");
	InOut::Display(author_st, "FullName (Country)");
	printf("\nauthor_st (FullName (BirthDate)) = ");
	InOut::Display(author_st, "FullName (BirthDate)");

	printf("\n\n*author_d (FullName) = ");
	InOut::Display(*author_d, "FullName");
	printf("\n*author_d (FullName (Country)) = ");
	InOut::Display(*author_d, "FullName (Country)");
	printf("\n*author_d (FullName (BirthDate)) = ");
	InOut::Display(*author_d, "FullName (BirthDate)");

	//Инициализация значений
	printf("\n\nИнициализация значений");
	author_st.Init("Паркер Энн", date_st, "США");
	printf("\nauthor_st = ");
	InOut::Display(author_st, "all");

	author_d->Init("Старикова Татьяна Алексеевна", date_st1, "Россия");
	printf("\n*author_d = ");
	InOut::Display(*author_d, "all");

	//Проверка родился ли автор в заданной стране
	printf("\n\nПроверка родился ли автор в заданной стране\n");
	InOut::Display(author_st, "all");
	printf(" и страна Россия");
	if (author_st.BornIn("Россия"))
		printf(": да.\n");
	else
		printf(": нет.\n");

	InOut::Display(*author_d, "all");
	printf(" и страна Россия");
	if (author_d->BornIn("Россия"))
		printf(": да.");
	else
		printf(": нет.");

	delete author_d;
	delete author_d1;
	delete author_d2;



	//Работа с объектами класса Address
	printf("\n\n\n\nРабота со объектами класса Address\n");

	//Статические переменные
	Address address_st,	//Создание через конструктор без параметров
		address_st1("г. Новосибирск", "ул. Сиреневая", 12, 4);		//Создание через конструкторы с параметрами

	//Динамические переменные
	Address* address_d, * address_d1;
	address_d = new Address();	//Создание через конструктор без параметров
	address_d1 = new Address("г. Барнаул", "ул. Антона Петрова", 154, 50);	//Создание через конструктор с параметрами

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\naddress_st = ");
	InOut::Display(address_st);
	printf("\naddress_st1 = ");
	InOut::Display(address_st1);
	printf("\n");

	printf("\nПечать данных динамических объектов\n*address_d = ");
	InOut::Display(*address_d);
	printf("\n*address_d1 = ");
	InOut::Display(*address_d1);
	printf("\n");

	//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта (передача и возврат по указателю)\n");

	InOut::Read(&address_st);
	printf("\naddress_st = ");
	InOut::Display(address_st);
	printf("\n\n");

	InOut::Read(address_d);
	printf("\n*address_d = ");
	InOut::Display(*address_d);

	printf("\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n");

	InOut::Read(address_st);
	printf("\naddress_st = ");
	InOut::Display(address_st);
	printf("\n\n");

	InOut::Read(*address_d);
	printf("\n*address_d = ");
	InOut::Display(*address_d);

	//Инициализация значений
	printf("\n\nИнициализация значений");
	address_st.Init("г. Троицк", "ул. Текстильщиков", 6, 2);
	printf("\naddress_st = ");
	InOut::Display(address_st);

	address_d->Init("г. Барнаул", "ул. Энтузиастов", 55, 23);
	printf("\n*address_d = ");
	InOut::Display(*address_d);

	//Проверка совпадения города
	printf("\n\nПроверка родился ли автор в заданной стране\n");
	InOut::Display(address_st);
	printf(" и г. Барнаул");
	if (address_st.City("г. Барнаул"))
		printf(": да.\n");
	else
		printf(": нет.\n");

	InOut::Display(*address_d);
	printf(" и г. Барнаул");
	if (address_d->City("г. Барнаул"))
		printf(": да.");
	else
		printf(": нет.");

	delete address_d;
	delete address_d1;



	//Работа с объектами класса Reader
	printf("\n\n\n\nРабота со объектами класса Reader\n");

	//Статические переменные
	Reader reader_st,	//Создание через конструктор без параметров
		//Создание через конструкторы с параметрами
		reader_st1("Петров Пётр Петрович", date_st, address_st, "0110 120954"),
		reader_st2("Сидорова Светлана Сергеевна", date_st1, address_st1, 987654);

	//Динамические переменные
	Reader* reader_d, * reader_d1, * reader_d2;
	reader_d = new Reader();	//Создание через конструктор без параметров
	//Создание через конструкторы с параметрами
	reader_d1 = new Reader("Кузнецов Кирилл Корнеевич", date_st2, address_st, "0112 765423");
	reader_d2 = new Reader("Третьякова Таисия Тимуровна", date_st1, address_st1, 54321789);

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\nreader_st = ");
	InOut::Display(reader_st2, "all");
	printf("\nreader_st1 = ");
	InOut::Display(reader_st1, "all");
	printf("\nreader_st2 = ");
	InOut::Display(reader_st2, "all");
	printf("\n");

	printf("\nПечать данных динамических объектов\n*reader_d = ");
	InOut::Display(*reader_d, "all");
	printf("\n*reader_d1 = ");
	InOut::Display(*reader_d1, "all");
	printf("\n*reader_d2 = ");
	InOut::Display(*reader_d2, "all");
	printf("\n");

	//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта (передача и возврат по указателю)\n");

	InOut::Read(&reader_st);
	printf("\nreader_st = ");
	InOut::Display(reader_st, "all");
	printf("\n\n");

	InOut::Read(reader_d);
	printf("\n*reader_d = ");
	InOut::Display(*reader_d, "all");

	printf("\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n");

	InOut::Read(reader_st);
	printf("\nreader_st = ");
	InOut::Display(reader_st, "all");
	printf("\n\n");

	InOut::Read(*reader_d);
	printf("\n*reader_d = ");
	InOut::Display(*reader_d, "all");

	//Вывод значений полей в выбранном формате
	printf("\n\nВывод значений полей в выбранном формате (помимо полного вывода)\nreader_st (FullName) = ");
	InOut::Display(reader_st, "FullName");
	printf("\nreader_st ([DocNumber] FullName) = ");
	InOut::Display(reader_st, "[DocNumber] FullName");
	printf("\nreader_st (FullName (BirthDate)) = ");
	InOut::Display(reader_st, "FullName (BirthDate)");

	printf("\n\n*reader_d (FullName) = ");
	InOut::Display(*reader_d, "FullName");
	printf("\n*reader_d ([DocNumber] FullName) = ");
	InOut::Display(*reader_d, "[DocNumber] FullName");
	printf("\n*reader_d (FullName (BirthDate)) = ");
	InOut::Display(*reader_d, "FullName (BirthDate)");

	//Инициализация значений
	printf("\n\nИнициализация значений");
	reader_st.Init("Кузнецов Кирилл Корнеевич", date_st2, address_st, "0112 765423");
	printf("\nreader_st = ");
	InOut::Display(reader_st, "all");

	reader_d->Init("Кузнецов Тимофей Корнеевич", date_st2, address_st, 0112765423);
	printf("\n*reader_d = ");
	InOut::Display(*reader_d, "all");

	//Проверка является ли дата днём рождения читателя
	printf("\n\nПроверка родился ли автор в заданной стране\n");
	InOut::Display(reader_st2, "all");
	printf(" и ");
	InOut::Display(date_st2, "DD.MM.YYYY");
	if (reader_st2.IsBirthday(date_st2))
		printf(": да.\n");
	else
		printf(": нет.\n");

	InOut::Display(*reader_d1, "all");
	printf(" и ");
	InOut::Display(date_st2, "DD.MM.YYYY");
	if (reader_d1->IsBirthday(date_st2))
		printf(": да.");
	else
		printf(": нет.");

	delete reader_d;
	delete reader_d1;
	delete reader_d2;



	//Работа с объектами класса Publishing
	printf("\n\n\n\nРабота со объектами класса Publishing\n");

	//Статические переменные
	Publishing publishing_st,	//Создание через конструктор без параметров
		publishing_st1("Издательство №2", "г. Барнаул");		//Создание через конструктор с параметрами

	//Динамические переменные
	Publishing* publishing_d, * publishing_d1;
	publishing_d = new Publishing();	//Создание через конструктор без параметров
	publishing_d1 = new Publishing("Мир", "г. Томск");		//Создание через конструктор с параметрами

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\npublishing_st = ");
	InOut::Display(publishing_st);
	printf("\npublishing_st1 = ");
	InOut::Display(publishing_st1);
	printf("\n");

	printf("\nПечать данных динамических объектов\n*publishing_d = ");
	InOut::Display(*publishing_d);
	printf("\n*publishing_d1 = ");
	InOut::Display(*publishing_d1);
	printf("\n");

	//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта (передача и возврат по указателю)\n");

	InOut::Read(&publishing_st);
	printf("\npublishing_st = ");
	InOut::Display(publishing_st);
	printf("\n\n");

	InOut::Read(publishing_d);
	printf("\n*publishing_d = ");
	InOut::Display(*publishing_d);

	printf("\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n");

	InOut::Read(publishing_st);
	printf("\npublishing_st = ");
	InOut::Display(publishing_st);
	printf("\n\n");

	InOut::Read(*publishing_d);
	printf("\n*publishing_d = ");
	InOut::Display(*publishing_d);

	//Инициализация значений
	printf("\n\nИнициализация значений");
	publishing_st.Init("Паркер", "г. Вашингтон");
	printf("\npublishing_st = ");
	InOut::Display(publishing_st);

	publishing_d->Init("Старт", "г. Ростов");
	printf("\n*publishing_d = ");
	InOut::Display(*publishing_d);

	//Проверка находится ли издательство в заданном городе
	printf("\n\nПроверка находится ли издательство в заданном городе\n");
	InOut::Display(publishing_st);
	printf(" и г. Москва");
	if (publishing_st.IsHere("г. Москва"))
		printf(": да.\n");
	else
		printf(": нет.\n");

	InOut::Display(*publishing_d);
	printf(" и г. Барнаул");
	if (publishing_d->IsHere("г. Барнаул"))
		printf(": да.");
	else
		printf(": нет.");

	delete publishing_d;
	delete publishing_d1;



	//Работа с объектами класса Book
	printf("\n\n\n\nРабота со объектами класса Book\n");

	//Статические переменные
	Book book_st,	//Создание через конструктор без параметров
		//Создание через конструкторы с параметрами
		book_st1("Новый мир"),
		book_st2("Петька и Васька", author_st2, 76, "Рассказы", publishing_st, 2019);

	//Динамические переменные
	Book* book_d, * book_d1, * book_d2;
	book_d = new Book();	//Создание через конструктор без параметров
	//Создание через конструкторы с параметрами
	book_d1 = new Book("Новый мир");
	book_d2 = new Book("Петька и Васька", author_st2, 76, "Рассказы", publishing_st, 2019);

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\nbook_st ");
	InOut::Display(book_st);
	printf("\n\nbook_st1 ");
	InOut::Display(book_st1);
	printf("\n\nbook_st2 ");
	InOut::Display(book_st2);
	printf("\n");

	printf("\nПечать данных динамических объектов\n*book_d ");
	InOut::Display(*book_d);
	printf("\n\n*book_d1 ");
	InOut::Display(*book_d1);
	printf("\n\n*book_d2 ");
	InOut::Display(*book_d2);
	printf("\n");

	//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта (передача и возврат по указателю)\n");

	InOut::Read(&book_st);
	printf("\n\nbook_st ");
	InOut::Display(book_st);
	printf("\n\n");

	InOut::Read(book_d);
	printf("\n\n*book_d ");
	InOut::Display(*book_d);

	printf("\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n");

	InOut::Read(book_st);
	printf("\n\nbook_st ");
	InOut::Display(book_st);
	printf("\n\n");

	InOut::Read(*book_d);
	printf("\n\n*book_d ");
	InOut::Display(*book_d);

	//Инициализация значений
	printf("\n\nИнициализация значений");
	book_st.Init("Петька и Кот", author_st2, 65, "Ужасы", publishing_st, 2005);
	printf("\nbook_st ");
	InOut::Display(book_st);

	book_d->Init("Наш мир", author_st1, 1021, "Энциклопедия", &reader_st, publishing_st1, 2013);
	printf("\n\n*book_d ");
	InOut::Display(*book_d);

	//Привязка читателя
	printf("\n\nПривязка читателя\nbook_st1 ");
	book_st1.AddReader(&reader_st);
	InOut::Display(book_st1);

	//Сравнение читателей книг
	printf("\n\nСравнение читателей книг\n");
	InOut::Display(book_st2);
	printf("\n\nи \n\n");
	InOut::Display(book_st1);
	if (book_st2.CmpReader(book_st1))
		printf("\n\nодин и тот же читатель.\n");
	else
		printf("\n\nразные читатели.\n\n");

	InOut::Display(*book_d);
	printf("\n\nи \n\n");
	InOut::Display(book_st1);
	if (book_d->CmpReader(book_st1))
		printf("\n\nодин и тот же читатель.\n");
	else
		printf("\n\nразные читатели.\n");
	
	printf("\n\nbook_st1\n");
	InOut::Display(book_st1);
	printf("\n\nbooki - глубокая копия book_st1\n");
	Book booki(book_st1);	//Конструктор копирования - глубокое копирование
	InOut::Display(booki);
	printf("\n\nbook_d2 - мелкая копия book_st1\n");
	*book_d2 = book_st1;	//Мелкое копирование
	InOut::Display(*book_d2);

	reader_st.Init("Тумбочкина Татьяна Леонидовна", date_st, address_st, 1234567890);
	printf("\n\nbooki - глубокая копия book_st1 после изменения данных о читателе не изменяется\n");
	InOut::Display(booki);
	printf("\n\nbook_d2 - мелкая копия book_st1 после изменения данных о читателе изменяется\n");
	InOut::Display(*book_d2);


	//Проверка принадлежности книги читателю
	printf("\n\nПроверка принадлежности книги читателю\n");
	InOut::Display(book_st1);
	printf("\n\nи читатель:\n\n");
	InOut::Display(reader_st, "all");
	if (book_st1.Belongs(&reader_st))
		printf("\n\nкнига принадлежит читателю.\n\n");
	else
		printf("\n\nкнига не принадлежит читателю.\n\n");

	InOut::Display(book_st1);
	printf("\n\nи читатель:\n\n");
	InOut::Display(reader_st1, "all");
	if (book_st1.Belongs(&reader_st1))
		printf("\n\nкнига принадлежит читателю.\n");
	else
		printf("\n\nкнига не принадлежит читателю.\n\n");

	//Отвязка читателя
	printf("\n\nОтвязка читателя\nbook_st1 ");
	book_st1.AddReader(NULL);
	InOut::Display(book_st1);

	//Всего книг в библиотеке
	printf("\n\nКниг в бибилиотеке: %d ", Book::GetCounter());
	printf("\n\nНажмите любую клавишу для продолжения...");
	_getch();
	system("cls");

	//Работа с динамическим массивом объектов класса и с массивом динамических объектов класса
	Book* books_mas1, * books_mas2[2];

	books_mas1 = new Book[2];

	for (int i = 0; i < 2; i++)
		books_mas2[i] = new Book;

	//Вывод объектов

	//Первый массив
	//Следующие выражения равносильны
	printf("books_mas1[0]\n");
	InOut::Display(*books_mas1);
	printf("\n\n");
	InOut::Display(books_mas1[0]);
	printf("\n\n\n");

	printf("\nbooks_mas1[1]\n");
	InOut::Display(*(books_mas1 + 1));
	printf("\n\n");

	//Второй массив
	//Следующие выражения равносильны
	printf("\n*books_mas2[0]\n");
	InOut::Display(**(books_mas2));
	printf("\n\n");
	InOut::Display(*books_mas2[0]);
	printf("\n\n");

	printf("\n*books_mas2[1]\n");
	InOut::Display(*books_mas2[1]);
	printf("\n\n");

	//Изменение значений полей объектов
	books_mas1[1].Init("Книга 1", author_st, 10, "Объект динамического массива", publishing_st, 2021);
	books_mas2[1]->Init("Книга 2", author_st1, 10, "Динамический объект массива", publishing_st1, 2021);

	//Вывод объектов

	//Элемент первого массива
	//Следующие выражения равносильны
	printf("\nbooks_mas1[1]\n");
	InOut::Display(*(books_mas1 + 1));
	printf("\n\n");
	InOut::Display(books_mas1[1]);
	printf("\n\n\n");

	//Следующие выражения равносильны
	printf("\n*books_mas2[1]\n");
	InOut::Display(**(books_mas2 + 1));
	printf("\n\n");
	InOut::Display(*books_mas2[1]);
	printf("\n\n");

	printf("\n\nКниг в бибилиотеке: %d", Book::GetCounter());
	printf("\n\nНажмите любую клавишу для продолжения...");
	_getch();
	system("cls");

	Book kniga;
	printf("Книг в библиотеке:%d \nВремя, на которое можно брать книги: %d", Book::GetCounter(), Book::GetTime());
	Book::SetTime(14);
	Book knigi[3] = { Book("Книга 1"), Book("Книга 2"), Book("Книга 3") };
	printf("\n\nКниг в библиотеке:%d \nВремя, на которое можно брать книги: %d\n", Book::GetCounter(), Book::GetTime());

	Book::BorrowBook(kniga, reader_st, Date::Today());
	InOut::Display(kniga);
	printf("\n\nКоличество выданных книг читателю reader_st2: %d\n\n", Book::BorrowBook(knigi, 2, reader_st2, Date::Today()));
	printf("\n\nКоличество выданных книг читателю reader_st1: %d\n\n", Book::BorrowBook(knigi, 3, reader_st1, Date::Today()));

	for (int i = 0; i < 3; i++)
	{
		printf("\n\n");
		InOut::Display(knigi[i]);
	}

	delete[] books_mas1;

	for (int i = 0; i < 2; i++)
		delete books_mas2[i];

	delete book_d;
	delete book_d1;
	delete book_d2;

	printf("\n\nНажмите любую клавишу для продолжения...");
	_getch();
	system("cls");

	//Работа с одномерным массивом
	Book odnm_mas[3] = { Book("Книга 1"), Book("Книга 2"), Book("Книга 3") };
	printf("Работа с одномерным массивом\nКниг в библиотеке:%d ", Book::GetCounter());

	for (int i = 0; i < 3; i++)
	{
		printf("\n\nodnm_mas[%d] ", i);
		InOut::Display(odnm_mas[i]);
	}

	printf("\n\nВведите индекс элемента массива для ввода: ");
	int k, d;
	do
	{
		k = _getch();
		k -= 48;
	} while (k < 0 || k > 2);

	printf("%d\n\nВвод информации о книге odnm_mas[%d]\n", k, k);
	InOut::Read(odnm_mas[k]);

	printf("\n\nodnm_mas[%d] ", k);
	InOut::Display(odnm_mas[k]);

	//Работа с двумерным массивом
	Book dvum_mas[2][2] = { {Book("Книга 1.1"), Book("Книга 1.2")}, {Book("Книга 2.1"), Book("Книга 2.2")} };
	printf("Работа с двумерным массивом\nКниг в библиотеке:%d ", Book::GetCounter());

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("\n\ndvum_mas[%d][%d] ", i, j);
			InOut::Display(dvum_mas[i][j]);
		}
	}

	printf("\n\nВведите номер строки двумерного массива: ");
	do
	{
		k = _getch();
		k -= 48;
	} while (k < 0 || k > 1);
	printf("%d", k);

	printf("\n\nВведите номер столбца двумерного массива: ");
	do
	{
		d = _getch();
		d -= 48;
	} while (d < 0 || d > 1);

	printf("%d\n\nВвод информации о книге dvum_mas[%d][%d]\n", d, k, d);
	InOut::Read(dvum_mas[k][d]);

	printf("\n\ndvum_mas[%d][%d]", k, d);
	InOut::Display(dvum_mas[k][d]);

	Date fdate(28, 11, 2001);
	Address faddress;
	Reader freader("Шишкова Валентина Алексеевна", fdate, faddress, 123456789);
	Author fauthor("Сьюэлл Анна", date_st, "Великобритания");
	Publishing fpublishing;

	ForeignBook fbook("Good Morning", fauthor, 345, "Фантастика", &freader, fpublishing, 2021, "Английский"), fbook1(fbook), fbook2;
	
	fbook2.Init("Black Beauty", fauthor, 289, "Рассказы", publishing_st, 2019, "Английский");
	fbook1.Init("Fahrenheit 1", author_st, 451, "Фантастика", &freader, publishing_st, 2013, "Английский");
 	return 0;
}