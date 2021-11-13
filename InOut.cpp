#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include "InOut.h"
#include "Book.h"

void InOut::Read(Address* address)
{
	printf("Введите название населённого пункта (например: г. Барнаул): ");

	char letter;
	address->city.clear();

	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			address->city += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			address->city.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			address->city += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nВведите название улицы (например: ул. Попова): ");
	address->street.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			address->street += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			address->street.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			address->street += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	string result;
	printf("\nВведите номер дома: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else
			i--;
	}

	address->house = stoi(result);
	result.clear();

	printf("\nВведите номер квартиры: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else
			i--;
	}

	address->flat = stoi(result);

	return;
}

void InOut::Read(Author* author)
{
	printf("Введите ФИО автора: ");

	char letter;
	author->full_name.clear();

	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			author->full_name += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			author->full_name.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			author->full_name += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nДата рождения\n");
	author->birth.ReadDate();

	printf("\nВведите страну происхождения автора: ");
	author->country.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			author->country += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			author->country.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			author->country += letter;
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
	book->title.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			book->title += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			book->title.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			book->title += letter;
			printf("%c", letter);
		}
		else
			i--;
	}


	printf("\n");
	Read(&book->author);


	printf("\nВведите количество страниц в книге: ");
	string result;
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	book->pages_number = stoi(result);


	printf("\nВведите жанр: ");
	book->genre.clear();
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			book->genre += '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			book->genre.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			book->genre += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\n");
	Read(&book->publishing);


	printf("\nВведите год издания книги: ");
	result.clear();
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else
			i--;
	}

	book->publ_year = stoi(result);

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
	publishing->name.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			publishing->name += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			publishing->name.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			publishing->name += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nВведите населённый пункт, в котором находится издательство (например: г. Барнаул): ");

	publishing->city.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			publishing->city += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			publishing->city.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			publishing->city += letter;
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
	reader->full_name.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			reader->full_name += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			reader->full_name.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			reader->full_name += letter;
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
	reader->doc_number.clear();
	for (int i = 0; i < 26; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			reader->doc_number += '\0';
			i = 26;
		}
		else if (letter == '\b' && i > 0)
		{
			reader->doc_number.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 25)
		{
			reader->doc_number += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}



void InOut::Read(Address& address)
{
	printf("Введите название населённого пункта (например: г. Барнаул): ");

	char letter;
	address.city.clear();

	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			address.city += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			address.city.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			address.city += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nВведите название улицы (например: ул. Попова): ");
	address.street.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			address.street += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			address.street.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			address.street += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	string result;
	printf("\nВведите номер дома: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else
			i--;
	}

	address.house = stoi(result);
	result.clear();

	printf("\nВведите номер квартиры: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else
			i--;
	}

	address.flat = stoi(result);

	return;
}

void InOut::Read(Author& author)
{
	printf("Введите ФИО автора: ");

	char letter;
	author.full_name.clear();

	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			author.full_name += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			author.full_name.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			author.full_name += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nДата рождения\n");
	author.birth.ReadDate();

	printf("\nВведите страну происхождения автора: ");
	author.country.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			author.country += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			author.country.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			author.country += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

void InOut::Read(Book& book)
{
	printf("Введите название книги: ");

	char letter;
	book.title.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			book.title += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			book.title.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			book.title += letter;
			printf("%c", letter);
		}
		else
			i--;
	}


	printf("\n");
	Read(book.author);


	printf("\nВведите количество страниц в книге: ");
	string result;
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");

		}
		else
			i--;
	}

	book.pages_number = stoi(result);


	printf("\nВведите жанр: ");
	book.genre.clear();
	for (int i = 0; i < 30; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			book.genre += '\0';
			i = 30;
		}
		else if (letter == '\b' && i > 0)
		{
			book.genre.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 29)
		{
			book.genre += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\n");
	Read(book.publishing);


	printf("\nВведите год издания книги: ");
	result.clear();
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			result += '\0';
			i = 5;
		}
		else if (letter >= '0' && letter <= '9' && (i == 0 && letter != '0' || i > 0 && i < 4))
		{
			result += letter;
			printf("%c", letter);
		}
		else if (letter == '\b' && i > 0)
		{
			result.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else
			i--;
	}

	book.publ_year = stoi(result);

	return;
}

void InOut::Read(Date& date)
{
	date.ReadTime();
	printf("\n");
	date.ReadDate();

	return;
}

void InOut::Read(Publishing& publishing)
{
	printf("Введите название издательства: ");

	char letter;
	publishing.name.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			publishing.name += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			publishing.name.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			publishing.name += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nВведите населённый пункт, в котором находится издательство (например: г. Барнаул): ");

	publishing.city.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			publishing.city += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			publishing.city.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			publishing.city += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}

void InOut::Read(Reader& reader)
{
	printf("Введите ФИО читателя: ");

	char letter;
	reader.full_name.clear();
	for (int i = 0; i < 50; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			reader.full_name += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			reader.full_name.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 49)
		{
			reader.full_name += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	printf("\nДата рождения\n");
	reader.birth.ReadDate();

	printf("\nАдрес проживания\n");
	Read(reader.address);

	printf("\nВведите номер документа, удостовряющего личность: ");
	reader.doc_number.clear();
	for (int i = 0; i < 26; i++)
	{
		letter = _getch();
		if (letter == '\r')
		{
			reader.doc_number += '\0';
			i = 26;
		}
		else if (letter == '\b' && i > 0)
		{
			reader.doc_number.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\b' && i < 25)
		{
			reader.doc_number += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	return;
}



void InOut::Display(Address address)
{
	cout << address.city + ", " + address.street;
	printf(" %d, %d", address.house, address.flat);
	return;
}

void InOut::Display(Author author, const char* format)
{
	char form[][21] = { "FullName", "FullName (Country)", "FullName (BirthDate)", "all" };
	int f = 1;

	cout << author.full_name;

	for (int i = 0; i < 4 && f; i++)
	{
		if (strcmp(format, form[i]) == 0)
		{
			if (i == 1)
				cout << " (" + author.country + ")";
			else if (i == 2)
			{
				printf(" (");
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
		printf(" (");
		Display(author.birth, "DD.MM.YYYY");
		cout << ", " + author.country + ")";
	}

	return;
}

void InOut::Display(Book book)
{
	printf("ID %d", book.id);
	cout << "\nНазвание: \"" + book.title + "\"";
	cout << "\nЖанр: " + book.genre;
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
	cout << publishing.name + " (" + publishing.city + ")";
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
				cout << reader.full_name + " ";
			else if (i == 1)
				cout << "[" + reader.doc_number + "] "+ reader.full_name + " ";
			else if (i == 2)
			{
				cout << reader.full_name + " (";
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
		cout << "[" + reader.doc_number + "] " + reader.full_name + " (Дата рождения: ";
		Display(reader.birth, "DD.MM.YYYY");
		printf(". Адрес проживания: ");
		Display(reader.address);
		printf(") ");
	}

	return;
}

