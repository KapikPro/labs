#include <iostream>
#include <stdio.h>  
#include <conio.h>  
#include <math.h>
#include <stdlib.h>  
#include <windows.h> 
#include <string.h>
#include<sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int count(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '1')
			sum += 1;
	return sum;
}

bool check(int sum)
{
	if (sum % 2 != 0)
		return 1;
}

void trr(string s, string &z)
{
	int sum = count(s);
	if (check(sum) == 1)
		z= s + '1';
	else
		z = s + '0';
}
int main()
{
	{
		setlocale(LC_ALL, "ru");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
	}

	int sum;
	string s, s1, s2;
	cout << "введите двоичное число:\n";
	cin >> s;
	cout << "число с контрольным битом:\n";
	trr(s, s1);
	cout << s1 << endl;
	cout << "введите искаженное двоичное число с измененным нечетным кол-вом бит(количество цифр " << s.size() << "):\n";
	cin >> s2;
	trr(s2, s2);
	if (s2!=s1)
		cout << "число было искажено\n";
	else
		cout << "число не было искажено\n";

}