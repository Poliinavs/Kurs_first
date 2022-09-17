#include "Hash.h"
#include <iostream>
#include<fstream>
using namespace std;

struct AAA // тип структур AAA, У-ли на которые хранятся в хэш-таблице, точнее в строках хэш-таблицы
{
	int key; // ключ, ПОЛЕ
	char* mas; // строка, то есть массив символов, ПОЛЕ
	AAA(int k, char* z) // целое число key и строка mas, конструктор с параметрами
					   // конструктор записывает ключ и строку в поля структуры
	{
		key = k;
		mas = z;
	}
	AAA() {} // конструктор без параметров
};

int key(void* d) // функция добавления данных, введённых с клавиатуры, в ключ
{
	AAA* f = (AAA*)d; // преобразуем У-ль на произвольные данные d в У-ль f на структуру AAA 
	return f->key;
	// возвращаем ключ структуры AAA по указателю f, то есть через У-ль обращаемся к ПОЛЮ int key
}

void AAA_print(void* d) // функция вывода 1 Э-а списка по У-лю на этот Э-т
{
	cout << "Ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}


void main()
{
	//system("chcp 1251");
	setlocale(LC_ALL, "rus");
	int siz;
	AAA* a;
	char* str;
	cout << "Введите размер хэш-таблицы" << endl;
	cin >> siz;
	Object H = Create(siz, key);	// создать хэш-таблицу заданных размеров
	int choise; 				// переменная для ввода выбора пользователя
	int k;					// ввод ключа в эту переменную
	for (;;)
	{
		system("cls");
		cout << "Меню:" << endl;
		cout << "1 - вывод хэш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "5 - коэффициент заполнения таблицы" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choise;
		switch (choise)
		{
		case 0: exit(0); // условия окончания работы программы
		case 1: H.Scan(AAA_print); break;
		case 2:
		{
			int k = 0;
			fstream doc("doc.txt");
			while (doc)
			{
				k = 0;
				str = new char[10];
				doc.getline(str, 10);
				for (int i = 0; i < 10; i++)
					k += (int)str[i];
				if (k > 0) {
					a = new AAA();
					a->key = k;
					a->mas = str;
					H.Insert(a);
				}
			}
		}
		break;
		case 3:
			cout << "Введите ключ для удаления " << endl;
			cin >> k;
			H.Delete(k);
			break;
		case 4:
			cout << "Введите ключ для поиска " << endl;
			str = new char[10];
			k = 0;
			cin >> str;
			for (int i = 0; i < 10; i++)
				k += (int)str[i];
			if (H.Search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else  AAA_print(H.Search(k));
			break;
		case 5:
			cout << "Таблица заполнена на " << H.koefzap() * 100 << "%" << endl;
			break;
		}
		system("pause");
	}
}
