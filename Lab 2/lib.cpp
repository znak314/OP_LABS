#include"lib.h"

// Уведення та перевірка валідності ім'я файлу
void EnterFileName(string& str)
{
	cout << "\t\t\tУведіть ім'я файлу, з яким хочете працювати:(без розширення)\n";
	char c[255]; //максимальний розмір назви файлу у Windows
	int InvalidInput;
	do {
		InvalidInput = 0;
		cout << "Ім'я файлу ---> ";
		cin.getline(c, 255);
		if (!cin.good())
		{
			cin.clear();
			InvalidInput = 1;
			cin.ignore(255, '\n');
			cout << "Упс! Схоже при введенні назви сталось помилка! Можливо ви ввели забагато символів, спробуйте ще раз\n";
		}
		else {
			str = c;
			str += ".bin";
		}
	} while (InvalidInput);
}

// перевірка існування файлу
bool is_file_exist(string NameOfFile)
{
	fstream file(NameOfFile, ios::binary | ios::in); // відкриваємо тільки для читання

	if (file.is_open())
	{
		file.close();
		return 1;
	}
	else {
		return 0;
	}
}

// перевірка чи існуючий файл не порожній:
bool is_file_empty(string NameOfFile)
{
	fstream file(NameOfFile, ios::binary | ios::in);
	long file_size;
	file.seekg(0, ios::end);
	file_size = file.tellg();
	file.close();
	if (file_size == 0)
	{
		cout << "Упс! Схоже  файл " << NameOfFile << " є порожнім, будь ласка доповніть його\n" << endl;
		return 1;
	}
	return 0;

}

// створення бінарного файлу
void create_file(string NameOfFile)
{
	ofstream file(NameOfFile, ios::binary);
	if (file.is_open())
	{
		cout << "Файл " << NameOfFile << " успішно створено!\n";
		file.close();
	}
	else {
		cout << "Упс! Схоже при створенні файлу сталась помилка\n";
	}
}

// заповнення (доповнення)
void append_file(string NameOfFile)
{
	ofstream file(NameOfFile, ios::binary | ios::app);
	int exit;
	int number = 1;
	do
	{
		cout << "----------------------Доповнення № " << number++ << "----------------------\n";

		Car NewCar;

		// Уведення марки
		cout << "Уведіть марку автомобіля (не більше 30 символів): ";
		int inv;
		do {
			inv = 0;
			cin.getline(NewCar.brand, 31, '\n');
			if (!cin.good()) {
				cin.clear();
				//cin.ignore(31,'\n');
				inv = 1;
				cout << "Марка автомобіля занадто довга, будь ласка, уведіть марку до 30 символів\n";
				while (getchar() != '\n');
			}
		} while (inv);

		// уведення дати випуску
		int flag;
		do {
			flag = 0;
			cout << "\n\t      Уведіть дату випуску автомобіля:\n";
			enter_date(&NewCar.ReleaseDate);
			cout << "\n\tУведіть дату надходження в продаж автомобіля:\n";
			enter_date(&NewCar.SaleDate);

			if (NewCar.ReleaseDate.year > NewCar.SaleDate.year)
			{
				flag = 1;
				cout << "Дата надходження у продаж не може бути давнішою за дату випуску автомобіля. Спробуйте ще раз\n";
			}
			if (NewCar.ReleaseDate.year == NewCar.SaleDate.year)
			{
				if (GetDayNumber(NewCar.ReleaseDate.day, NewCar.ReleaseDate.month, is_leap_year(NewCar.ReleaseDate.year)) > GetDayNumber(NewCar.SaleDate.day, NewCar.SaleDate.month, is_leap_year(NewCar.SaleDate.year)))
				{
					flag = 1;
					cout << "\n !!!Дата надходження у продаж не може бути давнішою за дату випуску автомобіля. Спробуйте ще раз!!!\n";
				}
			}

		} while (flag); // поки дати надходження старіша ніж дата випуску


		//тепер проводимо запис у файл
		if (file.is_open())
		{
			file.write(reinterpret_cast<char*>(&NewCar), sizeof(NewCar));
		}
		else {
			cout << "Упс! Схоже при відкритті файлу сталась помилка\n";
		}

		cout << "\t\t\tБажаєте додати ще автомобіль? Якщо ні - натисніть esc\n";
		exit = _getch();
	} while (exit != 27);


	file.close();

}


