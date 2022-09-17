#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"
struct STACK {
	int data;
	STACK* head;
	STACK* next;
};

void AddEl(int elem, STACK* stack);
int TakeFromStack(STACK* stack);
void PrintStack(STACK* stack);
void ToFile(STACK* stack);
void FromFile(STACK* stack);
int DeleteSame(STACK* stack);
void clear(STACK* stack);

void DeleteSameHelp(STACK* stack, int point);