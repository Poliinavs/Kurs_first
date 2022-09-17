// dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
int mn;
int st;
void ch(int k) {
	ofstream fout;
	fout.open("Dop_1.txt");
	if (mn <= k) {
		

	fout << mn << '\n';

		cout << mn << endl;
		mn++;
		ch(k);
	}
	fout.close();
	

}

int main()
{
	int f, k;
	
	setlocale(LC_ALL, "Russian");
	cout << "Введите число: ";
	cin >> f;
	k = f;
	while (f >= 10) {
		st++;
		f = f / 10;
	}
	
	mn = pow(10, st);
	
	ch(k);

	
	return 0;
}
