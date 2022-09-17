// osn1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"


int main()
{
	setlocale(LC_ALL, "rus");
	int choice, newEl, position;

	STACK* stack = new STACK;
	stack->head = NULL;

	PolST* st = new PolST;
	st->head1 = NULL;

	OtrST* stac= new OtrST;
	stac->head = NULL;
	while (true)
	{
		cout << "1 - добавить элемент в основной стек\n";
		cout << "2 - вывод стеков на экран\n";
		cout << "3 - запись в файл\n";
		cout << "4 - вывод из файла\n";
		cout << "5 - очистка стека\n";
		cout << "6 -  выход\n";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "\n";
			cout << "Значение > "; cin >> newEl;
			AddEl(newEl, stack, st, stac);
			cout << "\n";
			break;
		}

		case 2: {
			PrintStack(stack, st, stac);
			break;
		}
		case 3:
			ToFile(stack);
			break;
		case 4: {
			FromFile(stack);
			break;
		}
		case 5: {
			clear(stack, st, stac);
			cout << "\n\nСтек очищен!\n\n";
			break;
		}

		case 0: {
			exit(0);
			break;
		}
		}
	}

}


