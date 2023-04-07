#include"func.h"
int SizeArray;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int SizeObjArray, index;
	cout << "\tЗавдання:  " << "Розробити клас числовий масив вказаної розмірності.\nСтворити масив об'єктів даного класу. Визначити масив з найменшим максимальним елементом" << endl;
	cout << "\nУведіть розмірність масиву об'єктів\n";
	SizeObjArray = EnterSize();

	cout << "\nУведіть розмірність числового масиву\n";
	SizeArray = EnterSize();

	NumberArray* ObjArray = new NumberArray[SizeObjArray];
	cout << "\n\t\tЗгенерований масив об'єктів класу:\n";
	FillAll(ObjArray, SizeObjArray);
	PrintAll(ObjArray, SizeObjArray);
	index = FindSmallestMax(ObjArray, SizeObjArray);

	cout << "Масив з найменшим максимальним елементом:\n";
	ObjArray[index].printArray();
	cout << "Найменший максимальний елемент - " << ObjArray[index].getMax() << endl;

	return 0;
}
