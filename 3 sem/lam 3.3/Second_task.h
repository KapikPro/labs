#pragma once
using namespace std;

class LongInt
{
public:
	LongInt(long number)
	{
		_number = number;
	}
	long get_number()
	{
		return _number;
	}
	friend LongInt operator* (LongInt a1, LongInt a2)
	{
		return LongInt(a1._number * a2._number);
	}

	LongInt operator+ (LongInt a2)
	{
		return LongInt(_number + a2._number);
	}
private:
	long _number;
};