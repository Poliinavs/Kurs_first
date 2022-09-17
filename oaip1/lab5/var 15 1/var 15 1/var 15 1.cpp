///вар 7 ч 1
#include <iostream>  
#include<fstream>
# define str_len 256 
# define size 100  
using namespace std;
void enter_new();
void out();
void del();
void search();
struct Sklad
{
	char name[str_len];
	float price;
	int kol;
	int per;
};
enum Percent
{
	five = 5, seven = 7, eleven = 11, twenty = 20, twentyFive, thirty = 30
};
struct Sklad productonsklad[size];
Sklad all;
int current_size = 0; int choice;
int sell;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для удаления" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  del();  break;
		case 4:  search();	break;


		}
	} while (choice != 5);
}
void enter_new()
{
	cout << "Вывод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Наименование товара:" << endl;
		cin >> productonsklad[current_size].name;
		cout << "Цена:" << endl;
		cin >> productonsklad[current_size].price;
		cout << "Количество:" << endl;
		cin >> productonsklad[current_size].kol;
		cout << "Процент надбавки:" << endl;
		cin >> productonsklad[current_size].per;
		current_size++;

	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Строка номер " << endl;   cin >> n;  cout << endl;
		cout << "Наименование товара:" << endl;
		cout << productonsklad[n - 1].name << endl;
		cout << "Цена:" << endl;
		cout << productonsklad[n - 1].price << endl;
		cout << "Количество:" << endl;
		cout << productonsklad[n - 1].kol << endl;
		if (productonsklad[n - 1].per == 5) {
			cout << "Процентная надбавка:" << five << "%" << endl;
		}
		else if (productonsklad[n - 1].per == 7) {
			cout << "Процентная надбавка:" << seven << "%" << endl;
		}
		else if (productonsklad[n - 1].per == 11) {
			cout << "Процентная надбавка:" << eleven << "%" << endl;
		}
		else if (productonsklad[n - 1].per == 20) {
			cout << "Процентная надбавка:" << twenty << "%" << endl;
		}
		else if (productonsklad[n - 1].per == 25) {
			cout << "Процентная надбавка:" << twentyFive << "%" << endl;
		}
		else if (productonsklad[n - 1].per == 30) {
			cout << "Процентная надбавка:" << thirty << "%" << endl;
		}
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << endl << "Наименование товара:" << endl;
			cout << productonsklad[i].name << endl;
			cout << "Цена:" << endl;
			cout << productonsklad[i].price << endl;
			cout << "Количество:" << endl;
			cout << productonsklad[i].kol << endl;
			if (productonsklad[i].per == 5) {
				cout << "Процентная надбавка:" << five << "%" << endl;
			}
			else if (productonsklad[i].per == 7) {
				cout << "Процентная надбавка:" << seven << "%" << endl;
			}
			else if (productonsklad[i].per == 11) {
				cout << "Процентная надбавка:" << eleven << "%" << endl;
			}
			else if (productonsklad[i].per == 20) {
				cout << "Процентная надбавка:" << twenty << "%" << endl;
			}
			else if (productonsklad[i].per == 25) {
				cout << "Процентная надбавка:" << twentyFive << "%" << endl;
			}
			else if (productonsklad[i].per == 30) {
				cout << "Процентная надбавка:" << thirty << "%" << endl;
			}
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			productonsklad[de1] = productonsklad[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			productonsklad[i] = all;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	cout << "Цена товара" << "\n";
	cin >> sell;
	for (int z = 0; z < current_size; z++)
	{
		if (sell == productonsklad[z].price)
		{
			cout << endl << "Наименование товара:" << endl;
			cout << productonsklad[z].name << endl;
			cout << "Цена:" << endl;
			cout << productonsklad[z].price << endl;
			cout << "Количество:" << endl;
			cout << productonsklad[z].kol << endl;
			if (productonsklad[z].per == 5) {
				cout << "Процентная надбавка:" << five << "%" << endl;
			}
			else if (productonsklad[z].per == 7) {
				cout << "Процентная надбавка:" << seven << "%" << endl;
			}
			else if (productonsklad[z].per == 11) {
				cout << "Процентная надбавка:" << eleven << "%" << endl;
			}
			else if (productonsklad[z].per == 20) {
				cout << "Процентная надбавка:" << twenty << "%" << endl;
			}
			else if (productonsklad[z].per == 25) {
				cout << "Процентная надбавка:" << twentyFive << "%" << endl;
			}
			else if (productonsklad[z].per == 30) {
				cout << "Процентная надбавка:" << thirty << "%" << endl;
			}
		}
	}
	cout << "Выберете дальше" << endl;
	cin >> choice;
}