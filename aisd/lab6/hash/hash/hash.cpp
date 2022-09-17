// hash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#define SIZE 32
using namespace std;

bool Prov(string num, int left, int right)
{
	if (num == "")
		return false;
	char nums[] = "0123456789";
	bool notNumber = false;
	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < strlen(nums); j++)
		{
			if (num[i] == nums[j])
			{
				notNumber = false;
				break;
			}
			else
				notNumber = true;
		}
		if (notNumber) {
			cout << "Ввод выполнен не корректно. Попробуйте еще раз\n";
			return false;
		}
			
	}
	if (stoi(num) < left || stoi(num) > right) {
		cout << "Ввод выполнен не корректно. Попробуйте еще раз\n";
		return false;
	}
	return true;
}


struct Information {
	int number;
	string name;
} Inf;

struct HT {
	array <vector<Information>, SIZE> arr;

	int hash(int key)
	{
		return key % SIZE;
	}

	int cnt() {
		int cnt = 0;
		for (auto i : arr) 
			cnt += i.size();
		return cnt;
	}

	bool add(int number, string name)
	{
		if (cnt() == SIZE) 
			return false;
		int place = hash(number);
		for (auto& i : arr[place])
		{
			if (i.number == number) //если номера повтор то номер переписыв на последн имя
			{
				i.name = name;
				cout << i.name << endl;
				return true;
			}
		}

		Inf = { number, name };
		arr[place].push_back(Inf); //записываем в конец 
		return true;
	}

	string operator[](int num)
	{
		int place = hash(num);
		for (auto& i : arr[place])
		{
			if (i.number == num)
			{
				return i.name;
			}
		}
		return "none";
	}

	bool del(int num)
	{
		int place = hash(num);
		short j = 0;

		for (auto i : arr[place])
		{
			if (i.number == num)
			{
				arr[place].erase(arr[place].begin() + j); //идем уже по вектору
				return true;
			}
			j += 1;
		}


		return false;
	}

	void print()
	{
		for (auto i : arr)
		{
			for (auto j : i)
			{
				cout << "Name: " << j.name << "\ttelephone number: " << j.number << endl;
			}
		}
	}
};




void main()
{
	setlocale(LC_ALL, "ru");
	HT arr;
	string check;
	string name;
	string name_2;
	int number, N;
	bool isExit = false;

	while (!isExit)
	{
		do {
			cout << "1) Добавить человека\n"
				<< "2) Удалить человека\n"
				<< "3) Поиск человека\n"
				<< "4) Вывести таблицу\n"
				<< "5) Выход\n";
			getline(cin, check);
		} while (!Prov(check, 1, 5));
		N = stoi(check);
		switch (N)
		{
		case 1:
			do {
				cout << "Введите номер телефона: ";
				getline(cin, check);
				cout << endl;
			} while (!Prov(check, 100000, 999999));
			number = stoi(check);
			cout << "Введите имя: ";
			getline(cin, name);
			arr.add(number, name);
			break;
		case 2:
			do {
				cout << "Введите номер телефона: ";
				getline(cin, check);
				cout << endl;
			} while (!Prov(check, 100000, 999999));
			number = stoi(check);
			if (arr.del(number))
				cout << "Удалено!\n";
			else
				cout << "Нет такого человека\n";
			break;
		case 3:
			do {
				cout << "Введите номер телефона: ";
				getline(cin, check);
				cout << endl;
			} while (!Prov(check, 100000, 999999));

			number = stoi(check);
			name_2 = arr[number];
			cout << name_2 << endl;
			break;
		case 4:
			arr.print();
			break;

		case 5:
			exit(0);
			break;
		}
	}
}