#include <iostream>
#include <ctime>
using namespace std;
int fibon(int i) {
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	return fibon(i - 1) + fibon(i - 2);
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int kol, first = 1, sec = 1, fib = 0;
	cout << "Введите количесвто чисел: ";
	cin >> kol;
	
	if (kol == 1) {
		cout <<"0";
	}
	else if (kol == 2) {
		cout << "0 1 ";
	}
	else {
		unsigned int start_time = clock();
		for (int i = 3; i < kol; i++) {
			fib = first + sec;
			sec = first;
			first = fib;
		}
		cout << " " << fib;
	unsigned int end_time = clock();
	unsigned int time = end_time - start_time;
		cout << "\nВремя цикла: " << time << "мс."<<endl;
	}
	//рекурс
		unsigned int start = clock();
		cout << fibon(kol-1) << " ";
		unsigned int end = clock();
		unsigned int time1 = end - start;
	cout << "\nВремя рекрусивного цикла: " << time1 << "мс." << endl;

}
