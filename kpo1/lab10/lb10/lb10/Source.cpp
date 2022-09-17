#include <iostream>
#include "Varparm.h"

void main()
{
	Varparm::ivarparm(4, 5, 2, 3, 4); 
	Varparm::svarparm(6, 2, 3, 4, 5, 6, 1);
	Varparm::fvarparm(3.2, 1.2, 2.2, FLT_MAX);
	Varparm::dvarparm(2.11, 3.87, 4.89, DBL_MAX);
}