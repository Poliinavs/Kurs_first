// prim.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool val1 = true,
		val2 = false;

	char symbEN = 'a',
		symbRU = 'а';

	wchar_t sEN = 'G',
		sRU = 'Г';

	short x = 14, // 0xeeeeeeee
		_x = -14; // 0xfffffff2

  /*while (x > _x)
  {
	  _x = x;
	  x++;
  }

  char max[10],
	   min[10];

  _itoa_s(_x, max, 16);
  _itoa_s(x, min, 16);

  cout << _x << " " << max << endl <<x << " " << min << endl;*/

	short max = 0x7fff,
		min = 0xffff8000;

	unsigned short mins = 0x0;
	/* a,
				   b;

	a = 10;
	b = 11;

	while (a < b)
	{
		b = a--;
	}

	cout << b;*/

	int Y = 15, // 0xffffffff
		_Y = -15; // 0xfffffff1	

	/*char _Ystr[10];
	_itoa_s(-14, _Ystr, 16);
	cout << _Ystr;*/

	int maxInt,
		minInt,
		a = 1,
		b = 0;

	/*while (a > b)
	{
		b = a++;
	}*/

	/*char _Ystr[10];
	_itoa_s(b, _Ystr, 16);
	cout << _Ystr << endl;
	_itoa_s(a, _Ystr, 16);
	cout << _Ystr << endl;*/

	maxInt = 0x7fffffff;
	minInt = 0x80000000;

	unsigned int maxUnInt = 0xffffffff,
		minInInt = 0x00000000,
		c, d;

	/*c = 1;
	d = 0;

	while (c > d)
	{
		d = c++;
	}

	char str[10];
	_itoa_s(d, str, 16);
	cout << str;*/

	long Z = 0x10, // 0x10
		_z = 0xfffffff0;
	/*2147483647
		- 2147483648*/
		/*char str[16];
		_itoa_s(6.0, str, 16);
		cout << str;*/

	long maxL = 0x7fffffff,
		minL = 0x80000000;

	unsigned long maxUL = 0xffffffff,
		minUL = 0x00000000,
		h = 0, y = 1;

	/*4294967295*/


	float s = 6.0, // 0x6
		_s = -6.0; // 0xfffffffa



	return 0;
}