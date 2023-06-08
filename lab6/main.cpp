#include"Mylib.h"
#include"funcs.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int option, size;
	DataTypesMenu();
	std::cout << "Оберіть тип даних масиву: ";
	std::cin >> option;
	size = getInputNumber(); 
	switch (option)
	{
		case 1: // bool
		{
			processArray<bool>(size);
			break;
		}
		case 2: // int
		{
			processArray<int>(size);
			break;
		}
		case 3: // float
		{
			processArray<float>(size);
			break;
		}
		case 4: // double
		{
			processArray<double>(size);
			break;
		}
		case 5: // char
		{
			processArray<char>(size);
			break;
		}
		default: // некоректне введення
		{
			std::cout << "Некоректний тип даних\n";
			break;
			return 0;
		}
	}

	
	return 0;
}
