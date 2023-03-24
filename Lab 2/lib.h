#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include<conio.h>
#include <iomanip>

using namespace std;

struct date {
	int day,
		month,
		year;
};

struct Car {
	char brand[31]; // марка
	date ReleaseDate, // дата випуску
		SaleDate;  // дата надходження у продаж
};


void EnterFileName(string& str);
bool is_file_exist(string NameOfFile);
bool is_file_empty(string NameOfFile);
void create_file(string NameOfFile);
void enter_date(date* newDate);
void append_file(string NameOfFile);
void PrintFile(string NameOfFile);
void PrintSlashes();
bool is_leap_year(int year);
int GetDayNumber(int day, int month, bool is_leap);
void GetNewCars(string FileName);
int EnterYear();
void PrintCarsYoungerThanYear(string NameOfFile, int year);
