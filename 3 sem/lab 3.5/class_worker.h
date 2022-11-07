#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	worker(float plata, string fam, string otch, string name,string work)
	{
		_work = work;
		_plata = plata;
		_fam = fam;
		_otch = otch;
		_name = name;
	}
	string get_name()
	{
		return _name;
	}
	void set_name(string name)
	{
		_name = name;
	}
	string get_fam()
	{
		return _fam;
	}
	void set_fam(string fam)
	{
		_fam = fam;
	}
	string get_otch()
	{
		return _otch;
	}
	void set_otch(string otch)
	{
		_otch = otch;
	}
	void set_work(string work)
	{
		_work = work;
	}
	string get_work()
	{
		return _work;
	}
private:
	string _name;
	string _fam;
	string _otch;
	string _work;
	float _plata;
};