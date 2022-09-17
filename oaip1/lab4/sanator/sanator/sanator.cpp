// sanator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Название санатория, Место расположения, Лечебный профиль, Количество путевок Сгрупировать по группам лечебн и там по алфав 

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct Camp {
	string CampName;
	string CampPlace;
	string CampType;
	int voucher;
};

bool comp1(Camp lhs, Camp rhs)
{
	return lhs.CampName < rhs.CampName;
}

bool comp(Camp lhs, Camp rhs)
{
	return lhs.CampType < rhs.CampType;
}

void showInfo(Camp* lagger, int SIZE) {
	sort(lagger, lagger + SIZE, comp);
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (lagger[i].CampType == lagger[i + 1].CampType)
		{
			index1 = i;
			break;
		}
	}

	for (int i = SIZE; i > 0; i--)
	{
		if (lagger[i].CampType == lagger[i - 1].CampType)
		{
			index2 = i;
			break;
		}
	}

	sort(lagger + index1, lagger + index2 + 1, comp1);


	printf("+--------+----------------+-----------------+-----------+\n");
	printf("| nazvan |     place      |       Profil    |   kol     |\n");
	printf("+--------+----------------+-----------------+-----------+\n");
	for (int i = 0; i < SIZE; ++i) {
		cout << lagger[i].CampName << "\t\t";
		cout <<  lagger[i].CampPlace << "\t\t\t";
		cout <<  lagger[i].CampType << "\t\t";
		cout << lagger[i].voucher << "\t" << endl;
	printf("+--------+----------------+-----------------+-----------+\n");
	}


	

}

void ifileCamp(Camp* lagger, int SIZE)
{

	ifstream fin("Info.txt");

	if (!fin.is_open()) {
		cout << "Не удаётся открыть файл для чтения " << endl;
		exit(EXIT_FAILURE);
	}

	vector<string> fileinfo;
	string line, word;
	stringstream x;
	for (int i = 0; i < SIZE; ++i) {
		fin >> lagger[i].voucher;
		getline(fin, line);
		x << line;
		while (x >> word)
		{
			fileinfo.push_back(word);
		}
		for (int k = 0; k < fileinfo.size(); k++)
		{
			if (k == 0) { lagger[i].CampName = fileinfo[k]; }
			if (k == 1) { lagger[i].CampPlace = fileinfo[k]; }
			if (k == 2) { lagger[i].CampType = fileinfo[k]; }
		}
		x.clear();
		line.clear();
		word.clear();
		fileinfo.clear();
	}
	cout << "\nИнформация считана из файла Info.txt\n\n";
}


void main()
{

	setlocale(LC_CTYPE, "ru");
	const int SIZE = 5;
	Camp lager[SIZE];
	short choose;
	do {
		cout << "Выберите, что сделать:\n1 — вывести информацию из файла;\n2 — вывести в консоль информацию о путёвках;\n3 — выход\n";
		cin >> choose;
		switch (choose)
		{
		case 1: ifileCamp(lager, SIZE); break;
		case 2: showInfo(lager, SIZE); break;
		case 3: exit(0); break;
		}
	} while (choose != 3);
}




/*
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
struct Sanator
{
    char Nazv[30];
    char place[30];
    char prof[30];
    int kol;
};
Sanator a[30];


int main()
{
    setlocale(LC_ALL, "Russian");
    int p;
    char cur[30], sn[30], zn[30];
        cout << "Введите колличество санаториев: ";
    cin >> p;


        ifstream fin("studentsInfo.txt");
        if (!fin.is_open()) {
            cout << "Не удаётся открыть файл для чтения " << endl;
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < p; i++)
        {

            fin >> a[i].Nazv;

            fin >> a[i].place;

            fin >> a[i].prof;

            fin >> a[i].kol;
        }
        cout << "\nВыведена информация из файла studentsInfo.txt\n";



    int swap;
    for (int i = 0; i < p; i++)
    {
        for (int j = i + 1; j < p; j++) {
            if (strcmp(a[i].prof, a[j].prof) == 0) {//если проф равны
                strcpy_s(cur, a[i + 1].prof); // копир второе в перв
                strcpy_s(a[i + 1].prof, a[j].prof);
                strcpy_s(a[j].Nazv, cur);


                strcpy_s(cur, a[i].Nazv);
                strcpy_s(a[i].Nazv, a[j].Nazv);
                strcpy_s(a[j].Nazv, cur);

                swap = a[i].kol;
                a[i].kol = a[j].kol;
                a[j].kol = swap;

                strcpy_s(sn, a[i].place);
                strcpy_s(a[i].place, a[j].place);
                strcpy_s(a[j].place, sn);

                if (strcmp(a[i].Nazv, a[i+1].Nazv) > 0)
                {
                    strcpy_s(cur, a[i].Nazv);
                    strcpy_s(a[i].Nazv, a[i+1].Nazv);
                    strcpy_s(a[j].Nazv, cur);

                    swap = a[i].kol;
                    a[i].kol = a[i+1].kol;
                    a[i+1].kol = swap;

                    strcpy_s(sn, a[i].place);
                    strcpy_s(a[i].place, a[i+1].place);
                    strcpy_s(a[i+1].place, sn);



            }






                }
            }
        }

    cout << "\n\nПосле этого времени отправляются поезда \n";



    printf("+--------+------------+-----------------+-----------+\n");
    printf("| nazvan |     place  |       Profil    |   kol     |\n");
    printf("+--------+------------+-----------------+-----------+\n");
    for (int i = 0; i < p; i++) {
        cout <<  a[i].Nazv << "\t   ";
        cout <<a[i].place << "\t\t";
        cout <<  a[i].prof << "\t\t\t";
        cout <<  a[i].kol << "\n";
    printf("+--------+------------+-----------------+-----------+\n");
    }





}
*/