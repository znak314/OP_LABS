#include<iostream>
#include<Windows.h>
#include<ctime>
#include<iomanip>
#include<string>

#define MinLen1 1 // мін розмір масива - 1
#define MaxLen 20 //макс розмір масива - 20
extern int SizeArray;

using namespace std;

class NumberArray
{
	int size;
	int* arr;
public:
	void printArray();
	void FillArray();
	int getMax();
	NumberArray();
	~NumberArray();
};

int EnterSize();
void FillAll(NumberArray* Array, int sizeObj);
void PrintAll(NumberArray* Array, int sizeObj);
int FindSmallestMax(NumberArray* Array, int sizeObj);
