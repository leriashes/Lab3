#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include "InOut.h"
#include "Book.h"

void InOut::Read(Address* address)
{
	printf("������� �������� ���������� ������ (��������: �. �������): ");

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

	printf("\n������� �������� ����� (��������: ��. ������): ");
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
	printf("\n������� ����� ����: ");
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

	printf("\n������� ����� ��������: ");
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
	printf("������� ��� ������: ");

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

	printf("\n���� ��������\n");
	author->birth.ReadDate();

	printf("\n������� ������ ������������� ������: ");
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
	printf("������� �������� �����: ");

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


	printf("\n������� ���������� ������� � �����: ");
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


	printf("\n������� ����: ");
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


	printf("\n������� ��� ������� �����: ");
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
	printf("������� �������� ������������: ");

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

	printf("\n������� ��������� �����, � ������� ��������� ������������ (��������: �. �������): ");

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
	printf("������� ��� ��������: ");

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

	printf("\n���� ��������\n");
	reader->birth.ReadDate();

	printf("\n����� ����������\n");
	Read(&reader->address);

	printf("\n������� ����� ���������, �������������� ��������: ");
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
	printf("������� �������� ���������� ������ (��������: �. �������): ");

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

	printf("\n������� �������� ����� (��������: ��. ������): ");
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
	printf("\n������� ����� ����: ");
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

	printf("\n������� ����� ��������: ");
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
	printf("������� ��� ������: ");

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

	printf("\n���� ��������\n");
	author.birth.ReadDate();

	printf("\n������� ������ ������������� ������: ");
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
	printf("������� �������� �����: ");

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


	printf("\n������� ���������� ������� � �����: ");
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


	printf("\n������� ����: ");
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


	printf("\n������� ��� ������� �����: ");
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
	printf("������� �������� ������������: ");

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

	printf("\n������� ��������� �����, � ������� ��������� ������������ (��������: �. �������): ");

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
	printf("������� ��� ��������: ");

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

	printf("\n���� ��������\n");
	reader.birth.ReadDate();

	printf("\n����� ����������\n");
	Read(reader.address);

	printf("\n������� ����� ���������, �������������� ��������: ");
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
	cout << "\n��������: \"" + book.title + "\"";
	cout << "\n����: " + book.genre;
	printf("\n���������� �������: %d", book.pages_number);
	printf("\n��� ����������: %d", book.publ_year);
	printf("\n�����: ");
	Display(book.author, "FullName");
	printf("\n������������: ");
	Display(book.publishing);
	if (book.reader != NULL) {
		printf("\n��������: ");
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
						printf("��� ");
					else if (date.year % 10 >= 2 && date.year % 10 <= 4 && (date.year % 100 < 12 || date.year % 100 > 14))
						printf("���� ");
					else
						printf("��� ");
					k++;
				}

				if (date.day > 0)
				{
					printf("%d ", date.day);
					if (date.day % 10 == 1 && date.day % 100 != 11)
						printf("���� ");
					else if (date.day % 10 >= 2 && date.day % 10 <= 4 && (date.day % 100 < 12 || date.day % 100 > 14))
						printf("��� ");
					else
						printf("���� ");
					k++;
				}

				if (date.hour > 0)
				{
					printf("%d ", date.hour);
					if (date.hour % 10 == 1 && date.hour % 100 != 11)
						printf("��� ");
					else if (date.hour % 10 >= 2 && date.hour % 10 <= 4 && (date.hour % 100 < 12 || date.hour % 100 > 14))
						printf("���� ");
					else
						printf("����� ");
					k++;
				}

				if (date.min > 0)
				{
					printf("%d ", date.min);
					if (date.min % 10 == 1 && date.min % 100 != 11)
						printf("������ ");
					else if (date.min % 10 >= 2 && date.min % 10 <= 4 && (date.min % 100 < 12 || date.min % 100 > 14))
						printf("������ ");
					else
						printf("����� ");
					k++;
				}

				if (date.sec > 0)
				{
					printf("%d ", date.sec);
					if (date.sec % 10 == 1 && date.sec % 100 != 11)
						printf("������� ");
					else if (date.sec % 10 >= 2 && date.sec % 10 <= 4 && (date.sec % 100 < 12 || date.sec % 100 > 14))
						printf("������� ");
					else
						printf("������ ");
					k++;
				}

				if (k == 0)
					printf("��� ����� ��� ���������. ");
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
		cout << "[" + reader.doc_number + "] " + reader.full_name + " (���� ��������: ";
		Display(reader.birth, "DD.MM.YYYY");
		printf(". ����� ����������: ");
		Display(reader.address);
		printf(") ");
	}

	return;
}

