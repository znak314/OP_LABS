#include"ClassLib.h"

const int LINESIZE = 40;

int EnterSize(string s)
{
	cout << "Скільки" << s << "чисел створити? ";
	int size;
    while (true) {
        cout << "Введіть ціле число з діапазону від 1 до 20: ";
        if (cin >> size) {
            if (size >= 1 && size <= 20) {
                break; 
            }
            else {
                cout << "Помилка: введене число не знаходиться в діапазоні від 1 до 20." << endl;
            }
        }
        else {
            cout << "Помилка: введене значення не є цілим числом." << endl;
            cin.clear();  // очищення флагу помилки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // очищення введеного буферу
        }
    }
    return size;
}

void printLine()
{
    cout << "\t\t\t";
    for (int i = 0; i < LINESIZE; i++)
    {
        if (i == 0 || i == LINESIZE / 2 || i == LINESIZE)
        {
            cout << "+";
        }
        else {
            cout << "-";
        }
    }
    cout << endl;
}

void PrintBinMatrix(TIntNumber2* A, int size)
{
    cout << endl;
    printLine();
    cout << "\t\t\t|" << setw(13) << "Двійкова" << setw(7) << '|' << setw(14) << "Десяткова" << setw(5) << '|' << endl;
    printLine();

    for (int i = 0; i < size; i++)
    {
        A[i].print();
        printLine();
    }
} 

void PrintHexMatrix(TIntNumber16* A, int size)
{
    cout << endl;
    printLine();
    cout << "\t\t\t|" << setw(17) << "Шістнадцяткова" << setw(3) << '|' << setw(14) << "Десяткова" << setw(5) << '|' << endl;
    printLine();

    for (int i = 0; i < size; i++)
    {
        A[i].print();
        printLine();
    }
}

void BinIncrementation(TIntNumber2* A, int size)
{
    for (int i = 0; i < size; i++)
    {
        A[i].Increment();
    }
}

void HexDecrementation(TIntNumber16* A, int size)
{
    for (int i = 0; i < size; i++)
    {
        A[i].Decrement();
    }
}

int find_biggest_bin(TIntNumber2* A, int size)
{
    int max = A[0].GetDecimal();
    for (int i = 1; i < size; i++)
    {
        if (A[i].GetDecimal() > max)
            max = A[i].GetDecimal();
    }
    return max;
}

int find_biggest_hex(TIntNumber16* A, int size)
{
    int max = A[0].GetDecimal();
    for (int i = 1; i < size; i++)
    {
        if (A[i].GetDecimal() > max)
            max = A[i].GetDecimal();
    }
    return max;
}

int FindBiggestNum(TIntNumber2* bin, int size1, TIntNumber16* hex, int size2)
{
    if (find_biggest_bin(bin, size1) > find_biggest_hex(hex, size2))
    {
        return find_biggest_bin(bin, size1);
    }
    else
        find_biggest_hex(hex, size2);
}
