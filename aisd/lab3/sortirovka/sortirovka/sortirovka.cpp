// sortirovka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
void fast_arr(int*, int);
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int razm;
    cout << "Введите размер массива: ";
    cin >> razm;
    int* Arra = new int[razm];
    int* B = new int[razm];
    int* C = new int[razm];
    int* D = new int[razm];
    int* E = new int[razm];
    cout << "Ваш массив: ";
        for (int i = 0; i < razm; i++)
        {
            Arra[i] = rand()%100+1;
            B[i] = Arra[i];
            C[i] = Arra[i];
            D[i] = Arra[i];
            E[i] = Arra[i];
            cout << Arra[i]<<"\t";
        }
        unsigned int start_time = clock(); //пузырьковая сортировка  идет слева направо сравнивает 2 соседних
        for (int i = 0; i < razm; i++) {
            for (int j = 0; j < razm-1; j++) {
                if (B[j] > B[j + 1]) {
                    int b = B[j]; // создали дополнительную переменную
                    B[j] = B[j + 1]; // меняем местами
                   B[j + 1] = b; // значения элементов
                }
            }
        }
        unsigned int end_time = clock();
        unsigned int time = end_time - start_time;
        cout << "\nМассив после пузырьковой сортировки ";
        for (int i = 0; i < razm; i++)
        {
            cout << B[i] << "\t";
        }
        cout << "\nВремя пузырьковой сортировки: " << time << "мс." << endl;

        unsigned int start_time_vstavk = clock(); //сортировкой вставкой  //берем элементi и прогоняем его влево до его мета сравниван его с сосед
        for (int i = 1; i < razm; i++)
            for (int j = i; j > 0 && C[j - 1] > C[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
                swap(C[j - 1], C[j]);        // меняем местами элементы j и j-1

        unsigned int end_time_vstavk = clock();
        unsigned int time_vstavk = end_time_vstavk - start_time_vstavk;
        cout << "\nМассив после сортировки вставкой ";
        for (int i = 0; i < razm; i++)
        {
            cout << C[i] << "\t";
        }
        cout << "\nВремя сортировки вставкой: " << time_vstavk << "мс." << endl;

        int min = 0, buf;
        unsigned int start_time_find = clock(); //сортировка выбором
        for (int i = 0; i < razm; i++) 
        {
            min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
            // в цикле найдем реальный номер ячейки с минимальным значением
            for (int j = i + 1; j < razm; j++)   //проходит весь фор и находит самый меньший элемент среди всего ряда и елси это не 1 элемент то ставит его на 1 мметсо
                min = (D[j] < D[min]) ? j : min; //если да то min=j;
            // cделаем перестановку этого элемента, поменяв его местами с текущим
            if (i != min)
            {
                swap(D[i], D[min]);
            }
        }

        unsigned int end_time_find = clock();
        unsigned int time_find = end_time_find - start_time_find;
        cout << "\nМассив после сортировки выбором ";
        for (int i = 0; i < razm; i++)
        {
            cout << D[i] << "\t";
        }
        cout << "\nВремя сортировки выбором: " << time_find << "мс." << endl;




        unsigned int start_time_quickly = clock(); //быстрой сортировкой //из массива выбирается некоторый опорный элемент a[i] запускается процедура разделения массива, которая перемещает все ключи, меньшие, либо равные a[i], влево от него, а все ключи, большие, либо равные a[i] - вправо,
        fast_arr( E, razm);
        unsigned int end_time_quickly = clock();
        unsigned int time_quickly = end_time_quickly - start_time_quickly;
        cout << "\nМассив после быстрой сортировки  ";
        for (int i = 0; i < razm; i++)
        {
            cout << E[i] << "\t";
        }
        cout << "\nВремя быстрой сортировки: " << time_quickly << "мс." << endl;

        delete Arra;
        delete B;
        delete C;
        delete D;
        delete E;
}


void fast_arr(int* arr, int size)
{
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = arr[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (arr[i] < mid) {
            i++;
        }

        //В правой части пропускаем элементы, которые больше центрального
        while (arr[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        fast_arr(arr, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        fast_arr(&arr[i], size - i);
    }

}
