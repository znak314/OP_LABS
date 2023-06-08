#include"Mylib.h"
#include"funcs.h"


template<typename T>
void Array<T>::Iterator::SetValue(const T& value) {
	*ptr = value;
}

template<typename T>
Array<T>::Array(int s) :size(s) {
	data = new T[size];
	Iterator it = Begin();
	Iterator end = End();

	while (!it.IsEnd(end)) {
		it.SetValue(T());
		it.Next();
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] data;
}

template<typename T>
int Array<T>::GetSize()
{
	return size;
}


template<typename T>
int Array<T>::Find(const T& value) {
	Iterator it = Begin();
	Iterator end = End();
	int index = 0;

	while (!it.IsEnd(end)) {
		if (it.GetValue() == value)
			return index;

		it.Next();
		index++;
	}

	return -1;
}

template<typename T>
bool Array<T>::IsEmpty() {
	Iterator it = Begin();
	Iterator end = End();

	while (!it.IsEnd(end)) {
		T& value = it.GetValue();
		if (value != T() && value != ' ') {
			return false;  // Знайдено непустий елемент
		}
		it.Next();
	}
	return true;
}

template<typename T>
void Array<T>::Insert(int pos, const T& value) {
	if (pos >= 0 && pos < size)
		data[pos] = value;
}

template<typename T>
void Array<T>::PrintArray() {
	Iterator it = Begin();
	Iterator end = End();
	int counter = 0;

	while (!it.IsEnd(end)) {
		std::cout << counter + 1 << ". ";
		if (data[counter] == 0 || data[counter] == ' ')
		{
			std::cout << ' ' << std::endl;
		}
		else
			std::cout<< it.GetValue() << std::endl;
		counter++;
		it.Next();
	}
}

template<class T>
Array<T>::Iterator::Iterator(T* start) : ptr(start) {}


template<typename T>
T& Array<T>::Iterator::GetValue() {
	return *ptr;
}


template<typename T>
void Array<T>::Iterator::Next() {
	ptr++;
}

template<typename T>
void Array<T>::Iterator::Previous() {
	ptr--;
}

template<typename T>
bool Array<T>::Iterator::IsEnd(Iterator end) {
	return ptr == end.ptr;
}




template<typename T>
typename Array<T>::Iterator Array<T>::Begin() {
	return Iterator(data);
}


template<typename T>
typename Array<T>::Iterator Array<T>::End() {
	return Iterator(data + size);
}

template <typename T>
void processArray(int size)
{
	Array<T> MyArray(size);
	int option;
	int cont = 0;
	do
	{
		OperationMenu();

		std::cout << "Ваша опція: ";
		std::cin >> option;

		switch (option)
		{
		case 1: // визначення розміру масиву
		{
			std::cout << "Розмірність масиву: " << MyArray.GetSize() << std::endl;
			break;
		}
		case 2: // пошук елемента із заданим значенням
		{
			T value;
			std::cout << "Введіть значення для пошуку: ";
			std::cin >> value;

			int index = MyArray.Find(value);
			if (index != -1) {
				std::cout << "Елемент знайдено на позиції " << index + 1<< std::endl;
			}
			else {
				std::cout << "Елемент не знайдено" << std::endl;
			}
			break;
		}
		case 3: // перевірка масиву на пустоту
		{
			if (MyArray.IsEmpty()) {
				std::cout << "Масив порожній" << std::endl;
			}
			else {
				std::cout << "Масив не порожній" << std::endl;
			}
			break;
		}
		case 4: // включення нового елемента в позицію із заданим номером
		{
			int pos;
			T value;
			std::cout << "Введіть позицію для вставки: ";
			std::cin >> pos;
			if (pos < 1 || pos > MyArray.GetSize())
			{
				std::cout << "Некоректна позиція елементу\n";
				break;
			}
			std::cout << "Введіть значення для вставки: ";
			std::cin >> value;
			MyArray.Insert(pos - 1, value);
			break;
		}
		case 5: // виведення вмісту масиву
		{
			std::cout << "Вміст масиву:\n";
			MyArray.PrintArray();
			break;
		}
		default: // некоректне введення
		{
			std::cout << "Некоректне введення\n";
			break;
		}
		}
		
		std::cout << "\nНатисність будь-яку клавішу, щоб продовжити або 0, щоб вийти. ";
		cont = _getch();
	} while (cont != '0');
}

template class Array<bool>;
template class Array<int>;
template class Array<float>;
template class Array<double>;
template class Array<char>;

template void processArray<bool>(int size);
template void processArray<int>(int size);
template void processArray<float>(int size);
template void processArray<double>(int size);
template void processArray<char>(int size);

