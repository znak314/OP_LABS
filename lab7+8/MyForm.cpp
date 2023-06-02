
#include"MyForm.h"

void Lab7::MyForm::IsEmptyInterface()
{
	bool excep_flag = 0; // позначає, що треба ексепшн кинути

	System::String^ textFromTextBox = day1->Text; // отримує дані у типі String
	std::string d1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = month1->Text;
	std::string m1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = year1->Text;
	std::string y1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = day2->Text;
	std::string d2 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = month2->Text;
	std::string m2 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = year2->Text;
	std::string y2 = msclr::interop::marshal_as<std::string>(textFromTextBox);


	// спочатку перевіряємо чи ці штучки не пусті
	if (isStringEmpty(d1))
	{
		day1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (isStringEmpty(m1))
	{
		month1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (isStringEmpty(y1))
	{
		year1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (isStringEmpty(d2))
	{
		day2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (isStringEmpty(m2))
	{
		month2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (isStringEmpty(y2))
	{
		year2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (excep_flag)
		throw MyException("Одна з комірок є пустою. Будь ласка, введіть значення");
	return System::Void();
}

void Lab7::MyForm::SetWhiteBackColor()
{
	day1->BackColor = System::Drawing::Color::White;
	month1->BackColor = System::Drawing::Color::White;
	year1->BackColor = System::Drawing::Color::White;
	day2->BackColor = System::Drawing::Color::White;
	month2->BackColor = System::Drawing::Color::White;
	year2->BackColor = System::Drawing::Color::White;
	return;
}

void Lab7::MyForm::IsCellIsNumber()
{
	bool excep_flag = 0; // позначає, що треба ексепшн кинути

	System::String^ textFromTextBox = day1->Text; // отримує дані у типі String
	std::string d1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = month1->Text;
	std::string m1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = year1->Text;
	std::string y1 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = day2->Text;
	std::string d2 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = month2->Text;
	std::string m2 = msclr::interop::marshal_as<std::string>(textFromTextBox);

	textFromTextBox = year2->Text;
	std::string y2 = msclr::interop::marshal_as<std::string>(textFromTextBox);


	if (!is_number(d1))
	{
		day1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (!is_number(m1))
	{
		month1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (!is_number(y1))
	{
		year1->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (!is_number(d2))
	{
		day2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (!is_number(m2))
	{
		month2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}

	if (!is_number(y2))
	{
		year2->BackColor = System::Drawing::Color::Red;
		excep_flag = 1;
	}
	if (excep_flag)
		throw MyException("Дані повинні бути заповнені цілими числами з діапазону [1-9999] ");

	return;
}

void Lab7::MyForm::IsInterfaceDateExist()
{
	int d, m, y;
	bool excep_flag = 0;
	std::string mess = " ";

	System::String^ textFromTextBox = day1->Text;
	std::string strText = msclr::interop::marshal_as<std::string>(textFromTextBox);
	d= std::stoi(strText);

	textFromTextBox = month1->Text;
	strText = msclr::interop::marshal_as<std::string>(textFromTextBox);
	m  = std::stoi(strText);

	textFromTextBox = year1->Text;
	strText = msclr::interop::marshal_as<std::string>(textFromTextBox);
	y = std::stoi(strText);

	if (!is_Date_Exist(d, m, y))
	{
		excep_flag = 1;
		mess = "Дати 1 ";
	}

	textFromTextBox = day2->Text;
    strText = msclr::interop::marshal_as<std::string>(textFromTextBox);
	d = std::stoi(strText);

	textFromTextBox = month2->Text;
	strText = msclr::interop::marshal_as<std::string>(textFromTextBox);
	m = std::stoi(strText);

	textFromTextBox = year2->Text;
	strText = msclr::interop::marshal_as<std::string>(textFromTextBox);
	y = std::stoi(strText);

	if (!is_Date_Exist(d, m, y))
	{
		if (excep_flag)
			mess += " та ";
		excep_flag = 1;
		mess += " Дати 2";
	}
	if (excep_flag)
		throw MyException(mess + " не існує");
	return;
}

System::Void Lab7::MyForm::date_generation_Click(System::Object^ sender, System::EventArgs^ e)
{
	SetWhiteBackColor();

	std::string temp;
	int year = 1980 + rand() % 44;
	int month = 1 + rand() % 12; 
	int day = GenerateDay(year, month);       // день мусимо генерувати в залежності від місяця і року

	day1->Text = System::Convert::ToString(day);
	month1->Text = System::Convert::ToString(month);
	year1->Text = System::Convert::ToString(year);

	year = 1980 + rand() % 44;
	month = 1 + rand() % 12;
	day = GenerateDay(year, month);

	day2->Text = System::Convert::ToString(day);
	month2->Text = System::Convert::ToString(month);
	year2->Text = System::Convert::ToString(year);

	result->Text = " ";
	return System::Void();
}

System::Void Lab7::MyForm::find_new_date_Click(System::Object^ sender, System::EventArgs^ e)
{
	SetWhiteBackColor();

	try {
		IsEmptyInterface();
		IsCellIsNumber();
		IsInterfaceDateExist();
		
		Date d1, d2;
		int temp;
		temp = System::Convert::ToInt32(day1->Text);
		d1.setDay(temp);

		temp = System::Convert::ToInt32(month1->Text);
		d1.setMonth(temp);

		temp = System::Convert::ToInt32(year1->Text);
		d1.setYear(temp);

		temp = System::Convert::ToInt32(day2->Text);
		d2.setDay(temp);

		temp = System::Convert::ToInt32(month2->Text);
		d2.setMonth(temp);

		temp = System::Convert::ToInt32(year2->Text);
		d2.setYear(temp);

		std::string resultMess;
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
