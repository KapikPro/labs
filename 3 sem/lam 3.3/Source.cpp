#include"tools.h"
#include"WeirdStack.h"
#include"Second_task.h"
#include<iostream>
#include<exception>
using namespace std;

void work_with_weird_stack()
{
	WeirdStack b;
	int d = 0;
	cout << "введите 1, если хотите протестировать ++( добавить 1 в стек)\n 2, если хотите протестировать функцию --(удаление элемента из стека)\n 3, если хотите прекратить работу со стеком\n";
	while (d != 1)
	{
		long c;
		while (!try_read_int(c))
		{
			printf("вы ввыели не цисло!\nповторите ввод\n");
		}
		switch (c)
		{
		case 1:
			++b;
			cout << "вывод стека:\n";
			for (int i = 0; i < b.get_size(); i++)
			{
				cout << "1 ";
			}
			cout << endl;
			break;
		case 2:
			--b;
			cout << "вывод стека:\n";
			for (int i = 0; i < b.get_size(); i++)
			{
				cout << "1 ";
			}
			cout << endl;
			break;
		case 3:
			d = 1;
			break;
		default:
			cout << "вы ввели неподходящее число, повторите ввод\n";
		}
	}
}

void work_with_long_int()
{
	int d = 0;
	while (d != 1)
	{
		
		long a;
		cout << "введите первое число:\n";
		while (!try_read_int(a))
		{
			printf("вы ввели что-то страшное!\nповторите ввод\n");
		}
		LongInt b1(a);
		cout << "введите второе число:\n";
		while (!try_read_int(a))
		{
			printf("вы ввели что-то страшное!\nповторите ввод\n");
		}
		LongInt b2(a);
		cout << "введите:\n1-протестировать сложение чисел\n2-протестировать умножение чисел\n3-завершить работу с данным заданием\n";
		long c;
		while (!try_read_int(c))
		{
			printf("вы ввели что-то страшное!\nповторите ввод\n");
		}
		switch (c)
		{
		case 1:
			cout << "a + b = " << (b1+b2).get_number() << endl;
			break;
		case 2:
			cout << "a * b = " << (b1*b2).get_number() << endl;
			break;
		case 3:
			d = 1;
			break;
		default:
			cout << "вы ввели неподходящее число, повторите ввод\n";
		}
	}
}

int main();

void parse_cmd(int cmd)
{
	switch (cmd)
	{
	case 1:
		work_with_weird_stack();
		break;

	case 2:
		work_with_long_int();
		break;

	default:
		printf("вы ввели не 1 и не 2\n");
	}
	main();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		long cmd;
		cout << "введите 1, чтобы протестировать первое условие, или 2 ,чтобы протестировать второе\n";
		while (!try_read_int(cmd))
			printf("вы ввыели что-то страшное!\nповторите ввод\n");

		parse_cmd(cmd);
	}
	catch (exception ex)
	{
		cout << "Ошибка: " << ex.what() <<endl << "программа будет перезапущена!" << endl << endl;
		main();
	}

	return 0;
}