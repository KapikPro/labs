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
struct TElem {  // ������������� ����� �� ������ ������������ ������
	TInfo Info;   //  ��� struct TInfo Info;
	TElem* Next;  // ��� struct TElem *Next; ����� � �����
};
//-----------------------���������-------------------------------------------
TElem* PushStack(TElem* St, TInfo Info); // �������� ������� � ����
TInfo PopStack(TElem** PSt);  //������� ������� �� �����~~~~~~
// �������������� ��������� �������������� �������� �� ������ ����� (StTop) � ������(Dop)
void TopToTop(TElem** PSt, TElem** St3); // ��� ��������� ������� ���������, ������ �����
//----------������ �����: �������� ����� �� ���������� �����
TElem* CreateStack(TElem* St, int t);
//----------������ �����: ����� ����� �� ����� ------
void OutputStack(TElem*& St);
//----------������ �����: ������� ������ -------------
TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3);
//----------��������� �����: ������������ ������ -----
TElem* FreeStack(TElem* St);
//---------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "russian");
	TElem* StackTop1 = NULL, * StackTop2 = NULL, * StackTop3 = NULL;
	char ch;

	do {
		printf("\nN - ������� ����� ����; V - �����; D - �������; F - ����������;E - �����.\n��� �����?\n");
		ch = getchar();   fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------������ �����: �������� ����� �� ����������
		case 'N': if (StackTop1 || StackTop2) 
		{
			printf("Error: ������� ���� ���������� ������!\n"); break;
		}
				printf("\n������� ������ ����:\n");
				StackTop1 = CreateStack(StackTop1,0);
				printf("\n������� ������ ����:\n");
				StackTop2 = CreateStack(StackTop2,1);
				break;
				//----------������ �����: ����� ������ �� ����� ------
		case 'V':
			printf("������ ����:\n"); OutputStack(StackTop1);
			printf("������ ����:\n"); OutputStack(StackTop2);
			printf("������ ����:\n"); OutputStack(StackTop3);
			getchar();
			break;
			//----------������ �����: ������� ������ -------------
		case 'D': StackTop3 = Decide(&StackTop1, &StackTop2, StackTop3);
			getchar();
			break;
			//----------��������� �����: ������������ ������ -----
		case 'F': StackTop1 = FreeStack(StackTop1);
			StackTop2 = FreeStack(StackTop2);
			StackTop3 = FreeStack(StackTop3);
			printf("��� ������ ��� ����� ����������\n");
			getchar();
			break;
			//-----------------------�����------------------------
		case 'E': return 0;
		default:
			getchar();
			printf("��� ����� �������\nPress any key");
		}

	} while (ch != 'E');

	return 0;
}
//---------------------------------------------------------------------------
TElem* PushStack(TElem* St, TInfo Info) { // �������� ������� � ����
	TElem* Elem = new TElem;
	Elem->Info.num = Info.num;
	Elem->Next = St;
	return Elem; // ����� ����� �������
}
TInfo PopStack(TElem** PSt)
{ //������� ������� �� �����
	TElem* Elem = *PSt;
	TInfo Info = Elem->Info;
	*PSt = Elem->Next;
	delete Elem;
	return Info;
}
// �������������� ��������� �������������� �������� �� ������ ����� (StTop) � ������(Dop)
void TopToTop(TElem** PSt, TElem** St3)
{
	TElem* Elem, * StTop = *PSt, * Dop = *St3;
	Elem = StTop;
	StTop = StTop->Next;  // ��� StTop=(*StTop).Next;
	Elem->Next = Dop;
	Dop = Elem;
	*PSt = StTop; *St3 = Dop;  // ��������� ����� ������ ������ �� ������� PSt1 � PSt2
	return;
}
//----------������ �����: �������� ����� �� ����������
TElem* CreateStack(TElem* St,int t)
{
	int kol = 0;
	TInfo Info;
	char nums[5];
	if(t==0)
		fgets(nums, 4, stdin);
	while (1) 
	{
		printf(" ������� num ��� **\n");
		fgets(nums, 4, stdin);
		if (nums[1] == '*' && nums[0] == '*')
			break;
		fflush(stdin);
		Info.num = atoi(nums);
		St = PushStack(St, Info);
		kol++;
	}
	printf("������ ���� �� %d ���������\n", kol);
	return St;
}
//----------������ �����: ����� ����� �� ����� ------
void OutputStack(TElem*& St) {
	TElem* Dop = NULL;
	TInfo inf;
	if (!St) printf("������\n");
	while (St) {
		inf = PopStack(&St);
		printf("%3d\n", inf.num);
		Dop = PushStack(Dop, inf);
	}
	while (Dop) TopToTop(&Dop, &St);
}
//----------������ �����: ������� ������ -------------
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
printf("���� ����\n");
else 
printf("�� ������\n");
return St3;  // ����� ����� ����� ��������� ������� ��������
}
//----------��������� �����: ������������ ������ -----
TElem* FreeStack(TElem* St) {
	TInfo Info;
	while (St) {
		Info = PopStack(&St);
	}
	return St;
}