#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else if (A2->x > A1->x)
		rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
bool buildHeap(char* FileName, heap::Heap& h)
{
	bool rc = true;   int n;
	ifstream inFile;
	inFile.open(FileName, std::ios::out);
	if (!inFile)
	{
		cout << "���������� ������� ����" << endl;
		exit(1);
	}
	while (inFile >> n)
	{
		int* a = new int;
		*a = n;
		h.insert((void*)a);
	}
	inFile.close();
	return rc;
}
//-------------------------------
void SaveHeap(heap::Heap& h, char* FileName)
{
	ofstream  outFile(FileName, ios_base::out | ios_base::trunc);
	if (!outFile)
	{
		cout << "������ �������� ��������� �����" << std::endl;
		return;
	}
	int* a = new int;
	for (int u = 0, y = 0; u < h.size; u++)
	{
		a = (int*)h.storage[u];
		outFile << *a;
		outFile << endl;
	}
	outFile.close();
}
//-------------------------------
void Union(heap::Heap& h, heap::Heap& newh)
{
	int k;
	cout << "������� ����� ��� ����� ����: ";
	do
	{
		AAA* a = new AAA;
		cin >> k;
		if (k == 0)
			break;
		a->x = k;
		newh.insert(a);
	} while (true);
	cout << "���� ����" << endl;
	newh.scan(0);
	while (newh.size)
	{
		h.insert(newh.extractI(1));
	}
	newh.deleteHeap();
	cout << "����������� ���������." << endl;
}
//-------------------------------


void menu()
{
	cout << "1 - ����� ���� �� �����" << endl;
	cout << "2 - �������� ��������" << endl;
	cout << "3 - ������� ������������ �������" << endl;
	cout << "4 - ������� ����������� �������" << endl;
	cout << "5 - ������� i-� �������" << endl;
	cout << "6 - ���������� ����" << endl;
	cout << "0 - �����" << endl;
}
//-------------------------------
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	int k, i;
	int choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(15, cmpAAA);
	menu();
	for (;;)
	{
		cout << "����: ";  cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			h1.scan(0);
			break;
		case 2:
		{	cout << "������� �����: ";
		do
		{
			AAA* a = new AAA;
			cin >> k;
			if (k == 0)
				break;
			a->x = k;
			h1.insert(a);
		} while (true);
		}
		break;
		case 3:
			if (h1.extractMax())
				cout << "�������� ������� ���������." << endl;
			break;
		case 4:
			if (h1.extractMin())
				cout << "�������� ������� ���������." << endl;
			break;
		case 5:
			cout << "�������� ����� ���������� ��������: " << endl;
			cin >> i;
			if (h1.extractI(i))
				cout << "�������� ������� ���������." << endl;
			break;

		case 6:
		{
			Union(h1, h2);
			break;
		}

		default:
			cout << endl << "������� �������� �������!" << endl;
		}
		menu();
	} return 0;
}