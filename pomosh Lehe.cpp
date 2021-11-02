#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void min(vector<double> mas)
{
	int min=mas[0];
	for (int i = 1; i < mas.size(); i++)
		if (min > mas[i])
			min = mas[i];
	cout << "минимально значение этого массива =" << min<<endl;
	if (min == 0)
		cout << "минимально значение этого массива = 0, поэтому мы ничего не изменяем" << endl;
	else
		cout << "измененное минимальное значение =" << min + abs(min) << endl;
	cout << endl;
}
int main()
{
	setlocale(LC_ALL,"Russian");
	int i, n;
	cout << "введите количество элементов в массиве а" << endl;
	cin >> n;
	vector<double> a(n);
	cout << "введите массив а" << endl;
	for (i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	min(a);
	cout << "введите количество элементов в массиве b" << endl;
	cin >> n;
	vector<double> b(n);
	cout << "введите массив b" << endl;
	for (i = 0; i <b.size() ; i++)
	{
		cin >> b[i];
	}
	min(b);
}