// Уведення і валідація дати
void enter_date(date* newDate)
{
	cout << "\t    (Дати записуються у форматі DD:MM:YYYY)\n\n";
	int not_exist;
	do {
		not_exist = 0;
		int inv;
		// Введення дня
		do
		{
			cout << "---> Уведіть день (число): ";
			inv = 0;
			cin >> newDate->day;
			if (!cin.good())
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число не більше 31 і не менше 1, спробуйте ще раз\n";
			}
			else if (newDate->day > 31 || newDate->day <= 0)
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число з проміжку [1;31]\n";
			}
			else if (cin.get() != '\n') {
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число з проміжку [1;31]\n";
			}
		} while (inv);
		//Введення місяця
		do
		{
			cout << "---> Уведіть місяць (число): ";
			inv = 0;
			cin >> newDate->month;
			if (!cin.good())
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число не більше 12 і не менше 1, спробуйте ще раз\n";
			}
			else if (newDate->month > 12 || newDate->month <= 0)
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число з проміжку [1;12]\n";
			}
			else if (cin.get() != '\n') {
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число з проміжку [1;12]\n";
			}
		} while (inv);

		//Введення року
		do
		{
			cout << "---> Уведіть  рік: ";
			inv = 0;
			cin >> newDate->year;
			if (!cin.good())
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число з проміжку [1900; 2023]\n";
			}
			else if (newDate->year > 2023 || newDate->year < 1900)
			{
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число з проміжку [1900; 2023]\n";
			}
			else if (cin.get() != '\n') {
				inv = 1;
				cin.clear();
				while (getchar() != '\n');
				cout << "Це повинно бути число з проміжку [1900; 2023]\n";
			}
		} while (inv);


		// Перевірка існування введеної дати
		if (((newDate->month == 4) || (newDate->month == 6) || (newDate->month == 9) || (newDate->month == 10)) && (newDate->day) > 30)
		{
			not_exist = 1;
			cout << "\n\tТакої дати не існує. У цьому місяці тільки 30 днів, спробуйте ще раз\n";
		}
		else if (newDate->month == 2 && is_leap_year(newDate->year) && (newDate->day > 29)){
			cout << "\n\tТакої дати не існує. У цьому було місяці тільки 29 днів, спробуйте ще раз\n";
			not_exist = 1;
		}
		else if (newDate->month == 2 && !is_leap_year(newDate->year) && newDate->day > 28 )
		{
			not_exist = 1;
			cout << "\n\tТакої дати не існує. У цьому місяці тільки 28 днів, спробуйте ще раз\n";
		}
	} while (not_exist);
}

// Виведення вмісту
void PrintFile(string NameOfFile)
{
	ifstream file(NameOfFile, ios::binary);
	Car temp;
	if (file.is_open())
	{
		PrintSlashes();
		cout << '\t' << '|' << setw(28) << "Марка автомобіля" << setw(11) << '|' << setw(20) << "Дата випуску " << setw(5) << '|' << setw(21) << "Дата надходження" << setw(5) << '|' << endl;
		while (!file.eof())
		{
			PrintSlashes();
			file.read(reinterpret_cast<char*>(&temp), sizeof(Car));
			if (file.eof()) break;

			// 40 - поле для марки, 64 - 40 - дата1, 90 - 64 - дата 2
			int size = strlen(temp.brand); // дізнаємося довжину, щоб відцентрувати
			int buf = (40 - size) / 2;
			cout << '\t' << '|' << setw(buf + (size % 2 == 0 ? size : ++size)  - 1) << temp.brand << setw(buf) << '|'; // виведення поля марки
			cout << setw(10) << temp.ReleaseDate.day << ':' << temp.ReleaseDate.month << ':' << temp.ReleaseDate.year << setw(8 - (temp.ReleaseDate.month > 9 ? 1 : 0)) << '|'; // дата має 10 символів: DD:MM:YYYY
			cout << setw(10) << temp.SaleDate.day << ':' << temp.SaleDate.month << ':' << temp.SaleDate.year << setw(9 - (temp.SaleDate.month > 9 ? 1 : 0)) << '|' << endl;
		}
		file.close();
	}
	else {
		cout << "Упс! Схоже при відкритті файлу сталась помилка\n";
	}
}

