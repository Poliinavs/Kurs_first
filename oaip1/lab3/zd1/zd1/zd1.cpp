// zd1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <io.h>
#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    char buff[100]; // буфер для хранения считываемого из файла текста
    char str[256];
    ofstream fout("FILE1.txt");   // создание объекта fout класса ofstream для записи
    fout << "Работа с файлами в С++\n Четная строка\n Нечетная\n Ещё одна четная\n  Нечетная\n "; // запись строки в файл

    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        ofstream FILE2("FILE2.txt");
        for (int i = 0; i < 5; i++) {
            if (i == 2 || i == 4) {
                FILE2 << buff << "\n";
            }
            fin.getline(buff, 100);
        }
        fout.close();
        FILE2.close();
        fin.close();
        cout << "Все успешно записано";
    }
}
