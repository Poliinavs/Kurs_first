 #include <iostream>
using namespace std;
string vis;
int opr = 0;
int mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int count(int day, int month, int mes[]);
int prov(int god, int month, int day);
void visok_god(int god);
void nazv(int);
int main()
{
	setlocale(LC_ALL, "Russian");
	int c;
	int god, data, month, pust, day, day1, month1, data1, por = 0;
	cout << " ������� ����:  ";
	cin >> data;
	pust = data;
	god = data % 10000;
	data = pust;
	month = ((data - god) / 10000) % 100;
	day = ((data - god) / 10000 - month) / 100;
	visok_god(god);
	if (prov(god, month, day) == 1) {
		cout << "\n����������� ������� ����";
		return 0;
	}

	do
	{
		cout << endl;
		cout << "�������" << endl;
		cout << "1-����������, �������� �� ��������� ��� ���� ����������" << endl;
		cout << "2-��������� ���������� ����� ���������� ��� � ���� ����" << endl;
		cout << "3-��������� ������� ���� �������� �� ���������� ��� �����o ��������" << endl;
		cout << "4- ����������� �������� ������ " << endl;
		cout << "5- ����������, ����� ���� ������������  " << endl;
		cout << "6-�����" << endl;
		cin >> c;
		switch (c)
		{
		case 1: //�������� �� ���������� ���
			cout << vis; 
			break;
		case 2: // ������  �������� �����
			por = count(day, month, mes);
			cout << " ���������� �����: " << por;
			break;
		case 4:
			nazv(month);
			break;

		case 5:
			if (opr == 1) 
				cout << "���� ������������ 12 ��������"<<endl;
			else 
				cout << "���� ������������ 13 ��������" << endl;
			

			break;

		case 3: // ������ ������� ���� �� ���� ��� �������� 
			cout << "������� ���� � ����� ��� ��������: ";
			cin >> data1;
			pust = data1;
			month1 = data1 % 100;
			day1 = (pust - month1) / 100;
			if (prov(god, month1, day1) == 1) {
				cout << "\n����������� ������� ����";
				return 0;
			}
			int a = count(day1, month1, mes); //����� ����� ������ ��� ��������
			cout << "�� ��� �������� ��������: " << abs(a - por);
			break;
		
		
		}
	} while (c != 6); 
}
void nazv(int month) {
	string name[] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };
	cout << "�������� ������: " << name[month - 1]<<endl;
}

int prov(int god, int month, int day) {
	int a = 0;
	if (god <= 1000 || month <= 00 || month > 12|| day <= 00 || day > mes[month - 1] )
		a = 1;
	
	
	return (a);
}

int count(int day, int month, int mes[]) {
	int por = 0;
	for (int i = 0; i < month - 1; i++)
		por += mes[i];
	por += day;
	return por;
}

void visok_god(int god) {
	if (god % 4 != 0 || (god % 100 == 0 && god % 400 != 0)) {
		vis = " �� ���������� ��� ";
	}
	else {
		vis = "���������� ��� ";
		mes[1]++;
		opr = 1;
	}
}

