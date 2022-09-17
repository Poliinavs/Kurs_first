#pragma once
using namespace std;
struct STACK {
	int data;
	STACK* head;
	STACK* next;
};

struct PolST {
	int data1;
	PolST* head1;
	PolST* next1;
};
struct OtrST {
	int data;
	OtrST* head;
	OtrST* next;
};

void AddEl(int elem, STACK* stack, PolST* st, OtrST* stac);
void PrintStack(STACK* stack, PolST* st, OtrST* stac);
void ToFile(STACK* stack);
void FromFile(STACK* stack);
void clear(STACK* stack, PolST* st, OtrST* stac);