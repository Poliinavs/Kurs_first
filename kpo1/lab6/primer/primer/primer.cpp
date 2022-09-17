// primer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include "Dictionary.h"
using namespace std;
int main()
{
		setlocale(LC_ALL, "rus");
		try
		{
			Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5); // создание словаря
			Dictionary::Entry e1 = { 1,"Гладкий" }, e2 = { 2, "Веялкин" }, // элементы словаря
				e3 = { 3,"Смелов" }, e4 = { 4,"Урбанович" }, e5 = { 2,"Пацей" };
			Dictionary::AddEntry(d1, e1);											//добавление элемента словарь
			Dictionary::AddEntry(d1, e2);				//добавление элемента словарь
			Dictionary::AddEntry(d1, e3);			//добавление элемента словарь
			Dictionary::AddEntry(d1, e4);			//добавление элемента словарь
			Dictionary::Entry newentry1 = { 6, "Гурин" }; // элемент словаря
			Dictionary::UpdEntry(d1, 3, newentry1);  //заменить элемент словоря по индентифекатору
			Dictionary::Print(d1);    //распечатать элемент словоря 
			Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
			Dictionary::Entry s1 = {1, "Иванов"}, s2 = {2, "Петров"}, s3 = { 3,"Сидоров" };
			Dictionary::AddEntry(d2, s1);
			Dictionary::AddEntry(d2, s2);
			Dictionary::AddEntry(d2, s3);
			Dictionary::Entry newentry3 = { 3, "Николаев" };
			Dictionary::UpdEntry(d2, 3, newentry3);
			Dictionary::Print(d2);
			Delete(d1);
			Delete(d2);
		}
		catch (char* e ) // обработка исключений словаря
		{
			std::cout << e << std::endl;
		};
	system("pause");
	return 0;
}