#pragma once
#include <vector>
#include <exception> 
#include <algorithm>
#include <cmath>
#include <iostream> 

class Room
{
public:
	Room(double length, double width, double height, int windows_count = 0)
	{

		_length = length;
		_width = width;
		_height = height;

		_windows_count = windows_count;
	}

	double get_length()
	{
		return _length;
	}

	double get_width()
	{
		return _width;
	}

	double get_height()
	{
		return _height;
	}

	int get_windows_count()
	{
		return _windows_count;
	}

	double get_area()
	{
		return _length * _width;
	}

	double get_volume()
	{
		return _length * _width * _height;
	}

	double get_window_area()
	{
		return 0.25 * _height * std::min(_width, _length);

	}

private:
	double _length;
	double _width;
	double _height;

	int _windows_count;
};