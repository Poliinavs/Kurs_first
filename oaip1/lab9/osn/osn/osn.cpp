//ab bd ac dc
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;
int kol = 1;
struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];

	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
	kol++;
}
//-----------------------------------------------------------
Address* setElement() // Создание элемента и ввод его значений с клавиатуры
{
	Address* temp = new Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin >> temp->name;
	cout << "Введите город: ";
	cin >> temp->city;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast) //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead) // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}

//-----------------------------------------------------------
void writeToFile(Address** phead) //Запись в файл
{
	struct Address* t = *phead;
	ofstream file1("Lip.txt");
	if (file1.fail())
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		file1 << t->name << " " << t->city << endl;
		t = t->next;
	}
	file1.close();
}
//---------------------------------------------------------------
void fromFile(Address** phead)
{

	char buf[256];
	ifstream file2("Lip.txt");
	if (file2.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (!file2.eof())
	{
		file2.getline(buf, 256);
		if (strlen(buf))
			cout << " " << buf;
		cout << endl;
	}

	file2.close();
}

//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)// Удаление элемента по имени
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
/*
Address* Del_Same(Address* head)
{
	char d[256];
	Address* p = head, * t, * q, * u;

	while (p != NULL)
	{
		t = p;
		while (t->next != NULL)
		{
			if (p->name == t->next->name)
			{
				d = p->name;
				u = head;
				if (head == NULL) { puts("list empty"); return NULL; }
				if (head->name== d) { head = head->next; delete u; return head; }

				while (u->next != NULL)
				{
					if (u->next->name == d)
					{
						q = u->next;
						u->next = u->next->next;
						delete q;
					}
					else u = u->next;
				}
			}
			else t = t->next;
		}
		p = p->next;
	}
	return head;
}

*/

void delm(Address** phead, Address** plast)
{
	struct Address* t = *phead;
	struct Address* p = *phead;
	p = p->next;
	int none = 0;
	int k = 0;

	while (t) {
		while (p) {
			if (strcmp(p->name, t->name) == 0 && k==1) {
				if (*phead == t)
				{
					*phead = t->next;
					if (*phead)
						(*phead)->prev = NULL;
					else
						*plast = NULL;
					none++;
					break;
				}
				else
				{
					t->prev->next = t->next;
					if (t != *plast)
						t->next->prev = t->prev;
					else
						*plast = t->prev;
				}
				delete t;
				cout << "\nЭлемент удален\n" << endl;
				none++;

			}
			k = 1;
			p = p->next;
		}
		k = 0;
		p = t->next;
		t = t->next;
	}

}


	/*
	for (int i = 0; i < kol - 1; i++) {
		for (int j = i + 1; j < kol; j++) {
			if (strcmp(t[i].name, t[j].name) == 0) {
				if (*phead == t) {
					*phead = t->next;
					if(*phead)
						(*phead)->prev = NULL;
					else
						*plast = NULL;
				}
				else {
					t->next->prev = t->next;
					if (t != *plast)
						t->next->prev = t->prev;
					else
						*plast = t->prev;
				}
				delete t;
				none++;
			}

		}
		t = t->next;
		if (none == 0)
cout << "\n Элементов с одинаковыми полями не найдено\n";

	}
	}*/



	/*
	while (t)
	{
		if ((m++) % 2 == 0)
		{
			if (*phead == t)
			{
				*phead = t->next;
				if (*phead)
					(*phead)->prev = NULL;
				else
					*plast = NULL;
			}
			else
			{
				t->prev->next = t->next;
				if (t != *plast)
					t->next->prev = t->prev;
				else
					*plast = t->prev;
			}
			delete t;
			return;
		}

		t = t->next;}*/


	

int main()
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	cout << "1. Ввод адреса" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. В файл" << endl;
	cout << "6. Из файла" << endl;
	cout << "7. Удаление повторяющихся элементов "<< endl;
	cout << "8. Выход" << endl;
	cout << endl;
	for (;;)
	{
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert(setElement(), &head, &last);
			break;
		case 2: { char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin >> dname;
			delet(dname, &head, &last);
		}
			  break;
		case 3: outputList(&head, &last);
			break;
		case 4: { char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin >> fname;
			find(fname, &head);
		}
			  break;
		case 5: {
			writeToFile(&head);
		}
			  break;
		case 6: {
			fromFile(&head);
		}
			  break;
		case 7: {
			delm(&head, &last);
		}
			  break;
		case 8: exit(0);
		default: exit(1);
		}
	}
	return 0;
}





