#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

long str_to_long(string h)
{
	stringstream a;
	long ch;
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
bool try_read_int(long &val)
{
	string s;
	cin >> s;

	if (s.size() > 18 || !is_int(s))
		return 0;

	val = str_to_long(s);
	return 1;
}
