#pragma once
template<typename T>
void output(T* begin, T* end)
{
	for (t* i = begin; i != end; i++)
		cout << *i << " ";
	cout << endl;
}