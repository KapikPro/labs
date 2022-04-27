#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <cstdio>
#include <string>
#include <stdlib.h>
using namespace std;
struct list
{
    int nm;
    string otpr, prib;
    int totpr, tput;
    int cost;
};
void vv(list*& x, int& t)
{
    FILE* f;
    string s;
    char n = '#';
    if ((f = fopen("f.txt", "a+")) == NULL)
    {
        cout << "ошибка открытия файла\n";
        exit(0);
    }
    fscanf(f, "%d ", &t);
    x = new list[t];
    for (int i = 0; i < t; i++)
    {
            s.clear();
            char n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                s.push_back(n);
            }
            x[i].nm = stoi(s);
            cout << x[i].nm << '\n';
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                s.push_back(n);
            }
            x[i].otpr = s;
            cout << x[i].otpr << '\n';
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                s.push_back(n);
            }
            x[i].prib = s;
            cout << x[i].prib << '\n';
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                s.push_back(n);
            }
            x[i].totpr = stoi(s);
            cout << x[i].totpr << '\n';
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n')
            {
                n = fgetc(f);
                s += n;
            }
            x[i].tput = stoi(s);
            cout << x[i].tput << '\n';
            s.clear();
            n = '#';
            while (n != ' ' && n != '\n' && !feof(f))
            {
                n = fgetc(f);
                s += n;
            }
            x[i].cost = stoi(s);
            cout << x[i].cost << '\n';
            s.clear();
    }
    fclose(f);
}
int main()
{
    int i = 0;
    list* x;
    x = new list[1];
    vv(x, i);
}