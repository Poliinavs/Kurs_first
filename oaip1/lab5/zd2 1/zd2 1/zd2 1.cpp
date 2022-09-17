// zd2 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//вар 1 номер 2!!!!!    Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Выборка по году рождения. Дату рождения органи-зовать с помощью битового поля, пол  с помощью перечисления

#include <iostream>
using namespace std;
void vvod();
void putout();
void delit();
void poisk();
	struct Infcitizen
	{
		char name[256];
		char adres[256];
		unsigned  data : 25;
	};
	struct Infcitizen people[256];

	enum gender {
		women=1, men
	}pol;

	Infcitizen b[15];
	int l;
	int kol, choose;
int main()
{
    setlocale(LC_CTYPE, "ru");
	do {
		cout << "\nВыберите, что сделать:\n1 — Ввод информации ;\n2 — вывести в консоль информацию о сотруднике;\n3 — удалить информацию о сотруднике;\n4 — поиск информации.\n 5-выход из программы\n";
		cin >> choose;
		switch (choose)
		{
		case 1: vvod(); break;
		case 2: putout(); break;
		case 3:delit(); break;
		case 4:poisk(); break;
		case 5: break;
		}
	} while (choose != 5);

}
int p[10];
void vvod() {
	cout << "\nВведите колличество горожан: ";
	cin >> kol;
	for (int i = 0; i < kol; i++) {
		cout << "\nГорожанин № " << i + 1;
		cout << "\nВведите ФИО горожанина: ";
		cin >> people[i].name; 
		cout << "\n Введите адрес: ";
		cin >> people[i].adres;
		cout << "\nВведите дату: ";
		cin>> l;
		b[i].data = l;
		cout << "\nВыберите пол: 1-ж, 2-м";
		cin >> p[i];
		if (p[i] == women)
			cout << "\n Выбранный пол- женский";
		if (p[i] == men)
			cout << "\n Выбранный пол- мужской ";
	}

}

void putout() {

	for (int i = 0; i < kol; i++) {
		cout << "\nГорожанин № " << i + 1;
		cout << "\n ФИО горожанина: "<<people[i].name;
		cout << "\n Адрес: "<< people[i].adres;
		cout << "\nДата: " << b[i].data;
		if (p[i] == women)
			cout << "\n Пол- женский";
		if (p[i] == men)
			cout << "\n Пол- мужской ";
	}
}

void delit() {
	int c;
	cout << "Информацию о каком сотрудниике хотите удалить ";
	cin >> c;
	int i = c - 1;
	for (i; i < kol; i++)
		people[i] = people[i + 1];
	kol = kol - 1;
}

void poisk() {
	int i, c;
	cout << "Введите дату по которой должен быть поиск ";
	cin >> c;
	for (int i = 0; i < kol; i++) {
		if (b[i].data == c) {
			cout << "\n\nГорожанин номер " << i+1;
			cout << "\n ФИО горожанина: " << people[i].name;
			cout << "\n Адрес: " << people[i].adres;
			cout << "\nДата: " << b[i].data;
			if (p[i] == women)
				cout << "\n Пол- женский";
			if (p[i] == men)
				cout << "\n Пол- мужской ";
		}
}
	
}



	
