#include"header.h"

// Геттери для сторін
float Triangle::GetA()
{
	return a;
}
float Triangle::GetB()
{
	return b;
}
float Triangle::GetC()
{
	return c;
}


// конструктори
Triangle::Triangle(char r) // рандомний
{
	float A, B, C;
	int max = 10;
	do
	{
		A = rand() % max;
		B = rand() % max;
		C = rand() % max;
	}
	while (!IsTriangleExist(A,B,C));
	a = A;
	b = B;
	c = C;
}

// ініціалізує вказаними значеннями
Triangle::Triangle(float A, float B, float C)
{
	a = A;
	b = B;
	c = C;
}

//знаходження площі через формулу Герона
float Triangle::GetSquare()
{
	float p = (a + b + c) / 2;
	float Square = sqrt(p * (p - a) * (p - b) * (p - c));
	return Square;
}


// виведення сторін трикутник
void Triangle::printSides()
{
	cout << " | " << setw(6) <<  a <<  setw(3) << '|' << setw(7) <<  b << setw(3) << '|' << setw(7) << c << setw(3) << '|' << endl;
}

//повертає значення найменшої сторони
float Triangle::GetMin()
{
	if (a < b && a < c)
	{
		return a;
	}
	else if ( b < c)
	{
		return b;
	}
	return c;
}

// Введення однієї сторони
float  EnterSide()
{
		float side, inv;

		cout << "Введіть довжину  сторони: ";
		do {
			inv = 0;

			cin >> side;
			if (!cin.good())
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');

				cout << "Будь ласка, введіть число: ";
			}
			else if (getchar() != '\n')
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Будь ласка, введіть число: ";
			}
		} while (inv);
		return side;
}

//перегрузка ++ (постфікс)
const Triangle Triangle::operator++(int d)
{
	Triangle tmp = *this;
	a += 1;
	b += 1;
	c += 1;
	return tmp;
}
//префіксна
Triangle Triangle::operator++(void)
{
	a += 1;
	b += 1;
	c += 1;
	return *this;
}

//перегрузка -- (постфікс)
Triangle Triangle::operator--(int d)
{
	Triangle tmp = *this;
	a -= 1;
	b -= 1;
	c -= 1;
	return tmp;
}
//префіксна
Triangle Triangle::operator--(void)
{
	a -= 1;
	b -= 1;
	c -= 1;
	return *this;
}

//перегрузка += 
Triangle Triangle::operator+=(float d)
{
	a += d;
	b += d;
	c += d;
	return *this;
}

//перегрузка -= 
Triangle Triangle::operator-=(float d)
{
	a -= d;
	b -= d;
	c -= d;
	return *this;
}


// функція для перевірки існування трикутника:
bool IsTriangleExist(float a, float b, float c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 0;
	if ((a + b <= c) || (a + c <= b) || (b + c <= a))
		return 0;
	return 1;
}

// виведення лінії
void printLine()
{
	cout << "\t\t";
	for (int i = 0; i < 36; i++)
	{
		if (i == 0 || i == 5 || i == 15 || i == 25 || i == 35)
		{
			cout << '+';
		}
		else {
			cout << '-';
		}
	}
	cout << endl;
}

// виведення заголовку
void printHeader()
{
	printLine();
	cout << "\t\t|name|  side A |  side B |  side C |" << endl;
	printLine();
}

// введення числа, на яке збільшуємо
float  EnterNumber(float minimum)
{
	float side, inv;

	cout << "На скільки збільшити сторони трикутника T3 ? "; 
	do {
		inv = 0;

		cin >> side;
		if (!cin.good())
		{
			inv = 1;
			cin.clear();
			while (getchar() != '\n');

			cout << "Будь ласка, введіть число: ";
		}
		else if (getchar() != '\n')
		{
			inv = 1;
			cin.clear();
			while (getchar() != '\n');
			cout << "Будь ласка, введіть число: ";
		}
		else if (side < 0 && -side >= minimum)
		{
			inv = 1;
			cin.clear();
			cout << "Неможливо зменшити сторони трикутника на це число, адже тоді отримаємо від'ємні сторони, спробуйте ще раз\n";
		}
	} while (inv);
	return side;
}

// знаходження найменшого з трьох чисел
int FindMax(float a, float b, float c)
{
	if (a > b && a > c)
		return 1;
	if (a < c && b < c)
		return 3;
	return 2;
}

// функція для перевірки існування трикутника:
bool IsTriangleExist(Triangle T)
{
	if (T.GetA() <= 0 || T.GetB() <= 0 || T.GetC() <= 0)
		return 0;
	if ((T.GetA() + T.GetB() <= T.GetC()) || (T.GetA() + T.GetC() <= T.GetB()) || (T.GetB() + T.GetC() <= T.GetA()))
		return 0;
	return 1;
}
