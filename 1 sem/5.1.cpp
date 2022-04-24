#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<vector>
#include <cstdio>
using namespace std;//укажите в файле количество элементов в массиве, потом введите d, а уже потом введите массив;
int check(vector<int> a, int d)
{
    int k = -1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == d)
            k = i;
    }
    if (k == -1)
        k = a.size() - 1;
    return k;
}
void bum(vector<int> a ,int* num, int* min,int n)
{
    *min = a[0];
    *num = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
            *num = i;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");//укажите в файле количество элементов в массиве, потом введите d, а уже потом введите массив;
    freopen("C:\\Users\\yrik2\\Рабочий стол\\text.txt", "r", stdin);
    int n, d,num,min;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    n=check(a, d)+1;
    bum(a, &num, &min, n);
    fclose(stdin);
   freopen("C:\\Users\\yrik2\\Рабочий стол\\text.txt", "w", stdout);
    cout << "Вывод:" << endl << "номер искомого элемента равен " << num << "(считая с 0), а сам он равен " << min;
}
