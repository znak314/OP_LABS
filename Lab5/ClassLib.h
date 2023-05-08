#include<iostream>
#include <string>
#include<iomanip>
#include<ctime>

using namespace std;

class TIntNumber
{
protected:
	int number;
	int base;
public:
	TIntNumber();
	void Increment();
	void Decrement();
	int GetDecimal();
	virtual void Convert() = 0;
};

class TIntNumber2:public TIntNumber
{
	string binary;
public:
	TIntNumber2();
	void Convert();
	void print();
};

class TIntNumber8 :public TIntNumber
{
	string octal;
public:
	TIntNumber8();
	void Convert();
	void print();
};

class TIntNumber16 :public TIntNumber
{
	string hex;
public:
	TIntNumber16();
	void Convert();
	void print();
};
