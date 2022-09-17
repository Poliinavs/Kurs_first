// TRAIN.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// >Введенного времени появл все поезда и их информ в алфив по пунктам назн

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Train
{
	char Nazn[30];
	int Nom;
	int time;
};
Train a[30];


int main()
{
	char cur[30];
	setlocale(LC_ALL, "Russian");
	int kol, b, counter=0, swap, sn;
	cout << "Введите колличество поездов: ";
	cin >> kol;
	for (int i = 0; i < kol; i++)
	{
		cout << "Введите название пункта назначения " << i + 1 << "-ого поезда " << endl;
		cin >> a[i].Nazn;
		cout << endl << "номер поезда: ";
		cin >> a[i].Nom;
		cout << endl << "Время отправления: ";
		cin >> a[i].time;
		

	}

	cout << endl << "Введите время после которого нужно искать поезда: ";
	cin >> b;
	cout << endl;
	for (int i = 0; i < kol; i++)
	{
		if (b < a[i].time)
		{
			
				cout << "Станция: \t " << a[i].Nazn << "\n";
				cout << "Номер: \t " << a[i].Nom << "\n";
				cout << "Время: \t " << a[i].time << "\n";
		
/*
for (int j = i + 1; j < kol; j++) {
				if (strcmp(a[i].Nazn, a[j].Nazn) > 0)
				{
					strcpy_s(cur, a[i].Nazn);
					strcpy_s(a[i].Nazn, a[j].Nazn);
					strcpy_s(a[j].Nazn, cur);
					swap = a[i].time;
					a[i].time = a[j].time;
					a[j].time = swap;
					
					sn = a[i].Nom;
					a[i].Nom = a[j].Nom;
					a[j].Nom = sn;

				}
			}*/
			
			
			counter++;
		}


	}
	
		
	if (counter == 0) {
		cout << "После этого времени нет поездов";
	}
	return 0;

   
}

