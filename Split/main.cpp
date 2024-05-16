#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);

void Print(int arr[], const int n);

void main() {
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0)even_count++;
		else odd_count++;
	}
	cout << endl;
	cout << "Количество четных элементов: " << even_count << endl;
	cout << "Количество не четных элементов: " << odd_count << endl;
	//выделяем память для массива
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];
	//копируем четные и нечетные элементы в соответствующие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++) {
		if (arr[i] % 2 == 00) {
			even_arr[j] = arr[i];
			j++;
		}
		else {
			odd_arr[k] = arr[i];
			k++;
		}
	}
	//Вывод результатов
	Print(even_arr, even_count);
	cout << endl;
	Print(odd_arr, odd_count);
	//удаление масивов
	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++)	arr[i] = rand() % 100;
}

void Print(int arr[], const int n){
	for (int i = 0; i < n; i++)cout << arr[i]<<tab;
}