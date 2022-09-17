// zd2 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Номер поезда, пункт назначения, дни следования, время прибытия, время отправления. Выбор по пункту назначения.

#include <iostream>
using namespace std;

void enter_new();
void out();
void  search();
int kol;
union forTrain
{
	char str[20];
	int limb;
};

struct Train
{
	forTrain number;
	forTrain place;
	forTrain days;
	forTrain timeAr;
	forTrain timeOut;
};
Train inf[256];
int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите число:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();	break;
		}
	} while (choice != 4);
}

void enter_new() {
	cout << "\nВведите колличество поездов ";
	cin >> kol;
	for (int i = 0; i < kol; i++) {
		cout << "\n\nСтрока номер " << i + 1;
		cout << "\n Номер поезда: ";
		cin >> inf[i].number.limb;
		cout << "\n Место отправления: ";
		cin >> inf[i].place.str;
		cout << "\n Дни отправления: ";
		cin >> inf[i].days.str;
		cout << "\n Время отправления: ";
		cin >> inf[i].timeAr.limb;
		cout << "\n Время отбытия: ";
		cin >> inf[i].timeOut.limb;
	}
	cout << "\nЧто дальше?" << endl;
	cin >> choice;
}

void out() {
	cout << "\nВывод информации на экран: ";
	for (int i = 0; i < kol; i++) {
		cout << "\n\nСтрока номер " << i + 1;
		cout << "\n Номер поезда: " << inf[i].number.limb;
		cout << "\n Место отправления: "<< inf[i].place.str;
		cout << "\n Дни отправления: "<< inf[i].days.str;
		cout << "\n Время отправления: "<< inf[i].timeAr.limb;
		cout << "\n Время отбытия: " << inf[i].timeOut.limb;
	}
	cout << "\nЧто дальше?" << endl;
	cin >> choice;
}

void  search() {
	char b[256];
	cout << "Введите пункт назначения ";
	cin >> b;
	for (int i = 0; i < kol; i++) {
		if (strcmp(inf[i].place.str, b) == 0) {
			cout << "\n\nСтрока номер " << i + 1;
			cout << "\n Номер поезда: " << inf[i].number.limb;
			cout << "\n Место отправления: " << inf[i].place.str;
			cout << "\n Дни отправления: " << inf[i].days.str;
			cout << "\n Время отправления: " << inf[i].timeAr.limb;
			cout << "\n Время отбытия: " << inf[i].timeOut.limb;
		}

	}
	cout << "\nЧто дальше?" << endl;
	cin >> choice;

}