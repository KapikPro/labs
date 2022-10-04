#include"tools.h"
#include"WeirdStack.h"
#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "введит 1, если хотите проверить второе условие и 2, если первое\n";
	int a;
	while (!try_read_int(a))
	{
		printf("вы ввыели не число!\n");
	}

	WeirdStack<int> b;
	switch (a)
	{
	case 1:
		b + 101;
		cout << b--;
		break;

	case 2:
		
		break;

	default:
		printf("вы ввели не 1 и не 2..\n");
		main();
	}
}