// вар 4 ч1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    int kont = 0,a=0;
    char buff[100];            // буфер для хранения считываемого из файла текста
    ofstream fout("File1.txt");   // создание объекта fout класса ofstream для записи 
    fout << "Работа с файлами 123 в С++\n Анна пошла гулять\n Как найти код 145\n Алла любит математику \n Куда пойдем сегодная "; // запись строки в файл
    fout.close();
    ofstream ft("File2.txt");
    ifstream fin("File1.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < 5; i++)
        {
            fin.getline(buff, 100, '\n');
            for (int c = 0; c < strlen(buff); c++) {
                if (buff[c] >= '0' && buff[c] <= '9')
                    kont++;
                if (buff[c] =='А')
                    a++;
            }
            if (kont == 0)
                ft << buff << endl;
            kont = 0;
        }
        cout << "В файле File2 " << a << " строки начинаются на букву А";
        fin.close();
        ft.close();
    }
}