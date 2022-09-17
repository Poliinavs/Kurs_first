// вар 3 ч2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//You can do 123 whot you wont 3 4  145  and why

//Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл.
//Прочитать из файла данные, вывести слова строки и записать их в другой файл.
#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите строку: ";
    char buff[50], mx[50], max = 0;
    char S[255];// буфер для хранения считываемого из файла текста
    ofstream fout("File1.txt");   // создание объекта fout класса ofstream для записи 
    ofstream ft("File2.txt");
    cin.getline(S, 255); //Запоминаем в S то что ввели с клавиатуры
    fout << S << endl; //Записали S в файл и дописали перенос строки
    fout.close();
    ifstream fin("File1.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        cout << "\nВ файл будет записано: ";
        for (int i = 0; i < 25; i++) {

            fin.getline(buff, 50, ' ');
            for (int c = 0; c < strlen(buff); c++) {
                if (buff[c] >= '0' && buff[c] <= '9') {
                    c= strlen(buff);
                }
                else {
                    ft<< buff[c];

                }
                

            }
            ft << " ";


        }

        fin.close();
        ft.close();

    }
}
