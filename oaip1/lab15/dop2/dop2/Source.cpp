#include "Hash.h"
#include <iostream>
#include<fstream>
using namespace std;

struct AAA // ��� �������� AAA, �-�� �� ������� �������� � ���-�������, ������ � ������� ���-�������
{
	int key; // ����, ����
	char* mas; // ������, �� ���� ������ ��������, ����
	AAA(int k, char* z) // ����� ����� key � ������ mas, ����������� � �����������
					   // ����������� ���������� ���� � ������ � ���� ���������
	{
		key = k;
		mas = z;
	}
	AAA() {} // ����������� ��� ����������
};

int key(void* d) // ������� ���������� ������, �������� � ����������, � ����
{
	AAA* f = (AAA*)d; // ����������� �-�� �� ������������ ������ d � �-�� f �� ��������� AAA 
	return f->key;
	// ���������� ���� ��������� AAA �� ��������� f, �� ���� ����� �-�� ���������� � ���� int key
}

void AAA_print(void* d) // ������� ������ 1 �-� ������ �� �-�� �� ���� �-�
{
	cout << "���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}


void main()
{
	//system("chcp 1251");
	setlocale(LC_ALL, "rus");
	int siz;
	AAA* a;
	char* str;
	cout << "������� ������ ���-�������" << endl;
	cin >> siz;
	Object H = Create(siz, key);	// ������� ���-������� �������� ��������
	int choise; 				// ���������� ��� ����� ������ ������������
	int k;					// ���� ����� � ��� ����������
	for (;;)
	{
		system("cls");
		cout << "����:" << endl;
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "5 - ����������� ���������� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl; cin >> choise;
		switch (choise)
		{
		case 0: exit(0); // ������� ��������� ������ ���������
		case 1: H.Scan(AAA_print); break;
		case 2:
		{
			int k = 0;
			fstream doc("doc.txt");
			while (doc)
			{
				k = 0;
				str = new char[10];
				doc.getline(str, 10);
				for (int i = 0; i < 10; i++)
					k += (int)str[i];
				if (k > 0) {
					a = new AAA();
					a->key = k;
					a->mas = str;
					H.Insert(a);
				}
			}
		}
		break;
		case 3:
			cout << "������� ���� ��� �������� " << endl;
			cin >> k;
			H.Delete(k);
			break;
		case 4:
			cout << "������� ���� ��� ������ " << endl;
			str = new char[10];
			k = 0;
			cin >> str;
			for (int i = 0; i < 10; i++)
				k += (int)str[i];
			if (H.Search(k) == NULL)
				cout << "������� �� ������" << endl;
			else  AAA_print(H.Search(k));
			break;
		case 5:
			cout << "������� ��������� �� " << H.koefzap() * 100 << "%" << endl;
			break;
		}
		system("pause");
	}
}
