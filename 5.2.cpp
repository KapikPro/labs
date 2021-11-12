#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
double SrArfm(vector<vector<double>> a)
{
	double sa=0;
	for (int i = 0; i < a[0].size(); i++)
	{
		sa += a[i][i];
	}
	sa /= a[0].size();
	return sa;
}
void izm(vector<vector<double>> a,double sa)
{
	cout << endl;
	cout << "изменённый массив:" << endl;
	for (int i = 0; i < a[0].size(); i++)
	{
		cout << endl;
		for (int j = 0; j < a[0].size(); j++)
		{
			if (a[i][j] > 0)
				a[i][j] += sa;
			else
				if (a[i][j] < 0)
					a[i][j] -= sa;
			cout << a[i][j] << '\t'<<" ";
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "введите кол-во строк и столбцов квадратной матрицы" << endl;
	cin >> n;
	vector<vector<double>> a(n, vector<double>(n));
	vector<double> c(n);
	cout << "введите матрицу" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	cout << "введите одномерный массив с" << endl;
	for (int j = 0; j < n; j++)
		cin >> c[j];
	for (int i = 0; i < n; i++)
		if (SrArfm(a) > c[i])
		{
			cout << "среднее арифметическое элеметов главной диагонали массива больше, чем элемент массива с под номером "<<i << endl;
			return 0;
		}
	cout << "среднее арифметическое элеметов главной диагонали массива меньше, чем любой элемент массива с" << endl;
	izm(a, SrArfm(a));
}