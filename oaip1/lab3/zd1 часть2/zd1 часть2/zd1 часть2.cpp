// zd1 часть2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Это 2 маленькая 1 программа 123 нечетными 44 четными 12 

#include <iostream>
#include <fstream>
using namespace std;
void inFile(ifstream& f, char buff[]); //Функция чтения из файла
void fromFile(ofstream& f,  char s[]); //Функция записи в файл

void main()
{
	setlocale(0, "Rus");
	char str[40];
	char buff[50];
	ifstream ifile;
	ofstream ofile;
	cout << " ВВедите строку, котрую требуется записать: ";
	cin >> str; 
	fromFile(ofile, str);
	cout << "Нечетные числа строки: ";
	inFile(ifile,buff);			
}
	void fromFile(ofstream& f, char s[40]) //Функция записи в файл
	{
		ofstream fout("f.txt");// для записи
		if (f.fail())
		{
			cout << "\n Ошибка открытия файла";
			exit(1);
		}
		fout << "Это 2 маленькая 1 программа 123 нечетными 44 четными 12 ";
		fout.close();	
	}
		void inFile(ifstream& f, char buff[40]) //Функция чтения из файла
		{
			ifstream fin("f.txt");    // создание объекта fin класса ifstream для чтения  
			if (!fin.is_open())
				cout << "Файл не может быть открыт!\n";
			else
			{

				for (int i = 1; i < 11; i++) {
					if (i % 2 != 0 && i != 1) {
						int a = atoi(buff);
						if (a % 2 != 0)
							cout << a << "\t";
					}
					fin.getline(buff, 50, ' '); // считывание строки из файла
				}
				fin.close();
			}
		}

