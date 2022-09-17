// zamenaChisel.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int B[5], n=3;
int print(int A[5]) {
    for (int i=0; i < 5; i++)
        cout << A[i];
    cout << "\n";
    return 0;
}

void perest(int n, int A[5]) {
    int k = n;
   
   
        for (int j = 4; j < 5; j++) {
            for (int i = 4; i > n; i--) {
                swap(A[n], A[i]);
                print(A);
            }
            if (n > 2) {
                n--;
                perest(n, A);
            }
        }
       
    

}

int main()
{
    int temp = 0;
    int A[5];
    setlocale(LC_CTYPE, "Rus");
    cout << "Введите 5 чисел ";
    for (int i = 0; i < 5; i++) {
        cout << "Число номер " << i + 1 << "   ";
        cin >> A[i];
       
        B[i] = A[i];
    }
    cout << "\n";
    cout << A[0] << A[1] << A[2] << A[3] << A[4]<<endl;
    perest(n, A);

//
    for (int z = 0; z < 4; z++) {
        temp = B[0];
        for (int m = 0; m < 4; m++) {
            B[m] = B[m + 1];
        }
        B[4] = temp;
       
        perest(n, B);
        swap(A[0], B[1]);
        perest(n, B);
    }
}

