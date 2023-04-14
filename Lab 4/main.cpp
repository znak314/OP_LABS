#include"header.h"


/* Визначити клас "Трикутник", членами якого є сторони трикутника в просторі. Реалізувати для нього декілька
* конструкторів, геттери, методи обчислення площі трикутник. Перевантажити оператори:
*  "++" // "--" - для інкрементування/декрементування довжин сторін трикутника відповідно,
* "+=" / "-=" - для збільшення / зменшення довжин сторін трикутника на вказану величину.
* Створити три трикутника (T1, T2, T3), використовуючи різні конструктори. Інкрементувати 
* довжини сторін трикутника T1, а довжини трикутника T2 декрементувати. Збільшити довжини 
* сторін трикутника T3 на вказану величину. Серед трикутників T1, T2, T3 визначити трикутник, 
* що має найбільшу площу.
*/

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\nТрикутник T1 - одиничний\n";
	cout << "Трикутник T2 - задає користувач\n";
	cout << "Трикутника T3 - генерується випадково" << endl << endl;

	float T2a, T2b, T2c;
	bool flag;
	// введення сторін
	do {
		T2a = EnterSide();
		T2b = EnterSide();
		T2c = EnterSide();
		flag = !IsTriangleExist(T2a, T2b, T2c);
		if (flag)
			cout << "\nТакого трикутника не існує, спробуйте ще раз:\n";
	} while (flag);
		

	Triangle T1;                 // рівносторонній
	Triangle T2(T2a, T2b, T2c);  // заповнений параметрами
	Triangle T3('r');            // випадково заповнений

	// виведення створених трикутників
	
	printHeader();
	cout << "\t\t| T1";
	T1.printSides();
	printLine();
	cout << "\t\t| T2";
	T2.printSides();
	printLine();
	cout << "\t\t| T3";
	T3.printSides();
	printLine();
	
	
	float minValue = T3.GetMin();
	float Number = EnterNumber(minValue);

	cout << "\n Сторони трикутника T1 інкрементуємо\n";
	cout << " Сторони трикутника T2 декрементуємо\n";
	cout << " Сторони трикутника T3 збільшуємо на " << Number << endl << endl;

	T1++; // можна і ++T1
	T2--; // можна і --T2
	T3 += Number; 
	
	printHeader();
	if (IsTriangleExist(T1))
	{
		cout << "\t\t| T1";
		T1.printSides();
		printLine();
	}
	if (IsTriangleExist(T2))
	{
		cout << "\t\t| T2";
		T2.printSides();
		printLine();
	}
	if (IsTriangleExist(T3))
	{
		cout << "\t\t| T3";
		T3.printSides();
		printLine();
	}

	// перевірка чи після збільшення сторін це все ще трикутники
	float S1, S2, S3;
	if (IsTriangleExist(T1))
		S1 = T1.GetSquare();
	else S1 = 0;
	if (IsTriangleExist(T2))
		S2 = T2.GetSquare();
	else S2 = 0;
	if (IsTriangleExist(T3))
		S3 = T3.GetSquare();
	else S3 = 0;


	int MaxTriangle = FindMax(S1, S2, S3);
	switch (MaxTriangle)
	{
	case 1:
		cout << "Найбільша площа у трикутника T1: " << S1 << endl;
		printLine();
		cout << "\t\t| T1";
		T1.printSides();
		printLine();
		break;
	case 2:
		cout << "Найбільша площа у трикутника T2: " << S2 << endl;
		printLine();
		cout << "\t\t| T2";
		T2.printSides();
		printLine();
		break;
	case 3:
		cout << "Найбільша площа у трикутника T3: " << S3 << endl;
		printLine();
		cout << "\t\t| T3";
		T3.printSides();
		printLine();
		break;
	}

	return 0;
}
