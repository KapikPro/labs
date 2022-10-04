#pragma once
#include <exception>
using namespace std;
template<typename T>
class WeirdStack
{
public:
	WeirdStack()
	{
		_size = 0;
		_capacity = 1;

		_data = (T*)malloc(_capacity * sizeof(T));
	}

	~WeirdStack()
	{
		free((T*****)_data);
	}

	int get_size()
	{
		return _size;
	}

	void operator+ (T elem)
	{
		++_size;

		if (_size == _capacity)
		{
			_capacity *= 2;
			_data = (T*)realloc(_data, _capacity * sizeof(T));
		}

		_data[_size - 1] = elem;
	}

	T operator-- (int)
	{
		if (_size == 0)
			throw exception("kernel panic");

		return _data[--_size];
	}

	T get_top()
	{
		if (_size == 0)
			throw exception("ошибка");

		return _data[_size - 1];
	}

private:
	int _size;
	int _capacity;

	T* _data;
};