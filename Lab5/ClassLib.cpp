#include"ClassLib.h"

void TIntNumber::Increment()
{
	number++;
	Convert();
}

void TIntNumber::Decrement()
{
	number--;
	Convert();
}

// Функції для переведення з десяткової у інші системи числення

void TIntNumber2::Convert()
{
    binary = "";
    if (number == 0) {
         binary += "0";
    }
    int copy = number;
    while (copy > 0) {
        binary = to_string(copy % 2) + binary;
        copy /= 2;
    }
}

void TIntNumber8::Convert()
{
    int copy = number; 
    octal = "";

    if (copy == 0) {
        octal += "0";
    }
    while (copy > 0) {
        octal = to_string(copy % 8) + octal;
        copy /= 8;
    }
}

void TIntNumber16::Convert()
{
    hex = "";
    int copy = number;
    if (copy == 0) {
        hex += "0";
    }
    while (copy > 0) {
        int digit = copy % 16;
        if (digit < 10) {
            hex = to_string(digit) + hex;
        }
        else {
            hex = char(digit - 10 + 'A') + hex;
        }
        copy /= 16;
    }
}



// конструктори для класів різнихсистем числення
TIntNumber::TIntNumber()
{
    number = 1 + rand() % 100;
    base = 10;
}
TIntNumber2::TIntNumber2()
{
    base = 2;
    Convert();
}

TIntNumber8::TIntNumber8()
{
    base = 8;
    Convert();
}

TIntNumber16::TIntNumber16()
{
    base = 16;
    Convert();
}

// методи для виведення
void TIntNumber8::print()
{
    cout << "\t\t\t|" << setw((20 - octal.length()) / 2 + octal.length() + 1) << octal << setw(octal.length()) << '|' << setw(12) << number << setw(7) << '|' << endl;
}

void TIntNumber2::print()
{
    int buff = (20 - binary.length()) / 2 ;
    cout << "\t\t\t|" << setw((buff + binary.length() + binary.length() % 2)) << binary << setw(buff) << '|' << setw(12) << number << setw(7) << '|' << endl;
}

void TIntNumber16::print()
{
    int buff = (20 - hex.length()) / 2;
    cout << "\t\t\t|" << setw((buff + hex.length() + hex.length() % 2)) << hex << setw(buff) << '|' << setw(12) << number << setw(7) << '|' << endl;
}

// геттери для десяткової системи
int TIntNumber::GetDecimal()
{
    return number;
}
