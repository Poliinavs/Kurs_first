#include <iostream>
#include <windows.h>
using namespace std;
#include "stdafx.h"
using namespace Dictionary;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	try
	{
#if defined(TEST_CREATE_01)   //�������� �� ���������� ����� �������
		Instance d1 = Create("������a�����mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm�", 5);
#error Create: �������� ������ ����� �������
#elif defined(TEST_CREATE_02)    // �������� �� �������� ������ ������������ ������� �������
		Instance d1 = Create("������a������", 10000);
#else 
		Instance d1 = Create("������a������", 5);// �������� �������
#endif                                              
		Entry e1 = { 1, "�������" },      // �������� �������;
			e2 = { 2, "�������" },
			e3 = { 3, "������" },
			e4 = { 4, "���������" },
#if defined(TEST_ADDENTRY_04)    //�������� �� ������������ ��������������
			e5 = { 2, "��������" };

#else 
			e5 = { 5, "��������" };
#endif
		AddEntry(d1, e1);				//���������� �������� �������
		AddEntry(d1, e2);				//���������� �������� �������
		AddEntry(d1, e3);			//���������� �������� �������
		AddEntry(d1, e4); 
		AddEntry(d1, e5);//���������� �������� �������
	
#if defined(TEST_ADDENTRY_03)   //������������ �������
		AddEntry(d1, e5);
#endif
		cout << "�������� ������� ��������������\n";
		Print(d1);
#if defined(TEST_GETENTRY_05)
		Entry ex2 = GetEntry(d1, 10);
#else
		Entry ex2 = GetEntry(d1, 4); //��������� �������� ������� 
#endif
#if defined(TEST_DELENTRY_06) //�� ������ �������
		DelEntry(d1, 20);
#else
		DelEntry(d1, 2); // �������� �������� �������
#endif
		cout << "\n������� ����� �������� 2 ��������: \n";
		Print(d1);
#if defined(TEST_UPDENTRY_08)   //������������ ��������������
		Entry newentry1 = { 1, "�����" };
#else 
		Entry newentry1 = { 6, "�����" };
#endif
#if defined(TEST_UPDENTRY_07) // �� ������ �������
		UpdEntry(d1, 30000, newentry1);
#else
		UpdEntry(d1, 3, newentry1); //���������� ��������
#endif
		cout << "\n������� ����� ������ �������� � ID 3: \n";
		Print(d1);
		Instance d2 = Dictionary::Create("��������", 7);
		Entry s1 = { 1, "������" }, s2 = { 2, "������" }, s3 = { 3,"�������" },s4 = {4, "������"}, s5 = { 5, "�������" }, s6 = { 6, "��������" }, s7 = { 7, "������" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		AddEntry(d2, s4);
		AddEntry(d2, s5);
		AddEntry(d2, s6);
		AddEntry(d2, s7);
		Entry newentry3 = { 7, "�����" };
		UpdEntry(d2, 7, newentry3);
		cout << "������ ���������: "<<endl;
		Print(d2);
		cout << "������ ��������� ����� �������� 6 ��������: " << endl;
		DelEntry(d2, 6);
		Print(d2);
		cout<<"��������� �������� ����� 4: " <<endl;
		GetEntry(d2, 4).name;
		Delete(d1);
		Delete(d2);
		
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
}
