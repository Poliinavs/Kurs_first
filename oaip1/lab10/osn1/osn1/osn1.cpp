// osn1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// от основного числа отнимаем 1 и отнимаем получившиеся число от отсновного этот остаток чрез функцию или цикл раскадываем до момента пока все будут 1, 1 это выход из рекурсии

#include <iostream>
using namespace std;
int n = 1, kol=0, k=0;
void razl(int numb) {
    if (numb > 1) {
        for (int i = 1; i < numb - 1; i++) {
            k = numb - 1;
          
            kol++;
            if (k > 1)
                
                razl(k);
        }
   }

    
}

int main()
{
    setlocale(LC_CTYPE, "Rus");
    int numb, osn=0, ost=0;
    cout << "Введите число: "<<endl;
    cin >> numb;
    razl(numb);
    cout << "Количество разложений " << kol+1;
}

