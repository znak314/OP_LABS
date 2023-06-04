#include <exception>
#include<string>

class MyException : public std::exception {
    std::string errorMessage;

public:
    MyException(const std::string& message) : errorMessage(message) {}

    virtual const char* what() const throw();
};

class Date
{
    int day,
        month,
        year;
    std::string dateInFormat;
public:
    Date() { day = 0; month = 0; year = 0; }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
    void SetDateFormat(std::string s) { dateInFormat = s; }
    std::string GetDateFormat() { return dateInFormat; }

    int GetDay() { return day; }
    int GetMonth() { return month; }
    int GetYear() { return year; }
};
