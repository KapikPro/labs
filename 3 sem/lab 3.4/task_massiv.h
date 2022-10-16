#pragma once
#include<algorithm>

#define abs(a) a < 0 ? -a : a 

template<typename T>
int condition_1(T* begin, T* end)
{
	int sum = 0;
	for (T* i = begin; i != end; i++)
		if (*i < 0)
			sum++;
	return sum;
}

template<typename T>
T condition_2(T* begin, T* end)
{
	T sum = 0;
	T min_zn = abs( *begin);
	T* min_uk = begin;
	for (T* i = begin; i != end; i++)
		if (abs(*i) < abs(min_zn))
		{
			min_zn = *i;
			min_uk = i;
		}
	for (T* i = min_uk; i != end; i++)
		if (abs(*i) < 0)
			sum += abs(*i);
	return sum;
}

template<typename T>
void condition_3(T* begin, T* end)
{
	for (T* i = begin; i != end; i++)
		if (*i < 0)
		  *i = *i * (*i);
	sort(begin, end);
}