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
char* ANSIUpperCase(char* s, char* S) {
    S = strcpy(S, s);
    char* ch = S;
    while (*ch) {
        if (*ch >= 'a' && *ch <= 'z' || *ch >= '�' && *ch <= '�') *ch = *ch - 32;
        if (*ch == '�') *ch = '�';
        ch++;
    }
    return S;
}
struct list
{
    int nm;
    char otpr[31], prib[31];
    double totpr, tput;
    int cost;
};
void vv()
{
    FILE* f, * fr;
    char s[17];
    char n = '#';
    if ((f = fopen("fin.txt", "r")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    if ((fr = fopen("fout.txt", "wb")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }

    list x;
    int k = 0;

    while (true)
    {
        
        fscanf(f, "%d", &x.nm);
        if (feof(f) != 0)
            break;
        fscanf(f, "%s", &x.otpr);
        fscanf(f, "%s", &x.prib);
        fscanf(f, "%lf", &x.totpr);
        fscanf(f, "%lf", &x.tput);
        fscanf(f, "%d", &x.cost);
        fwrite(&x, sizeof(list), 1, fr);
    }
    fclose(f);

    fclose(fr);
}
void check()
{
    FILE* f;
    list x;
    int p = 0, c=0, t1=0,t2=0,t3=0;
    if ((f = fopen("fout.txt", "rb")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    cout << "�����| |����� �����������| |����� ����������| |����� ��������| |����� ����| |����\n";
    while (true)
    {
        t1 = 0, t2 = 0, t3 = 0;
        c++;
        char b[30];
        fread(&x, sizeof(list), 1, f);
        if (feof(f))
            break;
        strcpy(b, x.otpr);
        if (!(strcmp(ANSIUpperCase(x.otpr,b), "������")))
        {
           // t1++;
            if(!strcmp(ANSIUpperCase(x.prib, b), "�����-���������"))
            {
                //t2++;
                if ((x.totpr >= 7.0) && (x.totpr <= 9.0))
                {
                   // t3++;
                    cout << "������� ������� ������ � �������� ������:\n";
                    p++;
                    printf("%5d| |%17s| |%16s| |%14.2f| |%10.2f| |%4d\n", x.nm, x.otpr, x.prib, x.totpr, x.tput, x.cost);
                }
            }
        }
        //cout << t1 << " " << t2 << " " << t3 << "\n";
    }
    if (p < 1)
        cout << "������� ������� �� ������\n";
    fclose(f);
}
 void izm()
{
    FILE* f;
    list x;
    int p = 0,o=0;
    if ((f = fopen("fout.txt", "rb+")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    while (true)
    {
        o = ftell(f);
        fread(&x, sizeof(list), 1, f);
        if (feof(f) != 0)
            break;
            double c, d;
            d = modf(x.totpr, &c);
            d *= 100;
            d = (int)d;
            if (c > 23 || c < 0 || d > 59 || d < 0 || (x.totpr<0))
            {
                p++;
                if (p == 1)
                  cout << "�����| |����� �����������| |����� ����������| |����� ��������| |����� ����| |����\n";
                cout << "������������� � ������ ������ �����������:\n";
                x.totpr = 0.0;
                printf("%5d| |%17s| |%16s| |%14.2f| |%10.2f| |%4d\n", x.nm, x.otpr, x.prib, x.totpr, x.tput, x.cost);
                fseek(f,o, SEEK_SET);
                fwrite(&x, sizeof(list), 1, f);
                fseek(f,0, SEEK_CUR);
            }

    }
    if (p == 0)
        cout << "��������� �� ����\n";
    fclose(f);
}

void viv()
{
    FILE* f;
    list x;
    if ((f = fopen("fout.txt", "rb")) == NULL)
    {
        cout << "������ �������� �����\n";
        exit(0);
    }
    cout << "�����| |����� �����������| |����� ����������| |����� ��������| |����� ����| |����\n";
    while (true)
    {
        fread(&x, sizeof(list), 1, f);
        if (feof(f) != 0)
            break;
            printf("%5d| |%17s| |%16s| |%14.2f| |%10.2f| |%4d\n", x.nm, x.otpr, x.prib, x.totpr, x.tput, x.cost);
    }
    fclose(f);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int k = 6;
    while (k != 5)
    {
        cout << "\n";
        cout << "�������� ��������� ��������:\n1) �� ���������� ����� ������ ��� ������ � ������� �������� ����;\n2) ����� � �������� ����� �� ������� ������;\n3) ��������� ������ � �������� �����(�� ��� ����� �� ����������, � ������ �������������� ��������� �����);\n4) �������� ��������� ����� � ����� ������ �� ����� �� ����� � ���� �������.\n";
        cin >> k;

        switch (k)
        {
        case(1):
            vv();
            break;
        case(2):
            check();
            break;
        case(3):
            izm();
            break;
        case(4):
            viv();
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