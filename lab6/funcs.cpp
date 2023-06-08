#include"funcs.h"

using namespace std;

void DataTypesMenu()
{
	cout << "\tТип даних\n";
	cout << "1. bool\n";
	cout << "2. int\n";
	cout << "3. float\n";
	cout << "4. double\n";
	cout << "5. char\n\n";
}

void OperationMenu()
{
	cout << "\n\n\t\tМеню\n";
	cout << "1. Визначити розміру масиву\n";
	cout << "2. Знайти елемент із заданим значенням\n";
	cout << "3. Перевірка масиву на пустоту\n";
	cout << "4. Включення нового елемента у позицію із заданим номером\n";
	cout << "5. Вивести вміст масиву\n";
	cout << "---------------------------------------------------------\n\n";
}


int getInputNumber() {
    int number;
    bool isValidInput = false;

    while (!isValidInput) {
        std::cout << "Уведіть розмірність (від 0 до 20): ";
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некоректне введення. Будь ласка, спробуйте ще раз.\n";
        }
        else if (number < 0 || number > 20) {
            std::cout << "Число повинно бути від 0 до 20. Будь ласка, спробуйте ще раз.\n";
        }
        else {
            isValidInput = true;
        }
    }

    return number;
}
