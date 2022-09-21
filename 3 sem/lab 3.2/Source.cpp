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
			k = 2;
		else
			if ((((int)n[i] < 48) || ((int)n[i] > 57)))
			{
				k = 0;
				break;
			}
	}
	if (k == 1)
		if (str_to_int(n) == 0)
			return 3;
	if (k == 1)
		return 1;
	else
		if (k == 2)
			return 2;
	else return 0;
}

int main()
{
	string s;
	int l, w, h, c;
	setlocale(LC_ALL, "Russian");
	while (1)
	{
		cout << "введите длинну\n";
		cin >> s;
		if (check(s) != 1)
			while (1)
			{
				cout << "вы ввели неправильное число, повторите ввод\n";
				cin >> s;
				if (check(s) == 1)
					l = str_to_int(s);
			}
		else
			l = str_to_int(s);
		cout << "введите ширину комнаты\n";
		cin >> s;
		if (check(s) != 1)
			while (1)
			{
				cout << "вы ввели неправильное число, повторите ввод\n";
				cin >> s;
				if (check(s) == 1)
					w = str_to_int(s);
			}
		else
			w = str_to_int(s);
		cout << "введите высоту комнаты\n";
		cin >> s;
		if (check(s) != 1)
			while (1)
			{
				cout << "вы ввели неправильное число, повторите ввод\n";
				cin >> s;
				if (check(s) == 1)
					h = str_to_int(s);
			}
		else
			h = str_to_int(s);
		cout << "введите так же количество окон(на одну стену не больше одного окна)\n";
		cout << "высота одного окна равна половине высоты комнаты, а его ширина равна половине ширины кратчайшей из сторон\n";
		cin >> s;
		if (check(s) != 1)
			while (1)
			{
				cout << "вы ввели неправильное число, повторите ввод\n";
				cin >> s;
				if (check(s) == 1)
					c = str_to_int(s);
			}
		else
			c = str_to_int(s);
		Room a = Room(l, w, h, c);
		cout << "1-вычисление обьема комнаты\n2-вычисление площади пола комнаты\n3-вывод всех параметров комнаты\n4-расчет необходимого колиества обоев\n";


		cout << "если хотите закончить работу программы введите 0, в ином случае любой другой символ\n";
		cin >> s;
		if (check(s) == 3)
			break;
	}
	return 0;
}