/* 4. Исходные данные : В расписании поездов указаны : номер поезда, пункт отправления, пункт назначения,
время отправления, время в пути, цена билета.Условие поиска : Поезда, следующие из Москвы в СанктПетербург,
время отправления которых с 7.00 до 9.00.Коррекция : Время отправления : минуты 0 - 59, часы 0 -23.
Названия пунктов отправления и назначения могут состоят из нескольких слов. */

#define DEBUG 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LinkedDeque.h"
#include "ArrayDeque.h"
#include <string>
#include <Windows.h> 

int main()
{
	setlocale(LC_ALL, "russian");
	printf("выберете метод, которым хотите реализовать дек:\n1- дек заданный двухсвязным списком\n2- дек заданный двумерным массивом\n");
	int d = 0;
	scanf("%d", &d);
	if (d == 1)
	{
		FILE* t;
		if ((t = fopen("log.txt", "w")) == NULL)
		{
			printf("ошибка открытия файла\n");
			exit(0);
		}
		fclose(t);
		FILE* f;
		if ((f = fopen("fin.txt", "r")) == NULL)
		{
			printf("ошибка открытия файла\n");
			exit(0);
		}

		printf("\nA - создать новый дек из 1ого элемента; B - все выводы сделает каждый сам для себя ;С- создание стека из подх эл.;\nU-переворачивание декаD - ввод из файла; E -ввод с клавиатуры; F - освободить память ;V-вывод команд;Z-удаление n эл.\nG - кому-то конец.Вам решать..\n");

		LinkedDeque a;
		LinkedDeque b;
		LinkedDeque k;

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
					printf("вы уже создали дек, идите с миром..\n");
					break;
				}
				printf("введите 1, если хотите ввести его с клавиатеры и 2, если из файла\n");
				int o;
				NodeInfo j;

				scanf("%d", &o);
				if (o == 2)
					fread_info(j, f);
				else
					read_info(j);
				c = 1;
				init(a, j);
				//getchar();
				log(a);
				break;

			case 'B':
				if (c == 0)
				{
					printf("вы не создали дек, пойдите и создайте..\n");
					break;
				}
				printf("первый стэк:\n");
				print(a);
				printf("\nвторой стэк:\n");
				print(b);
				printf("\nтретий стэк:\n");
				print(k);
				//getchar();
				break;
			case 'Z':
				printf("сколько элементов вы хотите удалить?/n");
				int n;
				scanf("%d", &n);
				for (int i = 0; i < n; i++)
				{
					pop_back(a);
				}
				log(a);
				break;
			case 'C':
				if (c == 0)
				{
					printf("вы не создали дек, пойдите и создайте..\n");
					break;
				}
				solve(a, b, k);
				break;
			case 'D':
				if (c == 0)
				{
					printf("вы не создали дек, пойдите и создайте..\n");
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
				log(a);
				//getchar();
				break;
			case 'E':
				if (c == 0)
				{
					printf("вы не создали дек, пойдите и создайте..\n");
					break;
				}

				NodeInfo y;
				read_info(y);
				push_back(a, y);
				//getchar();
				log(a);
				break;
			case'U':
				reverse(a);
				printf("дек перевёрнут\n");
				log(a);
				break;
			case 'F':
				c = 0;
				clear(a);
				clear(b);
				clear(k);
				printf("стэки очищены\n");
				//getchar();
				log(a);
				break;
			case'V':
				printf("\nA - создать новый дек из 1ого элемента; B - все выводы сделает каждый сам для себя; С- создание дека из подх эл;\n D - ввод из файла; E -ввод с клавиатуры; F - освободить память; Z-  удалить N элементов\nG - кому-то конец.Вам решать..\n");
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
	else
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------------
	{
	FILE* t;
	if ((t = fopen("log.txt", "w")) == NULL)
	{
		printf("ошибка открытия файла\n");
		exit(0);
	}
	fclose(t);
	FILE* f;
	if ((f = fopen("fin.txt", "r")) == NULL)
	{
		printf("ошибка открытия файла\n");
		exit(0);
	}

	printf("\nA - создать новый дек из 1ого элемента; B - все выводы сделает каждый сам для себя ;С- создание стека из подх эл.;\nU-переворачивание декаD - ввод из файла; E -ввод с клавиатуры; F - освободить память ;V-вывод команд;Z-удаление n эл.\nG - кому-то конец.Вам решать..\n");


	bool c = 0;
	char ch;
	printf("введите букву для выбора действия:\n");
	do {
		ArrayDeque a;
		ArrayDeque b;
		ArrayDeque k;

		scanf("%c", &ch);
		if (ch == '\n' || ch == ' ')
			continue;
		ch = toupper(ch);
		switch (ch)
		{
		case 'A':
			if (c == 1)
			{
				printf("вы уже создали дек, идите с миром..\n");
				break;
			}
			printf("введите 1, если хотите ввести его с клавиатеры и 2, если из файла\n");
			int o;
			ElemInfo j;

			scanf("%d", &o);
			if (o == 2)
				fread_info(j, f);
			else
				read_info(j);
			c = 1;
			init(a);
			init(b);
			init(k);
			//getchar();
			log(a);
			break;

		case 'B':
			if (c == 0)
			{
				printf("вы не создали дек, пойдите и создайте..\n");
				break;
			}
			printf("первый стэк:\n");
			print(a);
			printf("\nвторой стэк:\n");
			print(b);
			printf("\nтретий стэк:\n");
			print(k);
			//getchar();
			break;
		case 'Z':
			printf("сколько элементов вы хотите удалить?/n");
			int n;
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				pop_back(a);
			}
			log(a);
			break;
		case 'C':
			if (c == 0)
			{
				printf("вы не создали дек, пойдите и создайте..\n");
				break;
			}
			solve(a, b, k);
			break;
		case 'D':
			if (c == 0)
			{
				printf("вы не создали дек, пойдите и создайте..\n");
				break;
			}
			ElemInfo x;
			if (!feof(f))
			{
				fread_info(x, f);
				push_back(a, x);
			}
			else
			{
				printf("больше элементов в файле нет..\n");
			}
			log(a);
			//getchar();
			break;
		case 'E':
			if (c == 0)
			{
				printf("вы не создали дек, пойдите и создайте..\n");
				break;
			}

			ElemInfo y;
			read_info(y);
			push_back(a, y);
			//getchar();
			log(a);
			break;
		case'U':
			reverse(a);
			printf("дек перевёрнут\n");
			log(a);
			break;
		case 'F':
			c = 0;
			clear(a);
			clear(b);
			clear(k);
			printf("стэки очищены\n");
			//getchar();
			log(a);
			break;
		case'V':
			printf("\nA - создать новый дек из 1ого элемента; B - все выводы сделает каждый сам для себя; С- создание дека из подх эл;\n D - ввод из файла; E -ввод с клавиатуры; F - освободить память; Z-  удалить N элементов\nG - кому-то конец.Вам решать..\n");
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
	return 0;
 }
}

