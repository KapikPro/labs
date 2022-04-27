#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<sstream>
#include<cstdio>
#include<string>
#include<stdlib.h>
using namespace std;
struct list
{
	int nm;
	string otpr, prib;
	int totpr, tput;
	int cost;
};
void vv(list* &x, int &i)
{
	FILE* f;
	string s;
	char *n;
	n = new char;
	if ((f = fopen("C:\\source\\repos\\lab 2.7\\lab 2.7\\f.txt", "a+")) == NULL)
	{
		cout << "ошибка открытия файла\n";
		exit;
	}
	while (!feof(f))
		while (*n != '/n')
		{
			x=(list*)realloc(x,i+1);
			s.clear();
			while (*n != ' ' || *n != '\n')
			{
				fgets(n, 1, f);
				s += n;
			}
			x[i].nm = stoi(s);
			s.clear();
			while (*n != ' ' || *n != '\n')
			{
				fgets(n, 1, f);
				s += n;
			}
			x[i].otpr = s;
			s.clear();
			while (*n != ' ' || *n != '\n')
			{
				fgets(n, 1, f);
				s += n;
			}
			x[i].prib = s;
			s.clear();
			while (*n != ' ' || *n != '\n')
			{
				fgets(n, 1, f);
				s += n;
			}
			x[i].totpr = stoi(s);
			s.clear();
			while (*n != ' ' || *n != '\n')
			{
				fgets(n, 1, f);
				s += n;
			}
			x[i].tput = stoi(s);
			s.clear();
			while (*n != ' ' || *n != '\n')
			{
				fgets(n, 1, f);
				s += n;
			}
			x[i].cost = stoi(s);
			s.clear();
			i++;
		}
	fclose(f);
	i += 1;
	for (int k = 0; k < i; k++)
	{
		cout << x[i].nm << " " << x[i].otpr << " " << x[i].prib;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int i=0;
	list* x;
	vv(x, i);
}