//для таблички
void PrintSlashes()
{
	cout << '\t';
	for (int i = 0; i < 91; i++)
	{
		if (i == 0 || i == 39 || i == 64 || i == 90)
		{
			cout << '+';
		}
		else {
			cout << '-';
		}
	}
	cout << endl;
}

// перевірка року на високосність
bool is_leap_year(int year)
{
	return  (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)); // перевірка на високосність
}

//  функція для того, щоб дізнатися який це день року по порядку
int GetDayNumber(int day, int month, bool is_leap)
{
	int NumberOfDay = 0;

	switch (month)
	{
		case 2:
		{
			NumberOfDay += 31;
			break;
		}
		case 3:
		{
			NumberOfDay += 59;
			break;
		}
		case 4:
		{
			NumberOfDay += 90;
			break;
		}
		case 5:
		{
			NumberOfDay += 120;
			break;
		}
		case 6:
		{
			NumberOfDay += 151;
			break;
		}
		case 7:
		{
			NumberOfDay += 181;
			break;
		}
		case 8:
		{
			NumberOfDay += 212;
			break;
		}
		case 9:
		{
			NumberOfDay += 243;
			break;
		}
		case 10:
		{
			NumberOfDay += 273;
			break;
		}
		case 11:
		{
			NumberOfDay += 304;
			break;
		}
		case 12:
		{
			NumberOfDay += 334;
			break;
		}
		default:
		{
			break;
		}
		if (is_leap && month > 2) // урахування високосності
		{
			NumberOfDay++;
		}

		return NumberOfDay + day;
	}
}

// функція для виведення нових автомобілів
void GetNewCars(string FileName)
{
	ifstream file(FileName, ios::binary);
	Car NewCar;

	if (file.is_open())
	{
		int count = 0; // змінна для збереження кількості нових  автомобілів
		while (!file.eof())
		{
			file.read(reinterpret_cast<char*>(&NewCar), sizeof(Car));
			if (file.eof()) break;
			
			// перевіряємо чи різниця менше 2 місяців
			int flag = 0;
			// 1 - й випадок: різні роки напр грудень 2011 і січень 2012
			if ((NewCar.SaleDate.year - NewCar.ReleaseDate.year) == 1)
			{
				if ((NewCar.ReleaseDate.month - NewCar.SaleDate.month) > 10)
				{
					flag = 1;
				}
				else if ((NewCar.ReleaseDate.month - NewCar.SaleDate.month) == 10)
				{
					if (NewCar.SaleDate.day <= NewCar.ReleaseDate.day)
						flag = 1;
				}
			}
			else if (NewCar.SaleDate.year == NewCar.ReleaseDate.year) // якщо один і той же рік
			{
				if ((NewCar.ReleaseDate.month - NewCar.SaleDate.month) < 2) // різниця місяців менше 2
					flag = 1;
				else if (((NewCar.ReleaseDate.month - NewCar.SaleDate.month) == 2) && (NewCar.SaleDate.day <= NewCar.ReleaseDate.day))// якщо різниця 2 місяці, то дививмося по днях
					flag = 1;
			}

			// якщо помічено нову машину, виводимо її 
			if (flag)
			{
				if (count == 0) // якщо це перша машина, то перед цим виводио опис
				{
					PrintSlashes();
					cout << '\t' << '|' << setw(28) << "Марка автомобіля" << setw(11) << '|' << setw(20) << "Дата випуску " << setw(5) << '|' << setw(21) << "Дата надходження" << setw(5) << '|' << endl;
				}
				count++;
				PrintSlashes();
				int size = strlen(NewCar.brand); // дізнаємося довжину, щоб відцентрувати
				int buf = (40 - size) / 2;
				cout << '\t' << '|' << setw(buf + (size % 2 == 0 ? size : ++size) - 1) << NewCar.brand << setw(buf) << '|'; // виведення поля марки
				cout << setw(10) << NewCar.ReleaseDate.day << ':' << NewCar.ReleaseDate.month << ':' << NewCar.ReleaseDate.year << setw(8 - (NewCar.ReleaseDate.month > 9 ? 1 : 0)) << '|'; // дата має 10 символів: DD:MM:YYYY
				cout << setw(10) << NewCar.SaleDate.day << ':' << NewCar.SaleDate.month << ':' << NewCar.SaleDate.year << setw(9 - (NewCar.SaleDate.month > 9 ? 1 : 0)) << '|' << endl;
			}
		}
		if (count == 0)
		{
			cout << "\n\t\t\t     На жаль, зараз немає доступних новинок, спробуйте будь ласка пізніше!\n";
		}
		else {
			PrintSlashes();
		}

		file.close();
	}
	else {
		cout << "На жаль, при відкритті файлу сталась помилка\n";
	}
}

