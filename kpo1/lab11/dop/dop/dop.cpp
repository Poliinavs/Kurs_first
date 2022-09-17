// dop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <functional>
using namespace std;

void main()
{
	string str1 = "Hello";
	string str2 = "World!";
	string str = [=]()
	{
		if (str1.size() >= str2.size())
			return str1;
		else
			return str2;
	}();
	cout << str<<endl;
	string str3 = [](string s1, string s2) {
		return s1 + " " + s2;
	}(str1, str2);
	cout << str3 << endl;

}