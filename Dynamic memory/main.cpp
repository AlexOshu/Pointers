#include <iostream>
using namespace std;

//#define PUSH_BACK
#define FRONT_BACK

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int& n, int value);
int* front_back(int* arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);
	arr = front_back(arr, n, value);


	
	Print(arr, n);

	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// Через арифметику указателей и оператор разыменования
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
#ifdef PUSH_BACK
int* push_back(int* arr, int& n, int value)
{
	//1) Создаём буфферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) После того как все данные чкопированы с исходного массива в буферный исходный, массив больше не нужен и его можно удалить:
	delete[] arr;

	//4) Подменяем адрес исходного массива в указателе 'arr' адресом нового массива
	arr = buffer;

	//5) И только после этого можно написать вот так:
	arr[n] = value;
	//поскольку только сейчас в массиве 'arr' появился ещё один элемент, в который можно сохранить значение.

	//6) После того как мы добавили в массив элемент, количество элементов массива увеличивается
	n++;

	// 7) Misson complete - Элемент добавлен!
	return arr;
}
#endif // PUSH_BACK
#ifdef FRONT_BACK
int* push_back(int* arr, int& n, int value)
{
	//1) Создаём буфферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) После того как все данные чкопированы с исходного массива в буферный исходный, массив больше не нужен и его можно удалить:
	delete[] arr;

	//4) Подменяем адрес исходного массива в указателе 'arr' адресом нового массива
	arr = buffer;

	//5) И только после этого можно написать вот так:
	arr[n] = value;
	//поскольку только сейчас в массиве 'arr' появился ещё один элемент, в который можно сохранить значение.

	//6) После того как мы добавили в массив элемент, количество элементов массива увеличивается
	n--;

	// 7) Misson complete - Элемент добавлен!
	return arr;
}
#endif // FRONT_BACK
