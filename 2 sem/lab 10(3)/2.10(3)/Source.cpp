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
struct TElem {  // моделирование стека на основе односв€зного списка
	TInfo Info;   //  или struct TInfo Info;
	TElem* Next;  // или struct TElem *Next; здесь и далее
};
//-----------------------прототипы-------------------------------------------
TElem* PushStack(TElem* St, TInfo Info); // добавить элемент в стек
TInfo PopStack(TElem** PSt);  //извлечь элемент из стека~~~~~~
// дополнительна€ процедура перекладывани€ элемента из одного стека (StTop) в другой(Dop)
void TopToTop(TElem** PSt, TElem** St3); // без изменени€ адресов элементов, только св€зи
//----------перва€ часть: создание стека из текстового файла
TElem* CreateStack(TElem* St);
//----------втора€ часть: вывод стека на экран ------
void OutputStack(TElem*& St);
//----------треть€ часть: решение задачи -------------
TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3);
//----------четверта€ часть: освобождение пам€ти -----
TElem* FreeStack(TElem* St);
//---------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "russian");
	TElem* StackTop1 = NULL, * StackTop2 = NULL, * StackTop3 = NULL;
	char ch;

	do {

		printf("\nN - создать новый стек; V - вывод; D - решение; F - освободить;E - конец.\n¬аш выбор?\n");
		ch = getchar();   fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------перва€ часть: создание стека из текстового
		case 'N': if (StackTop1 || StackTop2) 
		{
			printf("Error: сначала надо освободить пам€ть!\n"); break;
		}
				StackTop1 = CreateStack(StackTop1);
				StackTop2 = CreateStack(StackTop2);
				break;
				//----------втора€ часть: вывод стеков на экран ------
		case 'V':
			printf("ѕервый стек:\n"); OutputStack(StackTop1);
			printf("¬торой стек:\n"); OutputStack(StackTop2);
			printf("“ретий стек:\n"); OutputStack(StackTop3);
			break;
			//----------треть€ часть: решение задачи -------------
		case 'D': StackTop3 = Decide(&StackTop1, &StackTop2, StackTop3);
			break;
			//----------четверта€ часть: освобождение пам€ти -----
		case 'F': StackTop1 = FreeStack(StackTop1);
			StackTop2 = FreeStack(StackTop2);
			StackTop3 = FreeStack(StackTop3);
			printf("¬с€ пам€ть под стеки особождена\n");
			break;
			//-----------------------выход------------------------
		case 'E': return 0;
		default:
			printf("Ќет такой команды\nPress any key");
		}

	} while (ch != 'E');

	return 0;
}
//---------------------------------------------------------------------------
TElem* PushStack(TElem* St, TInfo Info) { // добавить элемент в стек
	TElem* Elem = new TElem;
	Elem->Info.num = Info.num;
	Elem->Next = St;
	return Elem; // јдрес новой вершины
}
TInfo PopStack(TElem** PSt)
{ //извлечь элемент из стека
	TElem* Elem = *PSt;
	TInfo Info = Elem->Info;
	*PSt = Elem->Next;
	delete Elem;
	return Info;
}
// дополнительна€ процедура перекладывани€ элемента из одного стека (StTop) в другой(Dop)
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
//----------перва€ часть: создание стека из текстового
TElem* CreateStack(TElem* St)
{
	int kol = 0;
	TInfo Info;
	char nums[5];

	while (1) {
		printf("num =?");
		printf("1\n");
		fgets(nums, 4, stdin);
		fflush(stdin);
		Info.num = atoi(nums);
		St = PushStack(St, Info);
		kol++;
	}
	printf("—оздан стек из %d элементов\n", kol);
	return St;
}
//----------втора€ часть: вывод стека на экран ------
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
//----------треть€ часть: решение задачи -------------
TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3)
{
	TElem* St1 = *PSt1, * St2 = *PSt2, * Dop = NULL;
	St3 = FreeStack(St3);

	int Sum = 0, N = 0;
	while (St1 || St2)
	{
		N++;
		if (St1->Info.num > St2->Info.num)
			St3 = PushStack(St3, St1->Info);
		else
			St3 = PushStack(St3, St2->Info);
	}
if (N==0) 
printf("—тек пуст\n");
else 
printf("¬сЄ хорошо\n");
return St3;  // новый адрес через результат функции вернетс€
}
//----------четверта€ часть: освобождение пам€ти -----
TElem* FreeStack(TElem* St) {
	TInfo Info;
	while (St) {
		Info = PopStack(&St);
	}
	return St;
}
