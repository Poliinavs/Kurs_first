// Dictionary.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Dictionary.h"

#include <iostream>
#include <cstring>
#include <stdlib.h>
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


void Dictionary:: AddEntry(Instance& inst, Entry ed) {
	
	
	inst.cnt >= inst.size ? throw  THROW03 : inst.dictionary[inst.cnt] = ed;			      //проверяем нет ли переполнения по количеству элементов словоря, если нет добавляем элемент
	for (int i=0; i < inst.cnt; i++) {												 // дублирование индентификатора 
		if (inst.dictionary[i-1].id == ed.id)                                 //сравниваем если имя элемента совпадает с другими уже имеющимися именами выкидываем ошибку
			throw THROW04;
	}
	inst.cnt++; //увеличиваем количество элементов словаря 
}
void  Dictionary::DelEntry(Instance& inst, int id) {
	for (int i = 1; i <= inst.cnt; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = i; j < inst.cnt; j++) //переставляем все элементы на позицию +1 тк удалили один элемент
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.cnt--;
			return;
		}
	}
	return throw THROW05;
	
		
}

Entry Dictionary::GetEntry(Instance& inst, int id) {         // поиск по id и вывод имени найденного элемента
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << inst.dictionary[i].name << endl;
			return inst.dictionary[i];
		}
	}                                        //если нет элемента с таким индентифекатором
		throw THROW05;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed)       //изменить элемент словаря 
{
	
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)                         //нашли элемент который надо заменить 
		{
			for (int j = i + 1; j < inst.cnt; j++)              //проверка на уникальность id
			{
				if (new_ed.id == inst.dictionary[j].id) throw THROW08;
			}
			

			inst.dictionary[i].id = new_ed.id;                //меняем элемент
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			return;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08;
	}
	
	return throw THROW07;
	
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



















