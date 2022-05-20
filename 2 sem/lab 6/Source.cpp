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
int input(int &n)
{
    FILE* f;
    char c;
    char* s;
    s = (char*)malloc(256 * sizeof(char));
    *s = '\0';
    int k=1,o=0,u=0;
    if ((f = fopen("fin.txt", "r")) == NULL)
    {
        cout << "ошибка открытия файла\n";
        exit(0);
    }
    while (!feof(f)) {
        c = fgetc(f);
        if(c==' ')
            *s = '\0';
        if ((c == '.' || c == '!' || c == '?' || c == ';' || c==EOF) && *s!= '\0')
        {
            if (o == 1 && (s[0] == 'К' || s[0] == 'к'))
            {
                n = k;
                u = 1;
            }
            cout << s[0] << " " << o << "\n";
            *s = '\0';
            k++;
            
        }
        if (c != '.' && c != '!' && c != '?' && c != ':' && c!=' ' && c != ';')
        {
            s[strlen(s)+1] = '\0';
            s[strlen(s)] = c;
            if (c == 'К' || c == 'к')
                o = 1;
            else
                o = 0;
        }
    }
    fclose(f);
    return u;
}
int main()
{
	setlocale(LC_ALL, "Russian");
    int n=1;
    if (input(n) != 0)
        cout << "искомое предложение находится под номером " << n;
    else
        cout << "искомого предложения не найдено";
    
}