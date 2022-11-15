#include<iostream>
#include<string>
#include"class_worker.h"
#include"other.h"
#include"tools.h"
using namespace std;
void first()
{
	int a,k=1,b,t=0,d=0;
	string s="1", cat;
	vector<boss> osn;
	vector<string> ob,prava,tran,teh;
	float plata;
	string fam, otch, name, work, name_boss, fam_boss,otch_boss;
	vector<worker> vec;
	cout << "меню:\n";
	cout << "1-вывести меню\n2-добавить сотрудника\n3-вывести список всех сотрудников одного из боссов\n4-вывод на экран определённого сотрудника(с доп данными профессии)\n5-завершить работу с заданием\n";
	while (try_read_int(a) != 1 || (a != 1 && a != 2 && a!=3 && a!=4 && a!=5))
		cout << "вы ввели что-то страшное, повторите ввод\n";
	while (1)
	{
		if (k == 0)
			break;
		switch (a)
		{
		case(1):
			cout << "1-вывести меню\n2-добавить сотрудника\n3-вывести список сотрудников одного из боссов(и при желании все данные 1 из них)\n4-удалить сотрудника\n5-завершить работу с заданием\n";
			break;
		case(2):
			cout << "вы хотите добавить нового директорa или обычного сотрудника?\n1-директора\n2-обычного сотрудника\n";
			while (try_read_int(b) != 1 || (b != 1 && b != 2))
				cout << "вы ввели что-то страшное, повторите ввод\n";
			if (b == 1)
			{
				cout << "Введите зарплату сотрудника:\n";
				while (try_read_float(plata)!=1)
					cout << "вы ввели что-то страшное, повторите ввод\n";
				cout << "Введите фамилию сотрудника:\n";
				cin >> fam;
				cout << "Введите имя сотрудника:\n";
				cin >> name;
				cout << "Введите отчество сотрудника:\n";
				cin >> otch;
				work = "boss";
				boss Alex(plata,fam,otch,name,work,vec);
				osn.push_back(Alex);
			}
			else
			{
				cout << "Введите зарплату сотрудника:\n";
				while (try_read_float(plata)!=1)
					cout << "вы ввели что-то страшное, повторите ввод\n";
				cout << "Введите фамилию сотрудника:\n";
				cin >> fam;
				cout << "Введите имя сотрудника:\n";
				cin >> name;
				cout << "Введите отчество сотрудника:\n";
				cin >> otch;
				cout << "введите 1, если сотрудник системный администратор\n2, если сотрудник программист\n3, если сотрудник водитель\n";
				while (try_read_int(d) != 1 || (d != 1 && d != 2 && d!=3))
					cout << "вы ввели что-то страшное, повторите ввод\n";
					switch (d)
					{
					case(1):
						work = "admin";
						break;
					case(2):
						work = "programist";
						break;
					case(3):
						work = "driver";
						break;
					}	
				worker Bob(plata, fam, otch, name, work);
				cout << "выберете босса, к которому хотите направить сотрудника в подчинение(введите фамилию, имя и отчество):\n";
					cout << "список боссов:\n";
					if (osn.size() == 0)
						cout << "боссов не обнаружено\n";
					else
					{
						for (int i = 0; i < osn.size(); i++)
							cout << i + 1 << "-" << osn[i].get_fam() << " " << osn[i].get_name() << " " << osn[i].get_otch() << endl;
						cout << "выберете номер нужного босса:\n";
						while (try_read_int(t) != 1 || t<1 || t>osn.size())
							cout << "вы ввели что-то страшное, повторите ввод\n";
						t--;
						osn[t].set_worker(Bob);
						switch (d)
						{
						case(1):
							cout << "вводите оборудование администатора, когда захотите закончить введите '-'\n";
							ob.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if(s!="-")
								ob.push_back(s);
							}
							if (1)
							{
								adm A(plata, fam, otch, name, work, ob);
								osn[t].set_adm(A);
							}
							break;
						case(2):
							cout << "вводите уровень программиста\n";
							cin >>cat;
							cout << "вводите технологии, которыми владеет программист, когда захотите закончить введите '-'\n";
							teh.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if (s != "-")
									teh.push_back(s);
							}
							if (1)
							{
								proger A(plata, fam, otch, name, work, cat, teh);
								osn[t].set_proger(A);
							}
							break;
						case(3):
							cout << "вводите категории прав водителя, когда захотите закончить введите '-'\n";
							prava.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if (s != "-")
									prava.push_back(s);
							}
							cout << "вводите категории транспорта водителя, когда захотите закончить введите '-'\n";
							tran.clear();
							s = "1";
							while (s != "-")
							{
								cin >> s;
								if (s != "-")
									tran.push_back(s);
							}
							if (1)
							{
								vodila A(plata, fam, otch, name, work, prava,tran);
								osn[t].set_driver(A);
							}
							break;
						}
					}
			}
			break;
		case(3):
			cout << "выберете босса, у которого хотите вывести сотрудников:\n";
			if (osn.size() == 0)
				cout << "боссов не обнаружено\n";
			else
			{
				for (int i = 0; i < osn.size(); i++)
					cout << i + 1 << "-" << osn[i].get_fam() << " " << osn[i].get_name() << " " << osn[i].get_otch() << endl;
				cout << "выберете номер нужного босса:\n";
				while (try_read_int(t) != 1 || t<1 || t>osn.size())
					cout << "вы ввели что-то страшное, повторите ввод\n";
				t--;
				osn[t].viv_workers();
				cout << "вы хотите просмотреть точные данные одного из них?\n1-да\n2-нет";
				while (try_read_int(b) != 1 || (b != 1 && b != 2))
					cout << "вы ввели что-то страшное, повторите ввод\n";
				if (b == 1)
				{
					cout << "введите номер нужного сотрудника:\n";
					while (try_read_int(d) != 1 || d<1 || d>osn[t].vec_size())
						cout << "вы ввели что-то страшное, повторите ввод\n";
					d--;
					if(osn[t].get_work() == "admin")
					{
						cout << "работа - системный администратор\n";
						cout << "Фио - " << osn[t].get_adm(d).get_fam() << " " << osn[t].get_adm(d).get_name() << " " << osn[t].get_adm(d).get_otch() << endl;
						cout << "зарплата - " << osn[t].get_adm(d).get_plata() << endl;
						osn[t].get_adm(d).get_obr();
				    }
					else
						if (osn[t].get_work() == "driver")
						{
							cout << "работа - системный администратор\n";
							cout << "Фио - " << osn[t].get_driver(d).get_fam() << " " << osn[t].get_driver(d).get_name() << " " << osn[t].get_driver(d).get_otch() << endl;
							cout << "зарплата - " << osn[t].get_driver(d).get_plata() << endl;
							osn[t].get_driver(d).get_prava();
							osn[t].get_driver(d).get_tran();
						}
						else
						{
							cout << "работа - программист\n";
							cout << "Фио - " << osn[t].get_proger(d).get_fam() << " " << osn[t].get_proger(d).get_name() << " " << osn[t].get_proger(d).get_otch() << endl;
							cout << "зарплата - " << osn[t].get_proger(d).get_plata() << endl;
							cout << " уровень программиста - " << osn[t].get_proger(d).get_cat() << endl;
							osn[t].get_proger(d).get_teh();
						}
				}
			}
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