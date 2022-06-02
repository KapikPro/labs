/* 4. Исходные данные : В расписании поездов указаны : номер поезда, пункт отправления, пункт назначения,
время отправления, время в пути, цена билета.Условие поиска : Поезда, следующие из Москвы в СанктПетербург,
время отправления которых с 7.00 до 9.00.Коррекция : Время отправления : минуты 0 - 59, часы 0 -23.
Названия пунктов отправления и назначения могут состоят из нескольких слов. */

#define DEBUG 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"LinkedDeque.h"

int main() noexcept
{
	setlocale(LC_ALL, "russian");
	printf("\nA - создать новый стек из 1ого элемента; B - все выводы сделает каждый сам для себя; С - вывод подходящих эл.;\n D - ввод из файла; E -ввод с клавиатуры; F - освободить память ;G - кому-то конец.\nВам решать..\n");

	LinkedDeque a;
	LinkedDeque b;

	bool c = 0;
	char ch;

	do {
		ch = getchar();
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
			if (o == 1)
				fread_info(j);
			else
				read_info(j);
			c = 1;
			init(a, j);
			break;

		case 'B':
			if (c == 0)
			{
				printf("вы не создали стек, пойдите и создайте..\n");
				break;
			}
			print(a);
			break;

		case 'C':
			if (c == 0)
			{
				printf("вы не создали стек, пойдите и создайте..\n");
				break;
			}
			print(b);
			getchar();
			break;
		case 'D':
			if (c == 0)
			{
				printf("вы не создали стек, пойдите и создайте..\n");
				break;
			}
			NodeInfo x;
			fread_info(x);
			push_back(a, x);
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

			break;

		case 'F':
			c = 0;
			break;

		case 'G':
			return 0;

		default:
			printf("Нет такой команды\nPress any key");
		}
	} while (ch != 'G');

	return 0;
}

