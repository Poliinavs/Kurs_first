// вар 2 ч1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    int m = 0;
    setlocale(LC_ALL, "rus");
    cout << "Начальная строка:\n Работа с файлами в С++\n Анна ехала гулять \n Нечетная\n Антилопа быстро бегает\n  Нечетная и большая\n  ";
    char buff[50], count[100];            // буфер для хранения считываемого из файла текста
    ofstream fout("FILE1.txt");   // создание объекта fout класса ofstream для записи 
    fout << "Работа с файлами в С++\n Анна ехала гулять \n Нечетная\n Антилопа быстро бегает \n  Нечетная и большая\n "; // запись строки в файл
    fout.close();
    ifstream fin("FILE1.txt");    // создание объекта fin класса ifstream для чтения  
    ofstream FILE2("FILE2.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        ifstream f2("FILE2.txt");
        for (int i = 0; i < 2; i++) {
            fin.getline(buff, 50, 'А');// считывание строки из файла
            fin.getline(buff, 50);
            FILE2 << "А" << buff << endl;
        }
        for (int i = 0; i < 50; i++) {
            f2.getline(count, 50);
            if ((count[i] == '\n') || (count[i] == ' '))
                m++;
        }
        cout << "\nКоличество слов в FILE2: " << m*2;
        f2.close();
        fin.close();
        FILE2.close();
    }
}
