#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

template<typename T>
T str_to(string h)
{
	stringstream a;
	T ch;
	a << h;
	a >> ch;
	return ch;
}

bool is_int(string str)
{
	for (int c = 0; c < str.size(); c++)
		if (c == 0 && str[c] == '-')
			continue;
		else
			if ((str[c] < '0' || str[c] > '9'))
				return false;
	return true;
}

bool is_double(string str)
{
	int k = 0;
	for (int c = 0; c < str.size(); c++)
		if (c == 0 && str[c] == '-')
			continue;
		else
			if (c == '.' && k == 0)
				k++;
			else
				if (c == '.' && k != 0)
					return false;
				else
			if ((str[c] < '0' || str[c] > '9'))
				return false;
	return true;
}

bool is_float(string str)
{
	int k = 0;
	for (int c = 0; c < str.size(); c++)
		if (c == 0 && str[c] == '-')
			continue;
		else
			if (c == '.' && k == 0)
				k++;
			else
				if (c == '.' && k != 0)
					return false;
				else
					if ((str[c] < '0' || str[c] > '9'))
						return false;
	return true;
}
bool try_read_int(int& val)
{
	string buf;
	cin >> buf;

	if (buf.size() > 9 || !is_int(buf))
		return 0;

	val = str_to<int>(buf);
	return 1;
}

bool try_read_double(double& val)
{
	string buf;
	cin >> buf;

	if (buf.size() > 9 || !is_double(buf))
		return 0;

	val = str_to<double>(buf);
	return 1;
}
bool try_read_float(float& val)
{
	string buf;
	cin >> buf;

	if (buf.size() > 9 || !is_float(buf))
		return 0;

	val = str_to<float>(buf);
	return 1;
}
template<typename T>
void output(T* begin, T* end)
{
	for (T* i = begin; i != end; i++)
		cout << *i << " ";
	cout << endl;
}