#include"ClassLib.h"
#include"Funcs.h"
#include<Windows.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int m, // к-ть двійкових
		n; // к-ть шістнадцяткових

	m = EnterSize(" Двійкових ");
	n = EnterSize(" Шістнадцяткових ");

	TIntNumber2* binary_matrix = new TIntNumber2[m];
	TIntNumber16* hex_matrix = new TIntNumber16[n];

	PrintBinMatrix(binary_matrix, m);
	PrintHexMatrix(hex_matrix, n);

	BinIncrementation(binary_matrix, m);
	HexDecrementation(hex_matrix, n);

	cout << "\n\t\t\t  Інкрементоваий масив двійкових чисел:";
	PrintBinMatrix(binary_matrix, m);

	cout << "\n\t\t     Декрементований  масив шістнадцяткових  чисел:";
	PrintHexMatrix(hex_matrix, n);

	int max = FindBiggestNum(binary_matrix,m,hex_matrix,n);
	cout << "\n\t\t\t\tНайбільше число - " << max << endl;
	return 0;
}
