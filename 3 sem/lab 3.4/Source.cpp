#include<iostream>
#include"tools.h"
#include"task_class.h"
#include"task_massiv.h"
using namespace std;
void work_with_massiv()
{
	cout << "1-добавить элемент в массив\n2-вывод кол-ва отрицательных элементов массива\n3-";
}
void work_with_class()
{

}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "1-задание с шаблоном функции\n2-задание с шаблоном класса\n";
	while (try_read_int(a) != 1 && (a != 1 || a != 2))
		cout << "введите число 1 или 2!\n";
	if (a == 1)
		work_with_massiv();
	else
		work_with_class();
}
