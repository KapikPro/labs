//16.  ���� ��������� ������������� � ������������ ��������� ������� P ������ 2,
//     ����� ����� ��������� ��� ������� ������� ������� A, ����� � ��� ������ ������.
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
	cout << "����� ��������� �������:\n";
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < a.size(); k++)
		{
			cout << a[i][k] << " ";
		}
		cout << "\n";
	}
	cout << "����� �������:\n";
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
	cout << "��������� ��������� �������:\n";
	string n;
	for (int i = 0; i < a.size(); i++)
		for (int k = 0; k < a.size(); k++)
		{
			cin >> n;
				while (check(n) != 1 && check(n) != 2 && check(n) != 3)
				{
					cout << "�� ����� ������� �����, ����������, ��������� ����\n";
					cin >> n;
				}
			a[i][k] = str_int(n);
		}
	cout << "��������� ������:\n";
	for (int i = 0; i < b.size(); i++)
	{
		cin >> n;
		while (check(n) != 1 && check(n) != 2 && check(n) != 3)
		{
			cout << "�� ����� ������� �����, ����������, ��������� ����\n";
			cin >> n;
		}
		b[i] = str_int(n);
	}
	output(a, b);
}
void auto_input(vector<vector<int>> &a, vector<int> &b)
{
//��������� ��������� �������
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
	cout << "����� ��������� ������� � �������:\n";
	output(a, b);
}
void coutn_line(vector<vector<int>> a)
{
	cout << "�� ��, ��������� ������������� � ������������ �������� ������� <2, �� ����������� ����� �����\n";
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < a.size(); k++)
		{
			sum += a[i][k];
		}
		cout << "����� " << i + 1 << "�� ������ ����� " << sum << endl;
		sum = 0;
	}
}
void count_column(vector<vector<int>> a)
{
	cout << "�� ��, ��������� ������������� � ������������ �������� ������� >=2, �� ����������� ����� ��������\n";
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < a.size(); k++)
		{
			sum += a[k][i];
		}
		cout << "����� " << i + 1 << "��� ������� ����� " << sum << endl;
		sum = 0;
	}
}
void input(vector<vector<int>> &a,vector<int> &b)
{
	string n;
	cout << "������� ������ ���������� ������� �������\n";
	cin >> n;
	while (check(n) != 1 )
		{
			cout << "�� ����� ������������ �����, ����������, ��������� ����\n";
			cin >> n;
		}
	int k = str_int(n);
	a.resize(k);
	for (int i = 0; i < k; i++)
	{
		a[i].resize(k);
	}
	b.resize(k);
	cout << "������� 1, ���� ������ ������� ��������� ������� � ������\n���� �� �� ������������� �� ��������� �������������, �� ������� 2\n";
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
				cout << "�� ����� ������������ �����, ����������, ��������� ����\n";
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
		cout << "� ������� �������� � ������� �������\n";
	}
	else
		if (min == 0)
			cout << "����������� ����� ����� ����, �� 0 ������ ������, ������� ���������� ����������\n";
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
		cout << "��� ����������� ������� ����� ����� ����� 0"<<endl;
		cin >> k;
	}
	
}