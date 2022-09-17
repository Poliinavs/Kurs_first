// вар 3 ч1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Скопировать из файла FILE1 в файл FILE2 строки, начиная с к до к + 3.
// Подсчитать количество гласных букв в FILE2.

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file1;
	string path1 = "file1.txt";
	file1.open(path1);

	fstream file2;
	string path2 = "file2.txt";
	file2.open(path2, fstream::in | fstream::out);

	short k;
	cout << "От какой строки начать копирование(1 - 10): ";
	cin >> k;

	string trash,
		str;

	int cntr = 0;

	for (int i = 0; i < 10; i++)
	{
		if (i >= k - 1 && i < k + 2)
		{
			getline(file1, str);
			char glasn[] = "aeyuoiаяуеоэюёAEYUOIАЯУЕОЭЮЁ";

			for (int i = 0; i < str.size(); i++)
			{
				for (int j = 0; j < 28; j++)
				{
					char symb = str[i];
					if (symb == glasn[j])
					{
						cntr++;
					}
				}
			}

			file2 <<str << "\n";
		}
		else
		{
			getline(file1, trash);
		}
	}

	cout << "Количество гласных в " << path2 <<" - " << cntr;

	file1.close();
	file2.close();

}
