#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include "InOut.h"
#include "Book.h"

void InOut::Read(Address* address)
{
	printf("������� �������� ���������� ������ (��������: �. �������): ");
	while (InpStr(address->city, 50));

	printf("\n������� �������� ����� (��������: ��. ������): ");
	while (InpStr(address->street, 50));

	char letter;
	string result;
	printf("\n������� ����� ����: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r' && i > 0)
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
		if (letter == '\r' && i > 0)
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
	while (InpStr(author->full_name, 50));

	printf("\n���� ��������\n");
	author->birth.ReadDate();

	printf("\n������� ������ ������������� ������: ");
	while (InpStr(author->country, 50)); 

	return;
}

void InOut::Read(Book* book)
{
	printf("������� �������� �����: ");
	while (InpStr(book->title, 50));

	printf("\n");
	Read(book->author);

	printf("\n������� ���������� ������� � �����: ");
	char letter;
	string result;
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r' && i > 0)
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
	while (InpStr(book->genre, 30));

	printf("\n");
	Read(book->publishing);

	printf("\n������� ��� ������� �����: ");
	result.clear();
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r' && i > 0)
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
	while (InpStr(publishing->name, 50));

	printf("\n������� ��������� �����, � ������� ��������� ������������ (��������: �. �������): ");
	while (InpStr(publishing->city, 50));

	return;
}

void InOut::Read(Reader* reader)
{
	printf("������� ��� ��������: ");
	while (InpStr(reader->full_name, 50));

	printf("\n���� ��������\n");
	reader->birth.ReadDate();

	printf("\n����� ����������\n");
	Read(reader->address);

	printf("\n������� ����� ���������, �������������� ��������: ");
	while (InpStr(reader->doc_number, 26));

	return;
}



void InOut::Read(Address& address)
{
	printf("������� �������� ���������� ������ (��������: �. �������): ");
	while (InpStr(address.city, 50));

	printf("\n������� �������� ����� (��������: ��. ������): ");
	while (InpStr(address.street, 50));

	char letter;
	string result;
	printf("\n������� ����� ����: ");
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r' && i > 0)
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
		if (letter == '\r' && i > 0)
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
	while (InpStr(author.full_name, 50));

	printf("\n���� ��������\n");
	author.birth.ReadDate();

	printf("\n������� ������ ������������� ������: ");
	while (InpStr(author.country, 50));

	return;
}

void InOut::Read(Book& book)
{
	printf("������� �������� �����: ");
	while (InpStr(book.title, 50));

	printf("\n");
	Read(book.author);

	printf("\n������� ���������� ������� � �����: ");
	char letter;
	string result;
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r' && i > 0)
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
	while (InpStr(book.genre, 30));

	printf("\n");
	Read(book.publishing);


	printf("\n������� ��� ������� �����: ");
	result.clear();
	for (int i = 0; i < 5; i++)
	{
		letter = _getch();
		if (letter == '\r' && i > 0)
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
	while (InpStr(publishing.name, 50));

	printf("\n������� ��������� �����, � ������� ��������� ������������ (��������: �. �������): ");
	while (InpStr(publishing.city, 50));

	return;
}

void InOut::Read(Reader& reader)
{
	printf("������� ��� ��������: ");
	while (InpStr(reader.full_name, 50));

	printf("\n���� ��������\n");
	reader.birth.ReadDate();

	printf("\n����� ����������\n");
	Read(reader.address);

	printf("\n������� ����� ���������, �������������� ��������: ");
	while (InpStr(reader.doc_number, 26));

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
		printf("\n���� ������ �����: ");
		Display(book.borrow_date, "DD.MM.YYYY");
		printf("\n���� ����� �����: ");
		Date plus(Book::time, 0, 0);
		Display(book.borrow_date + plus, "DD.MM.YYYY");
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


int InOut::InpStr(string& str, int max_len)
{
	int result = 0;
	char letter;
	str.clear();

	for (int i = 0; i < max_len; i++)
	{
		letter = _getch();
		if (letter == '\r' && i > 0)
		{
			str += '\0';
			i = 50;
		}
		else if (letter == '\b' && i > 0)
		{
			str.pop_back();
			i -= 2;
			printf("\b \b");
		}
		else if (letter != '\r' && letter != '\b' && i < max_len - 1)
		{
			str += letter;
			printf("%c", letter);
		}
		else
			i--;
	}

	try
	{
		for (int i = 0; i < str.size() - 1; i++)
		{
			if (str.compare(i, 1, " ") == 0)
			{
				if (i == 0 || i < str.size() - 2 && str.compare(i + 1, 1, " ") == 0 || i == str.size() - 2)
				{
					str.erase(i, 1); 
					i--;
				}
			}
		}

		if (str.size() == 1)
			throw "������� ������ ������.";
	}
	catch (const char* exception)
	{
		cerr << "\n������: " << exception;
		cout << "\n��������� ����: ";
		result = 1;
	}

	return result;
}

