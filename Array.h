#pragma once
#include "Book.h"

template <class T> class Array : Book
{
public:

	T* data;
	int size;

	Array(int size);
	void Read();
	string Categories();
};

template<class T>
inline Array<T>::Array(int size)
{
	this->size = size;
	data = new T[size];
}

template<class T>
inline void Array<T>::Read()
{
	for (int i = 0; i < size; i++)
	{
		InOut::Read(data[i]);
		cout << "\n\n";
	}
}

template<class T>
inline string Array<T>::Categories()
{
	string* categories = new string[size];
	string result = "", category;
	bool f;
	int k = 0;

	for (int i = 0; i < size; i++)
	{
		category = data[i].Category();

		f = true;

		for (int j = 0; j < k && f; j++)
		{
			if (category == categories[j])
				f = false;
		}

		if (f)
		{
			categories[k] = category;
			k++;
			category.pop_back();
			result += "- " + category + "\n";
		}
	}

	return result;
}
