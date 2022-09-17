// dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct Tree
{
	int key;
	char number[20];
	char surname[20];
	char tarif[20];
	int tar;
	Tree* Left, * Right;
};
enum Tarif
{
	MTS = 1, A1, Life
} oper;
int a = 0, m = 0, l = 0;

Tree* makeTree(Tree* Root);
Tree* list(int i, char* s, char* number, char* t, int tar);
Tree* insertElem(Tree* Root, int key, char* s, char* number, char* t, int tar);
void view(Tree* t, int level);
void search(Tree* n, char* number);
string popularTarif(Tree* n);
void delAll(Tree* t);


int c = 0;
int t1 = 0, t2 = 0, t3 = 0;
Tree* Root = NULL;
void main()
{
	setlocale(0, "Russian");
	int key, choice, n, tar;
	Tree* rc; char s[20], t[20], number[20];
	string ans;
	for (;;)
	{
		cout << "1 -создание дерева\n";
		cout << "2 -добавление элемента\n";
		cout << "3 -вывод дерева\n";
		cout << "4 -поиск по номеру \n";
		cout << "5 -популярный тариф \n";
		cout << "6 -удаление дерева \n";
		cout << "7 -выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: Root = makeTree(Root); break;
		case 2: cout << "\nвведите ключ: "; cin >> key;
			cout << "введите фамилию: "; cin >> s;
			cout << "введите номер: "; cin >> number;
			cout << "Выберите тариф: 1-МТС, 2-А1 "; cin >> tar;
			insertElem(Root, key, s, number, t, tar); break;
		case 3: if (Root->key >= 0)
		{
			cout << "дерево :" << endl;
			view(Root, 0);
		}
			  else cout << "дерево пустое\n"; break;

		case 4: cout << "\nвведите номер: ";
			cin >> number;
			cout << "абонент:";
			search(Root, number);
			break;

		case 5:
			cout << "популярный тариф: ";
			if (m > a)
				cout << "Мтс"<<endl;
				if(m<a)
					cout << "A1"<<endl;
				if (m == a)
					cout<< "Мтс и А1"<<endl;
			break;
		case 6: delAll(Root); break;

		case 7: exit(0);
		}
	}
}

Tree* makeTree(Tree* Root)
{
	int key, tar; 
	char s[20], t[20], number[20];
	cout << " онец ввода 0 ключ\n\n";
	if (Root == NULL)
	{
		cout << "введите ключ корня: "; cin >> key;
		cout << "введите фамилию абонента: "; cin >> s;
		cout << "введите номер абонента: "; cin >> number;
		cout << "Выберите тариф: 1-МТС, 2-А1 "; cin >> tar;
		Root = list(key, s, number, t, tar);
	}
	while (1)
	{
		cout << "\nвведите ключ: "; cin >> key;
		if (key == 0) break;
		cout << "введите фамилию абонента: "; cin >> s;
		cout << "введите номер абонента: "; cin >> number;
		cout << "Выберите тариф: 1-МТС, 2-А1: "; cin >> tar;
		insertElem(Root, key, s, number, t, tar);
	}
	return Root;
}

Tree* list(int i, char* s, char* number, char* t, int tr)
{
	Tree* tmp = new Tree[sizeof(Tree)];
	tmp->key = i;
	for (i = 0; i < 20; i++)
	{
		*((tmp->surname) + i) = *(s + i);

		
		*((tmp->number) + i) = *(number + i);


		*((tmp->tarif) + i) = *(t + i);
	}
	if (tr == 1)
		m++;
	if (tr == 2)
		a++;
	if (tr == 3)
		l++;

	tmp->tar =tr;
	tmp->Left = tmp->Right = NULL;
	return tmp;
}

Tree* insertElem(Tree* tmp, int key, char* s, char* number, char* t, int tar)
{
	Tree* Prev = tmp;
	int find = 0;
	while (tmp && !find)
	{
		Prev = tmp;
		if (key == tmp->key)
			find = 1;
		else
			if (key < tmp->key) tmp = tmp->Left;
			else tmp = tmp->Right;
	}
	if (!find)
	{
		tmp = list(key, s, number, t, tar);
		if (key < Prev->key)
			Prev->Left = tmp;
		else
			Prev->Right = tmp;
	}
	return tmp;
}



void view(Tree* t, int level)
{
	if (t)
	{
		view(t->Right, level + 1);
		for (int i = 0; i < level; i++)
			cout << " |";
		int tm = t->key;
		cout << tm << ' ';
		cout << t->surname << endl;
		cout << t->number << endl;
		if (t->tar == 1)
			cout<<"МТС\n\n";
		if (t->tar == 2)
			cout << "A1\n\n";
		if (t->tar == 3)
			cout << "Life\n\n";

		view(t->Left, level + 1);
	}
}

