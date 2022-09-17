// laba3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;

int(*f) (int, int);
int sum(int x, int y) { return x + y; };
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool b1 = true;
	bool b2 = false;

	char symbEN = 'v';
	char symbRU = 'в';

	wchar_t sEN = 'a';
	wchar_t sRU = 'а';
	int t = 'X';
	int t2 = '-X';

	short x = 10, // 0x0000000a
		_x = -10; // 0xfffffff6

/*
while (x > _x) //к 10 номеру  находим самый большое и маленькое число
  {
	  _x = x;
	  x++;
  }

  char max[10],
	   min[10];

  _itoa_s(_x, max, 16); //основание стипени счисления 16, преобраз в строку max, вычисляем 16 значение
  _itoa_s(x, min, 16);

  cout << _x << " " << max << endl <<x << " " << min << endl;*/
	short max = 0x7fff,  //задан 10
		min = 0xffff8000;
				
	unsigned short miins = 0x00000000,
					maaxs = 0x0000ffff;

	int Y = 11, // 0x00000000b
		_Y = -11; // 0xfffffff5
	int maxi = 0x7fffffff,
		mini = 0x80000000;

	unsigned int maxs_u = 0xFFFFFFFF;
	unsigned int min_u = 0x00000000;
	
	long  h1 = 12; //0x0000000c
	long  h2 = -12; //0xfffffff4

	
	unsigned long d1 = 0xFFFFFFFFFFFFFFFF;
	unsigned long d2 = 0x00000000;
	
	float s = 2.0;
	float s1 = -2.0;

	float r3 = s / 0;
	float r4 = s1 / 0;
	float r5 = r3 + r4;

	char* f_pnt_char = &symbEN;
	char* s_pnt_char = &symbRU;


	wchar_t* f_pnt_wchar = &sEN;
	wchar_t* s_pnt_wchar = &sRU;

	short* f_pnt_short = &x;
	short* s_pnt_short = &_x;

	int* f_pnt_val = &Y;
	int* s_pnt_val = &_Y;

	long* f_pnt_long = &h1;
	long* s_pnt_long = &h2;

	float* f_pnt_float = &s;
	float* s_pnt_float = &s1;

	char* p2011 = f_pnt_char + 3;
	wchar_t* p2022 = f_pnt_wchar + 3;
	short* p2033 = f_pnt_short + 3;
	int* p2044 = f_pnt_val + 3;
	float* p2055 = f_pnt_float + 3;
	long* p2066 = f_pnt_long + 3;
	

	
	f = sum;
	int a21 = f(1, 8);
	
}






