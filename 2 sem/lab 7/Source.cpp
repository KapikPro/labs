#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include<algorithm>
using namespace std;
struct list
{
    int nm;
    string otpr, prib;
    double totpr, tput;
    int cost;
};
void vv( int& t)
{
    FILE* f;
    string s;
    char n = '#';
    if ((f = fopen("fin.txt", "r")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    fscanf(f, "%d ", &t);
    list* x;
    x = new list[t];
    for (int i = 0; i < t; i++)
    {
            s.clear();
            char n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                if (n != ' ' && n != '\n')
                s.push_back(n);
            }
            x[i].nm = stoi(s);
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                if (n != ' ' && n != '\n')
                s.push_back(n);
            }
            x[i].otpr = s;
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                if(n!=' ' && n != '\n')
                s.push_back(n);
            }
            x[i].prib = s;
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                if (n != ' ' && n != '\n')
                s.push_back(n);
            }
            x[i].totpr = stoi(s);
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                if (n != ' ' && n != '\n')
                s += n;
            }
            x[i].tput = stoi(s);
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n' && !feof(f))
            {
                n = fgetc(f);
                if (n != ' ' && n != '\n')
                s += n;
            }
            x[i].cost = stoi(s);
            s.clear();
    }
    fclose(f);
    if ((f = fopen("fout.txt", "w")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    fwrite(x,sizeof(list),t,f);
    fclose(f);
}
void check(int t)
{
    FILE* f;
    list* x;
    int p = 0;
    x = new list[t];
    if ((f = fopen("fout.txt", "r")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    fread(x, sizeof(list), t, f);
    for (int i = 0; i < t; i++)
    {
        if (((x[i].otpr) == "������") && ((x[i].prib) == "�����-���������") && x[i].totpr > 7.0 && x[i].totpr < 9.0)
        {
            cout << "������� ������� ������ � " << i + 1 << "�� ������(������ � 1)\n";
            p++;
        }

    }
    if (p < 1)
        cout << "������� ������� �� ������\n";
    fclose(f);
}
void izm(int t)
{
    FILE* f;
    list* x;
    int p = 0;
    x = new list[t];
    if ((f = fopen("fout.txt", "r")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    fread(x, sizeof(list), t, f);
    fclose(f);
    for (int i = 0; i < t; i++)
    {
        double c, d;
        d = modf(x[i].totpr, &c);
        if (c > 23 ||c<0 || d > 59||d<0)
        {
            p++;
            if(p==1)
            cout << "�����| |����� �����������| |����� ����������| |����� ��������| |����� ����| |����\n";
            cout << "������������� � ������ ������ �����������:\n";
            x[i].totpr = 0.0;
            printf("%5d| |%17s| |%16s| |%14.2f| |%10.2f| |%4d\n", x[i].nm, x[i].otpr.data(), x[i].prib.data(), x[i].totpr, x[i].tput, x[i].cost);
        }
    }
    if (p != 0)
    {
        if ((f = fopen("fout.txt", "w")) == NULL)
        {
            cout << "������ �������� �����\n";
            exit(0);
        }
        fwrite(x, sizeof(list), t, f);
        fclose(f);
    }
}
void viv(int t)
{
    FILE* f;
    list* x;
    x = new list[t];
    if ((f = fopen("fout.txt", "a+")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    cout << "�����| |����� �����������| |����� ����������| |����� ��������| |����� ����| |����\n";
    fread(x, sizeof(list), t, f);
    for (int i = 0; i < t; i++)
    {
         printf("%5d| |%17s| |%16s| |%14.2f| |%10.2f| |%4d\n", x[i].nm, x[i].otpr.data(), x[i].prib.data(), x[i].totpr, x[i].tput, x[i].cost);
    }
    fclose(f);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int t = 0,k=6;
    while (k != 5)
    {
        cout << "\n";
        cout << "�������� ��������� ��������:\n1) �� ���������� ����� ������ ��� ������ � ������� �������� ����;\n2) ����� � �������� ����� �� ������� ������;\n3) ��������� ������ � �������� �����(�� ��� ����� �� ����������, � ������ �������������� ��������� �����);\n4) �������� ��������� ����� � ����� ������ �� ����� �� ����� � ���� �������.\n";
        cin >> k;

        switch (k)
        {
        case(1):
            vv(t);
            break;
        case(2):
            check(t);
            break;
        case(3):
            izm(t);
            break;
        case(4):
            viv(t);
            break;
        default:
        {
            getchar();
            return 0;
        }
        }
    }
    return 0;
}