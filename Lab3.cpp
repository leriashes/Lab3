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

	/*//Ввод только времени
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
	date_d->Display("all");*/

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
	author_st.Display("all");
	printf("\nauthor_st1 = ");
	author_st1.Display("all");
	printf("\nauthor_st2 = ");
	author_st2.Display("all");
	printf("\n");

	printf("\nПечать данных динамических объектов\n*author_d = ");
	author_d->Display("all");
	printf("\n*author_d1 = ");
	author_d1->Display("all");
	printf("\n*author_d2 = ");
	author_d2->Display("all");
	printf("\n");

	/*//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта\n");

	author_st.Read();
	printf("\nauthor_st = ");
	author_st.Display("all");
	printf("\n\n");

	author_d->Read();
	printf("\n*author_d = ");
	author_d->Display("all");*/

	//Вывод значений полей в выбранном формате
	printf("\n\nВывод значений полей в выбранном формате (помимо полного вывода)\nauthor_st (FullName) = ");
	author_st.Display("FullName");
	printf("\nauthor_st (FullName (Country)) = ");
	author_st.Display("FullName (Country)");
	printf("\nauthor_st (FullName (BirthDate)) = ");
	author_st.Display("FullName (BirthDate)");

	printf("\n\n*author_d (FullName) = ");
	author_d->Display("FullName");
	printf("\n*author_d (FullName (Country)) = ");
	author_d->Display("FullName (Country)");
	printf("\n*author_d (FullName (BirthDate)) = ");
	author_d->Display("FullName (BirthDate)");

	//Инициализация значений
	printf("\n\nИнициализация значений");
	author_st.Init("Паркер Энн", date_st, "США");
	printf("\nauthor_st = ");
	author_st.Display("all");

	author_d->Init("Старикова Татьяна Алексеевна", date_st1, "Россия");
	printf("\n*author_d = ");
	author_d->Display("all");

	//Проверка родился ли автор в заданной стране
	printf("\n\nПроверка родился ли автор в заданной стране\n");
	author_st.Display("all");
	printf(" и страна Россия");
	if (author_st.BornIn("Россия"))
		printf(": да.\n");
	else
		printf(": нет.\n");

	author_d->Display("all");
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
	address_st.Display();
	printf("\naddress_st1 = ");
	address_st1.Display();
	printf("\n");

	printf("\nПечать данных динамических объектов\n*address_d = ");
	address_d->Display();
	printf("\n*address_d1 = ");
	address_d1->Display();
	printf("\n");

	/*//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта\n");

	address_st.Read();
	printf("\naddress_st = ");
	address_st.Display();
	printf("\n\n");

	address_d->Read();
	printf("\n*address_d = ");
	address_d->Display();*/

	//Инициализация значений
	printf("\n\nИнициализация значений");
	address_st.Init("г. Троицк", "ул. Текстильщиков", 6, 2);
	printf("\naddress_st = ");
	address_st.Display();

	address_d->Init("г. Барнаул", "ул. Энтузиастов", 55, 23);
	printf("\n*address_d = ");
	address_d->Display();

	//Проверка совпадения города
	printf("\n\nПроверка родился ли автор в заданной стране\n");
	address_st.Display();
	printf(" и г. Барнаул");
	if (address_st.City("г. Барнаул"))
		printf(": да.\n");
	else
		printf(": нет.\n");

	address_d->Display();
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
	reader_st.Display("all");
	printf("\nreader_st1 = ");
	reader_st1.Display("all");
	printf("\nreader_st2 = ");
	reader_st2.Display("all");
	printf("\n");

	printf("\nПечать данных динамических объектов\n*reader_d = ");
	reader_d->Display("all");
	printf("\n*reader_d1 = ");
	reader_d1->Display("all");
	printf("\n*reader_d2 = ");
	reader_d2->Display("all");
	printf("\n");

	/*//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта\n");

	reader_st.Read();
	printf("\nreader_st = ");
	reader_st.Display("all");
	printf("\n\n");

	reader_d->Read();
	printf("\n*reader_d = ");
	reader_d->Display("all");*/

	//Вывод значений полей в выбранном формате
	printf("\n\nВывод значений полей в выбранном формате (помимо полного вывода)\nreader_st (FullName) = ");
	reader_st.Display("FullName");
	printf("\nreader_st ([DocNumber] FullName) = ");
	reader_st.Display("[DocNumber] FullName");
	printf("\nreader_st (FullName (BirthDate)) = ");
	reader_st.Display("FullName (BirthDate)");

	printf("\n\n*reader_d (FullName) = ");
	reader_d->Display("FullName");
	printf("\n*reader_d ([DocNumber] FullName) = ");
	reader_d->Display("[DocNumber] FullName");
	printf("\n*reader_d (FullName (BirthDate)) = ");
	reader_d->Display("FullName (BirthDate)");

	//Инициализация значений
	printf("\n\nИнициализация значений");
	reader_st.Init("Кузнецов Кирилл Корнеевич", date_st2, address_st, "0112 765423");
	printf("\nreader_st = ");
	reader_st.Display("all");

	reader_d->Init("Кузнецов Тимофей Корнеевич", date_st2, address_st, 0112765423);
	printf("\n*reader_d = ");
	reader_d->Display("all");

	//Проверка является ли дата днём рождения читателя
	printf("\n\nПроверка родился ли автор в заданной стране\n");
	reader_st2.Display("all");
	printf(" и ");
	date_st2.Display("DD.MM.YYYY");
	if (reader_st2.IsBirthday(date_st2))
		printf(": да.\n");
	else
		printf(": нет.\n");

	reader_d1->Display("all");
	printf(" и ");
	date_st2.Display("DD.MM.YYYY");
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
	publishing_st.Display();
	printf("\npublishing_st1 = ");
	publishing_st1.Display();
	printf("\n");

	printf("\nПечать данных динамических объектов\n*publishing_d = ");
	publishing_d->Display();
	printf("\n*publishing_d1 = ");
	publishing_d1->Display();
	printf("\n");

	/*//Ввод значений всех полей объекта
	printf("\nВвод значений всех полей объекта\n");

	publishing_st.Read();
	printf("\npublishing_st = ");
	publishing_st.Display();
	printf("\n\n");

	publishing_d->Read();
	printf("\n*publishing_d = ");
	publishing_d->Display();*/

	//Инициализация значений
	printf("\n\nИнициализация значений");
	publishing_st.Init("Паркер", "г. Вашингтон");
	printf("\npublishing_st = ");
	publishing_st.Display();

	publishing_d->Init("Старт", "г. Ростов");
	printf("\n*publishing_d = ");
	publishing_d->Display();

	//Проверка находится ли издательство в заданном городе
	printf("\n\nПроверка находится ли издательство в заданном городе\n");
	publishing_st.Display();
	printf(" и г. Москва");
	if (publishing_st.IsHere("г. Москва"))
		printf(": да.\n");
	else
		printf(": нет.\n");

	publishing_d->Display();
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
		book_st1("Новый мир", author_st1, 121, "Фантастика", publishing_st1, 2012),
		book_st2("Петька и Васька", author_st2, 76, "Рассказы", publishing_st, 2019);

	//Динамические переменные
	Book* book_d, * book_d1, * book_d2;
	book_d = new Book();	//Создание через конструктор без параметров
	//Создание через конструкторы с параметрами
	book_d1 = new Book("Новый мир", author_st1, 121, "Фантастика", publishing_st1, 2012);
	book_d2 = new Book("Петька и Васька", author_st2, 76, "Рассказы", publishing_st, 2019);

	//Печать созданных объектов
	printf("\nПечать данных статических объектов\nbook_st ");
	book_st.Display();
	printf("\n\nbook_st1 ");
	book_st1.Display();
	printf("\n\nbook_st2 ");
	book_st2.Display();
	printf("\n");

	printf("\nПечать данных динамических объектов\n*book_d ");
	book_d->Display();
	printf("\n\n*book_d1 ");
	book_d1->Display();
	printf("\n\n*book_d2 ");
	book_d2->Display();
	printf("\n");

	//Ввод значений всех полей объекта
	/*printf("\nВвод значений всех полей объекта\n");

	book_st.Read();
	printf("\n\nbook_st ");
	book_st.Display();
	printf("\n\n");

	book_d->Read();
	printf("\n\n*book_d ");
	book_d->Display();*/

	//Инициализация значений
	printf("\n\nИнициализация значений");
	book_st.Init("Петька и Кот", author_st2, 65, "Ужасы", publishing_st, 2005);
	printf("\nbook_st ");
	book_st.Display();

	book_d->Init("Наш мир", author_st1, 1021, "Энциклопедия", &reader_st, publishing_st1, 2013);
	printf("\n\n*book_d ");
	book_d->Display();

	//Привязка читателя
	printf("\n\nПривязка читателя\nbook_st1 ");
	book_st1.AddReader(&reader_st);
	book_st1.Display();
	
	//Сравнение читателей книг
	printf("\n\nСравнение читателей книг\n");
	book_st2.Display();
	printf("\n\nи \n\n");
	book_st1.Display();
	if (book_st2.CmpReader(book_st1))
		printf("\n\nодин и тот же читатель.\n");
	else
		printf("\n\nразные читатели.\n\n");

	book_d->Display();
	printf("\n\nи \n\n");
	book_st1.Display();
	if (book_d->CmpReader(book_st1))
		printf("\n\nодин и тот же читатель.\n");
	else
		printf("\n\nразные читатели.\n");

	//Отвязка читателя
	printf("\n\nОтвязка читателя\nbook_st1 ");
	book_st1.AddReader(NULL);
	book_st1.Display();

	delete book_d;
	delete book_d1;
	delete book_d2;


	return 0;
}