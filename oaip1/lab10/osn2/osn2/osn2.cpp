// osn2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int k = 0;
int n = 0;
float y = 1, x = 0;
 float razl(int numb) {
     y = sqrt(1 + (numb + numb - k) * y);
     k++;
     if (k != numb)
         razl(numb);
     return y;
}

int main()
{
    setlocale(LC_CTYPE, "Rus");
    int numb, osn = 0, ost = 0;
    cout << "Введите число: " << endl;
    cin >> numb;
    cout<<"Выражение равно: "<< razl(numb);
}


