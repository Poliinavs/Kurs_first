#pragma once
#include <cstring>
#define DICTNAMEMAXSIZE  20 // маскисальный размер имени словар€
#define DICTMAXSIZE      100 // маскисальна€ емкость словар€
#define ENTRYNAMEMAXSIZE 30 // маскисальна€ длина имени в словаре
#define THROW01 "Create: превышен размер имени словар€"
#define THROw02 "Create: превышен размер максимальной емкости словар€"
#define THROW03 "AddEntry: переполнение словар€"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROw08 "UpdEntry: дублирование идентификатора"
namespace Dictionary 
{
		struct Entry //элемент словар€
		{
			int id; // идентификатор (уникальный)
			char name[ENTRYNAMEMAXSIZE]; // сивольна€ информаци€
		};
		struct Instance // экземпл€р словар€
		{
			char name[DICTNAMEMAXSIZE];
			int maxsize; // максимальна€ емкость словар€
			int size; //текуций размер словар€
			Entry* dictionary; // массив элементов словар€
		}; 
		Instance Create(    //создать словарь
			char name[DICTNAMEMAXSIZE], //им€ словор€
			int size  //емкость словар€ diCTNAMEMAxSIZE
		);
	
		void AddEntry( // добавить элемент словар€
			Instance& inst, //экземпл€р словар€
			Entry ed        //элемент словар€
			);
		
		void DelEntry( // удалить элемент словар€
			Instance& inst, // экземал€р словар€
			int id //идентификатор удал€емого влемента(уникальный)
		);
			void UpdEntry( // изменить элемент словар€
				Instance& inst, // экземпл€р словар€
				int id,  //индентификатор замен€емого элемента
				Entry new_ed  // новыый элемент словар€
			);
			Entry GetEntry( //получит первый элемент словар€

				Instance inst, // экземпл€р словар€
				int id// идентификатор получаемого элемента
			);
	
	
	void Print(Instance d); // печать словар€
void Delete(Instance& d); // удалить словарь
};