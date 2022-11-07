#include<iostream>
#include<string>
#include"class_worker.h"
#include"other.h"
#include"tools.h"
using namespace std;
void first()
{
	int a,k=1,b,t=0;
	vector<boss> osn;
	vector<worker> baza;
	float plata;
	string fam, otch, name, work, name_boss, fam_boss,otch_boss;
	vector<worker> vec;
	cout << "меню:\n";
	cout << "1-вывести меню\n2-добавить сотрудника\n3-вывести список всех сотрудников одного из юоссов или секретарей\n4-вывод на экран определЄнного сотрудника(с доп данными профессии)\n5-завершить работу с заданием\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2 && a!=3 && a!=4 && a!=5))
		cout << "вы ввели что-то страшное, повторите ввод\n";
	while (1)
	{
		if (k == 0)
			break;
		switch (a)
		{
		case(1):
			cout << "1-вывести меню\n2-добавить сотрудника\n3-вывести список сотрудников одного из боссов или секретарей\n4-вывод на экран определЄнного сотрудника\n5-завершить работу с заданием\n";
			break;
		case(2):
			cout << "вы хотите добавить нового директор или обычного сотрудника?\n1-директора\n2-обычного сотрудника\n";
			while (try_read_int(b) != 1 || (b != 1 && b != 2))
				cout << "вы ввели что-то страшное, повторите ввод\n";
			if (b == 1)
			{
				cout << "¬ведите зарплату сотрудника:\n";
				while (try_read_float(plata)!=1)
					cout << "вы ввели что-то страшное, повторите ввод\n";
				cout << "¬ведите фамилию сотрудника:\n";
				cin >> fam;
				cout << "¬ведите им€ сотрудника:\n";
				cin >> name;
				cout << "¬ведите отчество сотрудника:\n";
				cin >> otch;
				work = "boss";
				boss Alex(plata,fam,otch,name,work,vec);
				osn.push_back(Alex);
			}
			else
			{
				cout << "¬ведите зарплату сотрудника:\n";
				while (try_read_float(plata)!=1)
					cout << "вы ввели что-то страшное, повторите ввод\n";
				cout << "¬ведите фамилию сотрудника:\n";
				cin >> fam;
				cout << "¬ведите им€ сотрудника:\n";
				cin >> name;
				cout << "¬ведите отчество сотрудника:\n";
				cin >> otch;
				cout << "введите 1, если сотрудник секретарь\n2, если сотрудник программист\n3, если сотрудник водитель\n";
				while (try_read_int(b) != 1 || (a != 1 && a != 2 && a!=3))
					switch (b)
					{
					case(1):
						break;
					case(2):
						break;
					case(3):
						break;
					}
					cout << "вы ввели что-то страшное, повторите ввод\n";
				worker Bob(plata, fam, otch, name, work);
				cout << "выберете босса, к которому хотите направить сотрудника в подчинение(введите фамилию, им€ и отчество):\n";
				while (1)
				{
					cin >> fam_boss;
					cin >> name_boss;
					cin >> otch_boss;
					for (int i = 0; i < osn.size(); i++)
					{
						if (osn[i].get_name() == name_boss && osn[i].get_fam() == fam_boss && osn[i].get_otch() == otch_boss)
						{
							t = 1;
							osn[i].set_vec(Bob);
							break;
						}
					}
					if (t == 1)
					{
						t = 0;
						break;
					}
					else
						cout << "такого босса не обнаружено, повторите ввод\n";
				}
				
			}
			break;
		case(3):

			break;
		case(4):
			break;
		case(5):
			k = 0;
			break;
		}
	}
}
void second()
{

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "введите 1, если хотите работать с пунктом 5.1 или 2, если с пунктом 5.2\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2))
		cout << "вы ввели что-то страшное, повторите ввод\n";
	switch (a)
	{
	case(1):
		first();
		break;
	case(2):
		second();
		break;
	}
	main();
}