//16.  Если отношение максимального и минимального элементов вектора P больше 2,
//     найти сумму элементов для каждого столбца матрицы A, иначе – для каждой строки.
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<time.h>
#include<cstdlib>
#include<string>
using namespace std;
int str_int(string n)
{
	stringstream a;
	int b;
	a << n;
	a >> b;
	return b;
}
void output(vector<vector<int>> a, vector<int> b)
{
	cout << "вывод двумерной матрицы:\n";
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < a.size(); k++)
		{
			cout << a[i][k] << " ";
		}
		cout << "\n";
	}
	cout << "вывод вектора:\n";
	for (int k = 0; k < a.size(); k++)
	{
		cout << b[k] << " ";
	}
	cout << endl;
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
		if (str_int(n) == 0)
			k = 3;
	if (k == 1)
		return 1;
	else
		if (k == 2)
			return 2;
	if(k==3)
		return 3;
		else return 0;
}
void manual_input(vector<vector<int>> &a, vector<int> &b)
{
	cout << "заполните двумерную матрицу:\n";
	string n;
	for (int i = 0; i < a.size(); i++)
		for (int k = 0; k < a.size(); k++)
		{
			cin >> n;
				while (check(n) != 1 && check(n) != 2 && check(n) != 3)
				{
					cout << "вы ввели нецелое число, пожалуйста, повторите ввод\n";
					cin >> n;
				}
			a[i][k] = str_int(n);
		}
	cout << "заполните вектор:\n";
	for (int i = 0; i < b.size(); i++)
	{
		cin >> n;
		while (check(n) != 1 && check(n) != 2 && check(n) != 3)
		{
			cout << "вы ввели нецелое число, пожалуйста, повторите ввод\n";
			cin >> n;
		}
		b[i] = str_int(n);
	}
	output(a, b);
}
void auto_input(vector<vector<int>> &a, vector<int> &b)
{
//заполняем двумерную матрицу
     int n;
	for (int i = 0; i < a.size(); i++)
		for (int k = 0; k < a.size(); k++)
		{
            n=rand()%50-15;
			a[i][k] = n;
		}
	for (int i = 0; i < b.size(); i++)
	{
		 n = rand() % 20 - 10;
		if (n == 0)
			n = 1;
		b[i] = n;
	}
	cout << "вывод двумерной матрицы и вектора:\n";
	output(a, b);
}
void coutn_line(vector<vector<int>> a)
{
	cout << "тк кк, отношение максимального и минимального элемента вектора <2, то подчитываем суммы строк\n";
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < a.size(); k++)
		{
			sum += a[i][k];
		}
		cout << "сумма " << i + 1 << "ой строки равна " << sum << endl;
		sum = 0;
	}
}
void count_column(vector<vector<int>> a)
{
	cout << "тк кк, отношение максимального и минимального элемента вектора >=2, то подчитываем суммы столбцов\n";
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < a.size(); k++)
		{
			sum += a[k][i];
		}
		cout << "сумма " << i + 1 << "ого столбца равна " << sum << endl;
		sum = 0;
	}
}
void input(vector<vector<int>> &a,vector<int> &b)
{
	string n;
	cout << "укажите размер квадратной матрицы вектора\n";
	cin >> n;
	while (check(n) != 1 )
		{
			cout << "вы ввели неподходящее число, пожалуйста, повторите ввод\n";
			cin >> n;
		}
	int k = str_int(n);
	a.resize(k);
	for (int i = 0; i < k; i++)
	{
		a[i].resize(k);
	}
	b.resize(k);
	cout << "введите 1, если хотите вручную заполнить матрицу и вектор\nесли же вы предпочитаете их заполнить автоматически, то введите 2\n";
	cin>>k;
	if (k == 1)
		manual_input(a, b);
	else
		if (k == 2)
			auto_input(a, b);
		else
		{
			while (k != 1 && k != 2)
			{
				cout << "вы ввели неподходящее число, пожалуйста, повторите ввод\n";
				cin >> k;
			}
			if (k == 1)
				manual_input(a, b);
			else
				if (k == 2)
					auto_input(a, b);
		}
}
void fork(vector<vector<int>> a, vector<int> b)
{
	double min, max;

	for (int i = 0; i < b.size(); i++)
	{
		if (i == 0)
		{
			max = b[i];
			min = b[i];
		}
		if (b[i] > max)
		 max = b[i];
		if (b[i] < min)
			min = b[i];
	}
	if (min == max)
	{
		cout << "у вектора максимум и минимум совпали\n";
	}
	else
		if (min == 0)
			cout << "минимальное число равно нулю, на 0 делить нельзя, поэтому вычисление невозможно\n";
		else
	if ((max / min)>= 2.0)
		count_column(a);
	else
		coutn_line(a);
}
int main()
{
	int k=1;
	
	while (k != 0) {
		setlocale(LC_ALL, "Russian");
		vector<vector<int>> a;
		vector<int> b;
		input(a, b);
		fork(a, b);
		cout << "Для продолжения введите любое число кроме 0"<<endl;
		cin >> k;
	}
	
}