// osn1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct Tree          //дерево
{
    int key;         //ключ
    int a[3];
	int sum;
	/*int b;
	int c;*/
    Tree* Left, * Right;
};
Tree* Root = NULL; 	//указатель корня
int lit = 1000;
int Lkey = 0;
Tree* list(int i, int b[3], int sm)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->sum = sm;
	if (sm < lit) {
		lit = sm;
		Lkey = i;
	}
	for (i = 0; i < 3; i++)   //записываем инфу в структуру 
		*((t->a) + i) = *(b + i);

	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, int b[3], int sm)  //Добавление нового элемента
{
	Tree* Prev = t;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key, b, sm);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}



	Tree* makeTree(Tree* Root)    //Создание дерева
	{
		int key, a[3], sum=0; 

		
		if (Root == NULL)	// если дерево не создано
		{
			cout << "Введите ключ корня: "; cin >> key;

			cout << "Введите 3 числа корня: \n";
			for (int i = 0; i < 3; i++) {
				cout << "Число номер: " << i + 1<< "\t";
				cin >> a[i];
				sum += a[i];
			}
			Root = list(key, a, sum);	// установка указателя на корень
		}
		
		while (1)                //добавление элементов
		{
			sum = 0;
			cout << "\nВведите ключ: ";  cin >> key;
			if (key < 0) break;       //признак выхода (ключ < 0)   
			cout << "Введите 3 числа корня: \n";
			for (int i = 0; i < 3; i++) {
				cout << "Число номер: " << i + 1 << "\t";
				cin >> a[i];
				sum += a[i];
			}
			insertElem(Root, key, a, sum);
		}
		return Root;
	}

	

	

	void print(Tree* t, int u)    //Вывод на экран
	{
		if (t == NULL)  return;
		else
		{
			print(t->Left, ++u);     //левое поддерево
			for (int i = 0; i < u; ++i)
				cout << "|";
			for (int m = 0; m < 3; m++)
				cout << t->a[m] << "\t";
			cout << endl;
			cout << "\nСумма элементов " << t->sum<<endl;
			u--;
		}
		print(t->Right, ++u);          // правое поддерево
	}

	Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
	{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
		// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
		Tree* Del, * Prev_Del, * R, * Prev_R;
		Del = Root;
		Prev_Del = NULL;
		while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
		{
			Prev_Del = Del;
			if (Del->key > key)
				Del = Del->Left;
			else
				Del = Del->Right;
		}
		if (Del == NULL)              // элемент не найден
		{
			puts("\nНет такого ключа");
			return Root;
		}
		if (Del->Right == NULL) // поиск элемента R для замены
			R = Del->Left;
		else
			if (Del->Left == NULL)
				R = Del->Right;
			else
			{
				Prev_R = Del; //поиск самого правого элемента в левом поддереве
				R = Del->Left;
				while (R->Right != NULL)
				{
					Prev_R = R;
					R = R->Right;
				}
				if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
					R->Right = Del->Right;
				else
				{
					R->Right = Del->Right;
					Prev_R->Right = R->Left;
					R->Left = Prev_R;
				}
			}
		if (Del == Root) Root = R;	//удаление корня и замена его на R
		else
			// поддерево R присоединяется к родителю удаляемого узла
			if (Del->key < Prev_Del->key)
				Prev_Del->Left = R; // на левую ветвь 
			else
				Prev_Del->Right = R;	// на правую ветвь
		int tmp = Del->key;
		cout << "\nУдален элемент с ключом " << tmp << endl;
		delete Del;
		return Root;
	}

	void delAll(Tree* t) //Очистка дерева
	{
		if (t != NULL)
		{
			delAll(t->Left);
			delAll(t->Right);
			delete t;
		}
	}

	Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
	{
		Tree* rc = n;
		if (rc != NULL)
		{
			if (key < (key, n->key))
				rc = search(n->Left, key);
			else
				if (key > (key, n->key))
					rc = search(n->Right, key);
		}
		else
			cout << "Нет такого элемента\n";
		return rc;
	}




int main()
{
    setlocale(0, "Russian");
    int key, choice, n3, a[3], sum=0;
	Tree* rc;
	for (;;)
	{
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента c наименьшей суммой\n";
		cout << "5 -	вывод дерева\n";
		cout << "7 -	очистка дерева\n";
		cout << "8 -	выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите ключ: ";
			cin >> key;
			cout << "Введите 3 числа корня: \n";
			for (int i = 0; i < 3; i++) {
				cout << "Число номер: " << i + 1 << endl;
				cin >> a[i];
				sum += a[i];
			}
			insertElem(Root, key, a, sum); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			cout << "Найденная сумма= ";
			cout<<rc->sum<<endl; break;

		case 4: 
			Root = delet(Root, Lkey);  break;


		case 5: print(Root, 0); break;
		case 7:  delAll(Root); break;
		case 8:  exit(0);


		}
	}
}

