// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*Сортировка пузырьком, сортировка подсчетом, сортировка Хоара*/
#include <ctime>             
#include <stdlib.h>
#include <iostream>
using namespace std;
int* sort1(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}

	return a;
}
//------------------------------
int* sort2(int in[], int size)
{
	int out[90000];
	int i, j, count;
	for (i = 0; i < size; ++i)
	{
		for (count = 0, j = 0; j < size; ++j)
			if (in[j] < in[i] || (in[j] == in[i] && i < j))
				count++;
		out[count] = in[i];
	}

		return in;
}
//------------------------------
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


//----------------------------
int getRandKey(int reg = 0)
{
	if (reg > 0)
		srand((unsigned)time(NULL));
	int rmin = 0;
	int rmax = 100000;
	return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}
//------------------------------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int t = 0;
	const int N = 30000;
	int k[N], f[N];
	clock_t  t1, t2;
	getRandKey(1);
	for (int i = 0; i < N; i++)
		f[i] = getRandKey(0);
	for (int n = 10000; n <= N; n += 10000)
	{
		cout << "n = " << n << endl;
		cout << "Сортировка пузырьком ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort1(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "Сортировка подсчетом   ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		sort2(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << "сортировка Хоара   ";
		memcpy(k, f, n * sizeof(int));
		t1 = clock();
		fast_arr(k, n);
		t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl << endl;
	}
	return 0;
}