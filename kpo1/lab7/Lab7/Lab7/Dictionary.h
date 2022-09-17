#pragma once

#include "stdafx.h"

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышен размер имени словар€"
#define THROW02 "Create: превышен размер максимальной емкости словар€"
#define THROW03 "AddEntry: переполнение словар€"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary
{
	struct Entry //элемент словор€ 
	{
		int id;      //индентифекатор уникальн
		char name[ENTRYNAMEMAXSIZE];    //симольн информ
	};
	struct Instance    //экземпл€р словор€ 
	{
		char name[ENTRYNAMEMAXSIZE];     //им€ словор€ 
		int maxsize = DICTMAXSIZE;       //максимальн емкость словор€
		int size;                        // текущий размер словор€
		int cnt = 0;            //количесво элементов словор€
		Entry* dictionary;       //массив элементов словор€
	};
	Instance Create
	(
		const char* name,
		int size
	);
	void AddEntry
	(
		Instance& ints,
		Entry ed
	);
	void DelEntry(
		Instance& inst,
		int id
	);
	void UpdEntry
	(
		Instance& ints,
		int id,
		Entry new_ed
	);
	Entry GetEntry(
		Instance& inst,
		int id
	);
	void Print(Instance& d);
	void Delete(Instance& d);
};