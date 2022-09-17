// lb10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Varparm.h"

int Varparm::ivarparm(int n, ...)
{
	
	int* p = &n;
	int mul = 1;
	for (int i = 1; i <= n; i++)
		mul = *(++p)*mul;
	return mul;
}

int Varparm::svarparm(short n, ...)
{
	int* p = (int*)&n;
	short max = 0;
	for (int i = 1; i <= n; i++) {
		p ++;
		if (*p > max)
			max = *p;

	}
		
	return max;
}

double Varparm::fvarparm(float n, ...)
{
	double *p = (double*)(&n+1);
	int k = 0;
	float sum = n;
	while (p[k] != (float)FLT_MAX) {
		sum += *(p+k);
		k++;
	}
	return sum;
}

double Varparm::dvarparm(double n, ...)
{
	double *p = (double*)(&n + 1);
	int k = 0;
	double sum = n;
	while (p[k] != (double)DBL_MAX) {
		sum += *(p + k);
		k++;
	}
	return sum;
}