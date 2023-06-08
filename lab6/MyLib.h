#pragma once
#include<Windows.h>
#include<string>
#include<iostream>

template<typename T>
class Array {
	T* data;
	int size;
public:
	class Iterator {
		T* ptr;
	public:
		Iterator(T* start);
		T& GetValue();
		void Next();
		void Previous();
		void SetValue(const T& value);
		bool IsEnd(Iterator end);
	};

	Array(int s);
	~Array();

	int GetSize();
	int Find(const T& value);
	bool IsEmpty();
	void Insert(int pos, const T& value);
	void PrintArray();

	Iterator Begin();
	Iterator End();
};

template <typename T>
void processArray(int size);
