/* 4. Исходные данные : В расписании поездов указаны : номер поезда, пункт отправления, пункт назначения,
время отправления, время в пути, цена билета.Условие поиска : Поезда, следующие из Москвы в СанктПетербург,
время отправления которых с 7.00 до 9.00.Коррекция : Время отправления : минуты 0 - 59, часы 0 -23.
Названия пунктов отправления и назначения могут состоят из нескольких слов. */

#define DEBUG 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LinkedDeque.h"
#include "ArrayDeque.h"

int main()
{
	FILE* f;
	if ((f = fopen("fin.txt", "r")) == NULL)
	{
		printf("ошибка открытия файла\n");
		exit(0);
	}
	setlocale(LC_ALL, "russian");
	printf("\nA - создать новый стек из 1ого элемента; B - все выводы сделает каждый сам для себя ы;С- создание стека из подх эл.\nD - ввод из файла; E -ввод с клавиатуры; F - освободить память ;V-вывод команд;G - кому-то конец.\nВам решать..\n");

	LinkedDeque a;
	LinkedDeque b;


	bool c = 0;
	char ch;
	printf("введите букву для выбора действия:\n");
	do {

		scanf("%c", &ch);
		if (ch == '\n' || ch == ' ')
			continue;
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':
			if (c == 1)
			{
				printf("вы уже создали стек, идите с миром..\n");
				break;
			}
			printf("введите 1, если хотите ввести его с клавиатеры и 2, если из файла\n");
			int o;
			NodeInfo j;

			scanf("%d", &o);
			if (o == 2)
				fread_info(j,f);
			else
				read_info(j);
			c = 1;
			init(a, j);
			//getchar();
			break;

		case 'B':
			if (c == 0)
			{
				printf("вы не создали стек, пойдите и создайте..\n");
				break;
			}
			print(a);
			print(b);
			//getchar();
			break;

		case 'C':
			if (c == 0)
			{
				printf("вы не создали стек, пойдите и создайте..\n");
				break;
			}
			solve(a, b);
			break;
		case 'D':
			if (c == 0)
			{
				printf("вы не создали стек, пойдите и создайте..\n");
				break;
			}
			NodeInfo x;
			if (!feof(f))
			{
				fread_info(x, f);
				push_back(a, x);
			}
			else
			{
				printf("больше элементов в файле нет..\n");
			}

			//getchar();
			break;
		case 'E':
			if (c == 0)
			{
				printf("вы не создали стек, пойдите и создайте..\n");
				break;
			}

			NodeInfo y;
			read_info(y);
			push_back(a, y);
			//getchar();
			break;

		case 'F':
			c = 0;
			clear(a);
			clear(b);
			printf("стэки очищены\n");
			//getchar();
			break;
		case'V':
			printf("\nA - создать новый стек из 1ого элемента; B - все выводы сделает каждый сам для себя; С - вывод подходящих эл.;\n D - ввод из файла; E -ввод с клавиатуры; F - освободить память ;G - кому-то конец.\nВам решать..\n");
			break;
		case 'G':
			return 0;
		default:
			printf("Нет такой команды\n");
			//getchar();
		}
		printf("введите букву для выбора действия:\n");
	} while (ch != 'G');
	fclose(f);
	return 0;
}

