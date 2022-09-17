// Olimp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int razm, rez[10000], maxRez=0;
    cout << "Введите число участников олимпиады(меньше 10000) ";
    cin >> razm;
    for (int i = 0; i < razm; i++) {
        rez[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < razm; i++) { /*сортировка встаавкой*/
        for (int i = 1; i < razm; i++)
            for (int j = i; j > 0 && rez[j - 1] > rez[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
                swap(rez[j - 1], rez[j]);
        cout << "Участник номер " << i + 1 << " результат " << rez[i] << endl;
    }
    maxRez = rez[razm - 1];
    int k = 0, kol=0;
    for (razm - 1; razm >= 0; razm--)
    {
        if (maxRez== rez[razm] || k<2) {
            kol++;
            if(maxRez != rez[razm])
            k++;
        }
   }
    cout << "Количество призеров: " << kol;

}
