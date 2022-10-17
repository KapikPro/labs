#include<iostream>
#include"tools.h"
#include"task_class.h"
#include"task_massiv.h"
#include<vector>
using namespace std;
void work_with_massiv()
{
	int a,b, k=0, t3;
	double t1;
	float t2;
	cout << "выберете массив для создания:\n1-double\n2-float\n3-int\n";
	while (try_read_int(a) != 1 && (a != 1 || a != 2 || a != 3))
		cout << "введите число 1, 2,3 или 4!\n";
		vector<double> v1;
		vector<float> v2;
		vector<int> v3;
	cout << "1-добавить элемент в массив\n2-вывод массива\n3-вывод кол-ва отрицательных элементов массива\n4-заменить все отрицательные элементы массива их квадратами и упорядочить элементы массива по возрастанию\n5-перезапустить программу\n";
	while (try_read_int(b) != 1 && (b != 1 || b != 2 || b != 3 || b!=4))
		switch (b)
		{
		case(1):
			if (a == 1)
			{
				try_read_double(t1);
				v1[k] = t1;
				k++;
			}
			if (a == 2)
			{
				try_read_float(t2);
				v2[k] = t2;
				k++;
			}
			if (a == 3)
			{
				try_read_int(t3);
				v3[k] = t3;
				k++;
			}
			break;
		case(2):
			cout << "вывод массива:\n";
			if (a == 1)
			{
				if (v1.size() == 0)
					cout << "массив пуст\n";
				else
				for (auto i : v1)
					cout << v1[i] << " ";
				cout << endl;
			}
			if (a == 2)
			{
				if (v2.size() == 0)
					cout << "массив пуст\n";
				else
				for (auto i : v2)
					cout << v2[i] << " ";
				cout << endl;
			}
			if (a == 3)
			{
				if (v3.size() == 0)
					cout << "массив пуст\n";
				else
				for (auto i : v3)
					cout << v3[i] << " ";
				cout << endl;
			}
			break;
		case(3):
			if (a == 1)
			{
				if (a == 1)
					cout << "количество отрицательных элементов равно " << condition_1(v1.begin(), v1.end())<<endl;
				if (a == 2)
					cout << "количество отрицательных элементов равно " << condition_1(v2.begin(), v2.end()) << endl;
				if (a == 3)
					cout << "количество отрицательных элементов равно " << condition_1(v3.begin(), v3.end()) << endl;
			}
			if (a == 2)
			{
			
			}
			if (a == 3)
			{
				
			}
			break;
		case(4):

			break;
		case(5):

			break;
		}
}
void work_with_class()
{

}
int main()
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
