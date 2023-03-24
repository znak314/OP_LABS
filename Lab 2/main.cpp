#include"lib.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string FileName; // строка для збереження назви файлу
	EnterFileName(FileName);

	if (is_file_exist(FileName))
	{
		if (is_file_empty(FileName))
		{
			//просимо доповнити у обов'язковому порядку
			append_file(FileName);
		}
		else {
			cout << "Бажаєте доповнити файл? (натисніть esc для доповнення):\n"; //запитуємо чи не хоче користувач доповнити
			if (_getch() == 27)
			{
				append_file(FileName);
			}
		}
	}
	else {
		create_file(FileName);
		append_file(FileName);
	}
	cout << "\t\t\t\t\t\tВміст файлу " << FileName << ":\n";
	PrintFile(FileName);
	cout << "\n\t\t\t\t\t\t      Наші новинки:\n";
	GetNewCars(FileName);

	cout << "\n\tМожливо, вас цікавлять тільки автомобілі випущені не раніше якогось року? (якщо так - натисніть esc)\n";
	if (_getch() == 27)
	{
		system("cls");
		PrintFile(FileName);
		int year;
		year = EnterYear();
		PrintCarsYoungerThanYear(FileName, year);
	}
	cout << "\n\t\t\t\t\tДякуємо, що скористалися програмою! \n";
	return 0;
}
