#include "ForeignBook.h"

//�����������
ForeignBook::ForeignBook()
{
	language = "��������";
}

//����������� � ����������
ForeignBook::ForeignBook(string language)
{
	this->language = language;
}


//����������� � ����������
ForeignBook::ForeignBook(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year, string language) : Book(title, author, pages_number, genre, publishing, publication_year)
{
	this->language = language;
}

//����������� � ����������
ForeignBook::ForeignBook(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year, string language) : Book(title, author, pages_number, genre, reader, publishing, publication_year)
{
	this->language = language;
}

//����������� �����������
ForeignBook::ForeignBook(const ForeignBook& source)
{
	title = source.title;
	author = source.author;
	pages_number = source.pages_number;
	genre = source.genre;

	if (source.reader != NULL)
	{
		reader = new Reader;
		*reader = *source.reader;
		borrow_date = source.borrow_date;
	}

	publishing = source.publishing;
	publ_year = source.publ_year;
	language = source.language;
	id = source.id;
}

ForeignBook::~ForeignBook()
{
}

void ForeignBook::Init(string title, Author author, int pages_number, string genre, Publishing publishing, int publication_year, string language)
{
	this->title = title;
	this->author = author;
	this->pages_number = abs(pages_number);
	this->genre = genre;
	this->publishing = publishing;
	this->publ_year = abs(publication_year);
	this->language = language;

	return;
}

void ForeignBook::Init(string title, Author author, int pages_number, string genre, Reader* reader, Publishing publishing, int publication_year, string language)
{
	this->Book::Init(title, author, pages_number, genre, reader, publishing, publication_year);
	this->language = language;

	return;
}

void ForeignBook::operator=(Book source)
{
	if (this != &source)
	{
		title = source.GetTitle();
		author = source.GetAuthor();
		pages_number = source.GetPagesNumber();
		genre = source.GetGenre();

		if (source.GetReader() != NULL)
		{
			reader = source.GetReader();
			borrow_date = source.GetBorrowDate();
		}

		publishing = source.GetPublishing();
		publ_year = source.GetPublicationYear();
		id = source.GetID(); 
	}

	return;
}
 