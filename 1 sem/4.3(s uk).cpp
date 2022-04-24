#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
void wwm(double* m)//work with massive;
{
	cout << "введите размер массива" << endl;
	int n;
	double min;
	cin >> n;
	vector<double> mas(n);
	cout << "введите этот массив" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		if (i == 0)
			min = mas[i];
		else
			if (min > mas[i])
				min = mas[i];
	}
	*m = min;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double m;
	wwm(&m);
	int a = m;
	cout << a;
}