// функція для введення року
int EnterYear()
{
	int inv;
	int year;
	do
	{
		cout << "---> Уведіть  рік: ";
		inv = 0;
		cin >> year;
		if (!cin.good())
		{
			inv = 1;
			cin.clear();
			while (getchar() != '\n');
			cout << "Це повинно бути число з проміжку [1900; 2023]\n";
		}
		else if (year > 2023 || year < 1900)
		{
			inv = 1;
			cin.clear();
			while (getchar() != '\n');
			cout << "Це повинно бути число з проміжку [1900; 2023]\n";
		}
		else if (cin.get() != '\n') {
			inv = 1;
			cin.clear();
			while (getchar() != '\n');
			cout << "Це повинно бути число з проміжку [1900; 2023]\n";
		}
	} while (inv);
	return year;
}

// функція для виведення машин вироблених не раніше вказаного року 
void PrintCarsYoungerThanYear(string NameOfFile, int year)
{
	ifstream file(NameOfFile, ios::binary);
	Car NewCar;
	if (file.is_open())
	{
		int count = 0; // змінна для збереження кількості нових  автомобілів
		while (!file.eof())
		{
			file.read(reinterpret_cast<char*>(&NewCar), sizeof(Car));
			if (file.eof()) break;

			if (NewCar.ReleaseDate.year >= year)
			{
				if (count == 0) // якщо це перша машина, то перед цим виводио опис
				{
					cout << "\n\t\t\t\t\tАвтомобілі, випущені не раніше " << year << " року:\n";
					PrintSlashes();
					cout << '\t' << '|' << setw(28) << "Марка автомобіля" << setw(11) << '|' << setw(20) << "Дата випуску " << setw(5) << '|' << setw(21) << "Дата надходження" << setw(5) << '|' << endl;
				}
				count++;
				PrintSlashes();
				int size = strlen(NewCar.brand); // дізнаємося довжину, щоб відцентрувати
				int buf = (40 - size) / 2;
				cout << '\t' << '|' << setw(buf + (size % 2 == 0 ? size : ++size) - 1) << NewCar.brand << setw(buf) << '|'; // виведення поля марки
				cout << setw(10) << NewCar.ReleaseDate.day << ':' << NewCar.ReleaseDate.month << ':' << NewCar.ReleaseDate.year << setw(8 - (NewCar.ReleaseDate.month > 9 ? 1 : 0)) << '|'; // дата має 10 символів: DD:MM:YYYY
				cout << setw(10) << NewCar.SaleDate.day << ':' << NewCar.SaleDate.month << ':' << NewCar.SaleDate.year << setw(9 - (NewCar.SaleDate.month > 9 ? 1 : 0)) << '|' << endl;
			}
		}
		if (count == 0)
		{
			cout << " \n\t\t\tНа жаль, поки що немає доступних автомобілів, випущених не раніше " << year << endl;
			cout << "\t\t\t\t\t\tБудь ласка, спробуйте пізніше\n";
		}
		else {
			PrintSlashes();
		}
		file.close();
	}
	else {
		cout << "Упс! Схоже при відкритті файлу сталась помилка\n";
	}
}
