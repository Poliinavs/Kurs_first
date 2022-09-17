// primer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;
struct Date {
	day dd;
	month mm;
	year yyyy;
};

bool operator == (Date date1, Date date2)
{

	return (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd);
	
};
bool operator <(Date date1, Date date2)
{
	return (date1.yyyy < date2.yyyy || date1.yyyy == date2.yyyy && date1.mm < date2.mm || date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd < date2.dd);
};
bool operator >(Date date1, Date date2)
{
	return (date1.yyyy > date2.yyyy || date1.yyyy == date2.yyyy && date1.mm > date2.mm || date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd > date2.dd);
};
int main()
{
	//1
	setlocale(LC_ALL, "rus");
	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1990 };
	Date date3 = { 7,1,1980 };
	if (date1 < date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 > date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 == date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 == date3) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }

}
