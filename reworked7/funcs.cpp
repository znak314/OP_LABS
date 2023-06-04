#include"Classes.h"
#include<cwctype>
#include<string>
#include <sstream>

bool is_leap(int year)
{
    if (year % 4 != 0) {
        return false;
    }
    else if (year % 100 != 0) {
        return true;
    }
    else if (year % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}

int GenerateDay(int year, int month)
{
    int day;
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
    {
        day = 1 + rand() % 31;
    }
    else if (month != 2)
    {
        day = 1 + rand() % 30;
    }
    else {
        if (is_leap(year)) // рік високосний
        {
            day = 1 + rand() % 29;
        }
        else {
            day = 1 + rand() % 28;
        }
    }
    return day;
}


bool isStringEmpty(const std::string& str) {
    return str.empty();
}

bool is_number(const std::string& str)
{
    for (char c : str) {
        if (!std::iswdigit(c)) {
            return false;  
        }
    }
    return true;
}

bool is_Date_Exist(std::string date)
{
    std::istringstream iss(date);
    std::string day_str, month_str, year_str;

    std::getline(iss, day_str, '-');
    std::getline(iss, month_str, '-');
    std::getline(iss, year_str);

    int day = std::stoi(day_str);
    int month = std::stoi(month_str);
    int year = std::stoi(year_str);

    if (month <= 12 && day <= 31 && year <= 9999)
    {
        if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && day <= 31)
        {
            return true;
        }
        else if ((month != 2) && day <= 30) {
            return true;
        }
        else {
            if (is_leap(year) && day <= 29)
                return true;
            if (day <= 28)
                return true;
        }
    }
    return false;

}

// валідація формату
bool isDateFormatValid(const std::string& date) {
    if (date.length() != 10) {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            if (date[i] != '-') {
                return false;
            }
        }
        else {
            if (!std::iswdigit(date[i])) {
                return false;
            }
        }
    }

    return true;
}

// якщо перша дата більше, повертаємо 1
int Compare(Date& A, Date& B)
{
    if (A.GetYear() > B.GetYear())
        return 1;
    if (A.GetYear() <  B.GetYear())
        return 2;

    // якщо дійшли доти, то роки однакові
    if (A.GetMonth() > B.GetMonth())
        return 1;
    if (A.GetMonth() < B.GetMonth())
        return 2;

    // якщо дійшли доти, то місяці однакові
    if (A.GetDay() > B.GetDay())
        return 1;
    if (A.GetDay() < B.GetDay())
        return 2;

    return 0; // дати однакові
}
