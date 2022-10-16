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
	for (auto c : str)
		if (c < '0' || c > '9')
			return false;
	return true;
}

bool is_double(string str)
{
	int k = 0;
	for (auto c : str)
		if (c == '.' && k == 0)
			k++;
		else
			if (c == '.' && k != 0)
				return false;
			else
		if (c < '0' || c > '9')
			return false;
	return true;
}

bool try_read_int(int& val)
{
	string buf;
	cin >> buf;

	if (buf.size() > 9 || !is_int(buf))
		return 0;

	val = str_to<double>(buf);
	return 1;
}

template<typename T>
void output(T* begin, T* end)
{
	for (t* i = begin; i != end; i++)
		cout << *i << " ";
	cout << endl;
}