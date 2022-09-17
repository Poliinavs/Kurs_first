#include<iostream>
using namespace std;
#define NUMBER 26;
void main() {
	setlocale(LC_CTYPE, "ru");
	int x, y, z;
	float s;
	bool t = true, f = false;
	char c1 = 'm';
	char c2 = 'ì';
	wchar_t wc1 = L's';
	wchar_t wc2 = L'ñ';
	x = 9 + NUMBER;
	y = 10 + NUMBER;
	z = 11 + NUMBER;
	s = 1.0 + NUMBER;
	short int x1 = x;
	short int x2 = -x;
	short int q1 = 0x7FFF;
	short int q2 = 0x8000;
	unsigned short int k1 = 0xFFFFu;
	unsigned short int k2 = 0x0u;
	int p1 = y;
	int p2 = -y;
	int m1 = 0x7FFFFFFF;
	int m2 =0x80000000;
	unsigned int b1 = 0xFFFFFFFF;
	unsigned int b2 = 0x0;
	long int h1 = 0x7fffffff;
	long int h2 =0x80000000;
	unsigned long d1 = 0xFFFFFFFFFFFFFFFF;
	unsigned long d2 = 0x0;
	float r1 = s;
	float r2 = -s;
	float r3 = r1 / 0;
	float r4 = r2 / 0;
	float r5 = r3 + r4;




	}