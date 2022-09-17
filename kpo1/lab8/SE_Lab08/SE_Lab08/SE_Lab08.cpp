// SE_Lab08.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Call.h"
using namespace std;

namespace call {
	int _cdecl cdevl(int a, int b, int c){return a + b + c;}
	int _stdcall cstd(int& a_ref, int b, int c){return a_ref * b * c;}
	int _fastcall cfst(int a, int b, int c, int d){return a + b + c + d;}
}
void main() {
	int a = 5;
	int result_1 = call::cdevl(3, 2, 1);
	int result_2 = call::cstd(a, 2, 1);
 	int result_3 = call::cfst(3, 2, 1, 4);
}
