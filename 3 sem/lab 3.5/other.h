#pragma once
#include "class_worker.h"
#include<vector>
using namespace std;

class boss : public  worker
{
public:
	boss(float plata, string fam,string otch,string name,string work, vector<worker> vec)
		:worker(plata, fam, otch, name, work)
	{
		_vec = vec;
	}
	void set_vec(worker c)
	{
		_vec.push_back(c);
	}
	worker get_worker(int n)
	{
		if (n <= _vec.size() - 1)
			return _vec[n];
		else
			cout << "вы ввели индекс элемента, которого нет в массиве\n";
	}
	int vec_size()
	{
		return _vec.size();
	}
private:
	vector<worker> _vec;
};
class secr : public  worker
{
public:
	secr(float plata, string fam, string otch, string name, string work, vector<worker>* vec, int vec_size)
		:worker(plata, fam, otch, name, work)
	{
		_vec = vec;
		_vec_size = vec_size;
	}
	void get_vector()
	{
		for (int i = 0; i < _vec_size; i++)
		{
			
			//cout << *(_vec+i)->get_fam();
		}
		cout << endl;
	}
private:
	vector<worker>* _vec;
	int _vec_size;
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
		cout << "категории транспорта, которыми кправляет водитель:\n";
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