// dop4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// c 33 начинаются сиволы

#include <iostream>
using namespace std;
#include <windows.h>
int k = 0;

int step(int n) {

	if (k != 26) {
		n++;
		k++;
		step(n);
	}
	else
	return n;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите n: " << endl;
	cin >> n;
	
	cout<<"Символ до ";
	printf("%c", n);
	cout << "\nСимвол после ";
	printf("%c", step(n));
	
}

