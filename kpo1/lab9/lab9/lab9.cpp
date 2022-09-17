// lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

namespace Call {
	int defaultparm(int a, int b, int c, int e = 4, int f = 5)
	{
		return (a + b + c + e + f) / 5;
	}
};
namespace Call2 {
	int defaultparm(int a, int b, int c, int k, int m, int e = 4, int f = 5)
	{
		return (a + b + c + e + f + k + m) / 7;
	}
};

void main()
{
	Call::defaultparm(1, 2, 3);
	Call2::defaultparm(1, 2, 3, 4, 5, 6);
}