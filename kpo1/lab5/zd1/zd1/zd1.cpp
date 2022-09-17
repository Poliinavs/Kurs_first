// zd1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//банковский_счет: номер, тип вклада, баланс, 
//дата_открытия, владелец, подключение смс оповещения,
//подключение_интернет - банкинга

#include <iostream>
using namespace std;

typedef unsigned int number;
typedef  string type;
typedef unsigned int balans;
typedef unsigned int date;
typedef  string owner;
typedef bool sms;
typedef bool internet;

using namespace std;
struct Banck_score {
    number nn;
    type tt;
    balans bb;
    date dd;
    owner oo;
    sms ss;
    internet ii;
};

bool operator >(Banck_score score1, Banck_score score2) {
    return(score1.bb > score2.bb); 

}
bool operator <(Banck_score score1, Banck_score score3) {
   
    return  (score1.bb < score3.bb); 
}
bool operator ==(Banck_score score1, Banck_score score3) {
   
    return (score1.dd == score3.dd && score1.ss == score3.ss) ; 
}

int main()
{
    setlocale(LC_ALL, "RUS");
    Banck_score  score1 = { 12, "Валютный", 1000, 12042021, "Игорь", 1, 0 };
    Banck_score  score2 = { 10, "Рублевый", 3000, 11042022, "Андрей", 0, 0 };
    Banck_score  score3 = { 14, "Валютный", 7000, 12042021, "Алексей", 1, 1 };

    if (score1 > score2)
        cout << "У клинта номер: " << score1.nn << " баланс больше" << endl;
    else
        cout << "У клинта номер: " << score2.nn << " баланс больше" << endl;

    if (score1 < score3)
        cout << "У клинта номер: " << score3.nn << " баланс больше" << endl;
    else
        cout << "У клинта номер: " << score1.nn << " баланс больше" << endl;
    if (score1 == score3)
        cout << "Клиенты номер " << score1.nn << " и " << score3.nn << " открыли счет в один день и подключили смс " << endl;
    else cout << "Клиенты номер " << score1.nn << " и " << score3.nn << "открыли счет в разные дни" << endl;



}