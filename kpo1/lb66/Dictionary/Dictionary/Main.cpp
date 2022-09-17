#include <iostream>
#include <windows.h>
using namespace std;
#include "stdafx.h"
using namespace Dictionary;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	try
	{
#if defined(TEST_CREATE_01)   //проверка на превышении имени словаря
		Instance d1 = Create("Преподaвателmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmи", 5);
#error Create: превышен размер имени словаря
#elif defined(TEST_CREATE_02)    // проверка на превышен размер максимальной емкости словаря
		Instance d1 = Create("Преподaватели", 10000);
#else 
		Instance d1 = Create("Преподaватели", 5);// создание словаря
#endif                                              
		Entry e1 = { 1, "Гладкий" },      // элементы словаря;
			e2 = { 2, "Веялкин" },
			e3 = { 3, "Смелов" },
			e4 = { 4, "Урбанович" },
#if defined(TEST_ADDENTRY_04)    //проверка на дублирование идентификатора
			e5 = { 2, "Наркевич" };

#else 
			e5 = { 5, "Наркевич" };
#endif
		AddEntry(d1, e1);				//добавление элемента словарь
		AddEntry(d1, e2);				//добавление элемента словарь
		AddEntry(d1, e3);			//добавление элемента словарь
		AddEntry(d1, e4); 
		AddEntry(d1, e5);//добавление элемента словарь
	
#if defined(TEST_ADDENTRY_03)   //переполнение словаря
		AddEntry(d1, e5);
#endif
		cout << "Исходный словарь преподавателей\n";
		Print(d1);
#if defined(TEST_GETENTRY_05)
		Entry ex2 = GetEntry(d1, 10);
#else
		Entry ex2 = GetEntry(d1, 4); //получение элемента словаря 
#endif
#if defined(TEST_DELENTRY_06) //не найден элемент
		DelEntry(d1, 20);
#else
		DelEntry(d1, 2); // удаление элемента словаря
#endif
		cout << "\nСловарь после удаления 2 элемента: \n";
		Print(d1);
#if defined(TEST_UPDENTRY_08)   //дублирование идентификатора
		Entry newentry1 = { 1, "Гурин" };
#else 
		Entry newentry1 = { 6, "Гурин" };
#endif
#if defined(TEST_UPDENTRY_07) // не найден элемент
		UpdEntry(d1, 30000, newentry1);
#else
		UpdEntry(d1, 3, newentry1); //добавление элемента
#endif
		cout << "\nСловарь после замены элемента с ID 3: \n";
		Print(d1);
		Instance d2 = Dictionary::Create("Студенты", 7);
		Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3,"Сидоров" },s4 = {4, "Козлов"}, s5 = { 5, "Смирнов" }, s6 = { 6, "Кузнецов" }, s7 = { 7, "Сколов" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		AddEntry(d2, s4);
		AddEntry(d2, s5);
		AddEntry(d2, s6);
		AddEntry(d2, s7);
		Entry newentry3 = { 7, "Попов" };
		UpdEntry(d2, 7, newentry3);
		cout << "Список студентов: "<<endl;
		Print(d2);
		cout << "Список студентов После удаления 6 студента: " << endl;
		DelEntry(d2, 6);
		Print(d2);
		cout<<"Получение элемента номер 4: " <<endl;
		GetEntry(d2, 4).name;
		Delete(d1);
		Delete(d2);
		
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
}
