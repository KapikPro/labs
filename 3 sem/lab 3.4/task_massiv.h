#pragma once
#include<algorithm>
#include<vector>
#define abs(a) a < 0 ? -a : a

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
		if (abs(v[i]) < abs(min_zn))
		{
			min_zn = v[i];
			m = i;
		}
	for (int i = m; i < v.size(); i++)
		if (abs(v[i]) < 0)
			sum += abs(v[i]);
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
