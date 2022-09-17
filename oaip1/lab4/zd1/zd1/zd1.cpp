

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
FILE* f;

// Основа 
//Клиенты банка. Ф.И.О., тип счета (срочный, льготный и т. д.), номер счета, сумма на счете, дата последнего изменения. Выбор по номеру счета.
struct Infcitizen
{
	string name;
	string date;
	string adres;
	string gender;
	
};
typedef struct Students
{
	char name1[16];
	char date1[10];
	char adres[16];
	char gender[3];
} STUD;

const short N = 20;

void input(Infcitizen citizen[])
{
	int num;
	do {
		cout << "Введите количество горожан (не более " << N << "): ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	for (int i = 0; i < num; i++)
	{
		cout << "\tКлиент №" << i + 1 << endl;
		cout << "Введите ФИО клиента:\n";
		cin >> citizen[i].name;
		cout << "Введите дату рождения:\n";
		cin >> citizen[i].date;
		cout << "адрес:\n";
		cin >> citizen[i].adres;
		cout << "пол:\n";
		cin >> citizen[i].gender;
	}
}

void output(Infcitizen citizen[])
{
	int ClientNum;
	cout << "Введите номер горожнина, которого вы хотите вывести:\n";
	cin >> ClientNum;
	int i = ClientNum - 1;
	cout << "\tГорожанин №" << ClientNum << '\n';
	cout << "ФИО клиента: " << citizen[i].name << '\n';
	cout << "Дата рождения : " << citizen[i].date << '\n';
	cout << "Адрес: " << citizen[i].adres << '\n';
	cout << "Пол: " << citizen[i].gender << '\n';
}

void deleteClient(Infcitizen citizen[])
{
	int numCin;
	cout << "Введите порядковый номер клиента, информацию о котором Вы хотите удалить:\n";
	cin >> numCin;
	cout << '\n';
	int i = numCin - 1;
	citizen[i].name = ' ';
	citizen[i].date = ' ';
	citizen[i].adres = ' ';
	citizen[i].gender = ' ';
	cout << '\n';
}

void search(Infcitizen citizen[])
{
	string numSearch;
	cout << "Введите год рождения искомого гражданина:\n";
	cin >> numSearch;
	for (int i = 0; i < N; i++)
	{
		if (numSearch == citizen[i].date)
		{
			cout << "Гражданин №" << i + 1 << ": Дата рождения " << citizen[i].date << '\n';
		}
	}
	cout << "\n\n";
}


void put()
{
	STUD buf = { ' ', ' ' };
	int num;
	cout << "Введите количество горожан (не более " << N << "): ";
	cin >> num;
		if (!fopen_s(&f, "base.txt", "ab"))
		{
			for (int p = 0; p < num; p++)
			{
				cout << "\tКлиент №" << p + 1 << endl;
				cout << "Введите ФИО клиента:\n "; 	cin >> buf.name1;
				cout << "Введите дату рождения:\n "; 	cin >> buf.date1;
				cout << "адрес:\n "; 	cin >> buf.adres;
				cout << "Пол:\n "; 	cin >> buf.gender;
				fwrite(&buf, sizeof(buf), 1, f);
			}
			fclose(f);
		}
		else {
			cout << "Ошибка открытия файла";
			return;
		}
	}
void  ifile()
{
	STUD buf;
	if (!fopen_s(&f, "base.txt", "rb"))
	{
		cout << "\nФИО клиента    дата рождения     адрес     пол\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.name1 << "\t    " << buf.date1 << "\t \t   " << buf.adres <<"\t \t   "<<buf.gender<< endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}



int main()
{
	setlocale(LC_ALL, "ru");
	short choose;
	Infcitizen clients[N];
	do {
		cout << "Выберите, что сделать:\n1 — ввод элементов структуры с клавиатуры;\n2 — вывод элементов стуктуры в консольное окно;"
			"\n3 — удаление заданной структурированной переменной; \n4 — поиск информации; \n5 — запись информации в файл; \n6 — чтение данных из файла; \n7 — выход из программы.\n";
		cin >> choose;
		switch (choose)
		{
		case 1: input(clients); break;
		case 2: output(clients); break;
		case 3: deleteClient(clients); break;
		case 4: search(clients); break;
		case 5: put(); break;
		case 6: ifile(); break;
	
		}
	} while (choose != 7);
}