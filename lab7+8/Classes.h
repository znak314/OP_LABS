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
public:
    Date() { day = 0; month = 0; year = 0; }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    int GetDay() { return day; }
    int GetMonth() { return month; }
    int GetYear() { return year; }


};
