// zd1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// laba3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;

int(*f) (int, int);
int sum(int x, int y) { return x + y; };
int mult(int x, int y) { return x*y; };

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool b1 = true; //01
	bool b2 = false; //00

	char symbEN = 'v'; //0x76
	char symbRU = 'в'; //0xe2

	wchar_t sEN = 'a'; //0x0061
	wchar_t sRU = 'а'; //0xffe0
	int t = 'X'; //0x00000058
	int t2 = '-X'; //00002d58

	short x = 10, // 0000 0000 0000 1010=0x000a 
		_x = -10; // 0000 0000 0000 1010 ПР=1111 1111 1111 0110 ДК==0xfff6

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

	short max = 0x7fff,  // 32767=0111 1111 1111 1111=7fff
		min = 0x8001; //=-32767= 0111 1111 1111 1111 ПР= 1000 0000 0000 0001

	unsigned short miins = 0x0000, 
		maaxs = 0xffff; //65535= 1111 1111 1111 1111

	int Y = 11, //   0000 0000 0000 0000 0000 0000 0001 0111 =0x00000000b
		_Y = -11; // 1111 1111 1111 1111 1111 1111 1111 1101=0xfffffff5
	int maxi = 0x7fffffff,  //2147483647=0111 1111 1111 1111 1111 1111 1111 1111
		mini = 0x80000000; //-2147483647 =0111 1111 1111 1111 1111 1111 1111 1111 ПР=1000 0000 0000 0000 0000 0000 0000 000 ОБР =1000 0000 0000 0000 0000 0000 0000 0001 Доп

	unsigned int maxs_u = 0xFFFFFFFF; //4294967295=1111 1111 1111 1111 1111 1111 1111 1111
	unsigned int min_u = 0x00000000; 

	long  h1 = 12; //0000 0000 0000 0000 0000 0000 0000 1100=0x0000000c
	long  h2 = -12; //0000 0000 0000 0000 0000 0000 0000 1100=1111 1111 1111 1111 1111 1111 1111 0100 ДК=0xfffffff4


	unsigned long d1 = 0xFFFFFFFF; //4294967295=1111 1111 1111 1111 1111 1111 1111 1111
	unsigned long d2 = 0x00000000;


	float s = 2.0;  //0.00000010.00000000000000000000000=20000000
	float s1 = -2.0; //1.11111110.000000000000000000000=c0000000

	float r3 = s / 0; //7f800000
	float r4 = s1 / 0; //ff800000
	float r5 = r3 + r4; //ffc00000

	char* f_pnt_char = &symbEN; //0x0x00a0f857
	char* s_pnt_char = &symbRU; //0x010ffe33


	wchar_t* f_pnt_wchar = &sEN; //00x00a0f83c
	wchar_t* s_pnt_wchar = &sRU; //0x010ffe18

	short* f_pnt_short = &x; //0x00a0f80c
	short* s_pnt_short = &_x; //0x010ffde8

	int* f_pnt_val = &Y; //0x00a0f7c4
	int* s_pnt_val = &_Y; //0x010ffda0

	long* f_pnt_long = &h1; //0x00a0f77c
	long* s_pnt_long = &h2; //0x010ffd58

	float* f_pnt_float = &s; //0x00a0f74c
	float* s_pnt_float = &s1; //0x010ffd28

	char* p2011 = f_pnt_char + 3; //0x00a0f857+sizeof(char)*3=00a0 f857+ 3 =0x00a0f85a//(+3 ) 
	wchar_t* p2022 = f_pnt_wchar + 3; //00x00a0f83c+sizeof(wchar_t)*3=00a0f83c + 6 =00a0f842 //+6 
	short* p2033 = f_pnt_short + 3; //00a0f80c+sizeof(short)*3=00a0f80c+6- =00a0f8012 //+6
	int* p2044 = f_pnt_val + 3; //00a0f7c4+sizeof(int)*3=00a0f7c4 + c =00a0f7d0 //+12
	float* p2055 = f_pnt_float + 3; //00a0f74c+sizeof(float)*3=00a0f74c +c =00a0f758 //+12   
	long* p2066 = f_pnt_long + 3; //00a0f77c+sizeof(long)*3=00a0f77c+12 =00a0f788//+12



	f = sum;
	int a21 = f(1, 8);

	f = mult;
	int a22 = f(1, 8);

	
	

}






