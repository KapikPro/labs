#pragma once
#include <exception>
using namespace std;

class WeirdStack
{
public:
	WeirdStack()
	{
		_size = 0;
		_capacity = 1;

		_data = (int*)malloc(_capacity * sizeof(int));
	}

	~WeirdStack()
	{
		free((int*)_data);
	}

	int get_size()
	{
		return _size;
	}

	void operator++ ()
	{
		++_size;
		int one = 1;
		if (_size == _capacity)
		{
			_capacity *= 2;
			_data = (int*)realloc(_data, _capacity * sizeof(int));
		}

		_data[_size - 1] = one;

	}

	void operator-- ()
	{
		if (_size == 0)
			throw exception("ошибка, обьем равен 0");

		--_size;

	}

	int get_top()
	{
		if (_size == 0)
			throw exception("ошибка");

		return _data[_size - 1];
	}

private:
	int _size;
	int _capacity;
	int* _data;
};