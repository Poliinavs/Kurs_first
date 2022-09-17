﻿#include "Hash_Twin_Chain.h"
#include <iostream>
using namespace std;
unsigned char rand8[256];
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z) //конструктор с параметрами
	{
		key = k;
		mas = z;
	}
	AAA()//конструктор без параметров
	{
		key = 0;
		mas = (char*)"";
	}
};
//-------------------------------
int hf(void* d) // функция получения ключа (3 вариант)
{
	double A;
	A = (sqrt(5.0f) - 1.0f) / 2.0f;
	std::cout << A;
	AAA* f = (AAA*)d;
	return  f->key * A;
}
int hf1(void* d) // функция получения ключа
{
	AAA* f = (AAA*)d;
	unsigned char h = 0;
	char i = 0;
	while (*(f->mas))
	{
		h = rand8[h ^ *(f->mas)++];
		i++;
	}
	f->mas -= i;
	return h;
}
//-------------------------------
void AAA_print(listx::Element* e) // функция вывода ключа и значений 
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;
	for (int i = 0; i < 256; i++)
		rand8[i] = rand() % 255;
	hashTC::Object H = hashTC::create(current_size, hf); //Создание таблицы 
	int choice; // переменная для выбора 
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA; // структура данных
			char* str = new char[20]; //заполнение 
			cout << "введите номер паспорта" << endl;
			cin >> k;
			a->key = k;
			cout << "введите имя клиента" << endl;
			cin >> str;
			a->mas = str;
			H.insert(a); //функция добавления в таблицу 
		}
			  break;
		case 1: H.Scan(); // функция вывода талицы
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "введите номер паспорта" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b); // функция удаления 
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "введите номер паспорта" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL) //поиск элемента 
				cout << "паспорт не найден" << endl;
			else
			{
				cout << "паспорт с данным номером" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}