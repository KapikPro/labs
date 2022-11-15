#pragma once
#include "class_worker.h"
#include<vector>
#include <memory>
using namespace std;


class adm : public  worker
{
public:
	adm(float plata, string fam, string otch, string name, string work, vector<string> obr)
		:worker(plata, fam, otch, name, work)
	{
		_obr = obr;
	}
	void get_obr()
	{
		cout << "вывод оборудования системного администратора:\n";
		for (int i = 0; i < _obr.size(); i++)
		{
			cout << _obr[i] << endl;
		}
	}
	vector<string> vozv_obr()
	{
		return _obr;
	}
	void set_obr(string s)
	{
		_obr.push_back(s);
	}
	void sset_obr(vector<string> obr)
	{
		_obr = obr;
	}
private:
	vector<string> _obr;
};
class vodila : public  worker
{
public:
	vodila(float plata, string fam, string otch, string name, string work, vector<string> prava,vector<string> tran)
		:worker(plata, fam, otch, name, work)
	{
		_prava = prava;
		_tran = tran;
	}
	void get_prava()
	{
		cout << "категории прав:\n";
		for (int i = 0; i < _prava.size(); i++)
		{
			cout << _prava[i]<<endl;
		}
	}
	void set_prava(string a)
	{
		_prava.push_back(a);
	}
	void set_tran(string a)
	{
		_tran.push_back(a);
	}
	void get_tran()
	{
		cout << "категории транспорта, которыми управляет водитель:\n";
		for (int i = 0; i < _tran.size(); i++)
		{
			cout << _tran[i] << endl;
		}
	}
private:
	vector<string> _prava;
	vector<string> _tran;
};

class proger : public  worker
{
public:
	proger(float plata, string fam, string otch, string name, string work, string cat, vector<string> teh)
		:worker(plata, fam, otch, name, work)
	{
		_cat = cat;
		_teh = teh;
	}
	string get_cat()
	{
		return _cat;
	}
	void set_cat(string cat)
	{
		_cat = cat;
	}
	void set_teh(string a)
	{
		_teh.push_back(a);
	}
	void get_teh()
	{
		cout << "технологии программирования, которыми владеет прогер:\n";
		for (int i = 0; i < _teh.size(); i++)
		{
			cout << _teh[i] << endl;
		}
	}
private:
	string _cat;
	vector<string> _teh;
};
class boss : public  worker
{
public:
	boss(float plata, string fam, string otch, string name, string work, vector<worker> vec)
		:worker(plata, fam, otch, name, work)
	{
		_vec = vec;
	}
	void set_worker(worker c)
	{
		_vec.push_back(c);
	}
	void set_adm(adm c)
	{
		_a.resize(_vec.size());
		_a[_vec.size() - 1].set_fam(c.get_fam());
		_a[_vec.size() - 1].set_name(c.get_name());
		_a[_vec.size() - 1].set_otch(c.get_otch());
		_a[_vec.size() - 1].set_plata(c.get_plata());
		_a[_vec.size() - 1].set_work(c.get_work());
		_a[_vec.size() - 1].sset_obr(c.vozv_obr());
	}
	adm get_adm(int n)
	{
		if (n <= _a.size() - 1 && n >= 0)
			return _a[n];
		else
			cout << "вы ввели индекс элемента, которого нет в массиве\n";
	}
	vodila get_driver(int n)
	{
		if (n <= _v.size() - 1 && n >= 0)
			return _v[n];
		else
			cout << "вы ввели индекс элемента, которого нет в массиве\n";
	}
	proger get_proger(int n)
	{
		if (n <= _p.size() - 1 && n >= 0)
			return _p[n];
		else
			cout << "вы ввели индекс элемента, которого нет в массиве\n";
	}
	void set_proger(proger c)
	{
		_p.resize(_vec.size());
		_p[_vec.size() - 1] = (c);
	}
	void set_driver(vodila c)
	{
		_v.resize(_vec.size());
		_v[_vec.size()-1]=(c);
	}
	void del_worker(int ind)
	{
		if(_vec[ind].get_work()=="")
		_vec.erase(_vec.begin() + ind);
	}
	worker get_worker(int n)
	{
		if (n <= _vec.size() - 1 && n>=0)
			return _vec[n];
		else
			cout << "вы ввели индекс элемента, которого нет в массиве\n";
	}
	int vec_size()
	{
		return _vec.size();
	}
	void viv_workers()
	{
		for (int i = 0; i < _vec.size(); i++)
		{
			cout << i + 1 << "-" << _vec[i].get_fam() << " " << _vec[i].get_name() << " " << _vec[i].get_otch() << "-" << _vec[i].get_work() << endl;
		}
	}
private:
	vector<worker> _vec;
	vector<adm> _a;
	vector<vodila> _v;
	vector<proger> _p;
};