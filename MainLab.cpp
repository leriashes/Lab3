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
	cout << "Работа со объектами класса Date\n";

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
	cout << "\nПечать данных статических объектов\ndate_st = " << date_st;
	cout << "\ndate_st1 = " << date_st1;
	cout << "\ndate_st2 = " << date_st2;
	cout << "\n";

	cout << "\nПечать данных динамических объектов\n*date_d = " << *date_d;
	cout << "\n*date_d1 = " << *date_d1;
	cout << "\n*date_d2 = " << *date_d2;
	cout << "\n";

	//Ввод только времени
	cout << "\nВвод только времени\n";

	date_st.ReadTime();
	cout << "\ndate_st = " << date_st;
	cout << "\n";

	date_d->ReadTime();
	cout << "\n*date_d = " << *date_d;

	//Ввод только даты
	cout << "\n\nВвод только даты\n";

	date_st.ReadDate();
	cout << "\ndate_st = " << date_st;
	cout << "\n";

	date_d->ReadDate();
	cout << "\n*date_d = " << *date_d;

	//Вывод значений полей в выбранном формате
	cout << "\n\nВывод значений полей в выбранном формате (помимо полного вывода)\ndate_st (hh:mm:ss) = ";
	InOut::Display(date_st, "hh:mm:ss");
	cout << "\ndate_st (hh:mm) = ";
	InOut::Display(date_st, "hh:mm");
	cout << "\ndate_st (mm:ss) = ";
	InOut::Display(date_st, "mm:ss");
	cout << "\ndate_st (DD.MM.YYYY) = ";
	InOut::Display(date_st, "DD.MM.YYYY");
	cout << "\ndate_st (DD/MM/YYYY) = ";
	InOut::Display(date_st, "DD/MM/YYYY");
	cout << "\ndate_st (MM.DD.YYYY) = ";
	InOut::Display(date_st, "MM.DD.YYYY");
	cout << "\ndate_st (DD-MM-YYYY) = ";
	InOut::Display(date_st, "DD-MM-YYYY");
	cout << "\ndate_st (YYYY-MM-DD) = ";
	InOut::Display(date_st, "YYYY-MM-DD");

	cout << "\n\n*date_d (hh:mm:ss) = ";
	InOut::Display(*date_d, "hh:mm:ss");
	cout << "\n*date_d (hh:mm) = ";
	InOut::Display(*date_d, "hh:mm");
	cout << "\n*date_d (mm:ss) = ";
	InOut::Display(*date_d, "mm:ss");
	cout << "\n*date_d (DD.MM.YYYY) = ";
	InOut::Display(*date_d, "DD.MM.YYYY");
	cout << "\n*date_d (DD/MM/YYYY) = ";
	InOut::Display(*date_d, "DD/MM/YYYY");
	cout << "\n*date_d (MM.DD.YYYY) = ";
	InOut::Display(*date_d, "MM.DD.YYYY");
	cout << "\n*date_d (DD-MM-YYYY) = ";
	InOut::Display(*date_d, "DD-MM-YYYY");
	cout << "\n*date_d (YYYY-MM-DD) = ";
	InOut::Display(*date_d, "YYYY-MM-DD");

	//Получение текущей даты и времени
	cout << "\n\nТекущая дата и время\ndate_st1 = " << date_st1.Now();
	cout << "\n*date_d1 = " << date_d1->Now();

	//Сравнение дат
	cout << "\n\n\nСравнение дат (сколько времени от первой даты до второй)\n" << date_st1;
	cout << " и " << date_st2;
	cout << "\n";
	InOut::Display(date_st1.Compare(date_st2), "CompareResult");
	cout << "\n";
	InOut::Display(date_st1.Compare(date_st2), "CompareResultRU");

	cout << "\n\n" << *date_d2;
	cout << " и " << *date_d1;
	cout << "\n";
	InOut::Display(date_d2->Compare(*date_d1), "CompareResult");
	cout << "\n";
	InOut::Display(date_d2->Compare(*date_d1), "CompareResultRU");

	//Инициализация значений
	cout << "\n\nИнициализация значений";
	date_st.Init(30, 5, 11, 27, 6, 2010);
	cout << "\ndate_st = " << date_st;

	date_d->Init(30, 5, 7, 2, 2, 1);
	cout << "\n*date_d = " << *date_d;

	date_d1->Init(0, 34, 16, 27, 6, 2021);
	cout << "\n*date_d1 = " << *date_d1;

	//Прибавление времени к дате
	cout << "\n\nПрибавление времени *date_d к дате date_st: ";
	date_st = date_st.Add(*date_d);
	cout << date_st;

	cout << "\n\nПрибавление времени *date_d к дате date_st (+): " << date_st + *date_d;

	++date_st;
	cout << "\n\n++date_st: " << date_st++;

	cout << "\n\ndate_st++: " << date_st;

	//Проверка является дата годовщиной другой
	cout << "\n\nПроверка является ли вторая дата 'годовщиной' первой\n" << date_st;
	cout << " и " << *date_d1;
	if (date_st.IsAnniversary(*date_d1))
		cout << ": да.\n";
	else
		cout << ": нет.\n";

	cout << date_st;
	cout << " и " << date_st1;
	if (date_st.IsAnniversary(date_st1))
		cout << ": да.";
	else
		cout << ": нет.";

	delete date_d;
	delete date_d1;
	delete date_d2;



	//Работа с объектами класса Author
	cout << "\n\n\n\nРабота со объектами класса Author\n";

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
	cout << "\nПечать данных статических объектов\nauthor_st = " << author_st;
	cout << "\nauthor_st1 = " << author_st1;
	cout << "\nauthor_st2 = " << author_st2;
	cout << "\n";

	cout << "\nПечать данных динамических объектов\n*author_d = " << *author_d;
	cout << "\n*author_d1 = " << *author_d1;
	cout << "\n*author_d2 = " << *author_d2;
	cout << "\n";

	//Ввод значений всех полей объекта
	cout << "\nВвод значений всех полей объекта (передача и возврат по указателю)\n";

	InOut::Read(&author_st);
	cout << "\nauthor_st = " << author_st;
	cout << "\n\n";

	InOut::Read(author_d);
	cout << "\n*author_d = " << *author_d;

	cout << "\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n";

	InOut::Read(author_st);
	cout << "\nauthor_st = " << author_st;
	cout << "\n\n";

	InOut::Read(*author_d);
	cout << "\n*author_d = " << *author_d;


	//Вывод значений полей в выбранном формате
	cout << "\n\nВывод значений полей в выбранном формате (помимо полного вывода)\nauthor_st (FullName) = ";
	InOut::Display(author_st, "FullName");
	cout << "\nauthor_st (FullName (Country)) = ";
	InOut::Display(author_st, "FullName (Country)");
	cout << "\nauthor_st (FullName (BirthDate)) = ";
	InOut::Display(author_st, "FullName (BirthDate)");

	cout << "\n\n*author_d (FullName) = ";
	InOut::Display(*author_d, "FullName");
	cout << "\n*author_d (FullName (Country)) = ";
	InOut::Display(*author_d, "FullName (Country)");
	cout << "\n*author_d (FullName (BirthDate)) = ";
	InOut::Display(*author_d, "FullName (BirthDate)");

	//Инициализация значений
	cout << "\n\nИнициализация значений";
	author_st.Init("Паркер Энн", date_st, "США");
	cout << "\nauthor_st = " << author_st;

	author_d->Init("Старикова Татьяна Алексеевна", date_st1, "Россия");
	cout << "\n*author_d = " << *author_d;

	//Проверка родился ли автор в заданной стране
	cout << "\n\nПроверка родился ли автор в заданной стране\n" << author_st;
	cout << " и страна Россия";
	if (author_st.BornIn("Россия"))
		cout << ": да.\n";
	else
		cout << ": нет.\n";

	cout << *author_d;
	cout << " и страна Россия";
	if (author_d->BornIn("Россия"))
		cout << ": да.";
	else
		cout << ": нет.";

	delete author_d;
	delete author_d1;
	delete author_d2;



	//Работа с объектами класса Address
	cout << "\n\n\n\nРабота со объектами класса Address\n";

	//Статические переменные
	Address address_st,	//Создание через конструктор без параметров
		address_st1("г. Новосибирск", "ул. Сиреневая", 12, 4);		//Создание через конструкторы с параметрами

	//Динамические переменные
	Address* address_d, * address_d1;
	address_d = new Address();	//Создание через конструктор без параметров
	address_d1 = new Address("г. Барнаул", "ул. Антона Петрова", 154, 50);	//Создание через конструктор с параметрами

	//Печать созданных объектов
	cout << "\nПечать данных статических объектов\naddress_st = ";
	InOut::Display(address_st);
	cout << "\naddress_st1 = ";
	InOut::Display(address_st1);
	cout << "\n";

	cout << "\nПечать данных динамических объектов\n*address_d = ";
	InOut::Display(*address_d);
	cout << "\n*address_d1 = ";
	InOut::Display(*address_d1);
	cout << "\n";

	//Ввод значений всех полей объекта
	cout << "\nВвод значений всех полей объекта (передача и возврат по указателю)\n";

	InOut::Read(&address_st);
	cout << "\naddress_st = " << address_st;
	cout << "\n\n";

	InOut::Read(address_d);
	cout << "\n*address_d = " << *address_d;

	cout << "\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n";

	InOut::Read(address_st);
	cout << "\naddress_st = " << address_st);
	cout << "\n\n";

	InOut::Read(*address_d);
	cout << "\n*address_d = " << *address_d);

	//Инициализация значений
	cout << "\n\nИнициализация значений";
	address_st.Init("г. Троицк", "ул. Текстильщиков", 6, 2);
	cout << "\naddress_st = " << address_st;

	address_d->Init("г. Барнаул", "ул. Энтузиастов", 55, 23);
	cout << "\n*address_d = " << *address_d;

	//Проверка совпадения города
	cout << "\n\nПроверка родился ли автор в заданной стране\n" << address_st;
	cout << " и г. Барнаул";
	if (address_st.City("г. Барнаул"))
		cout << ": да.\n";
	else
		cout << ": нет.\n";

	cout << *address_d;
	cout << " и г. Барнаул";
	if (address_d->City("г. Барнаул"))
		cout << ": да.";
	else
		cout << ": нет.";

	delete address_d;
	delete address_d1;



	//Работа с объектами класса Reader
	cout << "\n\n\n\nРабота со объектами класса Reader\n";

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
	cout << "\nПечать данных статических объектов\nreader_st = " << reader_st2;
	cout << "\nreader_st1 = " << reader_st1;
	cout << "\nreader_st2 = " << reader_st2;
	cout << "\n";

	cout << "\nПечать данных динамических объектов\n*reader_d = " << *reader_d;
	cout << "\n*reader_d1 = " << *reader_d1;
	cout << "\n*reader_d2 = " << *reader_d2;
	cout << "\n";

	//Ввод значений всех полей объекта
	cout << "\nВвод значений всех полей объекта (передача и возврат по указателю)\n";

	InOut::Read(&reader_st);
	cout << "\nreader_st = " << reader_st;
	cout << "\n\n";

	InOut::Read(reader_d);
	cout << "\n*reader_d = " << *reader_d;

	cout << "\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n";

	InOut::Read(reader_st);
	cout << "\nreader_st = " << reader_st;
	cout << "\n\n";

	InOut::Read(*reader_d);
	cout << "\n*reader_d = " << *reader_d;

	//Вывод значений полей в выбранном формате
	cout << "\n\nВывод значений полей в выбранном формате (помимо полного вывода)\nreader_st (FullName) = ";
	InOut::Display(reader_st, "FullName");
	cout << "\nreader_st ([DocNumber] FullName) = ";
	InOut::Display(reader_st, "[DocNumber] FullName");
	cout << "\nreader_st (FullName (BirthDate)) = ";
	InOut::Display(reader_st, "FullName (BirthDate)");

	cout << "\n\n*reader_d (FullName) = ";
	InOut::Display(*reader_d, "FullName");
	cout << "\n*reader_d ([DocNumber] FullName) = ";
	InOut::Display(*reader_d, "[DocNumber] FullName");
	cout << "\n*reader_d (FullName (BirthDate)) = ";
	InOut::Display(*reader_d, "FullName (BirthDate)");

	//Инициализация значений
	cout << "\n\nИнициализация значений";
	reader_st.Init("Кузнецов Кирилл Корнеевич", date_st2, address_st, "0112 765423");
	cout << "\nreader_st = " << reader_st;

	reader_d->Init("Кузнецов Тимофей Корнеевич", date_st2, address_st, 0112765423);
	cout << "\n*reader_d = " << *reader_d;

	//Проверка является ли дата днём рождения читателя
	cout << "\n\nПроверка родился ли автор в заданной стране\n" << reader_st2;
	cout << " и " << date_st2;
	if (reader_st2.IsBirthday(date_st2))
		cout << ": да.\n";
	else
		cout << ": нет.\n";

	cout << *reader_d1;
	cout << " и " << date_st2;
	if (reader_d1->IsBirthday(date_st2))
		cout << ": да.";
	else
		cout << ": нет.";

	delete reader_d;
	delete reader_d1;
	delete reader_d2;



	//Работа с объектами класса Publishing
	cout << "\n\n\n\nРабота со объектами класса Publishing\n";

	//Статические переменные
	Publishing publishing_st,	//Создание через конструктор без параметров
		publishing_st1("Издательство №2", "г. Барнаул");		//Создание через конструктор с параметрами

	//Динамические переменные
	Publishing* publishing_d, * publishing_d1;
	publishing_d = new Publishing();	//Создание через конструктор без параметров
	publishing_d1 = new Publishing("Мир", "г. Томск");		//Создание через конструктор с параметрами

	//Печать созданных объектов
	cout << "\nПечать данных статических объектов\npublishing_st = " << publishing_st;
	cout << "\npublishing_st1 = " << publishing_st1;
	cout << "\n";

	cout << "\nПечать данных динамических объектов\n*publishing_d = " << *publishing_d;
	cout << "\n*publishing_d1 = " << *publishing_d1;
	cout << "\n";

	//Ввод значений всех полей объекта
	cout << "\nВвод значений всех полей объекта (передача и возврат по указателю)\n";

	InOut::Read(&publishing_st);
	cout << "\npublishing_st = " << publishing_st;
	cout << "\n\n";

	InOut::Read(publishing_d);
	cout << "\n*publishing_d = " << *publishing_d;

	cout << "\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n";

	InOut::Read(publishing_st);
	cout << "\npublishing_st = " << publishing_st;
	cout << "\n\n";

	InOut::Read(*publishing_d);
	cout << "\n*publishing_d = " << *publishing_d;

	//Инициализация значений
	cout << "\n\nИнициализация значений";
	publishing_st.Init("Паркер", "г. Вашингтон");
	cout << "\npublishing_st = " << publishing_st;

	publishing_d->Init("Старт", "г. Ростов");
	cout << "\n*publishing_d = " << *publishing_d;

	//Проверка находится ли издательство в заданном городе
	cout << "\n\nПроверка находится ли издательство в заданном городе\n" << publishing_st;
	cout << " и г. Москва";
	if (publishing_st.IsHere("г. Москва"))
		cout << ": да.\n";
	else
		cout << ": нет.\n";

	cout << *publishing_d;
	cout << " и г. Барнаул";
	if (publishing_d->IsHere("г. Барнаул"))
		cout << ": да.";
	else
		cout << ": нет.";

	delete publishing_d;
	delete publishing_d1;



	//Работа с объектами класса Book
	cout << "\n\n\n\nРабота со объектами класса Book\n";

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
	cout << "\nПечать данных статических объектов\nbook_st " << book_st;
	cout << "\n\nbook_st1 " << book_st1;
	cout << "\n\nbook_st2 " << book_st2;
	cout << "\n";

	cout << "\nПечать данных динамических объектов\n*book_d " << *book_d;
	cout << "\n\n*book_d1 " << *book_d1;
	cout << "\n\n*book_d2 " << *book_d2;
	cout << "\n";

	//Ввод значений всех полей объекта
	cout << "\nВвод значений всех полей объекта (передача и возврат по указателю)\n";

	InOut::Read(&book_st);
	cout << "\n\nbook_st " << book_st;
	cout << "\n\n";

	InOut::Read(book_d);
	cout << "\n\n*book_d " << *book_d;

	cout << "\n\nВвод значений всех полей объекта (передача и возврат по ссылке)\n";

	InOut::Read(book_st);
	cout << "\n\nbook_st " << book_st;
	cout << "\n\n";

	InOut::Read(*book_d);
	cout << "\n\n*book_d " << *book_d;

	//Инициализация значений
	cout << "\n\nИнициализация значений";
	book_st.Init("Петька и Кот", author_st2, 65, "Ужасы", publishing_st, 2005);
	cout << "\nbook_st " << book_st;

	book_d->Init("Наш мир", author_st1, 1021, "Энциклопедия", &reader_st, publishing_st1, 2013);
	cout << "\n\n*book_d " << *book_d;

	//Привязка читателя
	cout << "\n\nПривязка читателя\nbook_st1 ";
	book_st1.AddReader(&reader_st);
	cout << book_st1;

	//Сравнение читателей книг
	cout << "\n\nСравнение читателей книг\n" << book_st2;
	cout << "\n\nи \n\n" << book_st1;
	if (book_st2.CmpReader(book_st1))
		cout << "\n\nодин и тот же читатель.\n";
	else
		cout << "\n\nразные читатели.\n\n";

	cout << *book_d;
	cout << "\n\nи \n\n" << book_st1;
	if (book_d->CmpReader(book_st1))
		cout << "\n\nодин и тот же читатель.\n";
	else
		cout << "\n\nразные читатели.\n";

	cout << "\n\nbook_st1\n" << book_st1;
	cout << "\n\nbooki - глубокая копия book_st1\n";
	Book booki(book_st1);	//Конструктор копирования - глубокое копирование
	cout << booki;
	cout << "\n\nbook_d2 - мелкая копия book_st1\n";
	*book_d2 = book_st1;	//Мелкое копирование
	cout << *book_d2;

	reader_st.Init("Тумбочкина Татьяна Леонидовна", date_st, address_st, 1234567890);
	cout << "\n\nbooki - глубокая копия book_st1 после изменения данных о читателе не изменяется\n" << booki;
	cout << "\n\nbook_d2 - мелкая копия book_st1 после изменения данных о читателе изменяется\n" << *book_d2;


	//Проверка принадлежности книги читателю
	cout << "\n\nПроверка принадлежности книги читателю\n" << book_st1;
	cout << "\n\nи читатель:\n\n" << reader_st;
	if (book_st1.Belongs(&reader_st))
		cout << "\n\nкнига принадлежит читателю.\n\n";
	else
		cout << "\n\nкнига не принадлежит читателю.\n\n";

	cout << book_st1;
	cout << "\n\nи читатель:\n\n" << reader_st1;
	if (book_st1.Belongs(&reader_st1))
		cout << "\n\nкнига принадлежит читателю.\n";
	else
		cout << "\n\nкнига не принадлежит читателю.\n\n";

	//Отвязка читателя
	cout << "\n\nОтвязка читателя\nbook_st1 ";
	book_st1.AddReader(NULL);
	cout << book_st1;

	//Всего книг в библиотеке
	cout << "\n\nКниг в бибилиотеке: " << Book::GetCounter();
	cout << "\n\nНажмите любую клавишу для продолжения...";
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
	cout << "books_mas1[0]\n" << *books_mas1;
	cout << "\n\n" << books_mas1[0];
	cout << "\n\n\n";

	cout << "\nbooks_mas1[1]\n" << *(books_mas1 + 1);
	cout << "\n\n";

	//Второй массив
	//Следующие выражения равносильны
	cout << "\n*books_mas2[0]\n" << **(books_mas2);
	cout << "\n\n" << *books_mas2[0];
	cout << "\n\n";

	cout << "\n*books_mas2[1]\n" << *books_mas2[1];
	cout << "\n\n";

	//Изменение значений полей объектов
	books_mas1[1].Init("Книга 1", author_st, 10, "Объект динамического массива", publishing_st, 2021);
	books_mas2[1]->Init("Книга 2", author_st1, 10, "Динамический объект массива", publishing_st1, 2021);

	//Вывод объектов

	//Элемент первого массива
	//Следующие выражения равносильны
	cout << "\nbooks_mas1[1]\n" << *(books_mas1 + 1);
	cout << "\n\n"<< books_mas1[1];
	cout << "\n\n\n";

	//Следующие выражения равносильны
	cout << "\n*books_mas2[1]\n" << **(books_mas2 + 1);
	cout << "\n\n" << *books_mas2[1];
	cout << "\n\n";

	cout << "\n\nКниг в бибилиотеке: " << Book::GetCounter();
	cout << "\n\nНажмите любую клавишу для продолжения...";
	_getch();
	system("cls");

	Book kniga;
	cout << "Книг в библиотеке: " << Book::GetCounter() << "\nВремя, на которое можно брать книги : " << Book::GetTime();
	Book::SetTime(14);
	Book knigi[3] = { Book("Книга 1"), Book("Книга 2"), Book("Книга 3") };
	cout << "Книг в библиотеке: " << Book::GetCounter() << "\nВремя, на которое можно брать книги : " << Book::GetTime();

	Book::BorrowBook(kniga, reader_st, Date::Today());
	InOut::Display(kniga);
	cout << "\n\nКоличество выданных книг читателю reader_st2: " << Book::BorrowBook(knigi, 2, reader_st2, Date::Today()) << "\n\n";
	cout << "\n\nКоличество выданных книг читателю reader_st1: " << Book::BorrowBook(knigi, 3, reader_st1, Date::Today()) << "\n\n";

	for (int i = 0; i < 3; i++)
	{
		cout << "\n\n" << knigi[i];
	}

	delete[] books_mas1;

	for (int i = 0; i < 2; i++)
		delete books_mas2[i];

	delete book_d;
	delete book_d1;
	delete book_d2;

	cout << "\n\nНажмите любую клавишу для продолжения...";
	_getch();
	system("cls");

	//Работа с одномерным массивом
	Book odnm_mas[3] = { Book("Книга 1"), Book("Книга 2"), Book("Книга 3") };
	cout << "Работа с одномерным массивом\nКниг в библиотеке: " << Book::GetCounter();

	for (int i = 0; i < 3; i++)
	{
		cout << "\n\nodnm_mas[" << i << "] " << odnm_mas[i];
	}

	cout << "\n\nВведите индекс элемента массива для ввода: ";
	int k, d;
	do
	{
		k = _getch();
		k -= 48;
	} while (k < 0 || k > 2);

	cout << k << "\n\nВвод информации о книге odnm_mas[" << k << "]\n";
	InOut::Read(odnm_mas[k]);

	cout << "\n\nodnm_mas[" << k << "] " << odnm_mas[k];

	//Работа с двумерным массивом
	Book dvum_mas[2][2] = { {Book("Книга 1.1"), Book("Книга 1.2")}, {Book("Книга 2.1"), Book("Книга 2.2")} };
	cout << "Работа с двумерным массивом\nКниг в библиотеке: ", Book::GetCounter();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "\n\ndvum_mas[" << i << "][" << j << "] " << dvum_mas[i][j];
		}
	}

	cout << "\n\nВведите номер строки двумерного массива: ";
	do
	{
		k = _getch();
		k -= 48;
	} while (k < 0 || k > 1);
	cout << k;

	cout << "\n\nВведите номер столбца двумерного массива: ";
	do
	{
		d = _getch();
		d -= 48;
	} while (d < 0 || d > 1);

	cout << d << "\n\nВвод информации о книге dvum_mas[" << k << "][" << d << "]\n";
	InOut::Read(dvum_mas[k][d]);

	cout << "\n\ndvum_mas[" << k << "][" << d << "] " << dvum_mas[k][d];

	Date fdate(28, 11, 2001);
	Address faddress;
	Reader freader("Шишкова Валентина Алексеевна", fdate, faddress, 123456789);
	Author fauthor("Сьюэлл Анна", date_st, "Великобритания");
	Publishing fpublishing;

	ForeignBook fbook("Good Morning", fauthor, 345, "Фантастика", &freader, fpublishing, 2021, "Английский"), fbook1(fbook), fbook2;

	cout << "\n\nfbook " << fbook;
	cout << "\n\nfbook1 " << fbook1;
	cout << "\n\nfbook2 " << fbook2;

	fbook2.Init("Black Beauty", fauthor, 289, "Рассказы", publishing_st, 2019, "Английский");
	fbook1.Init("Fahrenheit 1", author_st, 451, "Фантастика", &freader, publishing_st, 2013, "Английский");

	cout << "\n\nfbook1 " << fbook1;
	cout << "\n\nfbook2 " << fbook2;

	fbook1 = book_st;
	cout << "\n\nfbook1 " << fbook1;
	return 0;
}