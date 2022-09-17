// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack> 
#include <string> 
using namespace std;
stack <char> steck;
int t = 0;
void prov(char k) {
	if (k == steck.top()) //если закрыв элемент равн последн в стеке
		steck.pop(); //удал последн элем
	else {
		if(t==0)
			cout << "\nскобки расставлены не верно";
		t = 1;	
	}
}
int main()
{
	int kol=0;
	setlocale(LC_ALL, "rus");
	string n;
	cout << "\nВведите элемент: ";
	cin >> n;
	kol = n.length();
	for (int i=0; i < kol; i++) {
		if (n[i] == '(')
			steck.push(')');
		if (n[i] == '[')
			steck.push(']');
		if (n[i] == '{')
			steck.push('}');
				if (n[i] == ')') 
					prov(n[i]);
				if (n[i] == ']')
					prov(n[i]);
				if (n[i] == '}')
					prov(n[i]);
	}
	if (t == 0) {
		cout << "\nскобки расставлены верно";
	}
		
}


