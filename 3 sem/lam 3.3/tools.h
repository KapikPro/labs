#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int str_to_int(string h)
{
	stringstream a;
	int ch;
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

bool try_read_int(int &val)
{
	string buf;
	cin >> buf;

	if (buf.size() > 9 || !is_int(buf))
		return 0;

	val = str_to_int(buf);
	return 1;
}
