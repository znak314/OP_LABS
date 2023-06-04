#include"MyForm.h"
//#include"Classes.h"
//#include"funcs.h"


void Lab7::MyForm::IsEmptyInterface()
{
	bool excep_flag = 0; // позначає, що треба ексепшн кинути

	System::String^ textFromTextBox = date1->Text; // отримує дані у типі String
	std::string d1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = date2->Text; // отримує дані у типі String
	std::string d2 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	// спочатку перевіряємо чи ці штучки не пусті
	if (isStringEmpty(d1))
	{
		date1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (isStringEmpty(d2))
	{
		date2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}
	if (excep_flag)
		throw MyException("Деякі комірки є пустими. Будь ласка, введіть значення");
	return System::Void();
}

void Lab7::MyForm::SetWhiteBackColor()
{
	date1->BackColor = System::Drawing::Color::White;
	date2->BackColor = System::Drawing::Color::White;
}

void Lab7::MyForm::IsValidFormat()
{
	SetWhiteBackColor();
	int excep_flag = 0;
	System::String^ textFromTextBox = date1->Text; // отримує дані у типі String
	std::string d1 = msclr::interop::marshal_as<std::string>(textFromTextBox);
	
	textFromTextBox = date2->Text;
	std::string d2 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	// формат 2 числа - 2 числа - 4 числа
	if (!isDateFormatValid(d1))
	{
		date1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}
	if (!isDateFormatValid(d2))
	{
		date2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}
	if (excep_flag)
		throw MyException("Невірний формат дати");
	return System::Void();
}

void Lab7::MyForm::IsDataExist()
{
	SetWhiteBackColor();
	int excep_flag = 0;
	System::String^ textFromTextBox = date1->Text; // отримує дані у типі String
	std::string d1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = date2->Text;
	std::string d2 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	if (!is_Date_Exist(d1))
	{
		date1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}
	if (!is_Date_Exist(d2))
	{
		date2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}
	if (excep_flag)
		throw MyException("Такої дати не існує");
	return System::Void();
}


void Lab7::MyForm::FillDate1(Date& A)
{
	System::String^ textFromTextBox = date1->Text; // отримує дані у типі String
	std::string date = msclr::interop::marshal_as<std::string>(textFromTextBox);

	std::istringstream iss(date);
	std::string day_str, month_str, year_str;

	std::getline(iss, day_str, '-');
	std::getline(iss, month_str, '-');
	std::getline(iss, year_str);

	int day = std::stoi(day_str);
	int month = std::stoi(month_str);
	int year = std::stoi(year_str);

	A.setDay(day);
	A.setMonth(month);
	A.setYear(year);

	return System::Void();
}

void Lab7::MyForm::FillDate2(Date& A)
{
	System::String^ textFromTextBox = date2->Text; // отримує дані у типі String
	std::string date = msclr::interop::marshal_as<std::string>(textFromTextBox);

	std::istringstream iss(date);
	std::string day_str, month_str, year_str;

	std::getline(iss, day_str, '-');
	std::getline(iss, month_str, '-');
	std::getline(iss, year_str);

	int day = std::stoi(day_str);
	int month = std::stoi(month_str);
	int year = std::stoi(year_str);

	A.setDay(day);
	A.setMonth(month);
	A.setYear(year);

	return System::Void();
	throw gcnew System::NotImplementedException();
}



System::Void Lab7::MyForm::find_new_date_Click(System::Object^ sender, System::EventArgs^ e)
{
	SetWhiteBackColor();

	try {
		IsEmptyInterface(); // перевірка на непорожність
		IsValidFormat(); 
		IsDataExist();

		Date d1, d2;
		std::string resultMess;
		FillDate1(d1);
		FillDate2(d2);

		int opt = Compare(d1, d2);
		switch (opt)
		{
			case 0:
			{
				resultMess = "Дати однакові";
				break;
			}
			case 1:  // д1 новіша
			{
				resultMess = "Дата 1 новіша";
				break;
			}
			case 2:  // д2 новіша
			{
				resultMess = "Дата 2 новіша";
				break;
			}
		}

		String^ text = gcnew String(resultMess.c_str());
		result->Text = text;
	}
	catch (const MyException& e)
	{
		System::String^ errorMessage = gcnew System::String(e.what());
		MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	return System::Void();
}
