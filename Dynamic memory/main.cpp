#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value,int index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int index);


void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value, selection, index;
	cout << "¬ведите действие из предложенных: " << endl;
	cout << "1 - добавл€ет значение в конец массива" << endl
		<< "2 - добавл€ет значение в начало массива" << endl
		<< "3 - добавл€ет значение в массив по указанному индексу" << endl
		<< "4 - удал€ет значение из конца массива" << endl
		<< "5 - удал€ет значение c начала массива" << endl
		<< "6 - удал€ет значение из массива по указанному индексу" << endl;
	cin >> selection;
	switch (selection)
	{
	case(1):
		cout << "¬ведите значение дл€ добавлени€: "; cin >> value;
		arr = push_back(arr, n, value); break;

	case(2):
		cout << "¬ведите значение дл€ добавлени€: "; cin >> value;
		arr = push_front(arr, n, value); break;

	case(3):
		cout << "¬ведите значение дл€ добавлени€: "; cin >> value;
		cout << "¬ведите индекс значени€ дл€ добавлени€ в массив: "; cin >> index;
		arr = insert(arr, n, value, index); break;

	case(4):
		arr = pop_back(arr, n); break;

	case(5):
		arr = pop_front(arr, n); break;

	case(6):
		cout << "¬ведите индекс значени€ дл€ удалени€ из массива: "; cin >> index;
		arr = erase(arr, n, index); break;
	default: cout << "ќшибка ввода" << endl; break;
	}
	Print(arr, n);
	delete[] arr;
}



void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//„ерез арифметику указателей и оператор разыменовани€
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int* arr, int& n, int value)
{
	//1) —оздаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2)  опируем содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ѕосле того как все данные скопированы из исходного массива в буферный,
	//	 исходный массив больше не нужен, и его можно удалить:
	delete[] arr;

	//4) ѕодмен€ем адрес исходного массива в указателе 'arr' адресом нового массива:
	arr = buffer;

	//5) » только после всего этого можно написать вот так:
	arr[n] = value;
	//поскольку только сейчас в массиве 'arr' по€вилс€ еще один элемент, 
	//в который можно сохранить значение.

	//6) ѕосле того как мы добавили в массив элемент, количество элементов массива увеличиваетс€ на 1
	n++;
	//7) Mission complete - Ёлемент добавлен!
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		(i == 0 ? buffer[i] = value : buffer[i] = arr[i - 1]);
	}
	delete[]arr;
	arr = buffer;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		(i <= (index - 1) ? (i == (index - 1) ? buffer[i] = value : buffer[i] = arr[i]) : buffer[i] = arr[i - 1]);
	}
	delete[]arr;
	arr = buffer;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int* arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		(i <= (index - 1) ? (i == (index - 1) ? (buffer[i] = arr[i+1]) : (buffer[i] = arr[i])) : buffer[i] = arr[i + 1]);
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}



/*
-------------------------------------------------
Debug Assertion Failed:
1. ”даление из статической пам€ти
2. ѕовторное удаление динамической пам€ти, а именно, 
   когда оператору delete[] передали два раза один и тот же адрес.
--------
*/