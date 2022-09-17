// вар 2 часть 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Самая короткая группа  б м б б б 

#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50], sm[60];            // буфер для хранения считываемого из файла текста
    char S[255];
    int len, smoll=0;
    cout << "Введите групп цифр и нулей: ";
    ofstream fout("File1.txt");   // создание объекта fout класса ofstream для записи
        cin.getline(S, 255); //Запоминаем в S то что ввели с клавиатуры
        fout << S << endl; //Записали S в файл и дописали перенос строки
        fout.close();
    ifstream fin("File1.txt");    // создание объекта fin класса ifstream для чтения
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < 4; i++)
        {
            fin.getline(buff, 50, ' ');
            len = strlen(buff);
            if (i==0)
                smoll = len;
            if ( len < smoll) {
                smoll = len;
                cout << buff << endl;
            }
           
        }
       
        fin.close();
    }
}


