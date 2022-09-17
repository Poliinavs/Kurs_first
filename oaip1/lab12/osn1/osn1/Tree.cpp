#include "fstream"
#include "tree.h"
Tree* Root = NULL; 	//��������� �����
int lit = 1000;
int Lkey = 0;
Tree* list(int i, int b[3], int sm)     //�������� ������ ��������
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	t->sum = sm;
	if (sm < lit) {
		lit = sm;
		Lkey = i;
	}
	for (i = 0; i < 3; i++)   //���������� ���� � ��������� 
		*((t->a) + i) = *(b + i);

	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, int b[3], int sm)  //���������� ������ ��������
{
	Tree* Prev = t;	     // Prev - ������� ����� �������
	int find = 0;        // ������� ������
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //����� ������ ���� ���������
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //������� ����� � ������� Prev
	{
		t = list(key, b, sm);           //��������� ����� ���� 
		if (key < Prev->key)  // � �������������� ���� 
			Prev->Left = t;    //������� �� ����� �����,
		else
			Prev->Right = t;   // ���� �� ������ 
	}
	return t;
}



Tree* makeTree(Tree* Root)    //�������� ������
{
	int key, a[3], sum = 0;


	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;

		cout << "������� 3 ����� �����: \n";
		for (int i = 0; i < 3; i++) {
			cout << "����� �����: " << i + 1 << "\t";
			cin >> a[i];
			sum += a[i];
		}
		Root = list(key, a, sum);	// ��������� ��������� �� ������
	}

	while (1)                //���������� ���������
	{
		sum = 0;
		cout << "\n������� ����: ";  cin >> key;
		if (key < 0) break;       //������� ������ (���� < 0)   
		cout << "������� 3 ����� �����: \n";
		for (int i = 0; i < 3; i++) {
			cout << "����� �����: " << i + 1 << "\t";
			cin >> a[i];
			sum += a[i];
		}
		insertElem(Root, key, a, sum);
	}
	return Root;
}
void print(Tree* t, int u)    //����� �� �����
{
	if (t == NULL)  return;
	else
	{
		print(t->Left, ++u);     //����� ���������
		for (int i = 0; i < u; ++i)
			cout << "|";
		for (int m = 0; m < 3; m++)
			cout << t->a[m] << "\t";
		cout << endl;
		cout << "\n����� ��������� " << t->sum << endl;
		u--;
	}
	print(t->Right, ++u);          // ������ ���������
}
	void insert(Tree* t, int u, ofstream& file1)    //����� �� �����
	{
		if (t == NULL)  return;
		else
		{
			
			cout << "�������� � �����" << endl;
			insert(t->Left, ++u,  file1);     //����� ���������
			for (int i = 0; i < u; ++i)
				file1 << "|";
			for (int m = 0; m < 3; m++)
				file1 << t->a[m] << "\t";
			file1 << endl;
			//cout << "\n����� ��������� " << t->sum << endl;
			u--;
			
		}
		insert(t->Right, ++u, file1);          // ������ ���������
	}
	

Tree* delet(Tree* Root)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	int key = Lkey;
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� �������� 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

void view(Tree* t)
{
	if (t == NULL) return;
	cout << t->key << " ";
	view(t->Left);
	view(t->Right);
}
void view2(Tree* t)
{
	if (t == NULL) return;
	view(t->Left);
	cout << t->key << " ";
	view(t->Right);
}
void view3(Tree* t)
{
	if (t == NULL) return;
	view(t->Left);
	view(t->Right);
	cout << t->key << " ";
}
int height(Tree* t)
{

	if (t == NULL)
		return 0;

	return 1 + max((height(t->Left)),
		(height(t->Right)));
}
bool isBalanced(Tree* balanced)
{

	int lh;
	int rh;

	if (balanced == NULL)
		return 1;


	lh = height(balanced->Left);
	rh = height(balanced->Right);

	if (abs(lh - rh) <= 1 && isBalanced(balanced->Left) && isBalanced(balanced->Right))
		return 1;

	return 0;
}