void search(Tree* n, char* number)
{
	if (n != NULL)
	{
		if (strcmp(number, n->number) == 0)
		{
			cout << n->key << endl;
			cout << n->surname << endl;
			cout << n->number << endl;
		}
		else
			search(n->Left, number);
		search(n->Right, number);
	}

}


void delAll(Tree* t)
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}









//#include <iostream>
//#include <cstring>
//using namespace std;
//struct Tree          //дерево
//{
//	string key;         //ключ
//	int number;
//	int tar;
//	int m;
//	
//	Tree* Left, * Right;
//};
//Tree* Root = NULL; 	//указатель корня
//enum tarif
//{
//	Мтс= 1,
//	А1, ЛАЙФ
//};
//int m = 0, a = 0, l = 0;
//Tree* list(string i, int teleph, int tar)     //Создание нового элемента
//{
//	Tree* t = new Tree[sizeof(Tree)];
//	if (tar == 1) {
//		m++;
//	}
//	if (tar == 2) {
//		a++;
//	}
//	if (tar==3) {
//		l++;
//	}
//	t->key = i;
//	t->number = teleph;
//	t->Left = t->Right = NULL;
//	return t;
//}
//
//Tree* insertElem(Tree* t, string key, int telep, int tar)  //Добавление нового элемента
//{
//	int a = strcmp(char* key, const char*t->key);
//	Tree* Prev = t;	     // Prev - элемент перед текущим
//	string find = 0;        // признак поиска
//	if (key < t->key) t = t->Left;
//	else t = t->Right;
//	
//	return t;
//}
//
//
//
//Tree* makeTree(Tree* Root)    //Создание дерева
//{
//	string key;
//	int telep, tar;
//
//	if (Root == NULL)	// если дерево не создано
//	{
//		cout << "Введите Фамилию клиента: "; cin >> key;
//		cout << "Введите номер телефона: \n";
//		cin >> telep;
//		cout << "Выберите тариф: 1-МТС; 2-А1; 3-ЛАЙФ \n";
//		cin >> tar;
//		Root = list(key, telep, tar);	// установка указателя на корень
//	}
//
//	
//	return Root;
//}
//
//
//
//
//
//void print(Tree* t, int u)    //Вывод на экран
//{
//	if (t == NULL)  return;
//	else
//	{
//		print(t->Left, ++u);     //левое поддерево
//		for (int i = 0; i < u; ++i)
//			cout << "|";
//	
//	
//		cout << "\nФамилия клиента" << t->key<<endl;
//		cout << "\nНомер клиента" << t->number<<endl;
//		cout << "\nТариф клиента" << t->tar << endl;
//		cout << "\n";
//
//		u--;
//	}
//	print(t->Right, ++u);          // правое поддерево
//}
//
//Tree* search(Tree* n, string key)  //Поиск элемента по ключу 
//{
//	Tree* rc = n;
//	if (rc != NULL)
//	{
//		if (key < (key, n->key))
//			rc = search(n->Left, key);
//		else
//			if (key > (key, n->key))
//				rc = search(n->Right, key);
//	}
//	else
//		cout << "Нет такого элемента\n";
//	return rc;
//}
//
//
//int main()
//{
//	setlocale(0, "Russian");
//	int  choice, telep, tar;
//	string key;
//	Tree* rc;
//	for (;;)
//	{
//		cout << "1 -	создание дерева\n";
//		cout << "2 -	добавление клиента\n";
//		cout << "3 -	поиск по номеру телефонаn";
//		cout << "4 -	поиск наиболее востребованного тарифа\n";
//		cout << "5 -	вывод дерева\n";
//		cout << "7 -	очистка дерева\n";
//		cout << "8 -	выход\n";
//		cout << "ваш выбор?\n";
//		cin >> choice;
//		cout << "\n";
//		switch (choice)
//		{
//		case 1:  Root = makeTree(Root);	break;
//		case 2: cout << "Введите Фамилию клиента: "; cin >> key;
//			cout << "Введите 3 числа корня: \n";
//			cin >> telep;
//			cout << "Выберите тариф: 1-МТС; 2-А1; 3-ЛАЙФ \n";
//			cin >> tar;
//			insertElem(Root, key, telep, tar); break;
//	/*	case 3:  cout << "\nВведите ключ: ";  cin >> key;
//			rc = search(Root, key);
//			cout << "Найденная сумма= ";
//			cout << rc->sum << endl; break;*/
//
//		
//
//		case 5: print(Root, 0); break;
//
//		case 8:  exit(0);
//
//
//		}
//	}
//}
