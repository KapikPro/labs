#include"Room.h"
#include "RoomWithWallpaper.h" 
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int str_to_int(string n)
{
	stringstream a;
	int b;
	a << n;
	a >> b;
	return b;
}

int check(string n)
{
	int k = 1;
	for (int i = 0; i < n.size(); i++)
	{
		if (i == 0 && n[i] == '-')
		{
			//круто
		}
		else
		//проверяем посимвольно на цифры;
		if ((((int)n[i] < 48) || ((int)n[i] > 57)))
		{
			k = 0;
			break;
		}
	}
	if (k == 1)
		return 1;
	else return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "введите длинну, ширину и высоту комнаты, а так же количество окон(на одну стену не больше одного окна)\n";
	cout << "высота одного окна равна половине высоты комнаты, а его ширина равна половине ширины кратчайшей из сторон\n";
	string s;
	cin >> s;
	if(check(s)==1)
		//;
	return 0;
}