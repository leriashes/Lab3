#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "InOut.h"
#include "Book.h"

void InOut::Read(Address* address)
{
	printf("Введите название населённого пункта (например: г. Барнаул): ");

	char letter;
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			address->city[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			address->city[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nВведите название улицы (например: ул. Попова): ");
	for (int i = 0; i < 40; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			address->street[i] = '\0';
			i = 40;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 39)
		{
			address->street[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	char result[5];
	printf("\nВведите номер дома: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	address->house = 0;
	for (int i = 0; result[i] != '\0'; i++)
		address->house = address->house * 10 + result[i] - 48;

	printf("\nВведите номер квартиры: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	address->flat = 0;
	for (int i = 0; result[i] != '\0'; i++)
		address->flat = address->flat * 10 + result[i] - 48;

	return;
}

void InOut::Read(Author* author)
{
	printf("Введите ФИО автора: ");

	char letter;
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			author->full_name[i] = '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			author->full_name[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nДата рождения\n");
	author->birth.ReadDate();

	printf("\nВведите страну происхождения автора: ");
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			author->country[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			author->country[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

void InOut::Read(Book* book)
{
	printf("Введите название книги: ");

	char letter;
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			book->title[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			book->title[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}


	printf("\n");
	Read(&book->author);


	printf("\nВведите количество страниц в книге: ");
	char result[5];
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	book->pages_number = 0;
	for (int i = 0; result[i] != '\0'; i++)
		book->pages_number = book->pages_number * 10 + result[i] - 48;


	printf("\nВведите жанр: ");

	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			book->genre[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			book->genre[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\n");
	Read(&book->publishing);


	printf("\nВведите год издания книги: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result[i] = '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result[i] = letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	book->publ_year = 0;
	for (int i = 0; result[i] != '\0'; i++)
		book->publ_year = book->publ_year * 10 + result[i] - 48;

	return;
}

void InOut::Read(Date* date)
{
	date->ReadTime();
	printf("\n");
	date->ReadDate();

	return;
}

void InOut::Read(Publishing* publishing)
{
	printf("Введите название издательства: ");

	char letter;
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			publishing->name[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			publishing->name[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nВведите населённый пункт, в котором находится издательство (например: г. Барнаул): ");

	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			publishing->city[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			publishing->city[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

void InOut::Read(Reader* reader)
{
	printf("Введите ФИО читателя: ");

	char letter;
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			reader->full_name[i] = '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			reader->full_name[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nДата рождения\n");
	reader->birth.ReadDate();

	printf("\nАдрес проживания\n");
	Read(&reader->address);

	printf("\nВведите номер документа, удостовряющего личность: ");
	for (int i = 0; i < 26; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			reader->doc_number[i] = '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			reader->doc_number[i] = letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

void InOut::Display(Address address)
{
	printf("%s, %s %d, %d", address.city, address.street, address.house, address.flat);
	return;
}

void InOut::Display(Author author, const char* format)
{
	char form[][21] = { "FullName", "FullName (Country)", "FullName (BirthDate)", "all" };
	int f = 1;

	printf("%s ", author.full_name);

	for (int i = 0; i < 4 && f; i++)
	{
		if (strcmp(format, form[i]) == 0)
		{
			if (i == 1)
				printf("(%s)", author.country);
			else if (i == 2)
			{
				printf("(");
				Display(author.birth, "DD.MM.YYYY");
				printf(")");
			}

			if (i < 3)
				i = 4;
		}

		if (i == 3)
			f = 0;
	}

	if (!f)
	{
		printf("(");
		Display(author.birth, "DD.MM.YYYY");
		printf(", %s)", author.country);
	}

	return;
}

void InOut::Display(Book book)
{
	printf("Название: \"%s\"", book.title);
	printf("\nЖанр: %s", book.genre);
	printf("\nКоличество страниц: %d", book.pages_number);
	printf("\nГод публикации: %d", book.publ_year);
	printf("\nАвтор: ");
	Display(book.author, "FullName");
	printf("\nИздательство: ");
	Display(book.publishing);
	if (book.reader != NULL) {
		printf("\nЧитатель: ");
		Display(*book.reader, "[DocNumber] FullName");
	}

	return;
}

void InOut::Display(Date date, const char* format)
{
	char form[][16] = { "hh:mm:ss", "hh:mm", "mm:ss", "DD.MM.YYYY", "DD/MM/YYYY", "MM.DD.YYYY", "DD-MM-YYYY", "YYYY-MM-DD", "CompareResult", "CompareResultRU", "all" };
	int f = 1;
	for (int i = 0; i < 11 && f; i++)
	{
		if (strcmp(format, form[i]) == 0)
		{
			if (i == 0)
				printf("%02d:%02d:%02d", date.hour, date.min, date.sec);
			else if (i == 1)
				printf("%02d:%02d", date.hour, date.min);
			else if (i == 2)
				printf("%02d:%02d", date.min, date.sec);
			else if (i == 3)
				printf("%02d.%02d.%04d", date.day, date.month, date.year);
			else if (i == 4)
				printf("%02d/%02d/%04d", date.day, date.month, date.year);
			else if (i == 5)
				printf("%02d.%02d.%04d", date.month, date.day, date.year);
			else if (i == 6)
				printf("%02d-%02d-%04d", date.day, date.month, date.year);
			else if (i == 7)
				printf("%04d-%02d-%02d", date.year, date.month, date.day);
			else if (i == 8)
			{
				int k = 0;

				if (date.year > 0)
				{
					if (date.year > 1)
						printf("%d years ", date.year);
					else
						printf("%d year ", date.year);
					k++;
				}

				if (date.day > 0)
				{
					if (date.day > 1)
						printf("%d days ", date.day);
					else
						printf("%d day ", date.day);
					k++;
				}

				if (date.hour > 0)
				{
					if (date.hour > 1)
						printf("%d hours ", date.hour);
					else
						printf("%d hour ", date.hour);
					k++;
				}

				if (date.min > 0)
				{
					if (date.min > 1)
						printf("%d minutes ", date.min);
					else
						printf("%d minute ", date.min);
					k++;
				}

				if (date.sec > 0)
				{
					if (date.sec > 1)
						printf("%d seconds ", date.sec);
					else
						printf("%d second ", date.sec);
					k++;
				}

				if (k == 0)
					printf("The time has already come. ");
			}
			else if (i == 9)
			{
				int k = 0;

				if (date.year > 0)
				{
					printf("%d ", date.year);
					if (date.year % 10 == 1 && date.year % 100 != 11)
						printf("год ");
					else if (date.year % 10 >= 2 && date.year % 10 <= 4 && (date.year % 100 < 12 || date.year % 100 > 14))
						printf("года ");
					else
						printf("лет ");
					k++;
				}

				if (date.day > 0)
				{
					printf("%d ", date.day);
					if (date.day % 10 == 1 && date.day % 100 != 11)
						printf("день ");
					else if (date.day % 10 >= 2 && date.day % 10 <= 4 && (date.day % 100 < 12 || date.day % 100 > 14))
						printf("дня ");
					else
						printf("дней ");
					k++;
				}

				if (date.hour > 0)
				{
					printf("%d ", date.hour);
					if (date.hour % 10 == 1 && date.hour % 100 != 11)
						printf("час ");
					else if (date.hour % 10 >= 2 && date.hour % 10 <= 4 && (date.hour % 100 < 12 || date.hour % 100 > 14))
						printf("часа ");
					else
						printf("часов ");
					k++;
				}

				if (date.min > 0)
				{
					printf("%d ", date.min);
					if (date.min % 10 == 1 && date.min % 100 != 11)
						printf("минута ");
					else if (date.min % 10 >= 2 && date.min % 10 <= 4 && (date.min % 100 < 12 || date.min % 100 > 14))
						printf("минуты ");
					else
						printf("минут ");
					k++;
				}

				if (date.sec > 0)
				{
					printf("%d ", date.sec);
					if (date.sec % 10 == 1 && date.sec % 100 != 11)
						printf("секунда ");
					else if (date.sec % 10 >= 2 && date.sec % 10 <= 4 && (date.sec % 100 < 12 || date.sec % 100 > 14))
						printf("секунды ");
					else
						printf("секунд ");
					k++;
				}

				if (k == 0)
					printf("Это время уже наступило. ");
			}

			if (i < 10)
				i = 11;
		}

		if (i == 10)
			f = 0;
	}

	if (!f)
		printf("%02d:%02d:%02d %02d.%02d.%04d", date.hour, date.min, date.sec, date.day, date.month, date.year);

	return;
}

void InOut::Display(Publishing publishing)
{
	printf("%s (%s)", publishing.name, publishing.city);
	return;
}

void InOut::Display(Reader reader, const char* format)
{
	char form[][21] = { "FullName", "[DocNumber] FullName", "FullName (BirthDate)", "all" };
	int f = 1;

	for (int i = 0; i < 4 && f; i++)
	{
		if (strcmp(format, form[i]) == 0)
		{
			if (i == 0)
				printf("%s ", reader.full_name);
			else if (i == 1)
				printf("[%s] %s ", reader.doc_number, reader.full_name);
			else if (i == 2)
			{
				printf("%s (", reader.full_name);
				Display(reader.birth, "DD.MM.YYYY");
				printf(") ");
			}

			if (i < 3)
				i = 4;
		}

		if (i == 3)
			f = 0;
	}

	if (!f)
	{
		printf("[%s] %s (Дата рождения: ", reader.doc_number, reader.full_name);
		Display(reader.birth, "DD.MM.YYYY");
		printf(". Адрес проживания: ");
		Display(reader.address);
		printf(") ");
	}

	return;
}


