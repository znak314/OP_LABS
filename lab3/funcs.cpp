#include"func.h"

// конструтор за замовчуванням
NumberArray::NumberArray()
{
	size = SizeArray;
	arr = new int[size];
}

// виведення вмісту об'єкту класа
void NumberArray::printArray()
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(2) <<  arr[i] << '\t';
	}
	cout << endl;
}

//деструктор
NumberArray::~NumberArray()
{
	delete[] arr;
}

// заповнення об'єкту  випадковими числами
void NumberArray::FillArray()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

// знаходження мінімального елемента у об'єкті
int NumberArray::getMax()
{
	int local_max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (local_max < arr[i])
		{
			local_max = arr[i];
		}
	}
	return local_max;
}

// заповнення масиву об'єктів
void FillAll(NumberArray* Array, int sizeObj)
{
	for (int i = 0; i < sizeObj; i++)
	{
		Array[i].FillArray();
	}
}

// виведення масиву об'єктів
void PrintAll(NumberArray* Array, int sizeObj)
{
	for (int i = 0; i < sizeObj; i++)
	{
		Array[i].printArray();
	}
}

//знаходження найменшого макс елемента та індексу його масиву
int FindSmallestMax(NumberArray* Array, int sizeObj)
{
	int smallest_min = Array[0].getMax();
	int index = 0;

	for (int i = 1; i < sizeObj; i++)
	{
		if (smallest_min > Array[i].getMax())
		{
			smallest_min = Array[i].getMax();
			index = i;
		}
	}
	return  index;
}
// введення розміру масивів
int EnterSize()
{
	int size, inv;

	cout << "Введіть число з діапазону [1;20]: ";
	do {
		inv = 0;

		cin >> size;
		if (!cin.good())
		{
			inv = 1;
			cin.clear();
			while (getchar() != '\n');

			cout << "Будь ласка, введіть число з діапазону [1;20]: ";
		}
		else if (getchar() != '\n')
		{
			inv = 1;
			cin.clear();
			while (getchar() != '\n');
			cout << "Будь ласка, введіть число з діапазону [1;20]: ";
		}
		else if (size < 1 || size > 20)
		{
			inv = 1;
			cout << "Будь ласка, введіть число з діапазону [1;20]: ";
		}
	} while (inv);
	return size;
}
