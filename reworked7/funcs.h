#include<cwctype>
#include"Classes.h"
#include<string>
#include <sstream>

bool is_leap(int year);
int GenerateDay(int year, int month);
bool isStringEmpty(const std::string& str);
bool is_number(const std::string& str);
int Compare( Date& A,  Date& B);
bool isDateFormatValid(const std::string &s);
bool is_Date_Exist(std::string  date);
