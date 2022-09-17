// findcifr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int end = 0, kol=0;
	int right, left, middle, var;
	cout << "\nВведите нижнюю границу даипазона в которм находится загаданное число: ";
	cin >> left;
	cout << "\nВведите верхнюю границу даипазона в которм находится загаданное число: ";
	cin >> right;
	int t= (left + right) / 2;
	while (left <= right && end==0 ) {
		middle = (left+right) / 2;
				cout << "\nЧисло: \t" << middle;
				cout << "\nВыбирете : 1-загаданное число больше, 2-загаданное число меньше, 3-угадал   ";
				cin >> var;
				switch (var) {
				case 1: left = middle + 1; break;
				case 2: right = middle - 1; break;
				case 3: {cout << "Ваше число: " << middle; end = 1; break; }
				
			}	
		
	}
	cout << "\nШаги бинарного поиска: ";
	for (t; t > 0; t=t/2) {
		cout << t<<"\t";
		kol++;
	}
	
	cout << "\nМаксимальное количество шагов: " << kol;
}





