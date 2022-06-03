#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <stdlib.h>
#include<algorithm>
#include <conio.h>  
//---------------------------------------------------------------------------
struct TInfo {
	int num;
};
struct TElem {  // моделирование стека на основе односвязного списка
	TInfo Info;   //  или struct TInfo Info;
	TElem* Next;  // или struct TElem *Next; здесь и далее
};
//-----------------------прототипы-------------------------------------------
TElem* PushStack(TElem* St, TInfo Info); // добавить элемент в стек
TInfo PopStack(TElem** PSt);  //извлечь элемент из стека~~~~~~
// дополнительная процедура перекладывания элемента из одного стека (StTop) в другой(Dop)
void TopToTop(TElem** PSt, TElem** St3); // без изменения адресов элементов, только связи
//----------первая часть: создание стека из текстового файла
TElem* CreateStack(TElem* St, int t);
//----------вторая часть: вывод стека на экран ------
void OutputStack(TElem*& St);
//----------третья часть: решение задачи -------------
TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3);
//----------четвертая часть: освобождение памяти -----
TElem* FreeStack(TElem* St);
//---------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "russian");
	TElem* StackTop1 = NULL, * StackTop2 = NULL, * StackTop3 = NULL;
	char ch;

	do {
		printf("\nN - создать новый стек; V - вывод; D - решение; F - освободить;E - конец.\nВаш выбор?\n");
		ch = getchar();   fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------первая часть: создание стека из текстового
		case 'N': if (StackTop1 || StackTop2) 
		{
			printf("Error: сначала надо освободить память!\n"); break;
		}
				printf("\nвведите первый стэк:\n");
				StackTop1 = CreateStack(StackTop1,0);
				printf("\nвведите второй стэк:\n");
				StackTop2 = CreateStack(StackTop2,1);
				break;
				//----------вторая часть: вывод стеков на экран ------
		case 'V':
			printf("Первый стек:\n"); OutputStack(StackTop1);
			printf("Второй стек:\n"); OutputStack(StackTop2);
			printf("Третий стек:\n"); OutputStack(StackTop3);
			getchar();
			break;
			//----------третья часть: решение задачи -------------
		case 'D': StackTop3 = Decide(&StackTop1, &StackTop2, StackTop3);
			getchar();
			break;
			//----------четвертая часть: освобождение памяти -----
		case 'F': StackTop1 = FreeStack(StackTop1);
			StackTop2 = FreeStack(StackTop2);
			StackTop3 = FreeStack(StackTop3);
			printf("Вся память под стеки особождена\n");
			getchar();
			break;
			//-----------------------выход------------------------
		case 'E': return 0;
		default:
			getchar();
			printf("Нет такой команды\nPress any key");
		}

	} while (ch != 'E');

	return 0;
}
//---------------------------------------------------------------------------
TElem* PushStack(TElem* St, TInfo Info) { // добавить элемент в стек
	TElem* Elem = new TElem;
	Elem->Info.num = Info.num;
	Elem->Next = St;
	return Elem; // Адрес новой вершины
}
TInfo PopStack(TElem** PSt)
{ //извлечь элемент из стека
	TElem* Elem = *PSt;
	TInfo Info = Elem->Info;
	*PSt = Elem->Next;
	delete Elem;
	return Info;
}
// дополнительная процедура перекладывания элемента из одного стека (StTop) в другой(Dop)
void TopToTop(TElem** PSt, TElem** St3)
{
	TElem* Elem, * StTop = *PSt, * Dop = *St3;
	Elem = StTop;
	StTop = StTop->Next;  // или StTop=(*StTop).Next;
	Elem->Next = Dop;
	Dop = Elem;
	*PSt = StTop; *St3 = Dop;  // сохранить новые адреса вершин по адресам PSt1 и PSt2
	return;
}
//----------первая часть: создание стека из текстового
TElem* CreateStack(TElem* St,int t)
{
	int kol = 0;
	TInfo Info;
	char nums[5];
	if(t==0)
		fgets(nums, 4, stdin);
	while (1) 
	{
		printf(" введите num или **\n");
		fgets(nums, 4, stdin);
		if (nums[1] == '*' && nums[0] == '*')
			break;
		fflush(stdin);
		Info.num = atoi(nums);
		St = PushStack(St, Info);
		kol++;
	}
	printf("Создан стек из %d элементов\n", kol);
	return St;
}
//----------вторая часть: вывод стека на экран ------
void OutputStack(TElem*& St) {
	TElem* Dop = NULL;
	TInfo inf;
	if (!St) printf("пустой\n");
	while (St) {
		inf = PopStack(&St);
		printf("%3d\n", inf.num);
		Dop = PushStack(Dop, inf);
	}
	while (Dop) TopToTop(&Dop, &St);
}
//----------третья часть: решение задачи -------------
TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3)
{
	TElem* St1 = *PSt1, * St2 = *PSt2;
	St3 = FreeStack(St3);

	int N = 0;
	while (St1 && St2)
	{
		N++;
		if (St1->Info.num > St2->Info.num)
			TopToTop(&St1, &St3);

		else
			TopToTop(&St2, &St3);
		
	}
	while (St1)
		TopToTop(&St1, &St3);
	while (St2)
		TopToTop(&St2, &St3);
	*PSt1 = St1;
	*PSt2 = St2;
if (N==0) 
printf("Стек пуст\n");
else 
printf("Всё хорошо\n");
return St3;  // новый адрес через результат функции вернется
}
//----------четвертая часть: освобождение памяти -----
TElem* FreeStack(TElem* St) {
	TInfo Info;
	while (St) {
		Info = PopStack(&St);
	}
	return St;
}
