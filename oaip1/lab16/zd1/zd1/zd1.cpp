// zd1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int razm, z=0;
    cout << "Введите размер массива: ";
    cin >> razm;
    int* Arra = new int[razm];
    int* B = new int[razm];
    int* C = new int[razm];
    cout << "массив A: ";
    for (int i = 0; i < razm; i++)
    {
        Arra[i] = rand() % 100 + 1;
        cout << Arra[i] << "\t";
        if (i % 2 == 0) {
            B[z] = Arra[i];
            C[z] = Arra[i];
            z++;
        }
    }
    cout << "\nМассив B после сортировки пузырьком: ";
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < z - 1; j++) {
            if (B[j] > B[j + 1]) {
                int b = B[j]; // создали дополнительную переменную
                B[j] = B[j + 1]; // меняем местами
                B[j + 1] = b; // значения элементов
            }
        }
    }
    int k = z;
    for (z-=1; z >= 0; z--)
        cout << B[z]<<"\t";
    cout << "\nМассив после сортировки вставкой: ";
        for (int i = 1; i < k; i++)
            for (int j = i; j > 0 && C[j - 1] > C[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
                swap(C[j - 1], C[j]);
        for (k -= 1; k >= 0; k--)
            cout << C[k] << "\t";

    delete Arra;
    delete B;
    delete C;
}

