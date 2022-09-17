// magazin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int razm, prod[10000], cost=0;
    cout << "Введите число товаров(меньше 10000) ";
    cin >> razm;
    for (int i=0; i < razm; i++) {
        prod[i]= rand() % 100 + 1;
    }
    for (int i = 0; i < razm; i++) { /*сортировка встаавкой*/
        for (int i = 1; i < razm; i++)
            for (int j = i; j > 0 && prod[j - 1] > prod[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
                swap(prod[j - 1], prod[j]);
        cout << "Продукт номер " << i + 1 << " цена " << prod[i] << endl;
    }
    cout << "\nКассир будет пробивать в порядке: \n";
    for (int i = razm / 2; i < razm; i++) {
        cout << "\nДорогой продукт: " << prod[i];
        cout << "\nДешевый продукт: " << prod[i - razm / 2];
      
        cost += prod[i];
    }      
    cout << "\nОбщая стоимость товаров: " << cost;
}

