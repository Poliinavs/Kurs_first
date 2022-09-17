 #include <iostream>
#include <tchar.h>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct Queue
{
	char info;
	Queue* next;
};
void create(Queue** begin, Queue** end, char p);
void view(Queue* begin);
Queue* maxElem(Queue* begin);
void size(Queue* begin);
void delAll(Queue** begin);
void del3(Queue** begin);

char etal, del;
int main() {
	setlocale(LC_ALL, "Rus");
	Queue* begin = NULL, * end, * t;
		t = new Queue;
		char p;
		int max_size, choice;
		int current_size = 0;
		cout << "\nВведите эталонный символ:\n";
		cin >> etal;
		cout << "Введите первый элемент очереди= "; cin >> p;
		t->info = p;
		t->next = NULL;
		begin = end = t;
		while (p != etal) {
			current_size++;
			cout << "Введите элемент очереди "; cin >> p;
			create(&begin, &end, p);
		}
		
		cout << "\nЭлементы очереди: \n";
		view(begin);


		del3(&begin);

		cout << "\nЭлементы очереди: \n";
		view(begin);

		cout << "\nКоличество элементов очереди: " << current_size - 1;

}
void create(Queue** begin, Queue** end, char p)
{
	Queue* t = new Queue;
	
		t->next = NULL;
		if (*begin == NULL)
			*begin = *end = t;
		else
		{
			t->info = p;
			(*end)->next = t;
			*end = t;
		}
		
	
	
}
void view(Queue* begin)
{
	setlocale(LC_CTYPE, "RUSSIAN");
	Queue* t = begin;
	if (t == NULL)
	{
		cout << "Пустой список\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			t = t->next;
		}
}




void del3(Queue** begin)
{
	Queue* t;
	int i = 0;
	while (*begin != NULL && i != 2)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
		i++;
	}

}
