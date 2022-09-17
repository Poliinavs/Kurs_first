// dop2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <fstream>
#include "check.h"
using namespace std;

struct Integer
{
	Integer* head,
		* next,
		* end;

	int num;
} *Area, * NewEl;

string path = "data.txt";

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Area = new Integer;
	Area->head = Area;

	int min = 9000,
		numStr,
		i = 0;
	string str = " ";

	fstream file;
	file.open(path, fstream::in);

	while (!file.eof())
	{
		str = "";
		getline(file, str);
		if (str.size() <= min)
		{
			min = str.size();
			numStr = i + 1;
		}
		NewEl = new Integer;
		NewEl->num = str.size();
		NewEl->next = Area->head;
		Area->head = NewEl;
		i++;
		cout << i << ") " << str << endl;
	}

	ent;
	ent;
	cout << "Количесвто символов в строке= " << min
		<< "\nНомер строки= " << numStr << endl;

	cout << "количесвто сиволов в строках в файле:\n";
	i = 1;
	while (Area->head != Area)
	{
		cout << i++ << ") " << Area->head->num << endl;
		NewEl = Area->head->next;
		delete Area->head;
		Area->head = NewEl;
	}

	file.close();
	return 0;
}