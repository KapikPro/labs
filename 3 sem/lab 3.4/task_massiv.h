#pragma once
#include<algorithm>
#include<vector>
#include<cmath>


template<typename T>
int condition_1(vector<T> v)
{
	int sum = 0;
	for (int i = 0; i<v.size(); i++)
		if (v[i] < 0)
			sum++;
	return sum;
}

template<typename T>
T condition_2(vector<T> v)
{
	T sum = 0, m=0;
	T min_zn = abs(v[0]);
	for (int i = 0; i < v.size(); i++)
		if ((abs(v[i])) < (abs(min_zn)))
		{
			min_zn = v[i];
			m = i;
		}
	if ((m + 1) != str.size())
		for (int i = m + 1; i < v.size(); i++)
			sum += abs(v[i]);
	else
		cout << "минимальный элемент расположен последним\n";
	return sum;
}

template<typename T>
void condition_3(vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i] < 0)
		{
			v[i] = v[i] * v[i];
		}
	sort(v.begin(), v.end());
}
