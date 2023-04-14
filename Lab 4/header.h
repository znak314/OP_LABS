
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<math.h>
#include<iomanip>

using namespace std;


class Triangle
{
	float a, b, c;
public:
	float GetA();
	float GetB();
	float GetC();
	float GetMin();

	// знаходить площу через формулу Герона
	float GetSquare();

	// виводить сторони
	void printSides();


	// конструктори
	Triangle(char r);
	Triangle(float A, float B, float C);
	Triangle() { a = b = c = 1; }

	// перегрузка ++ (постфіксного і префіксного)
	Triangle operator++(void);
	const Triangle operator++(int d);

	// перегрузка -- (постфіксного і префіксного)
	Triangle operator--(void);
	Triangle operator--(int d);

	// перегрузка += і -=
	Triangle operator+=(float d);
	Triangle operator-=(float d);
};
float  EnterSide();
bool IsTriangleExist(float a, float b, float c);
void printLine();
void printHeader();
float  EnterNumber(float minimum);
int FindMax(float a, float b, float c);
bool IsTriangleExist(Triangle T);
