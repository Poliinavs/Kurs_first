// Dictionary.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Dictionary.h"
#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace Dictionary;
using namespace std;

Instance Dictionary::Create(const char* name, int size)
{
	Instance NewDict;
	strlen(name) > ENTRYNAMEMAXSIZE ? throw THROW01 : strcpy_s(NewDict.name, name);
	NewDict.maxsize < size ? throw THROW02 : NewDict.size = size;
	NewDict.dictionary = new Entry[size];
	return NewDict;
}
//Instance& ints, Entry ed  дублирование индентификатора 

void Dictionary::AddEntry(Instance& inst, Entry ed) {

	int cnt = inst.cnt;
	cnt >= inst.size ? throw  THROW03 : inst.dictionary[cnt] = ed;			//проверяем нет ли переполнения по количеству элементов словоря, если нет добавляем элемент
	for (int i = 0; i < cnt; i++) {												 // дублирование индентификатора 
		if (inst.dictionary[cnt - 1].id == ed.id) //сравниваем если имя элемента совпадает с другими уже имеющимися именами выкидываем ошибку
			throw THROW04;
	}
	inst.cnt++; //увеличиваем количество ээлементов словаря 
}
void  Dictionary::DelEntry(Instance& inst, int id) {
	int tr = 0;
	for (int i = 1; i <= inst.cnt; i++) {
		if (inst.dictionary[i].id == id) {
			tr = 1;
			for (int j = i; j < inst.cnt; j++) //переставляем все элементы на позицию +1 тк удалили один элемент
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.cnt--;
			break;
		}
	}
	if (tr == 0) //если нет элемента с таким индентифекатором
		throw THROW05;
}

Entry Dictionary::GetEntry(Instance& inst, int id) { // поиск по id и вывод имени найденного элемента
	int tr = 0;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << inst.dictionary[i].name << endl;
			return inst.dictionary[i];
		}
	}
	if (tr == 0) //если нет элемента с таким индентифекатором
		throw THROW05;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) //изменить элемент словаря 
{
	int a = 0;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)  //нашли элемент который надо заменить 
		{
			for (int j = i + 1; j < inst.cnt; j++) //проверка на уникальность id
			{
				if (new_ed.id == inst.dictionary[j].id) throw THROW08;
			}
			a = 1;

			inst.dictionary[i].id = new_ed.id;       //меняем элемент
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			break;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08;
	}
	if (a == 0) // не найден элемент
	{
		throw THROW07;
	}
}

void Dictionary::Print(Instance& d)
{
	cout << endl << endl;
	for (int i = 0; i < d.cnt; i++)
	{
		cout << "ID = " << d.dictionary[i].id
			<< "\nName is " << d.dictionary[i].name << endl << endl;
	}
}
void Dictionary::Delete(Instance& inst)
{
	delete[] inst.dictionary;
}



















